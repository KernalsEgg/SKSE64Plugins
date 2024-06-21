#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/S/Script.h"



namespace Skyrim
{
	void Script::ClearCachedValues()
	{
		auto* function{ reinterpret_cast<decltype(Script::ClearCachedValues)*>(
			Addresses::Script::ClearCachedValues()) };

		function();
	}

	void Script::CompileAndRun(ScriptCompiler* scriptCompiler, Utility::Enumeration<CompilerName, std::uint32_t> type, TESObjectREFR* target)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&Script::CompileAndRun)>::type>(
			Addresses::Script::CompileAndRun()) };

		function(this, scriptCompiler, type, target);
	}

	void Script::SetCommand(const char* command)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&Script::SetCommand)>::type>(
			Addresses::Script::SetCommand()) };

		function(this, command);
	}
}
