#include "PCH.h"

#include "Serialization.h"

#include "Settings.h"
#include "Shared/Skyrim/B/BSAtomic.h"
#include "Shared/Skyrim/P/PersistentFormManager.h"
#include "Shared/Skyrim/T/TESDataHandler.h"
#include "Shared/Utility/Log.h"



namespace ScrambledBugs::Serialization
{
	bool EnchantmentCost::Deserialize(SKSE::SerializationInterface* serializationInterface)
	{
		EnchantmentCost record;
		serializationInterface->ReadRecordData(record);

		if (!serializationInterface->ResolveFormID(record.formID, record.formID))
		{
			Utility::Log::Error("Failed to resolve form ID, 0x{:X}.", record.formID);

			return false;
		}

		auto enchantment = static_cast<Skyrim::EnchantmentItem*>(Skyrim::TESDataHandler::GetForm(record.formID));

		if (!enchantment || enchantment->formType != Skyrim::FormType::kEnchantment)
		{
			Utility::Log::Error("Enchantment not found, form ID 0x{:X}.", record.formID);

			return false;
		}

		auto enchantmentItemData = static_cast<Skyrim::EnchantmentItem::Data*>(enchantment->GetData());

		if (!enchantmentItemData)
		{
			Utility::Log::Error("Data not found, form ID 0x{:X}.", record.formID);

			return false;
		}

		enchantmentItemData->enchantmentCost      = record.enchantmentCost;
		enchantmentItemData->enchantmentItemFlags = record.enchantmentItemFlags;

		return true;
	}

	bool EnchantmentCost::Serialize(SKSE::SerializationInterface* serializationInterface, Skyrim::EnchantmentItem* enchantment)
	{
		if (!enchantment)
		{
			Utility::Log::Error("Enchantment not found.");

			return false;
		}

		auto enchantmentItemData = static_cast<Skyrim::EnchantmentItem::Data*>(enchantment->GetData());

		if (!enchantmentItemData)
		{
			Utility::Log::Error("Data not found.");

			return false;
		}

		EnchantmentCost record;
		record.formID               = enchantment->formID;
		record.enchantmentCost      = enchantment->enchantmentItemData.enchantmentCost;
		record.enchantmentItemFlags = enchantment->enchantmentItemData.enchantmentItemFlags;

		serializationInterface->WriteRecord(EnchantmentCost::kType, EnchantmentCost::kVersion, record);

		return true;
	}

	void Load(SKSE::SerializationInterface* serializationInterface)
	{
		Utility::Log::Information("Loading...");

		auto& settings = ScrambledBugs::Settings::GetSingleton();

		auto                    persistentFormManager = Skyrim::PersistentFormManager::GetSingleton();
		Skyrim::BSSpinLockGuard lockGuard(persistentFormManager->lock);

		std::uint32_t type, version, length;

		while (serializationInterface->GetNextRecordInfo(type, version, length))
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

					EnchantmentCost::Deserialize(serializationInterface);

					break;
				}
				default:
				{
					Utility::Log::Error("Type mismatch, {}.", type);
				}
			}
		}

		Utility::Log::Information("Loaded.");
	}

	void Save(SKSE::SerializationInterface* serializationInterface)
	{
		Utility::Log::Information("Saving...");

		auto& settings = ScrambledBugs::Settings::GetSingleton();

		if (settings.fixes.enchantmentCost)
		{
			auto                    persistentFormManager = Skyrim::PersistentFormManager::GetSingleton();
			Skyrim::BSSpinLockGuard lockGuard(persistentFormManager->lock);

			for (const auto& armorEnchantment : persistentFormManager->armorEnchantments)
			{
				EnchantmentCost::Serialize(serializationInterface, armorEnchantment.enchantment);
			}

			for (const auto& weaponEnchantment : persistentFormManager->weaponEnchantments)
			{
				EnchantmentCost::Serialize(serializationInterface, weaponEnchantment.enchantment);
			}
		}

		Utility::Log::Information("Saved.");
	}
}
