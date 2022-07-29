#include "Shared/PCH.h"

#include "Shared/Skyrim/B/bhkWorldObject.h"

#include "Shared/Skyrim/H/hkReferencedObject.h"
#include "Shared/Skyrim/H/hkpWorldObject.h"



namespace Skyrim
{
	hkSimplePropertyValue bhkWorldObject::GetProperty(std::uint32_t key)
	{
		return static_cast<hkpWorldObject*>(this->referencedObject.get())->GetProperty(key);
	}

	bool bhkWorldObject::HasProperty(std::uint32_t key) const
	{
		return static_cast<hkpWorldObject*>(this->referencedObject.get())->HasProperty(key);
	}
}
