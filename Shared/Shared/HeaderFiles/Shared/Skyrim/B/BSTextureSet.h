#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/N/NiObject.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class NiSourceTexture;

	class BSTextureSet :
		public NiObject // 0
	{
	public:
		enum class TextureMap : std::uint32_t
		{
			kDiffuse         = 0,
			kNormal          = 1,
			kGloss           = kNormal,
			kEnvironmentMask = 2,
			kGlow            = 3,
			kHeight          = 4,
			kEnvironment     = 5,
			kMultilayer      = 6,
			kBlacklightMask  = 7,
			kTotal           = 8
		};
		static_assert(sizeof(TextureMap) == 0x4);

		// Override
		virtual ~BSTextureSet() override; // 0

		// Override (NiObject)
		virtual const NiRTTI* GetRTTI() const override;      // 2
		virtual void          Unknown18(NiObject*) override; // 18
		virtual void          Unknown19(NiObject*) override; // 19
		virtual void          Unknown1A(NiObject*) override; // 1A
		virtual void          Unknown1B(NiObject*) override; // 1B
		virtual void          Unknown1C(NiObject*) override; // 1C

		// Add
		virtual const char* GetTextureFilename(Utility::Enumeration<TextureMap, std::uint32_t> textureMap)                              = 0; // 25
		virtual void        SetTexture(Utility::Enumeration<TextureMap, std::uint32_t> textureMap, NiSourceTexture* sourceTexture)      = 0; // 26
		virtual void        SetTextureFilename(Utility::Enumeration<TextureMap, std::uint32_t> textureMap, const char* textureFilename) = 0; // 27
	};
	static_assert(sizeof(BSTextureSet) == 0x10);
}
