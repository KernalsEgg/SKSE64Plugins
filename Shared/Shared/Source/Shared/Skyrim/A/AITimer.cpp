#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/AITimer.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	float AITimer::GetTimer()
	{
		auto* singleton{ reinterpret_cast<float*>(Addresses::AITimer::Timer()) };

		return *singleton;
	}
}
