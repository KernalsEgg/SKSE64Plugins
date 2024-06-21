#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	class BSVolumetricLightingRenderData
	{
	public:
		struct General
		{
		public:
			// Member variables
			float intensity; // 0
		};
		static_assert(offsetof(General, intensity) == 0x0);
		static_assert(sizeof(General) == 0x4);

		struct CustomColor
		{
		public:
			struct ColorF
			{
			public:
				// Member variables
				float red;   // 0
				float green; // 4
				float blue;  // 8
			};
			static_assert(offsetof(ColorF, red) == 0x0);
			static_assert(offsetof(ColorF, green) == 0x4);
			static_assert(offsetof(ColorF, blue) == 0x8);
			static_assert(sizeof(ColorF) == 0xC);

			// Member variables
			float  contribution; // 0
			ColorF color;        // 4
		};
		static_assert(offsetof(CustomColor, contribution) == 0x0);
		static_assert(offsetof(CustomColor, color) == 0x4);
		static_assert(sizeof(CustomColor) == 0x10);

		struct Density
		{
		public:
			// Member variables
			float contribution; // 0
			float size;         // 4
			float windSpeed;    // 8
			float fallingSpeed; // C
		};
		static_assert(offsetof(Density, contribution) == 0x0);
		static_assert(offsetof(Density, size) == 0x4);
		static_assert(offsetof(Density, windSpeed) == 0x8);
		static_assert(offsetof(Density, fallingSpeed) == 0xC);
		static_assert(sizeof(Density) == 0x10);

		struct PhaseFunction
		{
		public:
			// Member variables
			float contribution; // 0
			float scattering;   // 4
		};
		static_assert(offsetof(PhaseFunction, contribution) == 0x0);
		static_assert(offsetof(PhaseFunction, scattering) == 0x4);
		static_assert(sizeof(PhaseFunction) == 0x8);

		struct SamplingRepartition
		{
		public:
			// Member variables
			float rangeFactor; // 0
		};
		static_assert(offsetof(SamplingRepartition, rangeFactor) == 0x0);
		static_assert(sizeof(SamplingRepartition) == 0x4);

		// Member variables
		General             general;             // 0
		CustomColor         customColor;         // 4
		Density             density;             // 14
		PhaseFunction       phaseFunction;       // 24
		SamplingRepartition samplingRepartition; // 2C
	};
	static_assert(offsetof(BSVolumetricLightingRenderData, general) == 0x0);
	static_assert(offsetof(BSVolumetricLightingRenderData, customColor) == 0x4);
	static_assert(offsetof(BSVolumetricLightingRenderData, density) == 0x14);
	static_assert(offsetof(BSVolumetricLightingRenderData, phaseFunction) == 0x24);
	static_assert(offsetof(BSVolumetricLightingRenderData, samplingRepartition) == 0x2C);
	static_assert(sizeof(BSVolumetricLightingRenderData) == 0x30);
}
