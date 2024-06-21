#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSString.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSVoiceType :
		public TESForm // 0
	{
	public:
		enum class Flags : std::uint8_t
		{
			kNone                 = 0,
			kAllowDefaultDialogue = 1U << 0,
			kFemale               = 1U << 1
		};
		static_assert(sizeof(Flags) == 0x1);

		// Override
		virtual ~BGSVoiceType() override; // 0

		// Override (TESForm)
		virtual bool        Load(TESFile* file) override;               // 6
		virtual const char* GetEditorID() const override;               // 32
		virtual bool        SetEditorID(const char* editorID) override; // 33

		// Member variables
		Utility::Enumeration<Flags, std::uint8_t> voiceTypeFlags; // 20
		std::uint8_t                              padding21;      // 21
		std::uint16_t                             padding22;      // 22
		std::uint32_t                             padding24;      // 24
		BSString                                  editorID;       // 28
	};
	static_assert(offsetof(BGSVoiceType, voiceTypeFlags) == 0x20);
	static_assert(offsetof(BGSVoiceType, editorID) == 0x28);
	static_assert(sizeof(BGSVoiceType) == 0x38);
}
