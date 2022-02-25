#include "Shared/PCH.h"

#include "Shared/Skyrim/R/ReferenceEffect.h"

#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/F/FormType.h"
#include "Shared/Skyrim/T/TESObjectREFR.h"



namespace Skyrim
{
	Actor* ReferenceEffect::GetTargetActor() const
	{
		auto target = this->target.get().get();

		return target && target->formType == FormType::kActor ? static_cast<Actor*>(target) : nullptr;
	}
}
