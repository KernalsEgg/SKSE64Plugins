#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/S/ScriptCompiler.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	ScriptFunction* ScriptCompiler::GetFunctionDefinition(Utility::Enumeration<ScriptOutput, std::uint32_t> scriptOutput)
	{
		auto* function{ reinterpret_cast<decltype(ScriptCompiler::GetFunctionDefinition)*>(
			Addresses::ScriptCompiler::GetFunctionDefinition()) };

		return function(scriptOutput);
	}
}
