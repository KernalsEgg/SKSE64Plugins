#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSVolumetricLightingRenderData.h"
#include "Shared/Skyrim/T/TESForm.h"



namespace Skyrim
{
	class BGSVolumetricLighting :
		public TESForm,                       // 0
		public BSVolumetricLightingRenderData // 20
	{
	public:
		// Override
		virtual ~BGSVolumetricLighting() override; // 0

		// Override (TESForm)
		virtual void ClearData() override;         // 5
		virtual bool Load(TESFile* file) override; // 6
		virtual void Unknown13(TESForm*) override; // 13
	};
	static_assert(sizeof(BGSVolumetricLighting) == 0x50);
}
