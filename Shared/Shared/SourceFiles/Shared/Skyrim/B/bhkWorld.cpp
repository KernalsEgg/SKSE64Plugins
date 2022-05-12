#include "Shared/PCH.h"

#include "Shared/Skyrim/B/bhkWorld.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	float bhkWorld::GetScale()
	{
		auto singleton{ reinterpret_cast<float*>(Addresses::bhkWorld::Scale) };

		return *singleton;
	}

	float bhkWorld::GetScaleInverse()
	{
		auto singleton{ reinterpret_cast<float*>(Addresses::bhkWorld::ScaleInverse) };

		return *singleton;
	}
}
