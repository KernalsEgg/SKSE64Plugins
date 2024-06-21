#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/B/BSSimpleList.h"
#include "Shared/Skyrim/C/CommandTable.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Utility/Enumeration.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	class ScriptCompiler;
	class TESObjectREFR;
	class TESQuest;

	enum class CompilerName : std::uint32_t
	{
		kDefaultCompiler      = 0,
		kSystemWindowCompiler = 1,
		kDialogueCompiler     = 2
	};
	static_assert(sizeof(CompilerName) == 0x4);

	class Script :
		public TESForm // 0
	{
	public:
		// Override
		virtual ~Script() override; // 0

		// Override (TESForm)
		virtual void InitializeData() override;    // 4
		virtual void ClearData() override;         // 5
		virtual bool Load(TESFile* file) override; // 6
		virtual void Unknown13(TESForm*) override; // 13

		// Non-member functions
		static void ClearCachedValues();

		template <class... Arguments>
		static bool ParseParameters(const ScriptParameter* scriptParameters, ScriptFunction::ScriptData* scriptData, std::uint32_t& opcodeOffset, TESObjectREFR* object, TESObjectREFR* containingObject, Script* script, ScriptLocals* scriptLocals, Arguments... arguments)
		{
			auto* function{ reinterpret_cast<
				Utility::TypeTraits::AddVariadicArguments<decltype(Script::ParseParameters<>)*>::type>(
				Addresses::Script::ParseParameters()) };

			return function(scriptParameters, scriptData, opcodeOffset, object, containingObject, script, scriptLocals, arguments...);
		}

		// Member functions
		void CompileAndRun(ScriptCompiler* scriptCompiler, Utility::Enumeration<CompilerName, std::uint32_t> type, TESObjectREFR* target);
		void SetCommand(const char* command);

		// Member variables
		ScriptHeader                          scriptHeader;            // 20
		std::uint32_t                         padding34;               // 34
		char*                                 command;                 // 38
		ScriptFunction::ScriptData*           scriptData;              // 40
		float                                 profilerTimer;           // 48
		float                                 questScriptDelayTime;    // 4C
		float                                 questScriptElapsedTime;  // 50
		std::uint32_t                         padding54;               // 54
		TESQuest*                             scopeQuest;              // 58
		BSSimpleList<ScriptReferencedObject*> scriptReferencedObjects; // 60
		BSSimpleList<ScriptVariable*>         scriptVariables;         // 70
	};
	static_assert(offsetof(Script, scriptHeader) == 0x20);
	static_assert(offsetof(Script, command) == 0x38);
	static_assert(offsetof(Script, scriptData) == 0x40);
	static_assert(offsetof(Script, profilerTimer) == 0x48);
	static_assert(offsetof(Script, questScriptDelayTime) == 0x4C);
	static_assert(offsetof(Script, questScriptElapsedTime) == 0x50);
	static_assert(offsetof(Script, scopeQuest) == 0x58);
	static_assert(offsetof(Script, scriptReferencedObjects) == 0x60);
	static_assert(offsetof(Script, scriptVariables) == 0x70);
	static_assert(sizeof(Script) == 0x80);
}
