#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	enum class ActorValue : std::uint32_t
	{
		kNone            = static_cast<std::underlying_type_t<ActorValue>>(-1),
		kOneHanded       = 6,
		kEnchanting      = 23,
		kHealth          = 24,
		kMagicka         = 25,
		kStamina         = 26,
		kSpeedMultiplier = 30,
		kInventoryWeight = 31,
		kCarryWeight     = 32,
		kPoisonResist    = 40,
		kMagicResist     = 44,
		kWardPower       = 63,
		kRightItemCharge = 64,
		kLeftItemCharge  = 82,

		kSkills     = kOneHanded,
		kSkillCount = kEnchanting - kOneHanded
	};
	static_assert(sizeof(ActorValue) == 0x4);

	enum class ActorValueModifier
	{
		kPermanent = 0,
		kTemporary = 1,
		kDamage    = 2,
		kTotal     = 3
	};

	enum class ActorValueType
	{
		kDerivedAttribute = 0,
		kSkill            = 1
	};
}
