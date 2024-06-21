#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/F/FixedStrings.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	FixedStrings* FixedStrings::GetSingleton()
	{
		auto* function{ reinterpret_cast<decltype(FixedStrings::GetSingleton)*>(
			Addresses::FixedStrings::GetSingleton()) };

		return function();
	}
}
