#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSTEventSink.h"
#include "Shared/Skyrim/I/ICellAttachDetachEventSource.h"



namespace Skyrim
{
	namespace BSResource
	{
		struct ArchiveStreamOpenedEvent;
	}

	struct PositionPlayerEvent;

	class GridCellArray;
	class NiColorA;
	class NiPoint3;
	class Sky;
	class TESObjectCELL;
	class TESWorldSpace;

	class TES :
		public ICellAttachDetachEventSource,                       // 0
		public BSTEventSink<BSResource::ArchiveStreamOpenedEvent>, // 60
		public BSTEventSink<PositionPlayerEvent>                   // 68
	{
	public:
		// Override
		virtual ~TES() override; // 0

		// Override (BSTEventSink<BSResource::ArchiveStreamOpenedEvent>)
		virtual BSEventNotifyControl ProcessEvent(const BSResource::ArchiveStreamOpenedEvent* eventArguments, BSTEventSource<BSResource::ArchiveStreamOpenedEvent>* eventSource) override; // 1

		// Override (BSTEventSink<PositionPlayerEvent>)
		virtual BSEventNotifyControl ProcessEvent(const PositionPlayerEvent* eventArguments, BSTEventSource<PositionPlayerEvent>* eventSource) override; // 1

		// Non-member functions
		static TES* GetSingleton();

		// Member functions
		TESObjectCELL* GetCell(const NiPoint3& position) const;
		bool           GetLandColor(const NiPoint3& position, NiColorA& landColor) const;
		std::uint32_t  GetMaterialID(const NiPoint3& position) const;

		// Member variables
		std::uint64_t  unknown70;    // 70
		GridCellArray* gridCells;    // 78
		std::uint64_t  unknown80;    // 80
		std::uint64_t  unknown88;    // 88
		std::uint64_t  unknown90;    // 90
		std::uint64_t  unknown98;    // 98
		std::uint64_t  unknownA0;    // A0
		std::uint64_t  unknownA8;    // A8
		std::uint64_t  unknownB0;    // B0
		std::uint64_t  unknownB8;    // B8
		TESObjectCELL* interiorCell; // C0
		std::uint64_t  unknownC8;    // C8
		std::uint64_t  unknownD0;    // D0
		std::uint64_t  unknownD8;    // D8
		std::uint64_t  unknownE0;    // E0
		std::uint64_t  unknownE8;    // E8
		std::uint64_t  unknownF0;    // F0
		std::uint64_t  unknownF8;    // F8
		Sky*           sky;          // 100
		std::uint64_t  unknown108;   // 108
		std::uint64_t  unknown110;   // 110
		std::uint64_t  unknown118;   // 118
		std::uint64_t  unknown120;   // 120
		std::uint64_t  unknown128;   // 128
		std::uint64_t  unknown130;   // 130
		std::uint64_t  unknown138;   // 138
		TESWorldSpace* worldSpace;   // 140
		std::uint64_t  unknown148;   // 148
		std::uint64_t  unknown150;   // 150
		std::uint64_t  unknown158;   // 158
		std::uint64_t  unknown160;   // 160
		std::uint64_t  unknown168;   // 168
		std::uint64_t  unknown170;   // 170
		std::uint64_t  unknown178;   // 178
		std::uint64_t  unknown180;   // 180
		std::uint64_t  unknown188;   // 188
		std::uint64_t  unknown190;   // 190
		std::uint64_t  unknown198;   // 198
		std::uint64_t  unknown1A0;   // 1A0
		std::uint64_t  unknown1A8;   // 1A8
		std::uint64_t  unknown1B0;   // 1B0
		std::uint64_t  unknown1B8;   // 1B8
		std::uint64_t  unknown1C0;   // 1C0
		std::uint64_t  unknown1C8;   // 1C8
		std::uint64_t  unknown1D0;   // 1D0
		std::uint64_t  unknown1D8;   // 1D8
		std::uint64_t  unknown1E0;   // 1E0
		std::uint64_t  unknown1E8;   // 1E8
		std::uint64_t  unknown1F0;   // 1F0
		std::uint64_t  unknown1F8;   // 1F8
		std::uint64_t  unknown200;   // 200
		std::uint64_t  unknown208;   // 208
		std::uint64_t  unknown210;   // 210
		std::uint64_t  unknown218;   // 218
		std::uint64_t  unknown220;   // 220
		std::uint64_t  unknown228;   // 228
		std::uint64_t  unknown230;   // 230
		std::uint64_t  unknown238;   // 238
		std::uint64_t  unknown240;   // 240
		std::uint64_t  unknown248;   // 248
		std::uint64_t  unknown250;   // 250
		std::uint64_t  unknown258;   // 258
		std::uint64_t  unknown260;   // 260
		std::uint64_t  unknown268;   // 268
		std::uint64_t  unknown270;   // 270
		std::uint64_t  unknown278;   // 278
		std::uint64_t  unknown280;   // 280
		std::uint64_t  unknown288;   // 288
		std::uint64_t  unknown290;   // 290
		std::uint64_t  unknown298;   // 298
		std::uint64_t  unknown2A0;   // 2A0
		std::uint64_t  unknown2A8;   // 2A8
		std::uint64_t  unknown2B0;   // 2B0
	};
	static_assert(offsetof(TES, gridCells) == 0x78);
	static_assert(offsetof(TES, interiorCell) == 0xC0);
	static_assert(offsetof(TES, sky) == 0x100);
	static_assert(offsetof(TES, worldSpace) == 0x140);
	static_assert(sizeof(TES) == 0x2B8);
}
