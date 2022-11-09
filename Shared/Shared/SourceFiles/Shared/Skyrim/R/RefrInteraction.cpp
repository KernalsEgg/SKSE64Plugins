#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/R/RefrInteraction.h"

#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/T/TESObjectREFR.h"



namespace Skyrim
{
	bool RefrInteraction::GetActor(NiPointer<Actor>& actor) const
	{
		actor = this->actorHandle.get();

		return static_cast<bool>(actor);
	}

	bool RefrInteraction::GetTargetActor(NiPointer<Actor>& targetActor) const
	{
		auto target = this->targetHandle.get();

		if (target && target->formType == Skyrim::FormType::kActor)
		{
			targetActor.reset(static_cast<Actor*>(target.get()));
		}
		else
		{
			targetActor.reset();
		}

		return static_cast<bool>(targetActor);
	}
}
