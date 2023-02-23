#include "PrecompiledHeader.h"

#include "Events.h"

#include "Addresses.h"
#include "Shared/Utility/Conversion.h"



namespace ScriptEffectArchetypeCrashFix
{
	void Events::Register()
	{
		reinterpret_cast<Events::CheckTargetFunction**>(Addresses::ActiveEffect::CheckTargetFunctions)[Utility::Conversion::ToUnderlying(Skyrim::EffectArchetypes::ArchetypeID::kScript)] =
			reinterpret_cast<Events::CheckTargetFunction*>(Addresses::ActiveEffect::CheckTargetActorsOnly);
	}
}
