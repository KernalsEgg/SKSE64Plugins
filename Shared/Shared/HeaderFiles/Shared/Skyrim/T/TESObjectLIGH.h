#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BGSDestructibleObjectForm.h"
#include "Shared/Skyrim/B/BGSEquipType.h"
#include "Shared/Skyrim/B/BGSMessageIcon.h"
#include "Shared/Skyrim/C/Color.h"
#include "Shared/Skyrim/N/NiColor.h"
#include "Shared/Skyrim/T/TESBoundAnimObject.h"
#include "Shared/Skyrim/T/TESFullName.h"
#include "Shared/Skyrim/T/TESIcon.h"
#include "Shared/Skyrim/T/TESModelTextureSwap.h"
#include "Shared/Skyrim/T/TESValueForm.h"
#include "Shared/Skyrim/T/TESWeightForm.h"



namespace Skyrim
{
	class BGSSoundDescriptorForm;
	class BGSLensFlare;

	class TESObjectLIGH :
		public TESBoundAnimObject,        // 0
		public TESFullName,               // 30
		public TESModelTextureSwap,       // 40
		public TESIcon,                   // 78
		public BGSMessageIcon,            // 88
		public TESWeightForm,             // A0
		public TESValueForm,              // B0
		public BGSDestructibleObjectForm, // C0
		public BGSEquipType               // D0
	{
	public:
		enum class RecordFlags : std::uint32_t
		{
			kRandomAnimationStart = 1U << 16,
			kPortalStrict         = 1U << 17,
			kObstacle             = 1U << 25
		};
		static_assert(sizeof(RecordFlags) == 0x4);

		enum class Flags : std::uint32_t
		{
			kNone                  = 0,
			kThisLightCanBeCarried = 1U << 1,
			kFlicker               = 1U << 3,
			kOffByDefault          = 1U << 5,
			kPulse                 = 1U << 7,
			kShadowSpotlight       = 1U << 10,
			kShadowHemisphere      = 1U << 11,
			kShadowOmnidirectional = 1U << 12,
			kPortalStrict          = 1U << 13 // Also in RecordFlags
		};
		static_assert(sizeof(Flags) == 0x4);

		// Override
		virtual ~TESObjectLIGH() override;

		// Override (TESBoundAnimObject)
		virtual void Unknown4(TESForm*) override;         // 4
		virtual void Unknown6(TESForm*) override;         // 6
		virtual void UnknownE(TESForm*) override;         // E
		virtual void UnknownF(TESForm*) override;         // F
		virtual void Unknown13(TESForm*) override;        // 13
		virtual void Unknown37(TESForm*) override;        // 37
		virtual void Unknown41(TESObject*) override;      // 41
		virtual void Unknown47(TESObject*) override;      // 47
		virtual void Unknown4A(TESBoundObject*) override; // 4A

		// Override (BGSEquipType)
		virtual BGSEquipSlot* GetEquipSlot() const override;                  // 4
		virtual void          SetEquipSlot(BGSEquipSlot* equipSlot) override; // 5

		// Member variables
		std::int32_t                               time;                      // E0
		std::uint32_t                              radius;                    // E4
		Color                                      color;                     // E8
		Utility::Enumeration<Flags, std::uint32_t> lightFlags;                // EC
		float                                      falloffExponent;           // F0
		float                                      fov;                       // F4
		float                                      nearClip;                  // F8
		float                                      flickerPeriod;             // FC, Creation Kit value multiplied by 100
		float                                      flickerIntensityAmplitude; // 100
		float                                      flickerMovementAmplitude;  // 104
		float                                      colorFade;                 // 108
		std::uint32_t                              padding10C;                // 10C
		BGSSoundDescriptorForm*                    sound;                     // 110
		NiColor                                    emittanceColor;            // 118
		std::uint32_t                              padding124;                // 124
		BGSLensFlare*                              lensFlare;                 // 128
	};
	static_assert(offsetof(TESObjectLIGH, time) == 0xE0);
	static_assert(offsetof(TESObjectLIGH, radius) == 0xE4);
	static_assert(offsetof(TESObjectLIGH, color) == 0xE8);
	static_assert(offsetof(TESObjectLIGH, lightFlags) == 0xEC);
	static_assert(offsetof(TESObjectLIGH, falloffExponent) == 0xF0);
	static_assert(offsetof(TESObjectLIGH, fov) == 0xF4);
	static_assert(offsetof(TESObjectLIGH, nearClip) == 0xF8);
	static_assert(offsetof(TESObjectLIGH, flickerPeriod) == 0xFC);
	static_assert(offsetof(TESObjectLIGH, flickerIntensityAmplitude) == 0x100);
	static_assert(offsetof(TESObjectLIGH, flickerMovementAmplitude) == 0x104);
	static_assert(offsetof(TESObjectLIGH, colorFade) == 0x108);
	static_assert(offsetof(TESObjectLIGH, sound) == 0x110);
	static_assert(offsetof(TESObjectLIGH, emittanceColor) == 0x118);
	static_assert(offsetof(TESObjectLIGH, lensFlare) == 0x128);
	static_assert(sizeof(TESObjectLIGH) == 0x130);
}
