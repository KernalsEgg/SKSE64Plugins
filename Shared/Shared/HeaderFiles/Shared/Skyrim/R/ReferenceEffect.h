#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSPointerHandle.h"
#include "Shared/Skyrim/B/BSTempEffect.h"



namespace Skyrim
{
	class Actor;
	class ReferenceEffectController;

	class ReferenceEffect :
		public BSTempEffect // 0
	{
	public:
		// Override
		virtual ~ReferenceEffect() override; // 0

		// Override (BSTempEffect)
		virtual const NiRTTI* GetRTTI() const override;          // 2
		virtual void          Unknown27(BSTempEffect*) override; // 27
		virtual void          Unknown28(BSTempEffect*) override; // 28
		virtual void          Unknown2A(BSTempEffect*) override; // 2A
		virtual void          Unknown2B(BSTempEffect*) override; // 2B
		virtual void          Unknown2C(BSTempEffect*) override; // 2C
		virtual void          Unknown2D(BSTempEffect*) override; // 2D
		virtual void          Unknown2E(BSTempEffect*) override; // 2E
		virtual void          Unknown2F(BSTempEffect*) override; // 2F

		// Add
		virtual void Unknown36(ReferenceEffect*); // 36
		virtual void Unknown37(ReferenceEffect*); // 37
		virtual void Unknown38(ReferenceEffect*); // 38
		virtual void Unknown39(ReferenceEffect*); // 39
		virtual void Unknown3A(ReferenceEffect*); // 3A
		virtual void Unknown3B(ReferenceEffect*); // 3B
		virtual void Unknown3C(ReferenceEffect*); // 3C
		virtual void Unknown3D(ReferenceEffect*); // 3D
		virtual void Unknown3E(ReferenceEffect*); // 3E

		// Member functions
		Actor* GetTargetActor() const;

		// Member variables
		ReferenceEffectController* controller;    // 30
		ObjectReferenceHandle      target;        // 38
		ObjectReferenceHandle      facingTarget;  // 3C
		bool                       finished;      // 40
		bool                       ownController; // 41
		std::uint16_t              padding42;     // 42
		std::uint32_t              padding44;     // 44
	};
	static_assert(offsetof(ReferenceEffect, controller) == 0x30);
	static_assert(offsetof(ReferenceEffect, target) == 0x38);
	static_assert(offsetof(ReferenceEffect, facingTarget) == 0x3C);
	static_assert(offsetof(ReferenceEffect, finished) == 0x40);
	static_assert(offsetof(ReferenceEffect, ownController) == 0x41);
	static_assert(sizeof(ReferenceEffect) == 0x48);
}
