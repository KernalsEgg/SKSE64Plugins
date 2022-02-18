#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/R/ReferenceEffectController.h"



namespace Skyrim
{
	class SkyEffectController :
		public ReferenceEffectController // 0
	{
	public:
		// Override
		virtual ~SkyEffectController() override; // 0

		// Override (ReferenceEffectController)
		virtual void             UnknownA(ReferenceEffectController*) override;  // A
		virtual TESObjectREFR*   GetTarget() override;                           // B
		virtual BGSArtObject*    GetHitEffectArt() override;                     // C
		virtual TESEffectShader* GetHitShader() override;                        // D
		virtual void             UnknownE(ReferenceEffectController*) override;  // E
		virtual NiAVObject*      GetAttachRoot() override;                       // F
		virtual void             Unknown1A(ReferenceEffectController*) override; // 1A
		virtual void             Unknown1B(ReferenceEffectController*) override; // 1B
	};
	static_assert(sizeof(SkyEffectController) == 0x8);
}
