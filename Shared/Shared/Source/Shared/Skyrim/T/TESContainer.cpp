#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/T/TESContainer.h"



namespace Skyrim
{
	std::int32_t TESContainer::GetBoundObjectCount(TESBoundObject* boundObject) const
	{
		std::int32_t boundObjectCount{ 0 };

		for (auto* containerObject : *this)
		{
			if (containerObject->boundObject == boundObject)
			{
				boundObjectCount += containerObject->count;
			}
		}

		return boundObjectCount;
	}

	bool TESContainer::HasBoundObject(TESBoundObject* boundObject) const
	{
		for (auto* containerObject : *this)
		{
			if (containerObject->boundObject == boundObject)
			{
				return true;
			}
		}

		return false;
	}
}
