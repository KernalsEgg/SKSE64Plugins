#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/C/Color.h"
#include "Shared/Skyrim/N/NiPoint3.h"
#include "Shared/Skyrim/N/NiPointer.h"
#include "Shared/Skyrim/T/TESAttackDamageForm.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Skyrim/T/TESFullName.h"
#include "Shared/Skyrim/T/TESTexture.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSMaterialType;
	class BGSSoundDescriptorForm;
	class NiTexture;
	class SpellItem;
	class TESImageSpace;

	class TESWaterForm :
		public TESForm,            // 0
		public TESFullName,        // 20
		public TESAttackDamageForm // 30
	{
	public:
		enum class Flags : std::uint8_t
		{
			kNone                  = 0,
			kCausesDamagePerSecond = 1U << 0,
			kEnableFlowmap         = 1U << 3, // Noise Properties
			kBlendNormals          = 1U << 4  // Noise Properties
		};
		static_assert(sizeof(Flags) == 0x1);

		struct ColorProperties
		{
		public:
			// Member variables
			Color shallowColor;    // 0
			Color deepColor;       // 4
			Color reflectionColor; // 8
		};
		static_assert(offsetof(ColorProperties, shallowColor) == 0x0);
		static_assert(offsetof(ColorProperties, deepColor) == 0x4);
		static_assert(offsetof(ColorProperties, reflectionColor) == 0x8);
		static_assert(sizeof(ColorProperties) == 0xC);

		struct DisplacementSimulator
		{
		public:
			// Member variables
			float startingSize; // 0
			float force;        // 4
			float velocity;     // 8
			float falloff;      // C
			float dampner;      // 10
		};
		static_assert(offsetof(DisplacementSimulator, startingSize) == 0x0);
		static_assert(offsetof(DisplacementSimulator, force) == 0x4);
		static_assert(offsetof(DisplacementSimulator, velocity) == 0x8);
		static_assert(offsetof(DisplacementSimulator, falloff) == 0xC);
		static_assert(offsetof(DisplacementSimulator, dampner) == 0x10);
		static_assert(sizeof(DisplacementSimulator) == 0x14);

		struct DepthProperties
		{
		public:
			// Member variables
			float reflections;      // 0
			float refraction;       // 4
			float normals;          // 8
			float specularLighting; // C
		};
		static_assert(offsetof(DepthProperties, reflections) == 0x0);
		static_assert(offsetof(DepthProperties, refraction) == 0x4);
		static_assert(offsetof(DepthProperties, normals) == 0x8);
		static_assert(offsetof(DepthProperties, specularLighting) == 0xC);
		static_assert(sizeof(DepthProperties) == 0x10);

		// Override
		virtual ~TESWaterForm() override; // 0

		// Override (TESForm)
		virtual void InitializeData() override;                                                                                                                     // 4
		virtual bool Load(TESFile* file) override;                                                                                                                  // 6
		virtual void Unknown13(TESForm*) override;                                                                                                                  // 13
		virtual void Unknown1B(TESForm*) override;                                                                                                                  // 1B
		virtual bool Activate(TESObjectREFR* target, TESObjectREFR* activator, bool deferred, TESBoundObject* boundObject, std::int32_t boundObjectCount) override; // 37

		// Member variables
		std::uint64_t                             unknown40;                      // 40
		std::uint64_t                             unknown48;                      // 48
		std::uint64_t                             unknown50;                      // 50
		std::uint64_t                             unknown58;                      // 58
		std::uint64_t                             unknown60;                      // 60
		std::uint64_t                             unknown68;                      // 68
		std::uint64_t                             unknown70;                      // 70
		TESTexture                                noiseLayerTextures[4];          // 78, Noise Properties
		std::uint8_t                              opacity;                        // B8, Water Properties
		Utility::Enumeration<Flags, std::uint8_t> waterFormFlags;                 // B9
		std::uint8_t                              paddingBA;                      // BA
		std::uint32_t                             paddingBC;                      // BC
		BGSMaterialType*                          material;                       // C0, Water Properties
		BGSSoundDescriptorForm*                   openSound;                      // C8, Water Properties
		std::uint64_t                             unknownD0;                      // D0
		std::uint64_t                             unknownD8;                      // D8
		float                                     sunSpecularPower;               // E0, Specular Properties
		float                                     reflectivityAmount;             // E4, Water Properties
		float                                     fresnelAmount;                  // E8, Water Properties
		std::uint32_t                             unknownEC;                      // EC
		float                                     aboveWaterFogDistanceNearPlane; // F0, Fog Properties
		float                                     aboveWaterFogDistanceFarPlane;  // F4, Fog Properties
		ColorProperties                           colorProperties;                // F8
		std::uint32_t                             unknown104;                     // 104
		std::uint64_t                             unknown108;                     // 108
		std::uint64_t                             unknown110;                     // 110
		DisplacementSimulator                     displacementSimulator;          // 118, Water Properties
		std::uint32_t                             unknown12C;                     // 12C
		float                                     noiseFalloff;                   // 130, Noise Properties
		float                                     noiseLayerWindDirections[3];    // 134, Noise Properties
		float                                     noiseLayerWindSpeeds[3];        // 140, Noise Properties
		std::uint32_t                             unknown14C;                     // 14C
		std::uint32_t                             unknown150;                     // 150
		float                                     aboveWaterFogAmount;            // 154, Fog Properties
		std::uint32_t                             unknown158;                     // 158
		float                                     underWaterFogAmount;            // 15C, Fog Properties
		float                                     underWaterFogDistanceNearPlane; // 160, Fog Properties
		float                                     underWaterFogDistanceFarPlane;  // 164, Fog Properties
		float                                     refractionMagnitude;            // 168, Water Properties
		float                                     specularPower;                  // 16C, Specular Properties
		std::uint32_t                             unknown170;                     // 170
		float                                     specularRadius;                 // 174, Specular Properties
		float                                     specularBrightness;             // 178, Specular Properties
		float                                     noiseLayerUVScales[3];          // 17C, Noise Properties
		float                                     noiseLayerAmplitudeScales[3];   // 188, Noise Properties
		float                                     reflectionMagnitude;            // 194, Water Properties
		float                                     sunSparkleMagnitude;            // 198, Specular Properties
		float                                     sunSpecularMagnitude;           // 19C, Specular Properties
		DepthProperties                           depthProperties;                // 1A0
		float                                     sunSparklePower;                // 1B0, Specular Properties
		float                                     flowmapScale;                   // 1B4, Noise Properties
		std::uint64_t                             unknown1B8;                     // 1B8
		std::uint64_t                             unknown1C0;                     // 1C0
		std::uint64_t                             unknown1C8;                     // 1C8
		std::uint64_t                             unknown1D0;                     // 1D0
		std::uint64_t                             unknown1D8;                     // 1D8
		std::uint64_t                             unknown1E0;                     // 1E0
		std::uint64_t                             unknown1E8;                     // 1E8
		std::uint64_t                             unknown1F0;                     // 1F0
		SpellItem*                                contactSpellItem;               // 1F8
		NiPointer<NiTexture>                      noiseLayerTextureData[4];       // 200, Noise Properties
		std::uint64_t                             unknown220;                     // 220
		std::uint64_t                             unknown228;                     // 228
		std::uint64_t                             unknown230;                     // 230
		std::uint64_t                             unknown238;                     // 238
		TESImageSpace*                            imageSpaceModifier;             // 240
		NiPoint3                                  linearVelocity;                 // 248, Water Properties
		NiPoint3                                  angularVelocity;                // 254, Water Properties
	};
	static_assert(offsetof(TESWaterForm, noiseLayerTextures) == 0x78);
	static_assert(offsetof(TESWaterForm, opacity) == 0xB8);
	static_assert(offsetof(TESWaterForm, waterFormFlags) == 0xB9);
	static_assert(offsetof(TESWaterForm, material) == 0xC0);
	static_assert(offsetof(TESWaterForm, openSound) == 0xC8);
	static_assert(offsetof(TESWaterForm, sunSpecularPower) == 0xE0);
	static_assert(offsetof(TESWaterForm, reflectivityAmount) == 0xE4);
	static_assert(offsetof(TESWaterForm, fresnelAmount) == 0xE8);
	static_assert(offsetof(TESWaterForm, aboveWaterFogDistanceNearPlane) == 0xF0);
	static_assert(offsetof(TESWaterForm, aboveWaterFogDistanceFarPlane) == 0xF4);
	static_assert(offsetof(TESWaterForm, colorProperties) == 0xF8);
	static_assert(offsetof(TESWaterForm, displacementSimulator) == 0x118);
	static_assert(offsetof(TESWaterForm, noiseFalloff) == 0x130);
	static_assert(offsetof(TESWaterForm, noiseLayerWindDirections) == 0x134);
	static_assert(offsetof(TESWaterForm, noiseLayerWindSpeeds) == 0x140);
	static_assert(offsetof(TESWaterForm, aboveWaterFogAmount) == 0x154);
	static_assert(offsetof(TESWaterForm, underWaterFogAmount) == 0x15C);
	static_assert(offsetof(TESWaterForm, underWaterFogDistanceNearPlane) == 0x160);
	static_assert(offsetof(TESWaterForm, underWaterFogDistanceFarPlane) == 0x164);
	static_assert(offsetof(TESWaterForm, refractionMagnitude) == 0x168);
	static_assert(offsetof(TESWaterForm, specularPower) == 0x16C);
	static_assert(offsetof(TESWaterForm, specularRadius) == 0x174);
	static_assert(offsetof(TESWaterForm, specularBrightness) == 0x178);
	static_assert(offsetof(TESWaterForm, noiseLayerUVScales) == 0x17C);
	static_assert(offsetof(TESWaterForm, noiseLayerAmplitudeScales) == 0x188);
	static_assert(offsetof(TESWaterForm, reflectionMagnitude) == 0x194);
	static_assert(offsetof(TESWaterForm, sunSparkleMagnitude) == 0x198);
	static_assert(offsetof(TESWaterForm, sunSpecularMagnitude) == 0x19C);
	static_assert(offsetof(TESWaterForm, depthProperties) == 0x1A0);
	static_assert(offsetof(TESWaterForm, sunSparklePower) == 0x1B0);
	static_assert(offsetof(TESWaterForm, flowmapScale) == 0x1B4);
	static_assert(offsetof(TESWaterForm, contactSpellItem) == 0x1F8);
	static_assert(offsetof(TESWaterForm, noiseLayerTextureData) == 0x200);
	static_assert(offsetof(TESWaterForm, imageSpaceModifier) == 0x240);
	static_assert(offsetof(TESWaterForm, linearVelocity) == 0x248);
	static_assert(offsetof(TESWaterForm, angularVelocity) == 0x254);
	static_assert(sizeof(TESWaterForm) == 0x260);
}
