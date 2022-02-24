#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSAtomic.h"
#include "Shared/Skyrim/B/BSTHashMap.h"
#include "Shared/Skyrim/C/Color.h"
#include "Shared/Skyrim/D/DirectionalAmbientLighting.h"
#include "Shared/Skyrim/N/NiPointer.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Skyrim/T/TESFullName.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSEncounterZone;
	class BGSTerrainVisibilityData;
	class NiNode;
	class TESObjectREFR;
	class TESWorldSpace;

	struct ExteriorCellData
	{
	public:
		enum class ForceHideLandFlags : std::uint8_t
		{
			kNone  = 0,
			kQuad1 = 1U << 0,
			kQuad2 = 1U << 1,
			kQuad3 = 1U << 2,
			kQuad4 = 1U << 3
		};
		static_assert(sizeof(ForceHideLandFlags) == 0x1);

		// Member variables
		std::int32_t                                           offsetX;            // 0
		std::int32_t                                           offsetY;            // 4
		char*                                                  maximumHeightData;  // 8
		BGSTerrainVisibilityData*                              lodVisibilityData;  // 10
		float                                                  coordinateX;        // 18
		float                                                  coordinateY;        // 1C
		Utility::Enumeration<ForceHideLandFlags, std::uint8_t> forceHideLandFlags; // 20
		std::uint8_t                                           padding21;          // 21
		std::uint16_t                                          padding22;          // 22
		std::uint32_t                                          padding24;          // 24
	};
	static_assert(offsetof(ExteriorCellData, offsetX) == 0x0);
	static_assert(offsetof(ExteriorCellData, offsetY) == 0x4);
	static_assert(offsetof(ExteriorCellData, maximumHeightData) == 0x8);
	static_assert(offsetof(ExteriorCellData, lodVisibilityData) == 0x10);
	static_assert(offsetof(ExteriorCellData, coordinateX) == 0x18);
	static_assert(offsetof(ExteriorCellData, coordinateY) == 0x1C);
	static_assert(offsetof(ExteriorCellData, forceHideLandFlags) == 0x20);
	static_assert(sizeof(ExteriorCellData) == 0x28);

	struct InteriorCellData
	{
	public:
		enum class InheritanceFlags : std::uint32_t
		{
			kNone                = 0,
			kAmbientColor        = 1U << 0,
			kDirectionalColor    = 1U << 1,
			kFogColor            = 1U << 2,
			kFogNear             = 1U << 3,
			kFogFar              = 1U << 4,
			kDirectionalRotation = 1U << 5,
			kDirectionalFade     = 1U << 6,
			kClipDistance        = 1U << 7,
			kFogPower            = 1U << 8,
			kFogMax              = 1U << 9,
			kLightFadeDistances  = 1U << 10
		};
		static_assert(sizeof(InheritanceFlags) == 0x4);

		struct LightFadeDistances
		{
		public:
			// Member variables
			float start; // 0
			float end;   // 4
		};
		static_assert(offsetof(LightFadeDistances, start) == 0x0);
		static_assert(offsetof(LightFadeDistances, end) == 0x4);
		static_assert(sizeof(LightFadeDistances) == 0x8);

		// Member variables
		Color                                                 ambientColor;                     // 0
		Color                                                 directionalColor;                 // 4
		Color                                                 fogNearColor;                     // 8
		float                                                 fogNear;                          // C
		float                                                 fogFar;                           // 10
		std::uint32_t                                         directionalRotationXY;            // 14
		std::uint32_t                                         directionalRotationZ;             // 18
		float                                                 directionalFade;                  // 1C
		float                                                 fogClippingDistance;              // 20
		float                                                 fogPower;                         // 24
		DirectionalAmbientLighting                            directionalAmbientLighting;       // 28
		Color                                                 fogFarColor;                      // 48
		float                                                 fogMaximum;                       // 4C
		LightFadeDistances                                    lightFadeDistances;               // 50
		Utility::Enumeration<InheritanceFlags, std::uint32_t> lightingTemplateInheritanceFlags; // 58
		std::uint32_t                                         padding5C;                        // 5C
	};
	static_assert(offsetof(InteriorCellData, ambientColor) == 0x0);
	static_assert(offsetof(InteriorCellData, directionalColor) == 0x4);
	static_assert(offsetof(InteriorCellData, fogNearColor) == 0x8);
	static_assert(offsetof(InteriorCellData, fogNear) == 0xC);
	static_assert(offsetof(InteriorCellData, fogFar) == 0x10);
	static_assert(offsetof(InteriorCellData, directionalRotationXY) == 0x14);
	static_assert(offsetof(InteriorCellData, directionalRotationZ) == 0x18);
	static_assert(offsetof(InteriorCellData, directionalFade) == 0x1C);
	static_assert(offsetof(InteriorCellData, fogClippingDistance) == 0x20);
	static_assert(offsetof(InteriorCellData, fogPower) == 0x24);
	static_assert(offsetof(InteriorCellData, directionalAmbientLighting) == 0x28);
	static_assert(offsetof(InteriorCellData, fogFarColor) == 0x48);
	static_assert(offsetof(InteriorCellData, fogMaximum) == 0x4C);
	static_assert(offsetof(InteriorCellData, lightFadeDistances) == 0x50);
	static_assert(offsetof(InteriorCellData, lightingTemplateInheritanceFlags) == 0x58);
	static_assert(sizeof(InteriorCellData) == 0x60);

	union CellData
	{
	public:
		// Member variables
		ExteriorCellData* exteriorCellData;
		InteriorCellData* interiorCellData;
	};
	static_assert(sizeof(CellData) == 0x8);

	struct LoadedCellData
	{
	public:
		// Member variables
		std::uint64_t     unknown0;      // 0
		NiPointer<NiNode> current3D;     // 8
		std::uint64_t     unknown10;     // 10
		std::uint64_t     unknown18;     // 18
		std::uint64_t     unknown20;     // 20
		std::uint64_t     unknown28;     // 28
		std::uint64_t     unknown30;     // 30
		std::uint64_t     unknown38;     // 38
		std::uint64_t     unknown40;     // 40
		std::uint64_t     unknown48;     // 48
		std::uint64_t     unknown50;     // 50
		std::uint64_t     unknown58;     // 58
		std::uint64_t     unknown60;     // 60
		std::uint64_t     unknown68;     // 68
		std::uint64_t     unknown70;     // 70
		std::uint64_t     unknown78;     // 78
		std::uint64_t     unknown80;     // 80
		std::uint64_t     unknown88;     // 88
		std::uint64_t     unknown90;     // 90
		std::uint64_t     unknown98;     // 98
		std::uint64_t     unknownA0;     // A0
		std::uint64_t     unknownA8;     // A8
		std::uint64_t     unknownB0;     // B0
		std::uint64_t     unknownB8;     // B8
		std::uint64_t     unknownC0;     // C0
		std::uint64_t     unknownC8;     // C8
		std::uint64_t     unknownD0;     // D0
		std::uint64_t     unknownD8;     // D8
		std::uint64_t     unknownE0;     // E0
		std::uint64_t     unknownE8;     // E8
		std::uint64_t     unknownF0;     // F0
		std::uint64_t     unknownF8;     // F8
		std::uint64_t     unknown100;    // 100
		std::uint64_t     unknown108;    // 108
		std::uint64_t     unknown110;    // 110
		std::uint64_t     unknown118;    // 118
		std::uint64_t     unknown120;    // 120
		std::uint64_t     unknown128;    // 128
		std::uint64_t     unknown130;    // 130
		std::uint64_t     unknown138;    // 138
		std::uint64_t     unknown140;    // 140
		std::uint64_t     unknown148;    // 148
		std::uint64_t     unknown150;    // 150
		std::uint64_t     unknown158;    // 158
		BGSEncounterZone* encounterZone; // 160
		std::uint64_t     unknown168;    // 168
		std::uint64_t     unknown170;    // 170
		std::uint64_t     unknown178;    // 178
	};
	static_assert(offsetof(LoadedCellData, current3D) == 0x8);
	static_assert(offsetof(LoadedCellData, encounterZone) == 0x160);
	static_assert(sizeof(LoadedCellData) == 0x180);

	class TESObjectCELL :
		public TESForm,    // 0
		public TESFullName // 20
	{
	public:
		enum class Flags : std::uint16_t
		{
			kNone              = 0,
			kInteriorCell      = 1U << 0,
			kHasWater          = 1U << 1, // Common Data
			kCanTravelFromHere = 1U << 2, // Common Data
			kNoLODWater        = 1U << 3, // Common Data
			kPublicArea        = 1U << 5, // Interior Data
			kHandChanged       = 1U << 6, // Common Data
			kShowSky           = 1U << 7, // Lighting
			kUseSkyLighting    = 1U << 8  // Lighting
		};
		static_assert(sizeof(Flags) == 0x2);

		// Override
		virtual ~TESObjectCELL() override; // 0

		// Override (TESForm)
		virtual void        Unknown5(TESForm*) override;                // 5
		virtual void        Unknown6(TESForm*) override;                // 6
		virtual void        Unknown9(TESForm*) override;                // 9
		virtual void        UnknownC(TESForm*) override;                // C
		virtual void        UnknownE(TESForm*) override;                // E
		virtual void        UnknownF(TESForm*) override;                // F
		virtual void        Unknown12(TESForm*) override;               // 12
		virtual void        Unknown13(TESForm*) override;               // 13
		virtual void        Unknown16(TESForm*) override;               // 16
		virtual void        Unknown24(TESForm*) override;               // 24
		virtual void        Unknown30(TESForm*) override;               // 30
		virtual void        Unknown31(TESForm*) override;               // 31
		virtual const char* GetEditorID() const override;               // 32
		virtual bool        SetEditorID(const char* editorID) override; // 33
		virtual void        Unknown34(TESForm*) override;               // 34
		virtual void        Unknown36(TESForm*) override;               // 36

		// Member variables
		std::uint64_t                              unknown30;      // 30
		std::uint64_t                              unknown38;      // 38
		Utility::Enumeration<Flags, std::uint16_t> cellFlags;      // 40
		std::uint16_t                              unknown42;      // 42
		std::uint32_t                              unknown44;      // 44
		std::uint64_t                              unknown48;      // 48
		std::uint64_t                              unknown50;      // 50
		std::uint64_t                              unknown58;      // 58
		CellData                                   cellData;       // 60
		std::uint64_t                              unknown68;      // 68
		std::uint64_t                              unknown70;      // 70
		std::uint64_t                              unknown78;      // 78
		BSTSet<NiPointer<TESObjectREFR>>           references;     // 80
		std::uint64_t                              unknownB0;      // B0
		std::uint64_t                              unknownB8;      // B8
		std::uint64_t                              unknownC0;      // C0
		std::uint64_t                              unknownC8;      // C8
		std::uint64_t                              unknownD0;      // D0
		std::uint64_t                              unknownD8;      // D8
		std::uint64_t                              unknownE0;      // E0
		std::uint64_t                              unknownE8;      // E8
		std::uint64_t                              unknownF0;      // F0
		std::uint64_t                              unknownF8;      // F8
		std::uint64_t                              unknown100;     // 100
		std::uint64_t                              unknown108;     // 108
		std::uint64_t                              unknown110;     // 110
		mutable BSSpinLock                         lock;           // 118
		TESWorldSpace*                             worldSpace;     // 120
		LoadedCellData*                            loadedCellData; // 128
		std::uint64_t                              unknown130;     // 130
		std::uint64_t                              unknown138;     // 138
	};
	static_assert(offsetof(TESObjectCELL, cellFlags) == 0x40);
	static_assert(offsetof(TESObjectCELL, cellData) == 0x60);
	static_assert(offsetof(TESObjectCELL, references) == 0x80);
	static_assert(offsetof(TESObjectCELL, lock) == 0x118);
	static_assert(offsetof(TESObjectCELL, worldSpace) == 0x120);
	static_assert(offsetof(TESObjectCELL, loadedCellData) == 0x128);
	static_assert(sizeof(TESObjectCELL) == 0x140);
}
