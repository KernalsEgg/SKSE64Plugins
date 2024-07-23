#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/R/ReferenceEffect.h"

#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/T/TESObjectREFR.h"



namespace Skyrim
{
	Actor* ReferenceEffect::GetTargetActor() const
	{
		auto target = this->targetHandle.get();

		return target && target->formType == FormType::kActor ? static_cast<Actor*>(target.get()) : nullptr;
	}
}
