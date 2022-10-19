#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSPointerHandle.h"
#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class bhkCharacterController;
	class HighProcessData;
	class HitData;
	class InventoryEntryData;
	class MiddleHighProcessData;
	class NiAVObject;

	struct CachedValue
	{
	public:
		// Member variables
		bool          dirty;    // 0
		std::uint8_t  padding1; // 1
		std::uint16_t padding2; // 2
		float         value;    // 4
	};
	static_assert(offsetof(CachedValue, dirty) == 0x0);
	static_assert(offsetof(CachedValue, value) == 0x4);
	static_assert(sizeof(CachedValue) == 0x8);

	struct CachedValues
	{
	public:
		enum class BooleanValues : std::uint32_t
		{
			kNPC    = 1U << 1,
			kUndead = 1U << 2
		};
		static_assert(sizeof(BooleanValues) == 0x4);

		enum class Flags : std::uint32_t
		{
			kNPC    = 1U << 25,
			kUndead = 1U << 26
		};
		static_assert(sizeof(Flags) == 0x4);

		// Member variables
		std::uint64_t                                      unknown0;             // 0
		std::uint64_t                                      unknown8;             // 8
		std::uint64_t                                      unknown10;            // 10
		std::uint64_t                                      unknown18;            // 18
		std::uint64_t                                      unknown20;            // 20
		Utility::Enumeration<BooleanValues, std::uint32_t> booleanValues;        // 28
		Utility::Enumeration<Flags, std::uint32_t>         flags;                // 2C
		BSTArray<CachedValue>                              actorValues;          // 30
		BSTArray<CachedValue>                              permanentActorValues; // 48
	};
	static_assert(offsetof(CachedValues, booleanValues) == 0x28);
	static_assert(offsetof(CachedValues, flags) == 0x2C);
	static_assert(offsetof(CachedValues, actorValues) == 0x30);
	static_assert(offsetof(CachedValues, permanentActorValues) == 0x48);
	static_assert(sizeof(CachedValues) == 0x60);

	class MiddleLowProcessData
	{
	public:
		// Member variables
		std::uint32_t unknown0; // 0
	};
	static_assert(sizeof(MiddleLowProcessData) == 0x4);

	class AIProcess
	{
	public:
		// Member functions
		InventoryEntryData*     GetAmmunitionInventoryEntryData() const;
		bhkCharacterController* GetCharacterController() const;
		ObjectReferenceHandle   GetCurrentFurniture() const;
		InventoryEntryData*     GetLeftHandInventoryEntryData() const;
		InventoryEntryData*     GetRightHandInventoryEntryData() const;
		NiAVObject*             GetHeadNode() const;
		NiAVObject*             GetTorsoNode() const;
		HitData*                GetLastHitData() const;
		float                   GetMaximumWardPower() const;
		bool                    IsDualCasting() const;
		void                    SetMaximumWardPower(float maximumWardPower);

		// Member variables
		MiddleLowProcessData*  middleLowProcessData;  // 0
		MiddleHighProcessData* middleHighProcessData; // 8
		HighProcessData*       highProcessData;       // 10
		std::uint64_t          unknown18;             // 18
		std::uint64_t          unknown20;             // 20
		std::uint64_t          unknown28;             // 28
		std::uint64_t          unknown30;             // 30
		std::uint64_t          unknown38;             // 38
		std::uint64_t          unknown40;             // 40
		std::uint64_t          unknown48;             // 48
		CachedValues*          cachedValues;          // 50
		std::uint64_t          unknown58;             // 58
		std::uint64_t          unknown60;             // 60
		std::uint64_t          unknown68;             // 68
		std::uint64_t          unknown70;             // 70
		std::uint64_t          unknown78;             // 78
		std::uint64_t          unknown80;             // 80
		std::uint64_t          unknown88;             // 88
		std::uint64_t          unknown90;             // 90
		std::uint64_t          unknown98;             // 98
		std::uint64_t          unknownA0;             // A0
		std::uint64_t          unknownA8;             // A8
		std::uint64_t          unknownB0;             // B0
		std::uint64_t          unknownB8;             // B8
		std::uint64_t          unknownC0;             // C0
		std::uint64_t          unknownC8;             // C8
		std::uint64_t          unknownD0;             // D0
		std::uint64_t          unknownD8;             // D8
		std::uint64_t          unknownE0;             // E0
		std::uint64_t          unknownE8;             // E8
		std::uint64_t          unknownF0;             // F0
		std::uint64_t          unknownF8;             // F8
		std::uint64_t          unknown100;            // 100
		std::uint64_t          unknown108;            // 108
		std::uint64_t          unknown110;            // 110
		std::uint64_t          unknown118;            // 118
		std::uint64_t          unknown120;            // 120
		std::uint64_t          unknown128;            // 128
		std::uint64_t          unknown130;            // 130
		std::uint64_t          unknown138;            // 138
	};
	static_assert(offsetof(AIProcess, middleLowProcessData) == 0x0);
	static_assert(offsetof(AIProcess, middleHighProcessData) == 0x8);
	static_assert(offsetof(AIProcess, highProcessData) == 0x10);
	static_assert(offsetof(AIProcess, cachedValues) == 0x50);
	static_assert(sizeof(AIProcess) == 0x140);
}
