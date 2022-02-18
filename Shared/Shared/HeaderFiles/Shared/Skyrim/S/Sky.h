#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSPointerHandle.h"
#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/N/NiColor.h"
#include "Shared/Skyrim/N/NiPointer.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class Atmosphere;
	class BSMultiBoundNode;
	class Clouds;
	class Moon;
	class NiNode;
	class NiTexture;
	class Precipitation;
	class ReferenceEffect;
	class Stars;
	class Sun;
	class TESClimate;
	class TESRegion;
	class TESWeather;

	class Sky
	{
	public:
		enum class Mode : std::uint32_t
		{
			kNone        = 0,
			kInterior    = 1,
			kSkyDomeOnly = 2,
			kFull        = 3
		};
		static_assert(sizeof(Mode) == 0x4);

		struct DirectionalAmbientLighting
		{
		public:
			struct Axis
			{
			public:
				NiColor positive; // 0
				NiColor negative; // C
			};
			static_assert(offsetof(Axis, positive) == 0x0);
			static_assert(offsetof(Axis, negative) == 0xC);
			static_assert(sizeof(Axis) == 0x18);

			Axis    x;                    // 0
			Axis    y;                    // 18
			Axis    z;                    // 30
			NiColor specular;             // 48
			float   specularFresnelPower; // 54
		};
		static_assert(offsetof(DirectionalAmbientLighting, x) == 0x0);
		static_assert(offsetof(DirectionalAmbientLighting, y) == 0x18);
		static_assert(offsetof(DirectionalAmbientLighting, z) == 0x30);
		static_assert(offsetof(DirectionalAmbientLighting, specular) == 0x48);
		static_assert(offsetof(DirectionalAmbientLighting, specularFresnelPower) == 0x54);
		static_assert(sizeof(DirectionalAmbientLighting) == 0x58);

		// Add
		virtual ~Sky(); // 0

		// Non-member functions
		static Sky* GetSingleton();

		// Member variables
		NiPointer<BSMultiBoundNode>               root;                       // 8
		NiPointer<NiNode>                         moonsRoot;                  // 10
		NiPointer<NiNode>                         auroraRoot;                 // 18
		std::int64_t                              unknown20;                  // 20
		std::int64_t                              unknown28;                  // 28
		ObjectReferenceHandle                     currentRoom;                // 30
		ObjectReferenceHandle                     previousRoom;               // 34
		std::int64_t                              unknown38;                  // 38
		TESClimate*                               currentClimate;             // 40
		TESWeather*                               currentWeather;             // 48
		TESWeather*                               previousWeather;            // 50
		TESWeather*                               defaultWeather;             // 58
		TESWeather*                               overrideWeather;            // 60
		TESRegion*                                region;                     // 68
		Atmosphere*                               atmosphere;                 // 70
		Stars*                                    stars;                      // 78
		Sun*                                      sun;                        // 80
		Clouds*                                   clouds;                     // 88
		Moon*                                     masser;                     // 90
		Moon*                                     secunda;                    // 98
		Precipitation*                            precipitation;              // A0
		std::int64_t                              unknownA8;                  // A8
		std::int64_t                              unknownB0;                  // B0
		std::int64_t                              unknownB8;                  // B8
		std::int64_t                              unknownC0;                  // C0
		std::int64_t                              unknownC8;                  // C8
		std::int64_t                              unknownD0;                  // D0
		std::int64_t                              unknownD8;                  // D8
		std::int64_t                              unknownE0;                  // E0
		std::int64_t                              unknownE8;                  // E8
		std::int64_t                              unknownF0;                  // F0
		std::int64_t                              unknownF8;                  // F8
		std::int64_t                              unknown100;                 // 100
		std::int64_t                              unknown108;                 // 108
		std::int64_t                              unknown110;                 // 110
		std::int64_t                              unknown118;                 // 118
		std::int64_t                              unknown120;                 // 120
		std::int64_t                              unknown128;                 // 128
		std::int64_t                              unknown130;                 // 130
		std::int64_t                              unknown138;                 // 138
		std::int64_t                              unknown140;                 // 140
		std::int64_t                              unknown148;                 // 148
		std::int64_t                              unknown150;                 // 150
		std::int64_t                              unknown158;                 // 158
		std::int64_t                              unknown160;                 // 160
		std::int64_t                              unknown168;                 // 168
		std::int64_t                              unknown170;                 // 170
		std::int64_t                              unknown178;                 // 178
		std::int64_t                              unknown180;                 // 180
		std::int64_t                              unknown188;                 // 188
		std::int64_t                              unknown190;                 // 190
		std::int64_t                              unknown198;                 // 198
		std::int64_t                              unknown1A0;                 // 1A0
		std::int64_t                              unknown1A8;                 // 1A8
		float                                     currentGameHour;            // 1B0
		float                                     lastWeatherUpdate;          // 1B4
		float                                     currentWeatherPercentage;   // 1B8
		Utility::Enumeration<Mode, std::uint32_t> mode;                       // 1BC
		std::int64_t                              unknown1C0;                 // 1C0
		std::int64_t                              unknown1C8;                 // 1C8
		std::int64_t                              unknown1D0;                 // 1D0
		float                                     lastMoonPhaseUpdate;        // 1D8
		std::int32_t                              unknown1DC;                 // 1DC
		std::int64_t                              unknown1E0;                 // 1E0
		std::int64_t                              unknown1E8;                 // 1E8
		std::int64_t                              unknown1F0;                 // 1F0
		std::int64_t                              unknown1F8;                 // 1F8
		DirectionalAmbientLighting                directionalAmbientLighting; // 200
		float                                     auroraBeginFadeIn;          // 258
		float                                     auroraEndFadeIn;            // 25C
		float                                     auroraBeginFadeOut;         // 260
		float                                     auroraEndFadeOut;           // 264
		NiPointer<ReferenceEffect>                currentReferenceEffect;     // 268
		NiPointer<ReferenceEffect>                previousReferenceEffect;    // 270
		std::int64_t                              unknown278;                 // 278
		BSTArray<NiPointer<NiTexture>>            cloudTextures;              // 280
		BSTArray<NiPointer<NiTexture>>            worldMapCloudTextures;      // 298
		std::int64_t                              unknown2B0;                 // 2B0
		std::int64_t                              unknown2B8;                 // 2B8
		std::int64_t                              unknown2C0;                 // 2C0
	};
	static_assert(offsetof(Sky, root) == 0x8);
	static_assert(offsetof(Sky, moonsRoot) == 0x10);
	static_assert(offsetof(Sky, auroraRoot) == 0x18);
	static_assert(offsetof(Sky, currentRoom) == 0x30);
	static_assert(offsetof(Sky, previousRoom) == 0x34);
	static_assert(offsetof(Sky, currentClimate) == 0x40);
	static_assert(offsetof(Sky, currentWeather) == 0x48);
	static_assert(offsetof(Sky, previousWeather) == 0x50);
	static_assert(offsetof(Sky, defaultWeather) == 0x58);
	static_assert(offsetof(Sky, overrideWeather) == 0x60);
	static_assert(offsetof(Sky, region) == 0x68);
	static_assert(offsetof(Sky, atmosphere) == 0x70);
	static_assert(offsetof(Sky, stars) == 0x78);
	static_assert(offsetof(Sky, sun) == 0x80);
	static_assert(offsetof(Sky, clouds) == 0x88);
	static_assert(offsetof(Sky, masser) == 0x90);
	static_assert(offsetof(Sky, secunda) == 0x98);
	static_assert(offsetof(Sky, precipitation) == 0xA0);
	static_assert(offsetof(Sky, currentGameHour) == 0x1B0);
	static_assert(offsetof(Sky, lastWeatherUpdate) == 0x1B4);
	static_assert(offsetof(Sky, currentWeatherPercentage) == 0x1B8);
	static_assert(offsetof(Sky, mode) == 0x1BC);
	static_assert(offsetof(Sky, lastMoonPhaseUpdate) == 0x1D8);
	static_assert(offsetof(Sky, directionalAmbientLighting) == 0x200);
	static_assert(offsetof(Sky, auroraBeginFadeIn) == 0x258);
	static_assert(offsetof(Sky, auroraEndFadeIn) == 0x25C);
	static_assert(offsetof(Sky, auroraBeginFadeOut) == 0x260);
	static_assert(offsetof(Sky, auroraEndFadeOut) == 0x264);
	static_assert(offsetof(Sky, currentReferenceEffect) == 0x268);
	static_assert(offsetof(Sky, previousReferenceEffect) == 0x270);
	static_assert(offsetof(Sky, cloudTextures) == 0x280);
	static_assert(offsetof(Sky, worldMapCloudTextures) == 0x298);
	static_assert(sizeof(Sky) == 0x2C8);
}
