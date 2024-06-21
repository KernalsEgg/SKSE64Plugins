#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/T/TESContainer.h"



namespace Skyrim
{
	std::int32_t TESContainer::GetItemCount(TESBoundObject* item) const
	{
		std::int32_t itemCount{ 0 };

		for (auto* containerObject : *this)
		{
			if (containerObject->object == item)
			{
				itemCount += containerObject->count;
			}
		}

		return itemCount;
	}

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
