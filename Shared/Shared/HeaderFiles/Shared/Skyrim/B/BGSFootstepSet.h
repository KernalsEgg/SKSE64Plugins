#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Utility/Convert.h"



namespace Skyrim
{
	class BGSFootstep;

	class BGSFootstepSet :
		public TESForm
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
		virtual void Unknown6(TESForm*) override;  // 6
		virtual void Unknown13(TESForm*) override; // 13

		// Member variables
		BSTArray<BGSFootstep*> footsteps[Utility::ToUnderlying(MovementState::kTotal)]; // 20
	};
	static_assert(offsetof(BGSFootstepSet, footsteps) == 0x20);
	static_assert(sizeof(BGSFootstepSet) == 0x98);
}
