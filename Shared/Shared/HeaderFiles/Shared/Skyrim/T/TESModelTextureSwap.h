#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/T/TESModel.h"



namespace Skyrim
{
	class BGSTextureSet;

	class TESModelTextureSwap :
		public TESModel // 0
	{
	public:
		struct AlternateTexture
		{
		public:
			// Member variables
			BGSTextureSet* newTexture; // 0
			std::uint32_t  index3D;    // 8
			std::uint32_t  paddingC;   // C
			BSFixedString  name3D;     // 10
		};
		static_assert(offsetof(AlternateTexture, newTexture) == 0x0);
		static_assert(offsetof(AlternateTexture, index3D) == 0x8);
		static_assert(offsetof(AlternateTexture, name3D) == 0x10);
		static_assert(sizeof(AlternateTexture) == 0x18);

		// Override
		virtual ~TESModelTextureSwap() override; // 0

		// Override (TESModel)
		virtual void                 Unknown1(BaseFormComponent*) override; // 1
		virtual void                 Unknown2(BaseFormComponent*) override; // 2
		virtual void                 Unknown3(BaseFormComponent*) override; // 3
		virtual TESModelTextureSwap* AsModelTextureSwap() override;         // 6

		// Member variables
		AlternateTexture* alternateTextures;     // 28
		std::uint32_t     alternateTextureCount; // 30
		std::uint32_t     padding34;             // 34
	};
	static_assert(offsetof(TESModelTextureSwap, alternateTextures) == 0x28);
	static_assert(offsetof(TESModelTextureSwap, alternateTextureCount) == 0x30);
	static_assert(sizeof(TESModelTextureSwap) == 0x38);
}
