#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/T/TESForm.h"



namespace Skyrim
{
	class TESImageSpace :
		public TESForm // 0
	{
	public:
		struct HDR
		{
		public:
			// Member variables
			float eyeAdaptSpeed;         // 0
			float bloomBlurRadius;       // 4
			float bloomThreshold;        // 8
			float bloomScale;            // C
			float receiveBloomThreshold; // 10
			float white;                 // 14
			float sunlightScale;         // 18
			float skyScale;              // 1C
			float eyeAdaptStrength;      // 20
		};
		static_assert(offsetof(HDR, eyeAdaptSpeed) == 0x0);
		static_assert(offsetof(HDR, bloomBlurRadius) == 0x4);
		static_assert(offsetof(HDR, bloomThreshold) == 0x8);
		static_assert(offsetof(HDR, bloomScale) == 0xC);
		static_assert(offsetof(HDR, receiveBloomThreshold) == 0x10);
		static_assert(offsetof(HDR, white) == 0x14);
		static_assert(offsetof(HDR, sunlightScale) == 0x18);
		static_assert(offsetof(HDR, skyScale) == 0x1C);
		static_assert(offsetof(HDR, eyeAdaptStrength) == 0x20);
		static_assert(sizeof(HDR) == 0x24);

		struct Cinematic
		{
		public:
			struct ColorF
			{
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
			float  saturation; // 0
			float  brightness; // 4
			float  contrast;   // 8
			float  tintAmount; // C
			ColorF tintColor;  // 10
		};
		static_assert(offsetof(Cinematic, saturation) == 0x0);
		static_assert(offsetof(Cinematic, brightness) == 0x4);
		static_assert(offsetof(Cinematic, contrast) == 0x8);
		static_assert(offsetof(Cinematic, tintAmount) == 0xC);
		static_assert(offsetof(Cinematic, tintColor) == 0x10);
		static_assert(sizeof(Cinematic) == 0x1C);

		struct DepthOfField
		{
		public:
			// Member variables
			float         strength; // 0
			float         distance; // 4
			float         range;    // 8
			std::uint32_t unknownC; // C
		};
		static_assert(offsetof(DepthOfField, strength) == 0x0);
		static_assert(offsetof(DepthOfField, distance) == 0x4);
		static_assert(offsetof(DepthOfField, range) == 0x8);
		static_assert(sizeof(DepthOfField) == 0x10);

		// Override
		virtual ~TESImageSpace() override; // 0

		// Override (TESForm)
		virtual void Unknown4(TESForm*) override; // 4
		virtual void Unknown6(TESForm*) override; // 6

		// Member variables
		HDR          hdr;          // 0
		Cinematic    cinematic;    // 24
		DepthOfField depthOfField; // 40
	};
	static_assert(offsetof(TESImageSpace, hdr) == 0x20);
	static_assert(offsetof(TESImageSpace, cinematic) == 0x44);
	static_assert(offsetof(TESImageSpace, depthOfField) == 0x60);
	static_assert(sizeof(TESImageSpace) == 0x70);
}
