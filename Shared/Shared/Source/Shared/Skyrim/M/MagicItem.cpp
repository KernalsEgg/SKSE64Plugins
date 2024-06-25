#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/M/MagicItem.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/M/MagicItemTraversalFunctor.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	bool MagicItem::Adjustable() const
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

	float MagicItem::GetCost(Actor* caster) const
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&MagicItem::GetCost)>::type>(
			Addresses::MagicItem::GetCost()) };

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

	EffectItem* MagicItem::GetCostliestEffectItem(Utility::Enumeration<MagicSystem::Delivery, std::uint32_t> delivery, bool areaOfEffect) const
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&MagicItem::GetCostliestEffectItem)>::type>(
			Addresses::MagicItem::GetCostliestEffectItem()) };

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

	void MagicItem::Traverse(MagicItemTraversalFunctor& magicItemTraversalFunctor) const
	{
		for (auto* effectItem : this->effectItems)
		{
			if (magicItemTraversalFunctor(effectItem) != ForEachResult::kContinue)
			{
				break;
			}
		}
	}
}
