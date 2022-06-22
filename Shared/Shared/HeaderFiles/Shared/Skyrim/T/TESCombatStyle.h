#pragma once

#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class TESCombatStyle :
		public TESForm // 0
	{
	public:
		enum class RecordFlags : std::uint32_t
		{
			kAllowDualWielding = 1U << 19
		};
		static_assert(sizeof(RecordFlags) == 0x4);

		enum class Flags : std::uint32_t
		{
			kNone              = 0,
			kDueling           = 1U << 0, // Close Range
			kFlanking          = 1U << 1, // Close Range
			kAllowDualWielding = 1U << 2  // Melee, Also in RecordFlags
		};
		static_assert(sizeof(Flags) == 0x4);

		struct General
		{
		public:
			struct EquipmentScoreMultipliers
			{
			public:
				// Member variables
				float melee;   // 0
				float magic;   // 4
				float ranged;  // 8
				float shout;   // C
				float unarmed; // 10
				float staff;   // 14
			};
			static_assert(offsetof(EquipmentScoreMultipliers, melee) == 0x0);
			static_assert(offsetof(EquipmentScoreMultipliers, magic) == 0x4);
			static_assert(offsetof(EquipmentScoreMultipliers, ranged) == 0x8);
			static_assert(offsetof(EquipmentScoreMultipliers, shout) == 0xC);
			static_assert(offsetof(EquipmentScoreMultipliers, unarmed) == 0x10);
			static_assert(offsetof(EquipmentScoreMultipliers, staff) == 0x14);
			static_assert(sizeof(EquipmentScoreMultipliers) == 0x18);

			// Member variables
			float                     offensiveMultiplier;       // 0
			float                     defensiveMultiplier;       // 4
			float                     groupOffensiveMultiplier;  // 8
			EquipmentScoreMultipliers equipmentScoreMultipliers; // C
			float                     avoidThreatChance;         // 24
		};
		static_assert(offsetof(General, offensiveMultiplier) == 0x0);
		static_assert(offsetof(General, defensiveMultiplier) == 0x4);
		static_assert(offsetof(General, groupOffensiveMultiplier) == 0x8);
		static_assert(offsetof(General, equipmentScoreMultipliers) == 0xC);
		static_assert(offsetof(General, avoidThreatChance) == 0x24);
		static_assert(sizeof(General) == 0x28);

		struct Melee
		{
		public:
			// Member variables
			float attackStaggeredMultiplier;      // 0
			float powerAttackStaggeredMultiplier; // 4
			float powerAttackBlockingMultiplier;  // 8
			float bashMultiplier;                 // C
			float bashRecoiledMultiplier;         // 10
			float bashAttackMultiplier;           // 14
			float bashPoweredAttackMultiplier;    // 18
			float specialAttackMultiplier;        // 1C
		};
		static_assert(offsetof(Melee, attackStaggeredMultiplier) == 0x0);
		static_assert(offsetof(Melee, powerAttackStaggeredMultiplier) == 0x4);
		static_assert(offsetof(Melee, powerAttackBlockingMultiplier) == 0x8);
		static_assert(offsetof(Melee, bashMultiplier) == 0xC);
		static_assert(offsetof(Melee, bashRecoiledMultiplier) == 0x10);
		static_assert(offsetof(Melee, bashAttackMultiplier) == 0x14);
		static_assert(offsetof(Melee, bashPoweredAttackMultiplier) == 0x18);
		static_assert(offsetof(Melee, specialAttackMultiplier) == 0x1C);
		static_assert(sizeof(Melee) == 0x20);

		struct CloseRange
		{
		public:
			struct Dueling
			{
			public:
				// Member variables
				float circleMultiplier;   // 0
				float fallbackMultiplier; // 4
			};
			static_assert(offsetof(Dueling, circleMultiplier) == 0x0);
			static_assert(offsetof(Dueling, fallbackMultiplier) == 0x4);
			static_assert(sizeof(Dueling) == 0x8);

			struct Flanking
			{
			public:
				// Member variables
				float flankDistance; // 0
				float stalkTime;     // 4
			};
			static_assert(offsetof(Flanking, flankDistance) == 0x0);
			static_assert(offsetof(Flanking, stalkTime) == 0x4);
			static_assert(sizeof(Flanking) == 0x8);

			// Member variables
			Dueling  dueling;  // 0
			Flanking flanking; // 8
		};
		static_assert(offsetof(CloseRange, dueling) == 0x0);
		static_assert(offsetof(CloseRange, flanking) == 0x8);
		static_assert(sizeof(CloseRange) == 0x10);

		struct LongRange
		{
		public:
			// Member variables
			float strafeMultiplier; // 0
		};
		static_assert(offsetof(LongRange, strafeMultiplier) == 0x0);
		static_assert(sizeof(LongRange) == 0x4);

		struct Flight
		{
		public:
			// Member variables
			float hoverChance;        // 0
			float diveBombChance;     // 4
			float groundAttackChance; // 8
			float hoverTime;          // C
			float groundAttackTime;   // 10
			float perchAttackChance;  // 14
			float perchAttackTime;    // 18
			float flyingAttackChance; // 1C
		};
		static_assert(offsetof(Flight, hoverChance) == 0x0);
		static_assert(offsetof(Flight, diveBombChance) == 0x4);
		static_assert(offsetof(Flight, groundAttackChance) == 0x8);
		static_assert(offsetof(Flight, hoverTime) == 0xC);
		static_assert(offsetof(Flight, groundAttackTime) == 0x10);
		static_assert(offsetof(Flight, perchAttackChance) == 0x14);
		static_assert(offsetof(Flight, perchAttackTime) == 0x18);
		static_assert(offsetof(Flight, flyingAttackChance) == 0x1C);
		static_assert(sizeof(Flight) == 0x20);

		// Override
		virtual ~TESCombatStyle() override; // 0

		// Override (TESForm)
		virtual void InitializeData() override;    // 4
		virtual void Unknown6(TESForm*) override;  // 6
		virtual void Unknown13(TESForm*) override; // 13

		// Member variables
		General                                    general;          // 20
		Melee                                      melee;            // 48
		CloseRange                                 closeRange;       // 68
		LongRange                                  longRange;        // 78
		Flight                                     flight;           // 7C
		Utility::Enumeration<Flags, std::uint32_t> combatStyleFlags; // 9C
	};
	static_assert(offsetof(TESCombatStyle, general) == 0x20);
	static_assert(offsetof(TESCombatStyle, melee) == 0x48);
	static_assert(offsetof(TESCombatStyle, closeRange) == 0x68);
	static_assert(offsetof(TESCombatStyle, longRange) == 0x78);
	static_assert(offsetof(TESCombatStyle, flight) == 0x7C);
	static_assert(offsetof(TESCombatStyle, combatStyleFlags) == 0x9C);
	static_assert(sizeof(TESCombatStyle) == 0xA0);
}
