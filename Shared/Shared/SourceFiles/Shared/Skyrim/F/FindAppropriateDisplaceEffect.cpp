#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/F/FindAppropriateDisplaceEffect.h"

#include "Shared/Skyrim/A/ActiveEffect.h"
#include "Shared/Skyrim/A/AlchemyItem.h"
#include "Shared/Skyrim/M/MagicItem.h"



namespace Skyrim
{
	ForEachResult FindAppropriateDisplaceEffect::operator()(ActiveEffect* activeEffect)
	{
		if (activeEffect && activeEffect->activeEffectFlags.none(ActiveEffect::Flags::kInactive))
		{
			auto* magicItem = activeEffect->magicItem;

			if (magicItem == this->displacementSpell || (magicItem->GetSpellType() == MagicSystem::SpellType::kPotion && static_cast<AlchemyItem*>(magicItem)->alchemyItemData.addiction == this->addiction))
			{
				this->displace = true;

				return ForEachResult::kStop;
			}
		}

		this->displace = false;

		return ForEachResult::kContinue;
	}
}
