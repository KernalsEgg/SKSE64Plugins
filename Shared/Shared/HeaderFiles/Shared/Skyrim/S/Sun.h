#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/N/NiPointer.h"
#include "Shared/Skyrim/S/SkyObject.h"



namespace Skyrim
{
	class BSShaderAccumulator;
	class BSTriShape;
	class NiBillboardNode;
	class NiDirectionalLight;

	class Sun :
		public SkyObject // 0
	{
	public:
		// Override
		virtual ~Sun() override; // 0

		// Override (SkyObject)
		virtual void Unknown2(SkyObject*) override; // 2
		virtual void Unknown3(SkyObject*) override; // 3

		// Member variables
		NiPointer<NiBillboardNode>     sunNode;           // 10
		NiPointer<NiBillboardNode>     sunGlareNode;      // 18
		NiPointer<BSTriShape>          sun;               // 20
		NiPointer<BSTriShape>          sunOcclusionQuery; // 28
		NiPointer<BSTriShape>          sunGlare;          // 30
		NiPointer<NiDirectionalLight>  sunLight;          // 38
		NiPointer<NiDirectionalLight>  cloudLight;        // 40
		float                          sunGlareScale;     // 48
		bool                           occlusionTest;     // 4C
		std::uint8_t                   padding4D;         // 4D
		std::uint16_t                  padding4E;         // 4E
		NiPointer<BSShaderAccumulator> sunAccumulator;    // 50
	};
	static_assert(offsetof(Sun, sunNode) == 0x10);
	static_assert(offsetof(Sun, sunGlareNode) == 0x18);
	static_assert(offsetof(Sun, sun) == 0x20);
	static_assert(offsetof(Sun, sunOcclusionQuery) == 0x28);
	static_assert(offsetof(Sun, sunGlare) == 0x30);
	static_assert(offsetof(Sun, sunLight) == 0x38);
	static_assert(offsetof(Sun, cloudLight) == 0x40);
	static_assert(offsetof(Sun, sunGlareScale) == 0x48);
	static_assert(offsetof(Sun, occlusionTest) == 0x4C);
	static_assert(offsetof(Sun, sunAccumulator) == 0x50);
	static_assert(sizeof(Sun) == 0x58);
}
