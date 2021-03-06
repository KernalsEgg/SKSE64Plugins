#include "Shared/PCH.h"

#include "Shared/Skyrim/M/MagicItem.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	float MagicItem::GetCost(Actor* caster) const
	{
		auto function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&MagicItem::GetCost)>::type>(Addresses::MagicItem::GetCost) };

		return function(this, caster);
	}

	ActorValue MagicItem::GetCostActorValue(bool rightHand) const
	{
		switch (this->GetSpellType())
		{
			case MagicSystem::SpellType::kSpell:
			case MagicSystem::SpellType::kLesserPower:
			case MagicSystem::SpellType::kPoison:
			{
				return ActorValue::kMagicka;
			}
			case MagicSystem::SpellType::kEnchantment:
			case MagicSystem::SpellType::kStaffEnchantment:
			{
				if (this->GetCastingType() == MagicSystem::CastingType::kConstantEffect)
				{
					return ActorValue::kNone;
				}

				return rightHand ? ActorValue::kRightItemCharge : ActorValue::kLeftItemCharge;
			}
			default:
			{
				return ActorValue::kNone;
			}
		}
	}

	bool MagicItem::ShouldAddSpell() const
	{
		switch (this->GetSpellType())
		{
			case MagicSystem::SpellType::kDisease:
			case MagicSystem::SpellType::kAbility:
			case MagicSystem::SpellType::kAddiction:
			{
				return true;
			}
			default:
			{
				return false;
			}
		}
	}

	bool MagicItem::ShouldSetEffectiveness() const
	{
		auto spellType = this->GetSpellType();

		switch (spellType)
		{
			case MagicSystem::SpellType::kDisease:
			case MagicSystem::SpellType::kAbility:
			case MagicSystem::SpellType::kIngredient:
			case MagicSystem::SpellType::kAddiction:
			{
				return false;
			}
			case MagicSystem::SpellType::kEnchantment:
			{
				return this->GetCastingType() != MagicSystem::CastingType::kConstantEffect;
			}
			default:
			{
				return true;
			}
		}
	}
}
