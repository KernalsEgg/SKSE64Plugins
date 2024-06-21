#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/H/hkpCollidable.h"

#include "Shared/Skyrim/B/bhkCollisionObject.h"
#include "Shared/Skyrim/B/bhkWorldObject.h"
#include "Shared/Skyrim/H/hkpWorldObject.h"



namespace Skyrim
{
	NiAVObject* hkpCollidable::Get3D() const
	{
		auto* owner = this->GetOwner<hkpWorldObject>();

		if (!owner)
		{
			return nullptr;
		}

		auto* property = static_cast<bhkCollisionObject*>(owner->GetProperty(2).GetPointer());

		if (property)
		{
			return property->sceneObject;
		}

		auto* userData = reinterpret_cast<bhkWorldObject*>(owner->userData);

		if (userData)
		{
			return static_cast<NiAVObject*>(userData->GetProperty(1).GetPointer());
		}

		return nullptr;
	}

	void* hkpCollidable::GetOwner() const
	{
		return const_cast<char*>(reinterpret_cast<const char*>(this) + this->ownerOffset);
	}
}
