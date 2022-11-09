#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/S/Script.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	bool Script::ParseParameters(const ScriptParameter* scriptParameters, ScriptFunction::ScriptData* scriptData, std::uint32_t& opcodeOffset, TESObjectREFR* object, TESObjectREFR* containingObject, Script* script, ScriptLocals* scriptLocals, ...)
	{
		std::va_list arguments;
		auto*        function{ reinterpret_cast<decltype(&Script::ParseParameters)>(Addresses::Script::ParseParameters) };

		va_start(arguments, scriptLocals);
		auto result = function(scriptParameters, scriptData, opcodeOffset, object, containingObject, script, scriptLocals, arguments);
		va_end(arguments);

		return result;
	}

	void Script::CompileAndRun(ScriptCompiler* scriptCompiler, Utility::Enumeration<CompilerName, std::uint32_t> type, TESObjectREFR* target)
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Script::CompileAndRun)>::type>(Addresses::Script::CompileAndRun) };

		function(this, scriptCompiler, type, target);
	}

	void Script::SetCommand(const char* command)
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Script::SetCommand)>::type>(Addresses::Script::SetCommand) };

		function(this, command);
	}
}
