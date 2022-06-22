#include "Shared/PCH.h"

#include "Shared/Skyrim/S/Script.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/C/ConcreteFormFactory.h"
#include "Shared/Skyrim/C/Console.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	void Script::ExecuteCommand(std::string_view command)
	{
		Script::ExecuteCommand(command, Console::GetSelectedReference().get());
	}

	void Script::ExecuteCommand(std::string_view command, TESObjectREFR* target)
	{
		auto concreteFormFactory = ConcreteFormFactory<Script, FormType::kScript>::GetConcreteFormFactoryFromFormType();

		if (!concreteFormFactory)
		{
			return;
		}

		auto script = concreteFormFactory->Create();

		if (!script)
		{
			return;
		}

		script->SetCommand(command.data());

		ScriptCompiler scriptCompiler;
		script->CompileAndRun(std::addressof(scriptCompiler), CompilerName::kSystemWindowCompiler, target);

		delete script;
	}

	void Script::CompileAndRun(ScriptCompiler* scriptCompiler, Utility::Enumeration<CompilerName, std::uint32_t> type, TESObjectREFR* target)
	{
		auto function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Script::CompileAndRun)>::type>(Addresses::Script::CompileAndRun) };

		function(this, scriptCompiler, type, target);
	}

	void Script::SetCommand(const char* command)
	{
		auto function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Script::SetCommand)>::type>(Addresses::Script::SetCommand) };

		function(this, command);
	}
}
