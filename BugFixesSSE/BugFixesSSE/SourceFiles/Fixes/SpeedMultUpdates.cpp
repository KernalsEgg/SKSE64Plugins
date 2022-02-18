#include "PCH.h"

#include "Fixes/SpeedMultUpdates.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Skyrim/A/ActorValue.h"
#include "Shared/Utility/Convert.h"



namespace BugFixesSSE::Fixes
{
	bool SpeedMultUpdates::Fix()
	{
		if (!Patterns::Fixes::SpeedMultUpdates::SpeedMultSink())
		{
			return false;
		}

		reinterpret_cast<std::uintptr_t*>(Addresses::Fixes::SpeedMultUpdates::ActorValueSinks)[Utility::ToUnderlying(Skyrim::ActorValue::kSpeedMult)] = Addresses::Fixes::SpeedMultUpdates::SpeedMultSink;

		return true;
	}
}
