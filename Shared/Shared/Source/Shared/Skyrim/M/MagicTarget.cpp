#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/M/MagicTarget.h"

#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/T/TESObjectREFR.h"



namespace Skyrim
{
	Actor* MagicTarget::GetMagicTargetAsActor()
	{
		return this->MagicTargetIsActor() ? static_cast<Actor*>(this->GetMagicTargetAsReference()) : nullptr;
	}

	void MagicTarget::ForEachActiveEffect(ForEachActiveEffectVisitor& forEachActiveEffectVisitor)
	{
		auto* activeEffects = this->GetActiveEffects();

		if (activeEffects)
		{
			for (auto* activeEffect : *activeEffects)
			{
				if (!activeEffect)
				{
					break;
				}

				if (forEachActiveEffectVisitor(activeEffect) != ForEachResult::kContinue)
				{
					break;
				}
			}
		}
	}
}
