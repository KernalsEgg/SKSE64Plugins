#include "PrecompiledHeader.h"

#include "Serialization.h"

#include "Shared/Utility/Conversion.h"



namespace VendorRespawnFix
{
	bool Serialization::LastDayRespawned::LoadGame(SKSE::SerializationInterface* serializationInterface)
	{
		serializationInterface->ReadRecordData(*this);

		if (!serializationInterface->ResolveFormID(this->formID, this->formID))
		{
			SPDLOG_ERROR("Failed to resolve form ID, 0x{:X}.", this->formID);

			return false;
		}

		auto* faction = static_cast<Skyrim::TESFaction*>(Skyrim::TESDataHandler::GetForm(this->formID));

		if (!faction || faction->formType != Skyrim::FormType::kFaction)
		{
			SPDLOG_ERROR("Faction not found, form ID 0x{:X}.", this->formID);

			return false;
		}

		if (!faction->vendor.merchantContainer)
		{
			SPDLOG_ERROR("Merchant container not found, form ID 0x{:X}.", this->formID);

			return false;
		}

		faction->vendor.lastDayRespawned = this->lastDayRespawned;

		return true;
	}

	bool Serialization::LastDayRespawned::SaveGame(SKSE::SerializationInterface* serializationInterface, Skyrim::TESFaction* faction)
	{
		if (!faction)
		{
			SPDLOG_ERROR("Faction not found.");

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
		SPDLOG_INFO("Loading Game...");

		std::uint32_t type, version, length;

		while (serializationInterface->GetNextRecordInformation(type, version, length))
		{
			switch (type)
			{
				case LastDayRespawned::kType:
				{
					if (version != LastDayRespawned::kVersion)
					{
						SPDLOG_ERROR("{} version mismatch, {}.", type, version);

						continue;
					}

					if (length != sizeof(LastDayRespawned))
					{
						SPDLOG_ERROR("{} size mismatch, 0x{:X}.", type, length);

						continue;
					}

					LastDayRespawned().LoadGame(serializationInterface);

					break;
				}
				default:
				{
					SPDLOG_ERROR("Type mismatch, {}.", type);

					break;
				}
			}
		}

		SPDLOG_INFO("Loaded Game.");
	}

	void Serialization::SaveGame(SKSE::SerializationInterface* serializationInterface)
	{
		SPDLOG_INFO("Saving Game...");

		const auto& factions = Skyrim::TESDataHandler::GetSingleton()->formArrays[Utility::Conversion::ToUnderlying(Skyrim::FormType::kFaction)];

		for (auto* faction : factions)
		{
			LastDayRespawned().SaveGame(serializationInterface, static_cast<Skyrim::TESFaction*>(faction));
		}

		SPDLOG_INFO("Saved Game.");
	}
}
