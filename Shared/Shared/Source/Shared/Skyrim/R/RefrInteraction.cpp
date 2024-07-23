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
		auto temporary = this->targetHandle.get();

		if (temporary && temporary->formType == FormType::kActor)
		{
			targetActor.reset(static_cast<Actor*>(temporary.get()));
		}
		else
		{
			targetActor.reset();
		}

		return static_cast<bool>(targetActor);
	}
}
