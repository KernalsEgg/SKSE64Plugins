#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Skyrim/T/TESTexture.h"



namespace Skyrim
{
	class BGSShaderParticleGeometryData :
		public TESForm // 0
	{
	public:
		enum class SettingIndex
		{
			kGravityVelocity      = 0,
			kRotationVelocity     = 1,
			kParticleSizeX        = 2,
			kParticleSizeY        = 3,
			kCenterOffsetMin      = 4,
			kCenterOffsetMax      = 5,
			kInitialRotationRange = 6,
			kSubtextureCountX     = 7,
			kSubtextureCountY     = 8,
			kShader               = 9,
			kBoxSize              = 10,
			kParticleDensity      = 11,
			kTotal                = 12
		};

		union SettingValue
		{
		public:
			// Member variables
			float        floatingPoint;
			std::int32_t integer;
		};
		static_assert(sizeof(SettingValue) == 0x4);

		// Override
		virtual ~BGSShaderParticleGeometryData() override; // 0

		// Override (TESForm)
		virtual void Unknown4(TESForm*) override;  // 4
		virtual void Unknown5(TESForm*) override;  // 5
		virtual void Unknown6(TESForm*) override;  // 6
		virtual void Unknown13(TESForm*) override; // 13

		// Member variables
		BSTArray<SettingValue> settings;        // 20, size == SettingIndex::kTotal
		TESTexture             particleTexture; // 38
	};
	static_assert(offsetof(BGSShaderParticleGeometryData, settings) == 0x20);
	static_assert(offsetof(BGSShaderParticleGeometryData, particleTexture) == 0x38);
	static_assert(sizeof(BGSShaderParticleGeometryData) == 0x48);
}
