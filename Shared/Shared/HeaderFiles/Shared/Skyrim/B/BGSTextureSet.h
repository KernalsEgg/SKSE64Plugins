#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSTextureSet.h"
#include "Shared/Skyrim/I/ID.h"
#include "Shared/Skyrim/T/TESBoundObject.h"
#include "Shared/Skyrim/T/TESTexture.h"
#include "Shared/Utility/Convert.h"



namespace Skyrim
{
	struct DecalData;

	class BGSTextureSet :
		public TESBoundObject, // 0
		public BSTextureSet    // 30
	{
	public:
		enum class Flags : std::uint16_t
		{
			kNone                   = 0,
			kNoSpecularMap          = 1U << 0,
			kFacegenTextures        = 1U << 1,
			kHasModelSpaceNormalMap = 1U << 2
		};
		static_assert(sizeof(Flags) == 0x2);

		// Override
		virtual ~BGSTextureSet() override; // 0

		// Override (TESBoundObject)
		virtual void Unknown4(TESForm*) override;    // 4
		virtual void Unknown5(TESForm*) override;    // 5
		virtual void Unknown6(TESForm*) override;    // 6
		virtual void Unknown40(TESObject*) override; // 40
		virtual void Unknown41(TESObject*) override; // 41

		// Override (BSTextureSet)
		virtual const char* GetTextureFilename(Utility::Enumeration<TextureMap, std::uint32_t> textureMap) override;                              // 25
		virtual void        SetTexture(Utility::Enumeration<TextureMap, std::uint32_t> textureMap, NiSourceTexture* sourceTexture) override;      // 26
		virtual void        SetTextureFilename(Utility::Enumeration<TextureMap, std::uint32_t> textureMap, const char* textureFilename) override; // 27

		// Member variables
		TESTexture                                 textures[Utility::ToUnderlying(TextureMap::kTotal)];   // 40
		DecalData*                                 decalData;                                             // C0
		Utility::Enumeration<Flags, std::uint16_t> textureSetFlags;                                       // C8
		std::int16_t                               paddingCA;                                             // CA
		BSResource::ID                             textureIDs[Utility::ToUnderlying(TextureMap::kTotal)]; // CC
		std::int32_t                               padding12C;                                            // 12C
	};
	static_assert(offsetof(BGSTextureSet, textures) == 0x40);
	static_assert(offsetof(BGSTextureSet, decalData) == 0xC0);
	static_assert(offsetof(BGSTextureSet, textureSetFlags) == 0xC8);
	static_assert(offsetof(BGSTextureSet, textureIDs) == 0xCC);
	static_assert(sizeof(BGSTextureSet) == 0x130);
}
