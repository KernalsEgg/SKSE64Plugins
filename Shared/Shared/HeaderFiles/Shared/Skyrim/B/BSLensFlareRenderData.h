#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/N/NiPointer.h"



namespace Skyrim
{
	class BSLensFlareSpriteRenderData;

	class BSLensFlareRenderData
	{
	public:
		// Member variables
		float                                            fadeDistanceRadiusScale; // 0
		float                                            colorInfluence;          // 4
		BSTArray<NiPointer<BSLensFlareSpriteRenderData>> lensFlareSprites;        // 8
	};
	static_assert(offsetof(BSLensFlareRenderData, fadeDistanceRadiusScale) == 0x0);
	static_assert(offsetof(BSLensFlareRenderData, colorInfluence) == 0x4);
	static_assert(offsetof(BSLensFlareRenderData, lensFlareSprites) == 0x8);
	static_assert(sizeof(BSLensFlareRenderData) == 0x20);
}
