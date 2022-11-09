#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	namespace MagicSystem
	{
		enum class CastingSource : std::uint32_t
		{
			kLeftHand  = 0,
			kRightHand = 1,
			kOther     = 2,
			kInstant   = 3
		};
		static_assert(sizeof(CastingSource) == 0x4);

		enum class CastingType : std::uint32_t
		{
			kConstantEffect = 0,
			kFireAndForget  = 1,
			kConcentration  = 2,
			kScroll         = 3
		};
		static_assert(sizeof(CastingType) == 0x4);

		enum class Delivery : std::uint32_t
		{
			kSelf           = 0,
			kTouch          = 1,
			kAimed          = 2,
			kTargetActor    = 3,
			kTargetLocation = 4
		};
		static_assert(sizeof(Delivery) == 0x4);

		enum class SpellType : std::uint32_t
		{
			kSpell            = 0,
			kDisease          = 1,
			kPower            = 2,
			kLesserPower      = 3,
			kAbility          = 4,
			kPoison           = 5,
			kEnchantment      = 6,
			kPotion           = 7,
			kIngredient       = 8,
			kLeveledSpell     = 9,
			kAddiction        = 10,
			kVoicePower       = 11,
			kStaffEnchantment = 12,
			kScroll           = 13,
		};
		static_assert(sizeof(SpellType) == 0x4);

		enum class WardState : std::uint32_t
		{
			kNone   = 0,
			kAbsorb = 1,
			kBreak  = 2
		};
		static_assert(sizeof(WardState) == 0x4);
	}
}
