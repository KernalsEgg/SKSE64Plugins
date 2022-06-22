#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSCoreTypes.h"
#include "Shared/Skyrim/B/BSSimpleList.h"
#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/C/Color.h"
#include "Shared/Skyrim/D/DirectionalAmbientLighting.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Skyrim/T/TESModel.h"
#include "Shared/Skyrim/T/TESTexture1024.h"
#include "Shared/Utility/Convert.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSLensFlare;
	class BGSReferenceEffect;
	class BGSShaderParticleGeometryData;
	class BGSVolumetricLighting;
	class TESImageSpace;
	class TESObjectSTAT;

	class TESWeather :
		public TESForm // 0
	{
	public:
		enum class Layer
		{
			kTotal = 32
		};

		enum class Time
		{
			kSunrise = 0,
			kDay     = 1,
			kSunset  = 2,
			kNight   = 3,
			kTotal   = 4
		};

		enum class Flags : std::uint8_t
		{
			kNone                     = 0,
			kPleasant                 = 1U << 0, // Precipitation, Weather Classification
			kCloudy                   = 1U << 1, // Precipitation, Weather Classification
			kRainy                    = 1U << 2, // Precipitation, Weather Classification
			kSnow                     = 1U << 3, // Precipitation, Weather Classification
			kAuroraAlwaysVisible      = 1U << 4, // Effects, Visual Effect
			kAuroraFollowsSunPosition = 1U << 5  // Effects, Visual Effect
		};
		static_assert(sizeof(Flags) == 0x1);

		enum class Type
		{
			kSkyUpper        = 0,
			kFogNear         = 1,
			kAmbient         = 3,
			kSunlight        = 4,
			kSun             = 5,
			kStars           = 6,
			kSkyLower        = 7,
			kHorizon         = 8,
			kEffectLighting  = 9,
			kCloudLODDiffuse = 10,
			kCloudLODAmbient = 11,
			kFogFar          = 12,
			kSkyStatics      = 13,
			kWaterMultiplier = 14,
			kSunGlare        = 15,
			kMoonGlare       = 16,
			kTotal           = 17
		};

		struct Color3
		{
		public:
			// Member variables
			std::uint8_t red;   // 0
			std::uint8_t green; // 1
			std::uint8_t blue;  // 2
		};
		static_assert(offsetof(Color3, red) == 0x0);
		static_assert(offsetof(Color3, green) == 0x1);
		static_assert(offsetof(Color3, blue) == 0x2);
		static_assert(sizeof(Color3) == 0x3);

		struct FogDistance
		{
		public:
			// Member variables
			float dayNear;    // 0
			float dayFar;     // 4
			float nightNear;  // 8
			float nightFar;   // C
			float dayPower;   // 10
			float nightPower; // 14
			float dayMax;     // 18
			float nightMax;   // 1C
		};
		static_assert(offsetof(FogDistance, dayNear) == 0x0);
		static_assert(offsetof(FogDistance, dayFar) == 0x4);
		static_assert(offsetof(FogDistance, nightNear) == 0x8);
		static_assert(offsetof(FogDistance, nightFar) == 0xC);
		static_assert(offsetof(FogDistance, dayPower) == 0x10);
		static_assert(offsetof(FogDistance, nightPower) == 0x14);
		static_assert(offsetof(FogDistance, dayMax) == 0x18);
		static_assert(offsetof(FogDistance, nightMax) == 0x1C);
		static_assert(sizeof(FogDistance) == 0x20);

		struct Sound
		{
		public:
			enum class Type : std::uint32_t
			{
				kDefault       = 0,
				kPrecipitation = 1,
				kWind          = 2,
				kThunder       = 3
			};
			static_assert(sizeof(Type) == 0x4);

			// Member variables
			FormID                                    formID; // 0
			Utility::Enumeration<Type, std::uint32_t> type;   // 4
		};
		static_assert(offsetof(Sound, formID) == 0x0);
		static_assert(offsetof(Sound, type) == 0x4);
		static_assert(sizeof(Sound) == 0x8);

		// Override
		virtual ~TESWeather() override; // 0

		// Override (TESForm)
		virtual void InitializeData() override;    // 4
		virtual void ClearData() override;         // 5
		virtual void Unknown6(TESForm*) override;  // 6
		virtual void Unknown13(TESForm*) override; // 13

		// Member variables
		TESTexture1024                            cloudTextures[Utility::ToUnderlying(Layer::kTotal)];                                    // 20, General, Cloud Textures
		std::int8_t                               cloudSpeedY[Utility::ToUnderlying(Layer::kTotal)];                                      // 220, General, Cloud Textures
		std::int8_t                               cloudSpeedX[Utility::ToUnderlying(Layer::kTotal)];                                      // 240, General, Cloud Textures
		Color                                     cloudColors[Utility::ToUnderlying(Layer::kTotal)][Utility::ToUnderlying(Time::kTotal)]; // 260
		float                                     cloudAlpha[Utility::ToUnderlying(Layer::kTotal)][Utility::ToUnderlying(Time::kTotal)];  // 460, General, Cloud Textures
		std::uint32_t                             disabledCloudLayers;                                                                    // 660, General, Cloud Textures (bitfield)
		std::uint8_t                              windSpeed;                                                                              // 664, General
		std::uint8_t                              unknown665;                                                                             // 665
		std::uint8_t                              unknown666;                                                                             // 666
		std::uint8_t                              transitionDelta;                                                                        // 667, General
		std::uint8_t                              sunGlare;                                                                               // 668, General
		std::uint8_t                              sunDamage;                                                                              // 669, General
		std::uint8_t                              precipitationBeginFadeIn;                                                               // 66A, Precipitation, Precipitation
		std::uint8_t                              precipitationEndFadeOut;                                                                // 66B, Precipitation, Precipitation
		std::uint8_t                              thunderLightningBeginFadeIn;                                                            // 66C, Precipitation, Thunder/Lightning
		std::uint8_t                              thunderLightningEndFadeOut;                                                             // 66D, Precipitation, Thunder/Lightning
		std::uint8_t                              thunderLightningFrequency;                                                              // 66E, Precipitation, Thunder/Lightning
		Utility::Enumeration<Flags, std::uint8_t> weatherFlags;                                                                           // 66F
		Color3                                    lightningColor;                                                                         // 670, Precipitation, Lightning Color
		std::uint8_t                              visualEffectBegin;                                                                      // 673, Effects, Visual Effect
		std::uint8_t                              visualEffectEnd;                                                                        // 674, Effects, Visual Effect
		std::uint8_t                              windDirection;                                                                          // 675, General
		std::uint8_t                              windDirectionRange;                                                                     // 676, General
		std::uint8_t                              unknown677;                                                                             // 677
		FogDistance                               fogDistance;                                                                            // 678, General, Fog Distance
		Color                                     colors[Utility::ToUnderlying(Type::kTotal)][Utility::ToUnderlying(Time::kTotal)];       // 698
		BSSimpleList<Sound*>                      sounds;                                                                                 // 7A8
		BSTArray<TESObjectSTAT*>                  skyStatics;                                                                             // 7B8, Effects
		std::uint32_t                             cloudLayerCount;                                                                        // 7D0
		std::uint32_t                             padding7D4;                                                                             // 7D4
		TESImageSpace*                            imageSpaces[Utility::ToUnderlying(Time::kTotal)];                                       // 7D8, General
		DirectionalAmbientLighting                directionalAmbient[Utility::ToUnderlying(Time::kTotal)];                                // 7F8, General
		TESModel                                  aurora;                                                                                 // 878, Effects
		BGSLensFlare*                             sunGlareLensFlare;                                                                      // 8A0, General
		BGSVolumetricLighting*                    volumetricLighting[Utility::ToUnderlying(Time::kTotal)];                                // 8A8, General
		BGSShaderParticleGeometryData*            precipitation;                                                                          // 8C8, Precipitation, Precipitation
		BGSReferenceEffect*                       visualEffect;                                                                           // 8D0, Visual Effect
	};
	static_assert(offsetof(TESWeather, cloudTextures) == 0x20);
	static_assert(offsetof(TESWeather, cloudSpeedY) == 0x220);
	static_assert(offsetof(TESWeather, cloudSpeedX) == 0x240);
	static_assert(offsetof(TESWeather, cloudColors) == 0x260);
	static_assert(offsetof(TESWeather, cloudAlpha) == 0x460);
	static_assert(offsetof(TESWeather, disabledCloudLayers) == 0x660);
	static_assert(offsetof(TESWeather, windSpeed) == 0x664);
	static_assert(offsetof(TESWeather, transitionDelta) == 0x667);
	static_assert(offsetof(TESWeather, sunGlare) == 0x668);
	static_assert(offsetof(TESWeather, sunDamage) == 0x669);
	static_assert(offsetof(TESWeather, precipitationBeginFadeIn) == 0x66A);
	static_assert(offsetof(TESWeather, precipitationEndFadeOut) == 0x66B);
	static_assert(offsetof(TESWeather, thunderLightningBeginFadeIn) == 0x66C);
	static_assert(offsetof(TESWeather, thunderLightningEndFadeOut) == 0x66D);
	static_assert(offsetof(TESWeather, thunderLightningFrequency) == 0x66E);
	static_assert(offsetof(TESWeather, weatherFlags) == 0x66F);
	static_assert(offsetof(TESWeather, lightningColor) == 0x670);
	static_assert(offsetof(TESWeather, visualEffectBegin) == 0x673);
	static_assert(offsetof(TESWeather, visualEffectEnd) == 0x674);
	static_assert(offsetof(TESWeather, windDirection) == 0x675);
	static_assert(offsetof(TESWeather, windDirectionRange) == 0x676);
	static_assert(offsetof(TESWeather, fogDistance) == 0x678);
	static_assert(offsetof(TESWeather, colors) == 0x698);
	static_assert(offsetof(TESWeather, sounds) == 0x7A8);
	static_assert(offsetof(TESWeather, skyStatics) == 0x7B8);
	static_assert(offsetof(TESWeather, cloudLayerCount) == 0x7D0);
	static_assert(offsetof(TESWeather, padding7D4) == 0x7D4);
	static_assert(offsetof(TESWeather, imageSpaces) == 0x7D8);
	static_assert(offsetof(TESWeather, directionalAmbient) == 0x7F8);
	static_assert(offsetof(TESWeather, aurora) == 0x878);
	static_assert(offsetof(TESWeather, sunGlareLensFlare) == 0x8A0);
	static_assert(offsetof(TESWeather, volumetricLighting) == 0x8A8);
	static_assert(offsetof(TESWeather, precipitation) == 0x8C8);
	static_assert(offsetof(TESWeather, visualEffect) == 0x8D0);
	static_assert(sizeof(TESWeather) == 0x8D8);
}
