#include "Shared/PCH.h"

#include "Shared/Skyrim/F/FindAppropriateDisplaceEffect.h"

#include "Shared/Skyrim/A/ActiveEffect.h"
#include "Shared/Skyrim/A/AlchemyItem.h"
#include "Shared/Skyrim/M/MagicItem.h"
#include "Shared/Skyrim/M/MagicSystem.h"



namespace Skyrim
{
	MagicTarget::ForEachActiveEffectVisitor::ReturnType FindAppropriateDisplaceEffect::Visit(ActiveEffect* activeEffect)
	{
		if (activeEffect && activeEffect->activeEffectFlags.none(ActiveEffect::Flags::kInactive))
		{
			auto spell = activeEffect->spell;

			if (spell == this->displacementSpell || (spell->GetSpellType() == MagicSystem::SpellType::kPotion && static_cast<AlchemyItem*>(spell)->alchemyItemData.addiction == this->addiction))
			{
				this->displace = true;

				return MagicTarget::ForEachActiveEffectVisitor::ReturnType::kStop;
			}
		}

		this->displace = false;

		return MagicTarget::ForEachActiveEffectVisitor::ReturnType::kContinue;
	}
}
