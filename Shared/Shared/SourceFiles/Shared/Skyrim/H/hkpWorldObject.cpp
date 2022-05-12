#include "Shared/PCH.h"

#include "Shared/Skyrim/H/hkpWorldObject.h"



namespace Skyrim
{
	hkSimplePropertyValue hkpWorldObject::GetProperty(std::uint32_t key)
	{
		for (std::int32_t index = 0; index < this->properties.size(); ++index)
		{
			if (this->properties[index].key == key)
			{
				return this->properties[index].value;
			}
		}

		hkSimplePropertyValue result;
		result.data = 0UL;

		return result;
	}

	bool hkpWorldObject::HasProperty(std::uint32_t key) const
	{
		for (std::int32_t index = 0; index < this->properties.size(); ++index)
		{
			if (this->properties[index].key == key)
			{
				return true;
			}
		}

		return false;
	}
}
