#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/S/Sky.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	Sky* Sky::GetSingleton()
	{
		auto* function{ reinterpret_cast<decltype(&Sky::GetSingleton)>(Addresses::Sky::GetSingleton) };

		return function();
	}
}
