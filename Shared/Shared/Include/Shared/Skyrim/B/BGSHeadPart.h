#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Skyrim/T/TESFullName.h"
#include "Shared/Skyrim/T/TESModelTextureSwap.h"
#include "Shared/Skyrim/T/TESModelTri.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSColorForm;
	class BGSListForm;
	class BGSTextureSet;

	class BGSHeadPart :
		public TESForm,            // 0
		public TESFullName,        // 20
		public TESModelTextureSwap // 30
	{
	public:
		enum class Flags : std::uint8_t
		{
			kNone         = 0,
			kPlayable     = 1U << 0,
			kMale         = 1U << 1,
			kFemale       = 1U << 2,
			kIsExtraPart  = 1U << 3,
			kUseSolidTint = 1U << 4
		};
		static_assert(sizeof(Flags) == 0x1);

		enum class HeadPartType : std::uint32_t
		{
			kMisc       = 0,
			kFace       = 1,
			kEyes       = 2,
			kHair       = 3,
			kFacialHair = 4,
			kScar       = 5,
			kEyebrows   = 6
		};
		static_assert(sizeof(HeadPartType) == 0x4);

		// Override
		virtual ~BGSHeadPart() override; // 0

		// Override (TESForm)
		virtual void        InitializeData() override;                  // 4
		virtual void        ClearData() override;                       // 5
		virtual bool        Load(TESFile* file) override;               // 6
		virtual void        Unknown13(TESForm*) override;               // 13
		virtual const char* GetEditorID() const override;               // 32
		virtual bool        SetEditorID(const char* editorID) override; // 33

		// Member variables
		Utility::Enumeration<Flags, std::uint8_t>         headPartFlags;            // 68
		std::uint8_t                                      padding69;                // 69
		std::uint16_t                                     padding6A;                // 6A
		Utility::Enumeration<HeadPartType, std::uint32_t> headPartType;             // 6C
		BSTArray<BGSHeadPart*>                            extraParts;               // 70
		BGSTextureSet*                                    textureSet;               // 88
		TESModelTri                                       raceMorph;                // 90
		TESModelTri                                       morph;                    // B8
		TESModelTri                                       characterGenerationMorph; // E0
		BGSColorForm*                                     color;                    // 108
		BGSListForm*                                      validRaces;               // 110
		BSFixedString                                     editorID;                 // 118
	};
	static_assert(offsetof(BGSHeadPart, headPartFlags) == 0x68);
	static_assert(offsetof(BGSHeadPart, headPartType) == 0x6C);
	static_assert(offsetof(BGSHeadPart, extraParts) == 0x70);
	static_assert(offsetof(BGSHeadPart, textureSet) == 0x88);
	static_assert(offsetof(BGSHeadPart, raceMorph) == 0x90);
	static_assert(offsetof(BGSHeadPart, morph) == 0xB8);
	static_assert(offsetof(BGSHeadPart, characterGenerationMorph) == 0xE0);
	static_assert(offsetof(BGSHeadPart, color) == 0x108);
	static_assert(offsetof(BGSHeadPart, validRaces) == 0x110);
	static_assert(offsetof(BGSHeadPart, editorID) == 0x118);
	static_assert(sizeof(BGSHeadPart) == 0x120);
}
