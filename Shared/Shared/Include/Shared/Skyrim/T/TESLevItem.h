#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/T/TESBoundObject.h"
#include "Shared/Skyrim/T/TESLeveledList.h"



namespace Skyrim
{
	class TESLevItem :
		public TESBoundObject, // 0
		public TESLeveledList  // 30
	{
	public:
		// Override
		virtual ~TESLevItem() override; // 0

		// Override (TESBoundObject)
		virtual bool Load(TESFile* file) override;                         // 6
		virtual void SaveGame(BGSSaveFormBuffer* saveFormBuffer) override; // E
		virtual void LoadGame(BGSLoadFormBuffer* loadFormBuffer) override; // F
		virtual void Revert(BGSLoadFormBuffer* loadFormBuffer) override;   // 12
		virtual void Unknown13(TESForm*) override;                         // 13

		// Override (TESLeveledList)
		virtual void Unknown6(TESLeveledList*) override; // 6
		virtual void Unknown7(TESLeveledList*) override; // 7
	};
	static_assert(sizeof(TESLevItem) == 0x58);
}
