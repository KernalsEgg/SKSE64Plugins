#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSPointerHandle.h"
#include "Shared/Skyrim/N/NiPointer.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class bhkCharacterController;
	class HitData;
	class InventoryEntryData;
	class NiAVObject;

	enum class Update3DFlags : std::uint8_t
	{
		kNone  = 0,
		kModel = 1U << 0,
	};
	static_assert(sizeof(Update3DFlags) == 0x1);

	class MiddleHighProcessData
	{
	public:
		// Member variables
		std::uint64_t                                     unknown0;                     // 0
		std::uint64_t                                     unknown8;                     // 8
		std::uint64_t                                     unknown10;                    // 10
		std::uint64_t                                     unknown18;                    // 18
		std::uint64_t                                     unknown20;                    // 20
		std::uint64_t                                     unknown28;                    // 28
		std::uint64_t                                     unknown30;                    // 30
		std::uint64_t                                     unknown38;                    // 38
		std::uint64_t                                     unknown40;                    // 40
		std::uint64_t                                     unknown48;                    // 48
		std::uint64_t                                     unknown50;                    // 50
		std::uint64_t                                     unknown58;                    // 58
		std::uint64_t                                     unknown60;                    // 60
		std::uint64_t                                     unknown68;                    // 68
		std::uint64_t                                     unknown70;                    // 70
		std::uint64_t                                     unknown78;                    // 78
		std::uint64_t                                     unknown80;                    // 80
		std::uint64_t                                     unknown88;                    // 88
		std::uint64_t                                     unknown90;                    // 90
		std::uint64_t                                     unknown98;                    // 98
		std::uint64_t                                     unknownA0;                    // A0
		std::uint64_t                                     unknownA8;                    // A8
		std::uint64_t                                     unknownB0;                    // B0
		std::uint64_t                                     unknownB8;                    // B8
		std::uint64_t                                     unknownC0;                    // C0
		std::uint64_t                                     unknownC8;                    // C8
		std::uint64_t                                     unknownD0;                    // D0
		std::uint64_t                                     unknownD8;                    // D8
		std::uint64_t                                     unknownE0;                    // E0
		std::uint64_t                                     unknownE8;                    // E8
		std::uint64_t                                     unknownF0;                    // F0
		std::uint64_t                                     unknownF8;                    // F8
		std::uint64_t                                     unknown100;                   // 100
		std::uint64_t                                     unknown108;                   // 108
		std::uint64_t                                     unknown110;                   // 110
		std::uint64_t                                     unknown118;                   // 118
		std::uint64_t                                     unknown120;                   // 120
		std::uint64_t                                     unknown128;                   // 128
		std::uint64_t                                     unknown130;                   // 130
		std::uint64_t                                     unknown138;                   // 138
		std::uint64_t                                     unknown140;                   // 140
		std::uint64_t                                     unknown148;                   // 148
		std::uint64_t                                     unknown150;                   // 150
		NiAVObject*                                       headNode;                     // 158
		NiAVObject*                                       torsoNode;                    // 160
		std::uint64_t                                     unknown168;                   // 168
		std::uint64_t                                     unknown170;                   // 170
		std::uint64_t                                     unknown178;                   // 178
		std::uint64_t                                     unknown180;                   // 180
		std::uint64_t                                     unknown188;                   // 188
		HitData*                                          lastHitData;                  // 190
		std::uint64_t                                     unknown198;                   // 198
		std::uint64_t                                     unknown1A0;                   // 1A0
		std::uint64_t                                     unknown1A8;                   // 1A8
		std::uint64_t                                     unknown1B0;                   // 1B0
		std::uint64_t                                     unknown1B8;                   // 1B8
		std::uint64_t                                     unknown1C0;                   // 1C0
		std::uint64_t                                     unknown1C8;                   // 1C8
		std::uint64_t                                     unknown1D0;                   // 1D0
		std::uint64_t                                     unknown1D8;                   // 1D8
		std::uint64_t                                     unknown1E0;                   // 1E0
		std::uint64_t                                     unknown1E8;                   // 1E8
		std::uint64_t                                     unknown1F0;                   // 1F0
		std::uint64_t                                     unknown1F8;                   // 1F8
		std::uint64_t                                     unknown200;                   // 200
		ObjectReferenceHandle                             currentFurniture;             // 208
		std::uint32_t                                     unknown20C;                   // 20C
		std::uint64_t                                     unknown210;                   // 210
		ActorHandle                                       commandingActor;              // 218
		std::uint32_t                                     unknown21C;                   // 21C
		InventoryEntryData*                               leftHandInventoryEntryData;   // 220
		std::uint64_t                                     unknown228;                   // 228
		std::uint64_t                                     unknown230;                   // 230
		std::uint64_t                                     unknown238;                   // 238
		std::uint64_t                                     unknown240;                   // 240
		std::uint64_t                                     unknown248;                   // 248
		NiPointer<bhkCharacterController>                 characterController;          // 250
		std::uint64_t                                     unknown258;                   // 258
		InventoryEntryData*                               rightHandInventoryEntryData;  // 260
		InventoryEntryData*                               ammunitionInventoryEntryData; // 268
		std::uint64_t                                     unknown270;                   // 270
		std::uint64_t                                     unknown278;                   // 278
		std::uint64_t                                     unknown280;                   // 280
		std::uint64_t                                     unknown288;                   // 288
		std::uint64_t                                     unknown290;                   // 290
		std::uint64_t                                     unknown298;                   // 298
		std::uint64_t                                     unknown2A0;                   // 2A0
		std::uint64_t                                     unknown2A8;                   // 2A8
		std::uint64_t                                     unknown2B0;                   // 2B0
		std::uint32_t                                     unknown2B8;                   // 2B8
		float                                             maximumWardPower;             // 2BC
		std::uint64_t                                     unknown2C0;                   // 2C0
		std::uint64_t                                     unknown2C8;                   // 2C8
		std::uint64_t                                     unknown2D0;                   // 2D0
		std::uint64_t                                     unknown2D8;                   // 2D8
		std::uint64_t                                     unknown2E0;                   // 2E0
		std::uint64_t                                     unknown2E8;                   // 2E8
		std::uint64_t                                     unknown2F0;                   // 2F0
		std::uint64_t                                     unknown2F8;                   // 2F8
		std::uint64_t                                     unknown300;                   // 300
		std::uint64_t                                     unknown308;                   // 308
		std::uint8_t                                      unknown310;                   // 310
		Utility::Enumeration<Update3DFlags, std::uint8_t> update3DFlags;                // 311
		std::uint16_t                                     unknown312;                   // 312
		std::uint32_t                                     unknown314;                   // 314
		std::uint64_t                                     unknown318;                   // 318
		std::uint64_t                                     unknown320;                   // 320
		std::uint64_t                                     unknown328;                   // 328
		std::uint64_t                                     unknown330;                   // 330
	};
	static_assert(offsetof(MiddleHighProcessData, headNode) == 0x158);
	static_assert(offsetof(MiddleHighProcessData, torsoNode) == 0x160);
	static_assert(offsetof(MiddleHighProcessData, lastHitData) == 0x190);
	static_assert(offsetof(MiddleHighProcessData, currentFurniture) == 0x208);
	static_assert(offsetof(MiddleHighProcessData, commandingActor) == 0x218);
	static_assert(offsetof(MiddleHighProcessData, leftHandInventoryEntryData) == 0x220);
	static_assert(offsetof(MiddleHighProcessData, characterController) == 0x250);
	static_assert(offsetof(MiddleHighProcessData, rightHandInventoryEntryData) == 0x260);
	static_assert(offsetof(MiddleHighProcessData, ammunitionInventoryEntryData) == 0x268);
	static_assert(offsetof(MiddleHighProcessData, maximumWardPower) == 0x2BC);
	static_assert(sizeof(MiddleHighProcessData) == 0x338);
}
