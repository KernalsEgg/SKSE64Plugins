#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/C/Color.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Skyrim/T/TESTexture.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSDebris;
	class BGSSoundDescriptorForm;

	class TESEffectShader :
		public TESForm // 0
	{
	public:
		enum class Flags : std::uint32_t
		{
			kNone                                     = 0,
			kNoMembraneShader                         = 1U << 0,
			kFillTextureEffectGrayscaleToPaletteColor = 1U << 1,
			kFillTextureEffectGrayscaleToPaletteAlpha = 1U << 2,
			kNoParticleShader                         = 1U << 3,
			kEdgeEffectInverse                        = 1U << 4,
			kAffectSkinOnly                           = 1U << 5,
			kIgnoreAlpha                              = 1U << 6,
			kProjectedUVs                             = 1U << 7,
			kIgnoreBaseGeometryTextureAlpha           = 1U << 8,
			kLighting                                 = 1U << 9,
			kNoWeapons                                = 1U << 10,
			kNotAnimated                              = 1U << 15,
			kParticleShaderGrayscaleToPaletteColor    = 1U << 16,
			kParticleShaderGrayscaleToPaletteAlpha    = 1U << 17,
			kUseBloodGeometry                         = 1U << 24
		};
		static_assert(sizeof(Flags) == 0x4);

		// Override
		virtual ~TESEffectShader() override; // 0

		// Override (TESForm)
		virtual void InitializeData() override;    // 4
		virtual void Unknown6(TESForm*) override;  // 6
		virtual void Unknown13(TESForm*) override; // 13

		// Member variables
		std::uint32_t                              unknown20;                                  // 20
		::D3DBLEND                                 membraneShaderSourceBlendMode;              // 24
		::D3DBLENDOP                               membraneShaderBlendOperation;               // 28
		::D3DCMPFUNC                               membraneShaderZTestFunction;                // 2C
		Color                                      fillTextureEffectColorKey1;                 // 30
		float                                      fillTextureEffectAlphaFadeInTime;           // 34
		float                                      fillTextureEffectFullAlphaTime;             // 38
		float                                      fillTextureEffectAlphaFadeOutTime;          // 3C
		float                                      fillTextureEffectPersistentAlphaRatio;      // 40
		float                                      fillTextureEffectAlphaPulseAmplitude;       // 44
		float                                      fillTextureEffectAlphaPulseFrequency;       // 48
		float                                      fillTextureEffectTextureAnimationSpeedU;    // 4C
		float                                      fillTextureEffectTextureAnimationSpeedV;    // 50
		float                                      edgeEffectFallOff;                          // 54
		Color                                      edgeEffectColor;                            // 58
		float                                      edgeEffectAlphaFadeInTime;                  // 5C
		float                                      edgeEffectFullAlphaTime;                    // 60
		float                                      edgeEffectAlphaFadeOutTime;                 // 64
		float                                      edgeEffectPersistentAlphaRatio;             // 68
		float                                      edgeEffectAlphaPulseAmplitude;              // 6C
		float                                      edgeEffectAlphaPulseFrequency;              // 70
		float                                      fillTextureEffectFullAlphaRatio;            // 74
		float                                      edgeEffectFullAlphaRatio;                   // 78
		::D3DBLEND                                 membraneShaderDestBlendMode;                // 7C
		::D3DBLEND                                 particleShaderSourceBlendMode;              // 80
		::D3DBLENDOP                               particleShaderBlendOperation;               // 84
		::D3DCMPFUNC                               particleShaderZTestFunction;                // 88
		::D3DBLEND                                 particleShaderDestBlendMode;                // 8C
		float                                      particleShaderParticleBirthRampUpTime;      // 90
		float                                      particleShaderFullParticleBirthTime;        // 94
		float                                      particleShaderParticleBirthRampDownTime;    // 98
		float                                      particleShaderFullParticleBirthCount;       // 9C
		float                                      particleShaderPersistentParticleCount;      // A0
		float                                      particleShaderParticleLifetime;             // A4
		float                                      particleShaderParticleLifetimeRange;        // A8
		float                                      particleShaderInitialSpeedAlongNormal;      // AC
		float                                      particleShaderAccelerationAlongNormal;      // B0
		float                                      particleShaderInitialVelocityX;             // B4
		float                                      particleShaderInitialVelocityY;             // B8
		float                                      particleShaderInitialVelocityZ;             // BC
		float                                      particleShaderAccelerationX;                // C0
		float                                      particleShaderAccelerationY;                // C4
		float                                      particleShaderAccelerationZ;                // C8
		float                                      particleShaderScaleKey1;                    // CC
		float                                      particleShaderScaleKey2;                    // D0
		float                                      particleShaderScaleKey1Time;                // D4
		float                                      particleShaderScaleKey2Time;                // D8
		Color                                      particleShaderColorKey1;                    // DC
		Color                                      particleShaderColorKey2;                    // E0
		Color                                      particleShaderColorKey3;                    // E4
		float                                      particleShaderColorKey1ColorAlpha;          // E8
		float                                      particleShaderColorKey2ColorAlpha;          // EC
		float                                      particleShaderColorKey3ColorAlpha;          // F0
		float                                      particleShaderColorKey1ColorKeyTime;        // F4
		float                                      particleShaderColorKey2ColorKeyTime;        // F8
		float                                      particleShaderColorKey3ColorKeyTime;        // FC
		float                                      particleShaderInitialSpeedAlongNormalRange; // 100
		float                                      particleShaderInitialRotation;              // 104
		float                                      particleShaderInitialRotationRange;         // 108
		float                                      particleShaderRotationSpeed;                // 10C
		float                                      particleShaderRotationSpeedRange;           // 110
		std::uint32_t                              padding114;                                 // 114
		BGSDebris*                                 addonModels;                                // 118
		float                                      holesAlphaTestAnimationStartTime;           // 120
		float                                      holesAlphaTestAnimationEndTime;             // 124
		float                                      holesAlphaTestAnimationStartVal;            // 128
		float                                      holesAlphaTestAnimationEndVal;              // 12C
		std::uint64_t                              unknown130;                                 // 130
		float                                      particleShaderExplosionWindSpeed;           // 138
		float                                      particleShaderTextureCountU;                // 13C
		float                                      particleShaderTextureCountV;                // 140
		float                                      addonModelsFadeInTime;                      // 144
		float                                      addonModelsFadeOutTime;                     // 148
		float                                      addonModelsScaleStart;                      // 14C
		float                                      addonModelsScaleEnd;                        // 150
		float                                      addonModelsScaleInTime;                     // 154
		float                                      addonModelsScaleOutTime;                    // 158
		std::uint32_t                              padding15C;                                 // 15C
		BGSSoundDescriptorForm*                    ambientSound;                               // 160
		Color                                      fillTextureEffectColorKey2;                 // 168
		Color                                      fillTextureEffectColorKey3;                 // 16C
		float                                      fillTextureEffectColorKey1Scale;            // 170
		float                                      fillTextureEffectColorKey2Scale;            // 174
		float                                      fillTextureEffectColorKey3Scale;            // 178
		float                                      fillTextureEffectColorKey1Time;             // 17C
		float                                      fillTextureEffectColorKey2Time;             // 180
		float                                      fillTextureEffectColorKey3Time;             // 184
		float                                      particleShaderColorScale;                   // 188
		float                                      particleShaderBirthPositionOffset;          // 18C
		float                                      particleShaderBirthPositionOffsetRange;     // 190
		float                                      animatedStartFrame;                         // 194
		float                                      animatedStartFrameVariation;                // 198
		float                                      animatedEndFrame;                           // 19C
		float                                      animatedLoopStartFrame;                     // 1A0
		float                                      animatedLoopStartVariation;                 // 1A4
		float                                      animatedFrameCount;                         // 1A8
		float                                      animatedFrameCountVariation;                // 1AC
		Utility::Enumeration<Flags, std::uint32_t> effectShaderFlags;                          // 1B0
		float                                      fillTextureEffectTextureScaleU;             // 1B4
		float                                      fillTextureEffectTextureScaleV;             // 1B8
		std::uint32_t                              particleShaderSceneGraphEmitDepthLimit;     // 1BC
		TESTexture                                 fillTextureEffectFillTexture;               // 1C0
		TESTexture                                 particleShaderTexture;                      // 1D0
		TESTexture                                 holesTexture;                               // 1E0
		TESTexture                                 fillTextureEffectPaletteTexture;            // 1F0
		TESTexture                                 particleShaderPaletteTexture;               // 200
		std::uint64_t                              unknown210;                                 // 210
		std::uint64_t                              unknown218;                                 // 218
	};
	static_assert(offsetof(TESEffectShader, membraneShaderSourceBlendMode) == 0x24);
	static_assert(offsetof(TESEffectShader, membraneShaderBlendOperation) == 0x28);
	static_assert(offsetof(TESEffectShader, membraneShaderZTestFunction) == 0x2C);
	static_assert(offsetof(TESEffectShader, fillTextureEffectColorKey1) == 0x30);
	static_assert(offsetof(TESEffectShader, fillTextureEffectAlphaFadeInTime) == 0x34);
	static_assert(offsetof(TESEffectShader, fillTextureEffectFullAlphaTime) == 0x38);
	static_assert(offsetof(TESEffectShader, fillTextureEffectAlphaFadeOutTime) == 0x3C);
	static_assert(offsetof(TESEffectShader, fillTextureEffectPersistentAlphaRatio) == 0x40);
	static_assert(offsetof(TESEffectShader, fillTextureEffectAlphaPulseAmplitude) == 0x44);
	static_assert(offsetof(TESEffectShader, fillTextureEffectAlphaPulseFrequency) == 0x48);
	static_assert(offsetof(TESEffectShader, fillTextureEffectTextureAnimationSpeedU) == 0x4C);
	static_assert(offsetof(TESEffectShader, fillTextureEffectTextureAnimationSpeedV) == 0x50);
	static_assert(offsetof(TESEffectShader, edgeEffectFallOff) == 0x54);
	static_assert(offsetof(TESEffectShader, edgeEffectColor) == 0x58);
	static_assert(offsetof(TESEffectShader, edgeEffectAlphaFadeInTime) == 0x5C);
	static_assert(offsetof(TESEffectShader, edgeEffectFullAlphaTime) == 0x60);
	static_assert(offsetof(TESEffectShader, edgeEffectAlphaFadeOutTime) == 0x64);
	static_assert(offsetof(TESEffectShader, edgeEffectPersistentAlphaRatio) == 0x68);
	static_assert(offsetof(TESEffectShader, edgeEffectAlphaPulseAmplitude) == 0x6C);
	static_assert(offsetof(TESEffectShader, edgeEffectAlphaPulseFrequency) == 0x70);
	static_assert(offsetof(TESEffectShader, fillTextureEffectFullAlphaRatio) == 0x74);
	static_assert(offsetof(TESEffectShader, edgeEffectFullAlphaRatio) == 0x78);
	static_assert(offsetof(TESEffectShader, membraneShaderDestBlendMode) == 0x7C);
	static_assert(offsetof(TESEffectShader, particleShaderSourceBlendMode) == 0x80);
	static_assert(offsetof(TESEffectShader, particleShaderBlendOperation) == 0x84);
	static_assert(offsetof(TESEffectShader, particleShaderZTestFunction) == 0x88);
	static_assert(offsetof(TESEffectShader, particleShaderDestBlendMode) == 0x8C);
	static_assert(offsetof(TESEffectShader, particleShaderParticleBirthRampUpTime) == 0x90);
	static_assert(offsetof(TESEffectShader, particleShaderFullParticleBirthTime) == 0x94);
	static_assert(offsetof(TESEffectShader, particleShaderParticleBirthRampDownTime) == 0x98);
	static_assert(offsetof(TESEffectShader, particleShaderFullParticleBirthCount) == 0x9C);
	static_assert(offsetof(TESEffectShader, particleShaderPersistentParticleCount) == 0xA0);
	static_assert(offsetof(TESEffectShader, particleShaderParticleLifetime) == 0xA4);
	static_assert(offsetof(TESEffectShader, particleShaderParticleLifetimeRange) == 0xA8);
	static_assert(offsetof(TESEffectShader, particleShaderInitialSpeedAlongNormal) == 0xAC);
	static_assert(offsetof(TESEffectShader, particleShaderAccelerationAlongNormal) == 0xB0);
	static_assert(offsetof(TESEffectShader, particleShaderInitialVelocityX) == 0xB4);
	static_assert(offsetof(TESEffectShader, particleShaderInitialVelocityY) == 0xB8);
	static_assert(offsetof(TESEffectShader, particleShaderInitialVelocityZ) == 0xBC);
	static_assert(offsetof(TESEffectShader, particleShaderAccelerationX) == 0xC0);
	static_assert(offsetof(TESEffectShader, particleShaderAccelerationY) == 0xC4);
	static_assert(offsetof(TESEffectShader, particleShaderAccelerationZ) == 0xC8);
	static_assert(offsetof(TESEffectShader, particleShaderScaleKey1) == 0xCC);
	static_assert(offsetof(TESEffectShader, particleShaderScaleKey2) == 0xD0);
	static_assert(offsetof(TESEffectShader, particleShaderScaleKey1Time) == 0xD4);
	static_assert(offsetof(TESEffectShader, particleShaderScaleKey2Time) == 0xD8);
	static_assert(offsetof(TESEffectShader, particleShaderColorKey1) == 0xDC);
	static_assert(offsetof(TESEffectShader, particleShaderColorKey2) == 0xE0);
	static_assert(offsetof(TESEffectShader, particleShaderColorKey3) == 0xE4);
	static_assert(offsetof(TESEffectShader, particleShaderColorKey1ColorAlpha) == 0xE8);
	static_assert(offsetof(TESEffectShader, particleShaderColorKey2ColorAlpha) == 0xEC);
	static_assert(offsetof(TESEffectShader, particleShaderColorKey3ColorAlpha) == 0xF0);
	static_assert(offsetof(TESEffectShader, particleShaderColorKey1ColorKeyTime) == 0xF4);
	static_assert(offsetof(TESEffectShader, particleShaderColorKey2ColorKeyTime) == 0xF8);
	static_assert(offsetof(TESEffectShader, particleShaderColorKey3ColorKeyTime) == 0xFC);
	static_assert(offsetof(TESEffectShader, particleShaderInitialSpeedAlongNormalRange) == 0x100);
	static_assert(offsetof(TESEffectShader, particleShaderInitialRotation) == 0x104);
	static_assert(offsetof(TESEffectShader, particleShaderInitialRotationRange) == 0x108);
	static_assert(offsetof(TESEffectShader, particleShaderRotationSpeed) == 0x10C);
	static_assert(offsetof(TESEffectShader, particleShaderRotationSpeedRange) == 0x110);
	static_assert(offsetof(TESEffectShader, addonModels) == 0x118);
	static_assert(offsetof(TESEffectShader, holesAlphaTestAnimationStartTime) == 0x120);
	static_assert(offsetof(TESEffectShader, holesAlphaTestAnimationEndTime) == 0x124);
	static_assert(offsetof(TESEffectShader, holesAlphaTestAnimationStartVal) == 0x128);
	static_assert(offsetof(TESEffectShader, holesAlphaTestAnimationEndVal) == 0x12C);
	static_assert(offsetof(TESEffectShader, particleShaderExplosionWindSpeed) == 0x138);
	static_assert(offsetof(TESEffectShader, particleShaderTextureCountU) == 0x13C);
	static_assert(offsetof(TESEffectShader, particleShaderTextureCountV) == 0x140);
	static_assert(offsetof(TESEffectShader, addonModelsFadeInTime) == 0x144);
	static_assert(offsetof(TESEffectShader, addonModelsFadeOutTime) == 0x148);
	static_assert(offsetof(TESEffectShader, addonModelsScaleStart) == 0x14C);
	static_assert(offsetof(TESEffectShader, addonModelsScaleEnd) == 0x150);
	static_assert(offsetof(TESEffectShader, addonModelsScaleInTime) == 0x154);
	static_assert(offsetof(TESEffectShader, addonModelsScaleOutTime) == 0x158);
	static_assert(offsetof(TESEffectShader, ambientSound) == 0x160);
	static_assert(offsetof(TESEffectShader, fillTextureEffectColorKey2) == 0x168);
	static_assert(offsetof(TESEffectShader, fillTextureEffectColorKey3) == 0x16C);
	static_assert(offsetof(TESEffectShader, fillTextureEffectColorKey1Scale) == 0x170);
	static_assert(offsetof(TESEffectShader, fillTextureEffectColorKey2Scale) == 0x174);
	static_assert(offsetof(TESEffectShader, fillTextureEffectColorKey3Scale) == 0x178);
	static_assert(offsetof(TESEffectShader, fillTextureEffectColorKey1Time) == 0x17C);
	static_assert(offsetof(TESEffectShader, fillTextureEffectColorKey2Time) == 0x180);
	static_assert(offsetof(TESEffectShader, fillTextureEffectColorKey3Time) == 0x184);
	static_assert(offsetof(TESEffectShader, particleShaderColorScale) == 0x188);
	static_assert(offsetof(TESEffectShader, particleShaderBirthPositionOffset) == 0x18C);
	static_assert(offsetof(TESEffectShader, particleShaderBirthPositionOffsetRange) == 0x190);
	static_assert(offsetof(TESEffectShader, animatedStartFrame) == 0x194);
	static_assert(offsetof(TESEffectShader, animatedStartFrameVariation) == 0x198);
	static_assert(offsetof(TESEffectShader, animatedEndFrame) == 0x19C);
	static_assert(offsetof(TESEffectShader, animatedLoopStartFrame) == 0x1A0);
	static_assert(offsetof(TESEffectShader, animatedLoopStartVariation) == 0x1A4);
	static_assert(offsetof(TESEffectShader, animatedFrameCount) == 0x1A8);
	static_assert(offsetof(TESEffectShader, animatedFrameCountVariation) == 0x1AC);
	static_assert(offsetof(TESEffectShader, effectShaderFlags) == 0x1B0);
	static_assert(offsetof(TESEffectShader, fillTextureEffectTextureScaleU) == 0x1B4);
	static_assert(offsetof(TESEffectShader, fillTextureEffectTextureScaleV) == 0x1B8);
	static_assert(offsetof(TESEffectShader, particleShaderSceneGraphEmitDepthLimit) == 0x1BC);
	static_assert(offsetof(TESEffectShader, fillTextureEffectFillTexture) == 0x1C0);
	static_assert(offsetof(TESEffectShader, particleShaderTexture) == 0x1D0);
	static_assert(offsetof(TESEffectShader, holesTexture) == 0x1E0);
	static_assert(offsetof(TESEffectShader, fillTextureEffectPaletteTexture) == 0x1F0);
	static_assert(offsetof(TESEffectShader, particleShaderPaletteTexture) == 0x200);
	static_assert(sizeof(TESEffectShader) == 0x220);
}
