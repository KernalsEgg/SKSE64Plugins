#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BipedAnim.h"

#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/T/TESBoundObject.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	BipedObject* BipedAnim::GetShieldObject()
	{
		auto* actor = this->actorHandle.get().get();

		if (!actor)
		{
			return nullptr;
		}

		Utility::Enumeration<BipedObjectSlot, std::uint32_t> shieldObjectSlot = actor->GetShieldObject();

		if (shieldObjectSlot == BipedObjectSlot::kNone)
		{
			return nullptr;
		}

		auto* shieldObject = std::addressof(this->bipedObjects[shieldObjectSlot.underlying()]);
		auto* shield       = shieldObject->item;

		return shield && shield->formType == FormType::kArmor ? shieldObject : nullptr;
	}
}
