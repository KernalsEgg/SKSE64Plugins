#include "PCH.h"

#include "Fixes/SpeedMultUpdates.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Skyrim/A/ActorValue.h"
#include "Shared/Utility/Convert.h"



namespace BugFixesSSE::Fixes
{
	void SpeedMultUpdates::Fix(bool& speedMultUpdates)
	{
		if (!Patterns::Fixes::SpeedMultUpdates::SpeedMultSink())
		{
			speedMultUpdates = false;

			return;
		}

		reinterpret_cast<std::uintptr_t*>(Addresses::Fixes::SpeedMultUpdates::ActorValueSinks)[Utility::ToUnderlying(Skyrim::ActorValue::kSpeedMult)] = Addresses::Fixes::SpeedMultUpdates::SpeedMultSink;
	}
}
