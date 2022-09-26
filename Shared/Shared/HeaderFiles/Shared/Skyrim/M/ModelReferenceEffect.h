#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSTEventSink.h"
#include "Shared/Skyrim/N/NiPointer.h"
#include "Shared/Skyrim/R/RefAttachTechniqueInput.h"
#include "Shared/Skyrim/R/ReferenceEffect.h"
#include "Shared/Skyrim/S/SimpleAnimationGraphManagerHolder.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	struct BSAnimationGraphEvent;

	class BGSArtObject;
	class NiAVObject;

	class ModelReferenceEffect :
		public ReferenceEffect,                    // 0
		public SimpleAnimationGraphManagerHolder,  // 48
		public BSTEventSink<BSAnimationGraphEvent> // 60
	{
	public:
		enum class Flags : std::uint32_t
		{
			kNone        = 0,
			kInitialized = 1U << 0,
			kThirdPerson = 1U << 1,
		};
		static_assert(sizeof(Flags) == 0x4);

		// Override
		virtual ~ModelReferenceEffect() override; // 0

		// Override (ReferenceEffect)
		virtual const NiRTTI* GetRTTI() const override;             // 2
		virtual void          Unknown28(BSTempEffect*) override;    // 28
		virtual void          Unknown29(BSTempEffect*) override;    // 29
		virtual void          Unknown2C(BSTempEffect*) override;    // 2C
		virtual void          Unknown2D(BSTempEffect*) override;    // 2D
		virtual void          Unknown2E(BSTempEffect*) override;    // 2E
		virtual void          Unknown36(ReferenceEffect*) override; // 36
		virtual void          Unknown3A(ReferenceEffect*) override; // 3A
		virtual void          Unknown3B(ReferenceEffect*) override; // 3B
		virtual void          Unknown3C(ReferenceEffect*) override; // 3C
		virtual void          Unknown3D(ReferenceEffect*) override; // 3D
		virtual void          Unknown3E(ReferenceEffect*) override; // 3E

		// Override (SimpleAnimationGraphManagerHolder)
		virtual void Unknown8(IAnimationGraphManagerHolder*) override; // 8
		virtual void UnknownA(IAnimationGraphManagerHolder*) override; // A
		virtual void UnknownD(IAnimationGraphManagerHolder*) override; // D

		// Override (BSTEventSink<BSAnimationGraphEvent>)
		virtual BSEventNotifyControl ProcessEvent(const BSAnimationGraphEvent* eventArguments, BSTEventSource<BSAnimationGraphEvent>* eventSource) override; // 1

		// Member variables
		RefAttachTechniqueInput                    attachTechniqueInput;      // 68
		std::uint64_t                              unknownB0;                 // B0
		BGSArtObject*                              artObject;                 // B8
		std::uint64_t                              unknownC0;                 // C0
		NiPointer<NiAVObject>                      artObject3D;               // C8
		Utility::Enumeration<Flags, std::uint32_t> modelReferenceEffectFlags; // D0
		std::uint32_t                              unknownD4;                 // D4
	};
	static_assert(offsetof(ModelReferenceEffect, attachTechniqueInput) == 0x68);
	static_assert(offsetof(ModelReferenceEffect, artObject) == 0xB8);
	static_assert(offsetof(ModelReferenceEffect, artObject3D) == 0xC8);
	static_assert(offsetof(ModelReferenceEffect, modelReferenceEffectFlags) == 0xD0);
	static_assert(sizeof(ModelReferenceEffect) == 0xD8);
}
