#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiPoint3.h"



namespace Skyrim
{
	float NiPoint3::Magnitude() const
	{
		return std::sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
	}

	void NiPoint3::Normalize()
	{
		auto magnitude = this->Magnitude();

		if (magnitude)
		{
			this->operator/=(magnitude);
		}
	}
}
