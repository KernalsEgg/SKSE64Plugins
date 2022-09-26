#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	class BGSArtObject;
	class NiAVObject;
	class TESEffectShader;
	class TESObjectREFR;

	class ReferenceEffectController
	{
	public:
		// Add
		virtual ~ReferenceEffectController();                              // 0
		virtual void             Unknown1(ReferenceEffectController*);     // 1
		virtual void             Unknown2(ReferenceEffectController*);     // 2
		virtual void             Unknown3(ReferenceEffectController*);     // 3
		virtual void             Unknown4(ReferenceEffectController*);     // 4
		virtual void             Unknown5(ReferenceEffectController*);     // 5
		virtual void             Unknown6(ReferenceEffectController*);     // 6
		virtual void             Unknown7(ReferenceEffectController*);     // 7
		virtual void             Unknown8(ReferenceEffectController*);     // 8
		virtual void             Unknown9(ReferenceEffectController*);     // 9
		virtual void             UnknownA(ReferenceEffectController*);     // A
		virtual TESObjectREFR*   GetTarget()                          = 0; // B
		virtual BGSArtObject*    GetHitEffectArt()                    = 0; // C
		virtual TESEffectShader* GetHitShader()                       = 0; // D
		virtual void             UnknownE(ReferenceEffectController*) = 0; // E
		virtual NiAVObject*      GetAttachRoot();                          // F
		virtual void             Unknown10(ReferenceEffectController*);    // 10
		virtual void             Unknown11(ReferenceEffectController*);    // 11
		virtual void             Unknown12(ReferenceEffectController*);    // 12
		virtual void             Unknown13(ReferenceEffectController*);    // 13
		virtual void             Unknown14(ReferenceEffectController*);    // 14
		virtual void             Unknown15(ReferenceEffectController*);    // 15
		virtual void             Unknown16(ReferenceEffectController*);    // 16
		virtual void             Unknown17(ReferenceEffectController*);    // 17
		virtual TESObjectREFR*   GetFacingTarget();                        // 18
		virtual void             Unknown18(ReferenceEffectController*);    // 18
		virtual void             Unknown19(ReferenceEffectController*);    // 19
		virtual void             Unknown1A(ReferenceEffectController*);    // 1A
		virtual void             Unknown1B(ReferenceEffectController*);    // 1B
		virtual void             Unknown1C(ReferenceEffectController*);    // 1C
		virtual void             Unknown1D(ReferenceEffectController*);    // 1D
		virtual void             Unknown1E(ReferenceEffectController*);    // 1E
		virtual void             Unknown1F(ReferenceEffectController*);    // 1F
		virtual void             Unknown20(ReferenceEffectController*);    // 20
		virtual void             Unknown21(ReferenceEffectController*);    // 21
		virtual void             Unknown22(ReferenceEffectController*);    // 22
	};
	static_assert(sizeof(ReferenceEffectController) == 0x8);
}
