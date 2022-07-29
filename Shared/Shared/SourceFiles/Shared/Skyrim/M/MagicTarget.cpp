#include "Shared/PCH.h"

#include "Shared/Skyrim/M/MagicTarget.h"

#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/B/BSSimpleList.h"
#include "Shared/Skyrim/T/TESObjectREFR.h"



namespace Skyrim
{
	Actor* MagicTarget::GetMagicTargetOwnerActor()
	{
		return this->IsMagicTargetOwnerActor() ? static_cast<Actor*>(this->GetMagicTargetOwner()) : nullptr;
	}

	void MagicTarget::VisitActiveEffects(ForEachActiveEffectVisitor* visitor)
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

				if (visitor->Visit(activeEffect) != ForEachActiveEffectVisitor::ReturnType::kContinue)
				{
					break;
				}
			}
		}
	}
}
