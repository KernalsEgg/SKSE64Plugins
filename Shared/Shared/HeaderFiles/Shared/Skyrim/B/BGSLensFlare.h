#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSLensFlareRenderData.h"
#include "Shared/Skyrim/T/TESForm.h"



namespace Skyrim
{
	class BGSLensFlare :
		public TESForm,              // 0
		public BSLensFlareRenderData // 20
	{
	public:
		// Override
		virtual ~BGSLensFlare() override; // 0

		// Override (TESForm)
		virtual void ClearData() override;         // 5
		virtual void Unknown6(TESForm*) override;  // 6
		virtual void Unknown13(TESForm*) override; // 13
	};
	static_assert(sizeof(BGSLensFlare) == 0x40);
}
