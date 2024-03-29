#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiPointer.h"



namespace Skyrim
{
	class BSCullingProcess;
	class BSGeometry;
	class BSShaderAccumulator;
	class NiCamera;
	class NiPoint3;

	class Precipitation
	{
	public:
		class OcclusionMapData
		{
		public:
			// Member variables
			alignas(0x10) DirectX::XMFLOAT4X4 projection;  // 0
			NiPointer<NiCamera>            camera;         // 40
			NiPointer<BSShaderAccumulator> accumulator;    // 48
			BSCullingProcess*              cullingProcess; // 50
			std::uint64_t                  padding58;      // 58
		};
		static_assert(offsetof(OcclusionMapData, projection) == 0x0);
		static_assert(offsetof(OcclusionMapData, camera) == 0x40);
		static_assert(offsetof(OcclusionMapData, accumulator) == 0x48);
		static_assert(offsetof(OcclusionMapData, cullingProcess) == 0x50);
		static_assert(sizeof(OcclusionMapData) == 0x60);

		// Add
		virtual ~Precipitation(); // 0

		// Non-member functions
		static const NiPoint3& GetRainDirection();

		// Member functions
		bool HasActiveGeometry() const;

		// Member variables
		OcclusionMapData      occlusionMapData;        // 10
		NiPointer<BSGeometry> currentPrecipitation;    // 70
		NiPointer<BSGeometry> previousPrecipitation;   // 78
		float                 lastCubeSize;            // 80
		float                 currentParticleDensity;  // 84
		float                 previousParticleDensity; // 88
		std::uint32_t         padding8C;               // 8C
	};
	static_assert(offsetof(Precipitation, occlusionMapData) == 0x10);
	static_assert(offsetof(Precipitation, currentPrecipitation) == 0x70);
	static_assert(offsetof(Precipitation, previousPrecipitation) == 0x78);
	static_assert(offsetof(Precipitation, lastCubeSize) == 0x80);
	static_assert(offsetof(Precipitation, currentParticleDensity) == 0x84);
	static_assert(offsetof(Precipitation, previousParticleDensity) == 0x88);
	static_assert(sizeof(Precipitation) == 0x90);
}
