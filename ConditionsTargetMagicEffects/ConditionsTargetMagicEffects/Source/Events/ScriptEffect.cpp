#include "PrecompiledHeader.h"

#include "Events/ScriptEffect.h"

#include "Shared/Utility/Memory.h"



namespace ConditionsTargetMagicEffects::Events
{
	void ScriptEffect::Start(Skyrim::ScriptEffect* scriptEffect)
	{
		auto* function{ reinterpret_cast<decltype(ScriptEffect::Start)*>(
			Utility::Memory::ReadVirtualFunction(
				Skyrim::Addresses::ScriptEffect::VirtualFunctionTable(),
				0x20)) };

		function(scriptEffect);
	}
}
