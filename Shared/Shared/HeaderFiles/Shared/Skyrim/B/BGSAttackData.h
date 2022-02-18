#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/N/NiRefObject.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSKeyword;
	class SpellItem;

	class BGSAttackData :
		public NiRefObject // 0
	{
	public:
		enum class Flags : std::uint32_t
		{
			kNone           = 0,
			kIgnoreWeapon   = 1U << 0,
			kBashAttack     = 1U << 1,
			kPowerAttack    = 1U << 2,
			kLeftAttack     = 1U << 3,
			kRotatingAttack = 1U << 4
		};
		static_assert(sizeof(Flags) == 0x4);

		// Override
		virtual ~BGSAttackData() override; // 0

		// Member variables
		BSFixedString                              event;             // 10
		float                                      damageMultiplier;  // 18
		float                                      attackChance;      // 1C
		SpellItem*                                 attackSpell;       // 20
		Utility::Enumeration<Flags, std::uint32_t> attackDataFlags;   // 28
		float                                      attackAngle;       // 2C
		float                                      strikeAngle;       // 30
		float                                      stagger;           // 34
		BGSKeyword*                                attackType;        // 38
		float                                      knockdown;         // 40
		float                                      recoveryTime;      // 44
		float                                      staminaMultiplier; // 48
		std::int32_t                               padding4C;         // 4C
	};
	static_assert(offsetof(BGSAttackData, event) == 0x10);
	static_assert(offsetof(BGSAttackData, damageMultiplier) == 0x18);
	static_assert(offsetof(BGSAttackData, attackChance) == 0x1C);
	static_assert(offsetof(BGSAttackData, attackSpell) == 0x20);
	static_assert(offsetof(BGSAttackData, attackDataFlags) == 0x28);
	static_assert(offsetof(BGSAttackData, attackAngle) == 0x2C);
	static_assert(offsetof(BGSAttackData, strikeAngle) == 0x30);
	static_assert(offsetof(BGSAttackData, stagger) == 0x34);
	static_assert(offsetof(BGSAttackData, attackType) == 0x38);
	static_assert(offsetof(BGSAttackData, knockdown) == 0x40);
	static_assert(offsetof(BGSAttackData, recoveryTime) == 0x44);
	static_assert(offsetof(BGSAttackData, staminaMultiplier) == 0x48);
	static_assert(sizeof(BGSAttackData) == 0x50);
}
