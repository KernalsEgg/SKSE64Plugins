#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/T/TESForm.h"



namespace Skyrim
{
	class BGSKeyword :
		public TESForm // 0
	{
	public:
		// Override
		virtual ~BGSKeyword() override; // 0

		// Override (TESForm)
		virtual bool        Load(TESFile* file) override;               // 6
		virtual const char* GetEditorID() const override;               // 32
		virtual bool        SetEditorID(const char* editorID) override; // 33

		// Member variables
		BSFixedString editorID; // 20
	};
	static_assert(offsetof(BGSKeyword, editorID) == 0x20);
	static_assert(sizeof(BGSKeyword) == 0x28);
}
