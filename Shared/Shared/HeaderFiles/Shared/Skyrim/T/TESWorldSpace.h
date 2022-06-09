#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSCoreTypes.h"
#include "Shared/Skyrim/B/BSString.h"
#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/B/BSTHashMap.h"
#include "Shared/Skyrim/N/NiPoint2.h"
#include "Shared/Skyrim/N/NiPointer.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Skyrim/T/TESFullName.h"
#include "Shared/Skyrim/T/TESModel.h"
#include "Shared/Skyrim/T/TESTexture.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSEncounterZone;
	class BGSLightingTemplate;
	class BGSLocation;
	class BGSMusicType;
	class BGSTerrainManager;
	class TESClimate;
	class TESObjectCELL;
	class TESObjectREFR;
	class TESWaterForm;

	struct CellID
	{
	public:
		constexpr CellID() noexcept              = default;
		constexpr CellID(const CellID&) noexcept = default;
		constexpr CellID(CellID&&) noexcept      = default;

		constexpr ~CellID() noexcept = default;

		constexpr CellID& operator=(const CellID&) noexcept = default;
		constexpr CellID& operator=(CellID&&) noexcept = default;

		constexpr CellID(std::int16_t x, std::int16_t y) noexcept :
			x(x), y(y)
		{
		}

		friend constexpr bool operator==(const CellID& left, const CellID& right) noexcept { return left.x == right.x && left.y == right.y; }
		friend constexpr bool operator!=(const CellID& left, const CellID& right) noexcept { return !(left == right); }

		// Member variables
		std::int16_t x{ 0 }; // 0
		std::int16_t y{ 0 }; // 2
	};
	static_assert(offsetof(CellID, x) == 0x0);
	static_assert(offsetof(CellID, y) == 0x2);
	static_assert(sizeof(CellID) == 0x4);

	class BGSLargeRefData
	{
	public:
		// Member variables
		BSTHashMap<CellID, FormID*> largeReferences;       // 0
		BSTHashMap<FormID, CellID>  cells;                 // 30
		BSTHashMap<CellID, FormID*> largeReferencesToLoad; // 60
	};
	static_assert(offsetof(BGSLargeRefData, largeReferences) == 0x0);
	static_assert(offsetof(BGSLargeRefData, cells) == 0x30);
	static_assert(offsetof(BGSLargeRefData, largeReferencesToLoad) == 0x60);
	static_assert(sizeof(BGSLargeRefData) == 0x90);

	class TESWorldSpace :
		public TESForm,     // 0
		public TESFullName, // 20
		public TESModel     // 30
	{
	public:
		enum class RecordFlags : std::uint32_t
		{
			kCantWait = 1U << 19
		};
		static_assert(sizeof(RecordFlags) == 0x4);

		enum class Flags : std::uint8_t
		{
			kNone                   = 0,
			kSmallWorld             = 1U << 0,
			kCantFastTravelFromHere = 1U << 1,
			kNoLODWater             = 1U << 3,
			kNoLandscape            = 1U << 4,
			kNoSky                  = 1U << 5,
			kFixedDimensions        = 1U << 6,
			kNoGrass                = 1U << 7
		};
		static_assert(sizeof(Flags) == 0x1);

		enum class UseFlags : std::uint16_t
		{
			kNone           = 0,
			kUseLandData    = 1U << 0,
			kUseLODData     = 1U << 1,
			kDontUseMapData = 1U << 2,
			kUseWaterData   = 1U << 3,
			kUseClimateData = 1U << 4,
			kUseSkyCell     = 1U << 6
		};
		static_assert(sizeof(UseFlags) == 0x2);

		struct ClimateData
		{
		public:
			// Member variables
			TESClimate* climate; // 0
		};
		static_assert(offsetof(ClimateData, climate) == 0x0);
		static_assert(sizeof(ClimateData) == 0x8);

		struct CenterCell
		{
		public:
			// Member variables
			std::int16_t x; // 0
			std::int16_t y; // 2
		};
		static_assert(offsetof(CenterCell, x) == 0x0);
		static_assert(offsetof(CenterCell, y) == 0x2);
		static_assert(sizeof(CenterCell) == 0x4);

		struct WaterData
		{
		public:
			// Member variables
			TESWaterForm* water; // 0
		};
		static_assert(offsetof(WaterData, water) == 0x0);
		static_assert(sizeof(WaterData) == 0x8);

#pragma pack(push, 1)
		struct LODData
		{
		public:
			// Member variables
			TESWaterForm* lodWaterType;   // 0
			float         lodWaterHeight; // 8
		};
		static_assert(offsetof(LODData, lodWaterType) == 0x0);
		static_assert(offsetof(LODData, lodWaterHeight) == 0x8);
		static_assert(sizeof(LODData) == 0xC);
#pragma pack(pop)

		struct WorldMapData
		{
		public:
			struct UsableDimensions
			{
			public:
				// Member variables
				std::uint32_t x; // 0
				std::uint32_t y; // 4
			};
			static_assert(offsetof(UsableDimensions, x) == 0x0);
			static_assert(offsetof(UsableDimensions, y) == 0x4);
			static_assert(sizeof(UsableDimensions) == 0x8);

			struct CellCoordinates
			{
			public:
				// Member variables
				std::int16_t northWestCellX; // 0
				std::int16_t northWestCellY; // 2
				std::int16_t southEastCellX; // 4
				std::int16_t southEastCellY; // 6
			};
			static_assert(offsetof(CellCoordinates, northWestCellX) == 0x0);
			static_assert(offsetof(CellCoordinates, northWestCellY) == 0x2);
			static_assert(offsetof(CellCoordinates, southEastCellX) == 0x4);
			static_assert(offsetof(CellCoordinates, southEastCellY) == 0x6);
			static_assert(sizeof(CellCoordinates) == 0x8);

			struct CameraData
			{
			public:
				// Member variables
				float minimumHeight; // 0
				float maximumHeight; // 4
				float initialPitch;  // 8
			};
			static_assert(offsetof(CameraData, minimumHeight) == 0x0);
			static_assert(offsetof(CameraData, maximumHeight) == 0x4);
			static_assert(offsetof(CameraData, initialPitch) == 0x8);
			static_assert(sizeof(CameraData) == 0xC);

			// Member variables
			UsableDimensions usableDimensions; // 0
			CellCoordinates  cellCoordinates;  // 8
			CameraData       cameraData;       // 10
		};
		static_assert(offsetof(WorldMapData, usableDimensions) == 0x0);
		static_assert(offsetof(WorldMapData, cellCoordinates) == 0x8);
		static_assert(offsetof(WorldMapData, cameraData) == 0x10);
		static_assert(sizeof(WorldMapData) == 0x1C);

		struct WorldMapOffsetData
		{
		public:
			// Member variables
			float worldMapScale; // 0
			float cellXOffset;   // 4
			float cellYOffset;   // 8
			float cellZOffset;   // C
		};
		static_assert(offsetof(WorldMapOffsetData, worldMapScale) == 0x0);
		static_assert(offsetof(WorldMapOffsetData, cellXOffset) == 0x4);
		static_assert(offsetof(WorldMapOffsetData, cellYOffset) == 0x8);
		static_assert(offsetof(WorldMapOffsetData, cellZOffset) == 0xC);
		static_assert(sizeof(WorldMapOffsetData) == 0x10);

		struct LandData
		{
		public:
			// Member variables
			float defaultLandHeight;  // 0
			float defaultWaterHeight; // 4
		};
		static_assert(offsetof(LandData, defaultLandHeight) == 0x0);
		static_assert(offsetof(LandData, defaultWaterHeight) == 0x4);
		static_assert(sizeof(LandData) == 0x8);

		// Override
		virtual ~TESWorldSpace() override; // 0

		// Override (TESForm)
		virtual void        Unknown4(TESForm*) override;                // 4
		virtual void        Unknown5(TESForm*) override;                // 5
		virtual void        Unknown6(TESForm*) override;                // 6
		virtual void        Unknown7(TESForm*) override;                // 7
		virtual void        Unknown9(TESForm*) override;                // 9
		virtual void        UnknownC(TESForm*) override;                // C
		virtual void        Unknown13(TESForm*) override;               // 13
		virtual const char* GetEditorID() const override;               // 32
		virtual bool        SetEditorID(const char* editorID) override; // 33
		virtual void        Unknown34(TESForm*) override;               // 34
		virtual void        Unknown36(TESForm*) override;               // 36

		// Member variables
		BSTHashMap<CellID, TESObjectCELL*>                            cells;                      // 58
		TESObjectCELL*                                                persistentCell;             // 88
		BGSTerrainManager*                                            terrainManager;             // 90
		ClimateData                                                   climateData;                // 98
		Utility::Enumeration<Flags, std::uint8_t>                     worldSpaceFlags;            // A0
		std::uint8_t                                                  unknownA1;                  // A1
		Utility::Enumeration<UseFlags, std::uint16_t>                 useFlags;                   // A2
		CenterCell                                                    centerCell;                 // A4
		BSTHashMap<std::uint32_t, BSTArray<NiPointer<TESObjectREFR>>> fixedPersistentReferences;  // A8
		BSTArray<NiPointer<TESObjectREFR>>                            mobilePersistentReferences; // D8
		std::uint64_t                                                 unknownF0;                  // F0
		TESObjectCELL*                                                skyCell;                    // F8
		BSTHashMap<FormID, BGSLocation*>                              locations;                  // 100
		std::uint64_t                                                 unknown130;                 // 130
		std::uint64_t                                                 unknown138;                 // 138
		std::uint64_t                                                 unknown140;                 // 140
		std::uint64_t                                                 unknown148;                 // 148
		std::uint64_t                                                 unknown150;                 // 150
		TESWorldSpace*                                                parentWorldSpace;           // 158
		BGSLightingTemplate*                                          interiorLighting;           // 160
		WaterData                                                     waterData;                  // 168
		LODData                                                       lodData;                    // 170
		std::uint32_t                                                 padding17C;                 // 17C
		std::uint64_t                                                 unknown180;                 // 180
		WorldMapData                                                  worldMapData;               // 188
		WorldMapOffsetData                                            worldMapOffsetData;         // 1A4
		std::uint32_t                                                 padding1B4;                 // 1B4
		BGSMusicType*                                                 music;                      // 1B8
		NiPoint2                                                      minimumCoordinates;         // 1C0
		NiPoint2                                                      maximumCoordinates;         // 1C8
		std::uint64_t                                                 unknown1D0;                 // 1D0
		std::uint64_t                                                 unknown1D8;                 // 1D8
		std::uint64_t                                                 unknown1E0;                 // 1E0
		std::uint64_t                                                 unknown1E8;                 // 1E8
		std::uint64_t                                                 unknown1F0;                 // 1F0
		std::uint64_t                                                 unknown1F8;                 // 1F8
		BSString                                                      editorID;                   // 200
		LandData                                                      landData;                   // 210
		float                                                         distantLODMultiplier;       // 218
		std::uint32_t                                                 padding21C;                 // 21C
		BGSEncounterZone*                                             encounterZone;              // 220
		BGSLocation*                                                  location;                   // 228
		TESTexture                                                    canopyShadow;               // 230
		TESTexture                                                    waterEnvironmentMap;        // 240
		BGSLargeRefData                                               largeRefData;               // 250
		std::uint64_t                                                 unknown2E0;                 // 2E0
		std::uint64_t                                                 unknown2E8;                 // 2E8
		std::uint64_t                                                 unknown2F0;                 // 2F0
		std::uint64_t                                                 unknown2F8;                 // 2F8
		std::uint64_t                                                 unknown300;                 // 300
		std::uint64_t                                                 unknown308;                 // 308
		std::uint64_t                                                 unknown310;                 // 310
		std::uint64_t                                                 unknown318;                 // 318
		std::uint64_t                                                 unknown320;                 // 320
		std::uint64_t                                                 unknown328;                 // 328
		std::uint64_t                                                 unknown330;                 // 330
		std::uint64_t                                                 unknown338;                 // 338
		std::uint64_t                                                 unknown340;                 // 340
		std::uint64_t                                                 unknown348;                 // 348
		std::uint64_t                                                 unknown350;                 // 350
	};
	static_assert(offsetof(TESWorldSpace, cells) == 0x58);
	static_assert(offsetof(TESWorldSpace, persistentCell) == 0x88);
	static_assert(offsetof(TESWorldSpace, terrainManager) == 0x90);
	static_assert(offsetof(TESWorldSpace, climateData) == 0x98);
	static_assert(offsetof(TESWorldSpace, worldSpaceFlags) == 0xA0);
	static_assert(offsetof(TESWorldSpace, useFlags) == 0xA2);
	static_assert(offsetof(TESWorldSpace, centerCell) == 0xA4);
	static_assert(offsetof(TESWorldSpace, fixedPersistentReferences) == 0xA8);
	static_assert(offsetof(TESWorldSpace, mobilePersistentReferences) == 0xD8);
	static_assert(offsetof(TESWorldSpace, skyCell) == 0xF8);
	static_assert(offsetof(TESWorldSpace, locations) == 0x100);
	static_assert(offsetof(TESWorldSpace, parentWorldSpace) == 0x158);
	static_assert(offsetof(TESWorldSpace, interiorLighting) == 0x160);
	static_assert(offsetof(TESWorldSpace, waterData) == 0x168);
	static_assert(offsetof(TESWorldSpace, lodData) == 0x170);
	static_assert(offsetof(TESWorldSpace, worldMapData) == 0x188);
	static_assert(offsetof(TESWorldSpace, worldMapOffsetData) == 0x1A4);
	static_assert(offsetof(TESWorldSpace, music) == 0x1B8);
	static_assert(offsetof(TESWorldSpace, minimumCoordinates) == 0x1C0);
	static_assert(offsetof(TESWorldSpace, maximumCoordinates) == 0x1C8);
	static_assert(offsetof(TESWorldSpace, editorID) == 0x200);
	static_assert(offsetof(TESWorldSpace, landData) == 0x210);
	static_assert(offsetof(TESWorldSpace, distantLODMultiplier) == 0x218);
	static_assert(offsetof(TESWorldSpace, encounterZone) == 0x220);
	static_assert(offsetof(TESWorldSpace, location) == 0x228);
	static_assert(offsetof(TESWorldSpace, canopyShadow) == 0x230);
	static_assert(offsetof(TESWorldSpace, waterEnvironmentMap) == 0x240);
	static_assert(offsetof(TESWorldSpace, largeRefData) == 0x250);
	static_assert(sizeof(TESWorldSpace) == 0x358);
}
