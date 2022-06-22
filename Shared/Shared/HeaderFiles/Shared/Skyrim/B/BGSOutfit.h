#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/T/TESForm.h"



namespace Skyrim
{
	class BGSOutfit :
		public TESForm // 0
	{
	public:
		// Override
		virtual ~BGSOutfit() override; // 0

		// Override (TESForm)
		virtual void ClearData() override;         // 5
		virtual void Unknown6(TESForm*) override;  // 6
		virtual void Unknown13(TESForm*) override; // 13

		// Member variables
		BSTArray<TESForm*> armor; // 20, TESObjectARMO and TESLevItem
	};
	static_assert(offsetof(BGSOutfit, armor) == 0x20);
	static_assert(sizeof(BGSOutfit) == 0x38);
}
