#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSString.h"
#include "Shared/Skyrim/C/Color.h"
#include "Shared/Skyrim/N/NiPoint2.h"
#include "Shared/Skyrim/N/NiPointer.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class NiColorInterpolator;
	class NiFloatInterpolator;

	class TESImageSpaceModifier :
		public TESForm // 0
	{
	public:
		template <class T>
		struct MultiplyAdd
		{
		public:
			// Member variables
			T multiply;
			T add;
		};

		struct HDR
		{
		public:
			// Member variables
			MultiplyAdd<float> eyeAdaptSpeed;   // 0
			MultiplyAdd<float> bloomBlurRadius; // 8
			MultiplyAdd<float> bloomThreshold;  // 10
			MultiplyAdd<float> bloomScale;      // 18
			MultiplyAdd<float> targetLumMin;    // 20
			MultiplyAdd<float> targetLumMax;    // 28
			MultiplyAdd<float> sunlightScale;   // 30
			MultiplyAdd<float> skyScale;        // 38
			MultiplyAdd<float> empty[6];        // 40, Used in GECK
		};
		static_assert(offsetof(HDR, eyeAdaptSpeed) == 0x0);
		static_assert(offsetof(HDR, bloomBlurRadius) == 0x8);
		static_assert(offsetof(HDR, bloomThreshold) == 0x10);
		static_assert(offsetof(HDR, bloomScale) == 0x18);
		static_assert(offsetof(HDR, targetLumMin) == 0x20);
		static_assert(offsetof(HDR, targetLumMax) == 0x28);
		static_assert(offsetof(HDR, sunlightScale) == 0x30);
		static_assert(offsetof(HDR, skyScale) == 0x38);
		static_assert(offsetof(HDR, empty) == 0x40);
		static_assert(sizeof(HDR) == 0x70);

		struct Bloom
		{
		public:
			// Member variables
			MultiplyAdd<float> empty[3]; // 0, Used in GECK
		};
		static_assert(offsetof(Bloom, empty) == 0x0);
		static_assert(sizeof(Bloom) == 0x18);

		struct Cinematic
		{
		public:
			// Member variables
			MultiplyAdd<float> saturation; // 0
			MultiplyAdd<float> brightness; // 8
			MultiplyAdd<float> contrast;   // 10
			MultiplyAdd<float> empty;      // 18, Used in GECK
		};
		static_assert(offsetof(Cinematic, saturation) == 0x0);
		static_assert(offsetof(Cinematic, brightness) == 0x8);
		static_assert(offsetof(Cinematic, contrast) == 0x10);
		static_assert(offsetof(Cinematic, empty) == 0x18);
		static_assert(sizeof(Cinematic) == 0x20);

		struct Blur
		{
		public:
			// Member variables
			std::uint32_t blurRadius; // 0
		};
		static_assert(offsetof(Blur, blurRadius) == 0x0);
		static_assert(sizeof(Blur) == 0x4);

		struct DoubleVision
		{
		public:
			// Member variables
			std::uint32_t strength; // 0
		};
		static_assert(offsetof(DoubleVision, strength) == 0x0);
		static_assert(sizeof(DoubleVision) == 0x4);

		struct DepthOfField
		{
		public:
			enum class Mode : std::uint8_t
			{
				kFrontBack = 0,
				kFront     = 1,
				kBack      = 2,
				kNone      = 3
			};
			static_assert(sizeof(Mode) == 0x1);

			// Member variables
			std::uint32_t                            strength;  // 0
			std::uint32_t                            distance;  // 4
			std::uint32_t                            range;     // 8
			bool                                     useTarget; // C
			Utility::Enumeration<Mode, std::uint8_t> mode;      // D
			std::uint16_t                            paddingE;  // E
		};
		static_assert(offsetof(DepthOfField, strength) == 0x0);
		static_assert(offsetof(DepthOfField, distance) == 0x4);
		static_assert(offsetof(DepthOfField, range) == 0x8);
		static_assert(offsetof(DepthOfField, useTarget) == 0xC);
		static_assert(offsetof(DepthOfField, mode) == 0xD);
		static_assert(sizeof(DepthOfField) == 0x10);

		struct FullScreenMotionBlur
		{
		public:
			// Member variables
			std::uint32_t strength; // 0
		};
		static_assert(offsetof(FullScreenMotionBlur, strength) == 0x0);
		static_assert(sizeof(FullScreenMotionBlur) == 0x4);

		struct Interpolators
		{
		public:
			struct HDR
			{
			public:
				// Member variables
				MultiplyAdd<NiPointer<NiFloatInterpolator>> eyeAdaptSpeed;   // 0
				MultiplyAdd<NiPointer<NiFloatInterpolator>> bloomBlurRadius; // 10
				MultiplyAdd<NiPointer<NiFloatInterpolator>> bloomThreshold;  // 20
				MultiplyAdd<NiPointer<NiFloatInterpolator>> bloomScale;      // 30
				MultiplyAdd<NiPointer<NiFloatInterpolator>> targetLumMin;    // 40
				MultiplyAdd<NiPointer<NiFloatInterpolator>> targetLumMax;    // 50
				MultiplyAdd<NiPointer<NiFloatInterpolator>> sunlightScale;   // 60
				MultiplyAdd<NiPointer<NiFloatInterpolator>> skyScale;        // 70
				MultiplyAdd<NiPointer<NiFloatInterpolator>> empty[6];        // 80
			};
			static_assert(offsetof(HDR, eyeAdaptSpeed) == 0x0);
			static_assert(offsetof(HDR, bloomBlurRadius) == 0x10);
			static_assert(offsetof(HDR, bloomThreshold) == 0x20);
			static_assert(offsetof(HDR, bloomScale) == 0x30);
			static_assert(offsetof(HDR, targetLumMin) == 0x40);
			static_assert(offsetof(HDR, targetLumMax) == 0x50);
			static_assert(offsetof(HDR, sunlightScale) == 0x60);
			static_assert(offsetof(HDR, skyScale) == 0x70);
			static_assert(offsetof(HDR, empty) == 0x80);
			static_assert(sizeof(HDR) == 0xE0);

			struct Bloom
			{
			public:
				// Member variables
				MultiplyAdd<NiPointer<NiFloatInterpolator>> empty[3]; // 0
			};
			static_assert(offsetof(Bloom, empty) == 0x0);
			static_assert(sizeof(Bloom) == 0x30);

			struct Cinematic
			{
			public:
				// Member variables
				MultiplyAdd<NiPointer<NiFloatInterpolator>> saturation; // 0
				MultiplyAdd<NiPointer<NiFloatInterpolator>> brightness; // 10
				MultiplyAdd<NiPointer<NiFloatInterpolator>> contrast;   // 20
				MultiplyAdd<NiPointer<NiFloatInterpolator>> empty;      // 30
			};
			static_assert(offsetof(Cinematic, saturation) == 0x0);
			static_assert(offsetof(Cinematic, brightness) == 0x10);
			static_assert(offsetof(Cinematic, contrast) == 0x20);
			static_assert(offsetof(Cinematic, empty) == 0x30);
			static_assert(sizeof(Cinematic) == 0x40);

			struct Blur
			{
			public:
				// Member variables
				NiPointer<NiFloatInterpolator> blurRadius; // 0
			};
			static_assert(offsetof(Blur, blurRadius) == 0x0);
			static_assert(sizeof(Blur) == 0x8);

			struct DoubleVision
			{
			public:
				// Member variables
				NiPointer<NiFloatInterpolator> strength; // 0
			};
			static_assert(offsetof(DoubleVision, strength) == 0x0);
			static_assert(sizeof(DoubleVision) == 0x8);

			struct RadialBlur
			{
			public:
				// Member variables
				NiPointer<NiFloatInterpolator> strength;  // 0
				NiPointer<NiFloatInterpolator> rampUp;    // 8
				NiPointer<NiFloatInterpolator> start;     // 10
				NiPointer<NiFloatInterpolator> rampDown;  // 18
				NiPointer<NiFloatInterpolator> downStart; // 20
			};
			static_assert(offsetof(RadialBlur, strength) == 0x0);
			static_assert(offsetof(RadialBlur, rampUp) == 0x8);
			static_assert(offsetof(RadialBlur, start) == 0x10);
			static_assert(offsetof(RadialBlur, rampDown) == 0x18);
			static_assert(offsetof(RadialBlur, downStart) == 0x20);
			static_assert(sizeof(RadialBlur) == 0x28);

			struct DepthOfField
			{
			public:
				// Member variables
				NiPointer<NiFloatInterpolator> strength; // 0
				NiPointer<NiFloatInterpolator> distance; // 8
				NiPointer<NiFloatInterpolator> range;    // 10
			};
			static_assert(offsetof(DepthOfField, strength) == 0x0);
			static_assert(offsetof(DepthOfField, distance) == 0x8);
			static_assert(offsetof(DepthOfField, range) == 0x10);
			static_assert(sizeof(DepthOfField) == 0x18);

			struct FullScreenMotionBlur
			{
			public:
				// Member variables
				NiPointer<NiFloatInterpolator> strength; // 0, NiColorInterpolator in CommonLibSSE
			};
			static_assert(offsetof(FullScreenMotionBlur, strength) == 0x0);
			static_assert(sizeof(FullScreenMotionBlur) == 0x8);

			// Member variables
			HDR                            hdr;                  // 0
			Bloom                          bloom;                // E0
			Cinematic                      cinematic;            // 110
			Blur                           blur;                 // 150
			DoubleVision                   doubleVision;         // 158
			NiPointer<NiColorInterpolator> tint;                 // 160
			NiPointer<NiColorInterpolator> fade;                 // 168
			RadialBlur                     radialBlur;           // 170
			DepthOfField                   depthOfField;         // 198
			FullScreenMotionBlur           fullScreenMotionBlur; // 1B0
		};
		static_assert(offsetof(Interpolators, hdr) == 0x0);
		static_assert(offsetof(Interpolators, bloom) == 0xE0);
		static_assert(offsetof(Interpolators, cinematic) == 0x110);
		static_assert(offsetof(Interpolators, blur) == 0x150);
		static_assert(offsetof(Interpolators, doubleVision) == 0x158);
		static_assert(offsetof(Interpolators, tint) == 0x160);
		static_assert(offsetof(Interpolators, fade) == 0x168);
		static_assert(offsetof(Interpolators, radialBlur) == 0x170);
		static_assert(offsetof(Interpolators, depthOfField) == 0x198);
		static_assert(offsetof(Interpolators, fullScreenMotionBlur) == 0x1B0);
		static_assert(sizeof(Interpolators) == 0x1B8);

		// Override
		virtual ~TESImageSpaceModifier() override; // 0

		// Override (TESForm)
		virtual void        Unknown4(TESForm*) override;                // 4
		virtual void        Unknown5(TESForm*) override;                // 5
		virtual void        Unknown6(TESForm*) override;                // 6
		virtual const char* GetEditorID() const override;               // 32
		virtual bool        SetEditorID(const char* editorID) override; // 33

		// Member variables
		bool                 animatable;           // 20
		std::uint8_t         padding21;            // 21
		std::uint16_t        padding22;            // 22
		float                duration;             // 24
		HDR                  hdr;                  // 28
		Bloom                bloom;                // 98
		Cinematic            cinematic;            // B0
		Color                cinematicTint;        // D0
		Blur                 blur;                 // D4
		DoubleVision         doubleVision;         // D8
		std::uint32_t        radialBlurStrength;   // DC
		std::uint32_t        radialBlurRampUp;     // E0
		std::uint32_t        radialBlurStart;      // E4
		bool                 radialBlurUseTarget;  // E8
		std::uint8_t         paddingE9;            // E9
		std::uint16_t        paddingEA;            // EA
		NiPoint2             radialBlurCenter;     // EC
		DepthOfField         depthOfField;         // F4
		std::uint32_t        radialBlurRampDown;   // 104
		std::uint32_t        radialBlurDownStart;  // 108
		Color                cinematicFade;        // 10C, std::uint32_t in CommonLibSSE
		FullScreenMotionBlur fullScreenMotionBlur; // 110
		std::uint32_t        padding114;           // 114
		Interpolators        interpolators;        // 118
		BSString             editorID;             // 2D0
	};
	static_assert(offsetof(TESImageSpaceModifier, animatable) == 0x20);
	static_assert(offsetof(TESImageSpaceModifier, duration) == 0x24);
	static_assert(offsetof(TESImageSpaceModifier, hdr) == 0x28);
	static_assert(offsetof(TESImageSpaceModifier, bloom) == 0x98);
	static_assert(offsetof(TESImageSpaceModifier, cinematic) == 0xB0);
	static_assert(offsetof(TESImageSpaceModifier, cinematicTint) == 0xD0);
	static_assert(offsetof(TESImageSpaceModifier, blur) == 0xD4);
	static_assert(offsetof(TESImageSpaceModifier, doubleVision) == 0xD8);
	static_assert(offsetof(TESImageSpaceModifier, radialBlurStrength) == 0xDC);
	static_assert(offsetof(TESImageSpaceModifier, radialBlurRampUp) == 0xE0);
	static_assert(offsetof(TESImageSpaceModifier, radialBlurStart) == 0xE4);
	static_assert(offsetof(TESImageSpaceModifier, radialBlurUseTarget) == 0xE8);
	static_assert(offsetof(TESImageSpaceModifier, radialBlurCenter) == 0xEC);
	static_assert(offsetof(TESImageSpaceModifier, depthOfField) == 0xF4);
	static_assert(offsetof(TESImageSpaceModifier, radialBlurRampDown) == 0x104);
	static_assert(offsetof(TESImageSpaceModifier, radialBlurDownStart) == 0x108);
	static_assert(offsetof(TESImageSpaceModifier, cinematicFade) == 0x10C);
	static_assert(offsetof(TESImageSpaceModifier, fullScreenMotionBlur) == 0x110);
	static_assert(offsetof(TESImageSpaceModifier, interpolators) == 0x118);
	static_assert(offsetof(TESImageSpaceModifier, editorID) == 0x2D0);
	static_assert(sizeof(TESImageSpaceModifier) == 0x2E0);
}
