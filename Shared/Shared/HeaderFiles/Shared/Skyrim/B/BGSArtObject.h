#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/T/TESBoundObject.h"
#include "Shared/Skyrim/T/TESModelTextureSwap.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSArtObject :
		public TESBoundObject,     // 0
		public TESModelTextureSwap // 30
	{
	public:
		enum class ArtType : std::uint32_t
		{
			kMagicCasting      = 0,
			kMagicHitEffect    = 1,
			kEnchantmentEffect = 2
		};
		static_assert(sizeof(ArtType) == 0x4);

		// Override
		virtual ~BGSArtObject() override; // 0

		// Override (TESBoundObject)
		virtual void Unknown6(TESForm*) override;  // 6
		virtual void Unknown13(TESForm*) override; // 13

		// Member variables
		Utility::Enumeration<ArtType, std::uint32_t> artType;   // 68
		std::int32_t                                 padding6C; // 6C
	};
	static_assert(offsetof(BGSArtObject, artType) == 0x68);
	static_assert(sizeof(BGSArtObject) == 0x70);
}
