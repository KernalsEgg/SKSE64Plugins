#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/T/TESForm.h"



namespace Skyrim
{
	class BGSImpactDataSet;

	class BGSFootstep :
		public TESForm // 0
	{
	public:
		// Override
		virtual ~BGSFootstep() override; // 0

		// Override (TESForm)
		virtual void Unknown4(TESForm*) override;  // 4
		virtual void Unknown6(TESForm*) override;  // 6
		virtual void Unknown13(TESForm*) override; // 13

		// Member variables
		BSFixedString     tag;       // 20
		BGSImpactDataSet* impactSet; // 28
	};
	static_assert(offsetof(BGSFootstep, tag) == 0x20);
	static_assert(offsetof(BGSFootstep, impactSet) == 0x28);
	static_assert(sizeof(BGSFootstep) == 0x30);
}
