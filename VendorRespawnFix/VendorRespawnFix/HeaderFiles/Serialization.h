#pragma once

#include "PrecompiledHeader.h"

#include "Shared/SKSE/Interfaces.h"
#include "Shared/Skyrim/B/BSCoreTypes.h"
#include "Shared/Skyrim/T/TESFaction.h"



namespace VendorRespawnFix
{
	class Serialization
	{
	public:
		enum : std::uint32_t
		{
			kUniqueID = 'VRF'
		};

		struct LastDayRespawned
		{
		public:
			enum : std::uint32_t
			{
				kType = 'LDR',

				kVersion = 1
			};

			bool LoadGame(SKSE::SerializationInterface* serializationInterface);
			bool SaveGame(SKSE::SerializationInterface* serializationInterface, Skyrim::TESFaction* faction);

			Skyrim::FormID formID;           // 0
			std::uint32_t  lastDayRespawned; // 4
		};
		static_assert(offsetof(LastDayRespawned, formID) == 0x0);
		static_assert(offsetof(LastDayRespawned, lastDayRespawned) == 0x4);
		static_assert(sizeof(LastDayRespawned) == 0x8);

		static void LoadGame(SKSE::SerializationInterface* serializationInterface);
		static void SaveGame(SKSE::SerializationInterface* serializationInterface);
	};
}
