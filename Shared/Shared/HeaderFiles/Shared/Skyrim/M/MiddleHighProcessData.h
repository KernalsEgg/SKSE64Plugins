#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSPointerHandle.h"



namespace Skyrim
{
	class MiddleHighProcessData
	{
	public:
		// Member variables
		std::int64_t          unknown0;         // 0
		std::int64_t          unknown8;         // 8
		std::int64_t          unknown10;        // 10
		std::int64_t          unknown18;        // 18
		std::int64_t          unknown20;        // 20
		std::int64_t          unknown28;        // 28
		std::int64_t          unknown30;        // 30
		std::int64_t          unknown38;        // 38
		std::int64_t          unknown40;        // 40
		std::int64_t          unknown48;        // 48
		std::int64_t          unknown50;        // 50
		std::int64_t          unknown58;        // 58
		std::int64_t          unknown60;        // 60
		std::int64_t          unknown68;        // 68
		std::int64_t          unknown70;        // 70
		std::int64_t          unknown78;        // 78
		std::int64_t          unknown80;        // 80
		std::int64_t          unknown88;        // 88
		std::int64_t          unknown90;        // 90
		std::int64_t          unknown98;        // 98
		std::int64_t          unknownA0;        // A0
		std::int64_t          unknownA8;        // A8
		std::int64_t          unknownB0;        // B0
		std::int64_t          unknownB8;        // B8
		std::int64_t          unknownC0;        // C0
		std::int64_t          unknownC8;        // C8
		std::int64_t          unknownD0;        // D0
		std::int64_t          unknownD8;        // D8
		std::int64_t          unknownE0;        // E0
		std::int64_t          unknownE8;        // E8
		std::int64_t          unknownF0;        // F0
		std::int64_t          unknownF8;        // F8
		std::int64_t          unknown100;       // 100
		std::int64_t          unknown108;       // 108
		std::int64_t          unknown110;       // 110
		std::int64_t          unknown118;       // 118
		std::int64_t          unknown120;       // 120
		std::int64_t          unknown128;       // 128
		std::int64_t          unknown130;       // 130
		std::int64_t          unknown138;       // 138
		std::int64_t          unknown140;       // 140
		std::int64_t          unknown148;       // 148
		std::int64_t          unknown150;       // 150
		std::int64_t          unknown158;       // 158
		std::int64_t          unknown160;       // 160
		std::int64_t          unknown168;       // 168
		std::int64_t          unknown170;       // 170
		std::int64_t          unknown178;       // 178
		std::int64_t          unknown180;       // 180
		std::int64_t          unknown188;       // 188
		std::int64_t          unknown190;       // 190
		std::int64_t          unknown198;       // 198
		std::int64_t          unknown1A0;       // 1A0
		std::int64_t          unknown1A8;       // 1A8
		std::int64_t          unknown1B0;       // 1B0
		std::int64_t          unknown1B8;       // 1B8
		std::int64_t          unknown1C0;       // 1C0
		std::int64_t          unknown1C8;       // 1C8
		std::int64_t          unknown1D0;       // 1D0
		std::int64_t          unknown1D8;       // 1D8
		std::int64_t          unknown1E0;       // 1E0
		std::int64_t          unknown1E8;       // 1E8
		std::int64_t          unknown1F0;       // 1F0
		std::int64_t          unknown1F8;       // 1F8
		std::int64_t          unknown200;       // 200
		ObjectReferenceHandle currentFurniture; // 208
		std::int32_t          unknown20C;       // 20C
		std::int64_t          unknown210;       // 210
		std::int64_t          unknown218;       // 218
		std::int64_t          unknown220;       // 220
		std::int64_t          unknown228;       // 228
		std::int64_t          unknown230;       // 230
		std::int64_t          unknown238;       // 238
		std::int64_t          unknown240;       // 240
		std::int64_t          unknown248;       // 248
		std::int64_t          unknown250;       // 250
		std::int64_t          unknown258;       // 258
		std::int64_t          unknown260;       // 260
		std::int64_t          unknown268;       // 268
		std::int64_t          unknown270;       // 270
		std::int64_t          unknown278;       // 278
		std::int64_t          unknown280;       // 280
		std::int64_t          unknown288;       // 288
		std::int64_t          unknown290;       // 290
		std::int64_t          unknown298;       // 298
		std::int64_t          unknown2A0;       // 2A0
		std::int64_t          unknown2A8;       // 2A8
		std::int64_t          unknown2B0;       // 2B0
		std::int32_t          unknown2B8;       // 2B8
		float                 maximumWardPower; // 2BC
		std::int64_t          unknown2C0;       // 2C0
		std::int64_t          unknown2C8;       // 2C8
		std::int64_t          unknown2D0;       // 2D0
		std::int64_t          unknown2D8;       // 2D8
		std::int64_t          unknown2E0;       // 2E0
		std::int64_t          unknown2E8;       // 2E8
		std::int64_t          unknown2F0;       // 2F0
		std::int64_t          unknown2F8;       // 2F8
		std::int64_t          unknown300;       // 300
		std::int64_t          unknown308;       // 308
		std::int64_t          unknown310;       // 310
		std::int64_t          unknown318;       // 318
		std::int64_t          unknown320;       // 320
		std::int64_t          unknown328;       // 328
		std::int64_t          unknown330;       // 330
	};
	static_assert(offsetof(MiddleHighProcessData, currentFurniture) == 0x208);
	static_assert(offsetof(MiddleHighProcessData, maximumWardPower) == 0x2BC);
	static_assert(sizeof(MiddleHighProcessData) == 0x338);
}
