#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/T/TESContainer.h"



namespace Skyrim
{
	bool TESContainer::HasItem(TESBoundObject* item) const
	{
		for (auto* containerObject : *this)
		{
			if (containerObject->object == item)
			{
				return true;
			}
		}

		return false;
	}
}
