#include "Shared/PCH.h"

#include "Shared/Skyrim/S/ScriptEventSourceHolder.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	ScriptEventSourceHolder* ScriptEventSourceHolder::GetSingleton()
	{
		auto* function{ reinterpret_cast<decltype(&ScriptEventSourceHolder::GetSingleton)>(Addresses::ScriptEventSourceHolder::GetSingleton) };

		return function();
	}
}
