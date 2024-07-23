#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/ActorValue.h"
#include "Shared/Skyrim/B/BodyPartType.h"
#include "Shared/Skyrim/B/BSPointerHandle.h"
#include "Shared/Skyrim/N/NiPoint3.h"
#include "Shared/Skyrim/N/NiPointer.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSAttackData;
	class SpellItem;
	class TESObjectWEAP;
	class VATSCommand;

	class HitData
	{
	public:
		enum class Flags : std::uint32_t
		{
			kBlocked               = 1U << 0,
			kBlockedWithWeapon     = 1U << 1,
			kBlockable             = 1U << 2,
			kCriticalHit           = 1U << 3,
			kCriticalEffectOnDeath = 1U << 4,
			kKilled                = 1U << 5,
			kDismemberBodyPart     = 1U << 6,
			kExplodeBodyPart       = 1U << 7,
			kCrippleBodyPart       = 1U << 8,
			kSneakAttack           = 1U << 11,
			kBash                  = 1U << 14,
			kTimedBash             = 1U << 15,
			kPowerAttack           = 1U << 16,
			kLeftAttack            = 1U << 17
		};
		static_assert(sizeof(Flags) == 0x4);

		// Member variables
		NiPoint3                                          position;                       // 0
		NiPoint3                                          direction;                      // C
		ActorHandle                                       aggressorHandle;                // 18
		ActorHandle                                       targetHandle;                   // 1C
		ObjectReferenceHandle                             sourceHandle;                   // 20
		std::uint32_t                                     padding24;                      // 24
		NiPointer<BGSAttackData>                          attackData;                     // 28
		TESObjectWEAP*                                    weapon;                         // 30
		SpellItem*                                        criticalEffect;                 // 38, TESObjectWEAP
		SpellItem*                                        attackSpellItem;                // 40, BGSAttackData
		VATSCommand*                                      vatsCommand;                    // 48
		float                                             damageAfterResistances;         // 50
		float                                             damageBeforeResistances;        // 54
		float                                             targetBodyPartDamage;           // 58
		float                                             percentageBlocked;              // 5C
		float                                             damageToArmor;                  // 60
		float                                             damageToWeapon;                 // 64
		float                                             stagger;                        // 68
		std::uint32_t                                     unknown6C;                      // 6C
		float                                             sneakAttackDamageMultiplier;    // 70
		float                                             targetBodyPartDamageMultiplier; // 74
		float                                             reflectedDamage;                // 78
		std::uint32_t                                     unknown7C;                      // 7C
		Utility::Enumeration<Flags, std::uint32_t>        hitDataFlags;                   // 80
		std::uint32_t                                     unknown84;                      // 84
		Utility::Enumeration<ActorValue, std::uint32_t>   skill;                          // 88, TESObjectWEAP
		Utility::Enumeration<BodyPartType, std::uint32_t> targetBodyPartType;             // 8C
	};
	static_assert(offsetof(HitData, position) == 0x0);
	static_assert(offsetof(HitData, direction) == 0xC);
	static_assert(offsetof(HitData, aggressorHandle) == 0x18);
	static_assert(offsetof(HitData, targetHandle) == 0x1C);
	static_assert(offsetof(HitData, sourceHandle) == 0x20);
	static_assert(offsetof(HitData, attackData) == 0x28);
	static_assert(offsetof(HitData, weapon) == 0x30);
	static_assert(offsetof(HitData, criticalEffect) == 0x38);
	static_assert(offsetof(HitData, attackSpellItem) == 0x40);
	static_assert(offsetof(HitData, vatsCommand) == 0x48);
	static_assert(offsetof(HitData, damageAfterResistances) == 0x50);
	static_assert(offsetof(HitData, damageBeforeResistances) == 0x54);
	static_assert(offsetof(HitData, targetBodyPartDamage) == 0x58);
	static_assert(offsetof(HitData, percentageBlocked) == 0x5C);
	static_assert(offsetof(HitData, damageToArmor) == 0x60);
	static_assert(offsetof(HitData, damageToWeapon) == 0x64);
	static_assert(offsetof(HitData, stagger) == 0x68);
	static_assert(offsetof(HitData, sneakAttackDamageMultiplier) == 0x70);
	static_assert(offsetof(HitData, targetBodyPartDamageMultiplier) == 0x74);
	static_assert(offsetof(HitData, reflectedDamage) == 0x78);
	static_assert(offsetof(HitData, hitDataFlags) == 0x80);
	static_assert(offsetof(HitData, skill) == 0x88);
	static_assert(offsetof(HitData, targetBodyPartType) == 0x8C);
	static_assert(sizeof(HitData) == 0x90);
}
