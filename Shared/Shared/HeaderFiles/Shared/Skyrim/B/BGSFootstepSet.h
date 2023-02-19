#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Utility/Conversion.h"



namespace Skyrim
{
	class BGSFootstep;

	class BGSFootstepSet :
		public TESForm // 0
	{
	public:
		enum class MovementState
		{
			kWalking   = 0,
			kRunning   = 1,
			kSprinting = 2,
			kSneaking  = 3,
			kSwimming  = 4,
			kTotal     = 5
		};

		// Override
		virtual ~BGSFootstepSet() override; // 0

		// Override (TESForm)
		virtual void InitializeData() override;    // 4
		virtual bool Load(TESFile* file) override; // 6
		virtual void Unknown13(TESForm*) override; // 13

		// Member variables
		BSTArray<BGSFootstep*> footsteps[Utility::Conversion::ToUnderlying(MovementState::kTotal)]; // 20
	};
	static_assert(offsetof(BGSFootstepSet, footsteps) == 0x20);
	static_assert(sizeof(BGSFootstepSet) == 0x98);
}
