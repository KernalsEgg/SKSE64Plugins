#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/ActorValueInfo.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	ActorValueInfo* ActorValueInfo::GetSingleton(Utility::Enumeration<ActorValue, std::uint32_t> actorValue)
	{
		auto* function{ reinterpret_cast<decltype(ActorValueInfo::GetSingleton)*>(
			Addresses::ActorValueInfo::GetSingleton()) };

		return function(actorValue);
	}
}
