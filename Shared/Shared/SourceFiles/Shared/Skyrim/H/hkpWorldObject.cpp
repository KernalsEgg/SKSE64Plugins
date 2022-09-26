#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/H/hkpWorldObject.h"



namespace Skyrim
{
	hkSimplePropertyValue hkpWorldObject::GetProperty(std::uint32_t key)
	{
		for (const auto& property : this->properties)
		{
			if (property.key == key)
			{
				return property.value;
			}
		}

		hkSimplePropertyValue result;
		result.data = 0;

		return result;
	}

	bool hkpWorldObject::HasProperty(std::uint32_t key) const
	{
		for (const auto& property : this->properties)
		{
			if (property.key == key)
			{
				return true;
			}
		}

		return false;
	}
}
