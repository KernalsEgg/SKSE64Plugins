#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/M/MagicItem.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	float MagicItem::GetCost(Actor* caster) const
	{
		auto* function{ reinterpret_cast<Utility::TypeTraits::MakeFunctionPointer<decltype(&MagicItem::GetCost)>::type>(Addresses::MagicItem::GetCost) };

		return function(this, caster);
	}

	ActorValue MagicItem::GetCostActorValue(Utility::Enumeration<MagicSystem::CastingSource, std::uint32_t> castingSource) const
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

				return castingSource == MagicSystem::CastingSource::kLeftHand ? ActorValue::kLeftItemCharge : ActorValue::kRightItemCharge;
			}
			default:
			{
				return ActorValue::kNone;
			}
		}
	}

	EffectItem* MagicItem::GetCostliestEffect(Utility::Enumeration<MagicSystem::Delivery, std::uint32_t> delivery, bool areaOfEffect) const
	{
		auto* function{ reinterpret_cast<Utility::TypeTraits::MakeFunctionPointer<decltype(&MagicItem::GetCostliestEffect)>::type>(Addresses::MagicItem::GetCostliestEffect) };

		return function(this, delivery, areaOfEffect);
	}

	bool MagicItem::IsPermanent() const
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

	bool MagicItem::ShouldAdjustEffects() const
	{
		switch (this->GetSpellType())
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
