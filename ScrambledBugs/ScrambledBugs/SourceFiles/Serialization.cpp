#include "PrecompiledHeader.h"

#include "Serialization.h"

#include "Settings.h"
#include "Shared/Skyrim/B/BGSCreatedObjectManager.h"
#include "Shared/Skyrim/B/BSAtomic.h"
#include "Shared/Skyrim/T/TESDataHandler.h"
#include "Shared/Utility/Log.h"



namespace ScrambledBugs
{
	bool Serialization::EnchantmentCost::LoadGame(SKSE::SerializationInterface* serializationInterface)
	{
		serializationInterface->ReadRecordData(*this);

		if (!serializationInterface->ResolveFormID(this->formID, this->formID))
		{
			Utility::Log::Error("Failed to resolve form ID, 0x{:X}.", this->formID);

			return false;
		}

		auto* enchantment = static_cast<Skyrim::EnchantmentItem*>(Skyrim::TESDataHandler::GetForm(this->formID));

		if (!enchantment || enchantment->formType != Skyrim::FormType::kEnchantment)
		{
			Utility::Log::Error("Enchantment not found, form ID 0x{:X}.", this->formID);

			return false;
		}

		auto* enchantmentItemData = static_cast<Skyrim::EnchantmentItem::Data*>(enchantment->GetData());

		if (!enchantmentItemData)
		{
			Utility::Log::Error("Data not found, form ID 0x{:X}.", this->formID);

			return false;
		}

		enchantmentItemData->enchantmentCost      = this->enchantmentCost;
		enchantmentItemData->enchantmentItemFlags = this->enchantmentItemFlags;

		return true;
	}

	bool Serialization::EnchantmentCost::SaveGame(SKSE::SerializationInterface* serializationInterface, Skyrim::EnchantmentItem* enchantment)
	{
		if (!enchantment)
		{
			Utility::Log::Error("Enchantment not found.");

			return false;
		}

		const auto* enchantmentItemData = static_cast<const Skyrim::EnchantmentItem::Data*>(enchantment->GetConstantData());

		if (!enchantmentItemData)
		{
			Utility::Log::Error("Data not found.");

			return false;
		}

		this->formID               = enchantment->formID;
		this->enchantmentCost      = enchantmentItemData->enchantmentCost;
		this->enchantmentItemFlags = enchantmentItemData->enchantmentItemFlags;

		serializationInterface->WriteRecord(EnchantmentCost::kType, EnchantmentCost::kVersion, *this);

		return true;
	}

	void Serialization::LoadGame(SKSE::SerializationInterface* serializationInterface)
	{
		Utility::Log::Information("Loading...");

		const auto& settings = ScrambledBugs::Settings::GetSingleton();

		auto*                   createdObjectManager = Skyrim::BGSCreatedObjectManager::GetSingleton();
		Skyrim::BSSpinLockGuard lockGuard(createdObjectManager->lock);

		std::uint32_t type, version, length;

		while (serializationInterface->GetNextRecordInformation(type, version, length))
		{
			switch (type)
			{
				case EnchantmentCost::kType:
				{
					if (!settings.fixes.enchantmentCost)
					{
						continue;
					}

					if (version != EnchantmentCost::kVersion)
					{
						Utility::Log::Error("{} version mismatch, {}.", type, version);

						continue;
					}

					if (length != sizeof(EnchantmentCost))
					{
						Utility::Log::Error("{} size mismatch, 0x{:X}.", type, length);

						continue;
					}

					EnchantmentCost().LoadGame(serializationInterface);

					break;
				}
				default:
				{
					Utility::Log::Error("Type mismatch, {}.", type);

					break;
				}
			}
		}

		Utility::Log::Information("Loaded.");
	}

	void Serialization::SaveGame(SKSE::SerializationInterface* serializationInterface)
	{
		Utility::Log::Information("Saving...");

		const auto& settings = ScrambledBugs::Settings::GetSingleton();

		if (settings.fixes.enchantmentCost)
		{
			auto*                   createdObjectManager = Skyrim::BGSCreatedObjectManager::GetSingleton();
			Skyrim::BSSpinLockGuard lockGuard(createdObjectManager->lock);

			for (const auto& armorEnchantment : createdObjectManager->armorEnchantments)
			{
				EnchantmentCost().SaveGame(serializationInterface, armorEnchantment.enchantment);
			}

			for (const auto& weaponEnchantment : createdObjectManager->weaponEnchantments)
			{
				EnchantmentCost().SaveGame(serializationInterface, weaponEnchantment.enchantment);
			}
		}

		Utility::Log::Information("Saved.");
	}
}
