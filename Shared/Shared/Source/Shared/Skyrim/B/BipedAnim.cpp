#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BipedAnim.h"

#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/T/TESBoundObject.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	BipedObject* BipedAnim::GetShieldBipedObject()
	{
		auto actor = this->actorHandle.get();

		if (!actor)
		{
			return nullptr;
		}

		Utility::Enumeration<BipedObjectSlot, std::uint32_t> shieldBipedObjectSlot = actor->GetShieldBipedObjectSlot();

		if (shieldBipedObjectSlot == BipedObjectSlot::kNone)
		{
			return nullptr;
		}

		auto* shieldBipedObject = std::addressof(this->bipedObjects[shieldBipedObjectSlot.underlying()]);
		auto* shield            = shieldBipedObject->boundObject;

		return shield && shield->formType == FormType::kArmor ? shieldBipedObject : nullptr;
	}
}
