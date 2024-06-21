#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSString.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class TESGlobal :
		public TESForm // 0
	{
	public:
		enum class RecordFlags : std::uint32_t
		{
			kConstant = 1U << 6
		};

		enum class VariableType : std::uint8_t
		{
			kFloat = 'f',
			kLong  = 'l',
			kShort = 's'
		};
		static_assert(sizeof(VariableType) == 0x1);

		// Override
		virtual ~TESGlobal() override; // 0

		// Override (TESForm)
		virtual bool        Load(TESFile* file) override;               // 6
		virtual const char* GetEditorID() const override;               // 32
		virtual bool        SetEditorID(const char* editorID) override; // 33

		// Member variables
		BSString                                         editorID;     // 20
		Utility::Enumeration<VariableType, std::uint8_t> variableType; // 30
		std::uint8_t                                     padding31;    // 31
		std::uint16_t                                    padding32;    // 32
		float                                            value;        // 34
	};
	static_assert(offsetof(TESGlobal, editorID) == 0x20);
	static_assert(offsetof(TESGlobal, variableType) == 0x30);
	static_assert(offsetof(TESGlobal, value) == 0x34);
	static_assert(sizeof(TESGlobal) == 0x38);
}
