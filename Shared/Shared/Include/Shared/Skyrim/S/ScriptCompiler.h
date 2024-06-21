#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/S/ScriptOutput.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	struct ScriptFunction;

	class ScriptCompiler
	{
	public:
		ScriptCompiler()                      = default;
		ScriptCompiler(const ScriptCompiler&) = default;
		ScriptCompiler(ScriptCompiler&&)      = default;

		~ScriptCompiler() = default;

		ScriptCompiler& operator=(const ScriptCompiler&) = default;
		ScriptCompiler& operator=(ScriptCompiler&&)      = default;

		// Non-member functions
		static ScriptFunction* GetFunctionDefinition(Utility::Enumeration<ScriptOutput, std::uint32_t> scriptOutput);
	};
	static_assert(std::is_empty_v<ScriptCompiler>);
}
