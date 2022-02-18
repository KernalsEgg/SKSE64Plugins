#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/T/TESBoundObject.h"
#include "Shared/Skyrim/T/TESLeveledList.h"



namespace Skyrim
{
	class TESLevSpell :
		public TESBoundObject, // 0
		public TESLeveledList  // 30
	{
	public:
		// Override
		virtual ~TESLevSpell() override; // 0

		// Override (TESBoundObject)
		virtual void Unknown6(TESForm*) override;  // 6
		virtual void UnknownE(TESForm*) override;  // E
		virtual void UnknownF(TESForm*) override;  // F
		virtual void Unknown12(TESForm*) override; // 12
		virtual void Unknown13(TESForm*) override; // 13

		// Override (TESLeveledList)
		virtual void Unknown7(TESLeveledList*) override; // 7
	};
	static_assert(sizeof(TESLevSpell) == 0x58);
}
