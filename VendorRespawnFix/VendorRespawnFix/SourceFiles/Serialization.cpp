#include "PrecompiledHeader.h"

#include "Serialization.h"

#include "Shared/Utility/Conversion.h"
#include "Shared/Utility/Log.h"



namespace VendorRespawnFix
{
	bool Serialization::LastDayRespawned::LoadGame(SKSE::SerializationInterface* serializationInterface)
	{
		serializationInterface->ReadRecordData(*this);

		if (!serializationInterface->ResolveFormID(this->formID, this->formID))
		{
			Utility::Log::Error()("Failed to resolve form ID, 0x{:X}.", this->formID);

			return false;
		}

		auto* faction = static_cast<Skyrim::TESFaction*>(Skyrim::TESDataHandler::GetForm(this->formID));

		if (!faction || faction->formType != Skyrim::FormType::kFaction)
		{
			Utility::Log::Error()("Faction not found, form ID 0x{:X}.", this->formID);

			return false;
		}

		if (!faction->vendor.merchantContainer)
		{
			Utility::Log::Error()("Merchant container not found, form ID 0x{:X}.", this->formID);

			return false;
		}

		faction->vendor.lastDayRespawned = this->lastDayRespawned;

		return true;
	}

	bool Serialization::LastDayRespawned::SaveGame(SKSE::SerializationInterface* serializationInterface, Skyrim::TESFaction* faction)
	{
		if (!faction)
		{
			Utility::Log::Error()("Faction not found.");

			return false;
		}

		if (!faction->vendor.merchantContainer)
		{
			return false;
		}

		this->formID           = faction->formID;
		this->lastDayRespawned = faction->vendor.lastDayRespawned;

		serializationInterface->WriteRecord(LastDayRespawned::kType, LastDayRespawned::kVersion, *this);

		return true;
	}

	void Serialization::LoadGame(SKSE::SerializationInterface* serializationInterface)
	{
		Utility::Log::Information()("Loading Game...");

		std::uint32_t type, version, length;

		while (serializationInterface->GetNextRecordInformation(type, version, length))
		{
			switch (type)
			{
				case LastDayRespawned::kType:
				{
					if (version != LastDayRespawned::kVersion)
					{
						Utility::Log::Error()("{} version mismatch, {}.", type, version);

						continue;
					}

					if (length != sizeof(LastDayRespawned))
					{
						Utility::Log::Error()("{} size mismatch, 0x{:X}.", type, length);

						continue;
					}

					LastDayRespawned().LoadGame(serializationInterface);

					break;
				}
				default:
				{
					Utility::Log::Error()("Type mismatch, {}.", type);

					break;
				}
			}
		}

		Utility::Log::Information()("Loaded Game.");
	}

	void Serialization::SaveGame(SKSE::SerializationInterface* serializationInterface)
	{
		Utility::Log::Information()("Saving Game...");

		const auto& factions = Skyrim::TESDataHandler::GetSingleton()->formArrays[Utility::Conversion::ToUnderlying(Skyrim::FormType::kFaction)];

		for (auto* faction : factions)
		{
			LastDayRespawned().SaveGame(serializationInterface, static_cast<Skyrim::TESFaction*>(faction));
		}

		Utility::Log::Information()("Saved Game.");
	}
}
