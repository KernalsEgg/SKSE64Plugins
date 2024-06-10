#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Relocation/PreprocessorDirectives.h"
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
		virtual EventNotifyControl ProcessEvent(const BSResource::ArchiveStreamOpenedEvent* eventArguments, BSTEventSource<BSResource::ArchiveStreamOpenedEvent>* eventSource) override; // 1

		// Override (BSTEventSink<PositionPlayerEvent>)
		virtual EventNotifyControl ProcessEvent(const PositionPlayerEvent* eventArguments, BSTEventSource<PositionPlayerEvent>* eventSource) override; // 1

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
#ifdef SKYRIM_ANNIVERSARY_EDITION
		std::uint64_t unknown140; // 140
#endif
		TESWorldSpace* worldSpace; // 140, 148
		std::uint64_t  unknown150; // 148, 150
		std::uint64_t  unknown158; // 150, 158
		std::uint64_t  unknown160; // 158, 160
		std::uint64_t  unknown168; // 160, 168
		std::uint64_t  unknown170; // 168, 170
		std::uint64_t  unknown178; // 170, 178
		std::uint64_t  unknown180; // 178, 180
		std::uint64_t  unknown188; // 180, 188
		std::uint64_t  unknown190; // 188, 190
		std::uint64_t  unknown198; // 190, 198
		std::uint64_t  unknown1A0; // 198, 1A0
		std::uint64_t  unknown1A8; // 1A0, 1A8
		std::uint64_t  unknown1B0; // 1A8, 1B0
		std::uint64_t  unknown1B8; // 1B0, 1B8
		std::uint64_t  unknown1C0; // 1B8, 1C0
		std::uint64_t  unknown1C8; // 1C0, 1C8
		std::uint64_t  unknown1D0; // 1C8, 1D0
		std::uint64_t  unknown1D8; // 1D0, 1D8
		std::uint64_t  unknown1E0; // 1D8, 1E0
		std::uint64_t  unknown1E8; // 1E0, 1E8
		std::uint64_t  unknown1F0; // 1E8, 1F0
		std::uint64_t  unknown1F8; // 1F0, 1F8
		std::uint64_t  unknown200; // 1F8, 200
		std::uint64_t  unknown208; // 200, 208
		std::uint64_t  unknown210; // 208, 210
		std::uint64_t  unknown218; // 210, 218
		std::uint64_t  unknown220; // 218, 220
		std::uint64_t  unknown228; // 220, 228
		std::uint64_t  unknown230; // 228, 230
		std::uint64_t  unknown238; // 230, 238
		std::uint64_t  unknown240; // 238, 240
		std::uint64_t  unknown248; // 240, 248
		std::uint64_t  unknown250; // 248, 250
		std::uint64_t  unknown258; // 250, 258
		std::uint64_t  unknown260; // 258, 260
		std::uint64_t  unknown268; // 260, 268
		std::uint64_t  unknown270; // 268, 270
		std::uint64_t  unknown278; // 270, 278
		std::uint64_t  unknown280; // 278, 280
		std::uint64_t  unknown288; // 280, 288
		std::uint64_t  unknown290; // 288, 290
		std::uint64_t  unknown298; // 290, 298
		std::uint64_t  unknown2A0; // 298, 2A0
		std::uint64_t  unknown2A8; // 2A0, 2A8
		std::uint64_t  unknown2B0; // 2A8, 2B0
		std::uint64_t  unknown2B8; // 2B0, 2B8
	};
	static_assert(offsetof(TES, gridCells) == 0x78);
	static_assert(offsetof(TES, interiorCell) == 0xC0);
	static_assert(offsetof(TES, sky) == 0x100);
	static_assert(offsetof(TES, worldSpace) == SKYRIM_RELOCATE(0x140, 0x148));
	static_assert(sizeof(TES) == SKYRIM_RELOCATE(0x2B8, 0x2C0));
}
