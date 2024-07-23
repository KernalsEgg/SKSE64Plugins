#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/D/DecalData.h"
#include "Shared/Skyrim/I/ImpactResult.h"
#include "Shared/Skyrim/S/SoundLevel.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Skyrim/T/TESModel.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSHazard;
	class BGSSoundDescriptorForm;
	class BGSTextureSet;

	class BGSImpactData :
		public TESForm, // 0
		public TESModel // 20
	{
	public:
		enum class Orientation : std::uint32_t
		{
			kSurfaceNormal        = 0,
			kProjectileVector     = 1,
			kProjectileReflection = 2
		};
		static_assert(sizeof(Orientation) == 0x4);

		enum class Flags : std::uint8_t
		{
			kNone             = 0,
			kInheritDecalData = 1U << 0
		};
		static_assert(sizeof(Flags) == 0x1);

		// Override
		virtual ~BGSImpactData() override; // 0

		// Override (TESForm)
		virtual void InitializeData() override;    // 4
		virtual bool Load(TESFile* file) override; // 6
		virtual void Unknown13(TESForm*) override; // 13

		// Member variables
		float                                            effectDuration;      // 48
		Utility::Enumeration<Orientation, std::uint32_t> effectOrientation;   // 4C
		float                                            angleThreshold;      // 50
		float                                            placementRadius;     // 54
		Utility::Enumeration<SoundLevel, std::uint32_t>  impactSoundLevel;    // 58
		Utility::Enumeration<Flags, std::uint8_t>        impactDataFlags;     // 5C
		Utility::Enumeration<ImpactResult, std::uint8_t> effectImpactResult;  // 5D
		std::uint16_t                                    padding5E;           // 5E
		BGSTextureSet*                                   primaryTextureSet;   // 60
		BGSTextureSet*                                   secondaryTextureSet; // 68
		BGSSoundDescriptorForm*                          impactSound1;        // 70
		BGSSoundDescriptorForm*                          impactSound2;        // 78
		BGSHazard*                                       effectHazard;        // 80
		DecalData                                        decalData;           // 88
		std::uint32_t                                    paddingAC;           // AC
	};
	static_assert(offsetof(BGSImpactData, effectDuration) == 0x48);
	static_assert(offsetof(BGSImpactData, effectOrientation) == 0x4C);
	static_assert(offsetof(BGSImpactData, angleThreshold) == 0x50);
	static_assert(offsetof(BGSImpactData, placementRadius) == 0x54);
	static_assert(offsetof(BGSImpactData, impactSoundLevel) == 0x58);
	static_assert(offsetof(BGSImpactData, impactDataFlags) == 0x5C);
	static_assert(offsetof(BGSImpactData, effectImpactResult) == 0x5D);
	static_assert(offsetof(BGSImpactData, primaryTextureSet) == 0x60);
	static_assert(offsetof(BGSImpactData, secondaryTextureSet) == 0x68);
	static_assert(offsetof(BGSImpactData, impactSound1) == 0x70);
	static_assert(offsetof(BGSImpactData, impactSound2) == 0x78);
	static_assert(offsetof(BGSImpactData, effectHazard) == 0x80);
	static_assert(offsetof(BGSImpactData, decalData) == 0x88);
	static_assert(sizeof(BGSImpactData) == 0xB0);
}
