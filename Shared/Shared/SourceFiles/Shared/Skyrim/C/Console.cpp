#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/C/Console.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/C/ConcreteFormFactory.h"
#include "Shared/Skyrim/S/Script.h"
#include "Shared/Skyrim/T/TESObjectREFR.h"



namespace Skyrim
{
	void Console::ExecuteCommand(std::string_view command)
	{
		Console::ExecuteCommand(command, Console::GetSelectedReference().get());
	}

	void Console::ExecuteCommand(std::string_view command, TESObjectREFR* target)
	{
		auto* concreteFormFactory = ConcreteFormFactory<Script, FormType::kScript>::GetFormFactory();

		if (!concreteFormFactory)
		{
			return;
		}

		auto* script = concreteFormFactory->Create();

		if (!script)
		{
			return;
		}

		script->SetCommand(command.data());

		ScriptCompiler scriptCompiler;
		script->CompileAndRun(std::addressof(scriptCompiler), CompilerName::kSystemWindowCompiler, target);

		delete script;
	}

	NiPointer<TESObjectREFR> Console::GetSelectedReference()
	{
		return Console::GetSelectedReferenceHandle().get();
	}

	ObjectReferenceHandle Console::GetSelectedReferenceHandle()
	{
		auto* singleton{ reinterpret_cast<ObjectReferenceHandle*>(Addresses::Console::SelectedReferenceHandle) };

		return *singleton;
	}
}
