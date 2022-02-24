#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSSimpleList.h"
#include "Shared/Skyrim/B/BSString.h"
#include "Shared/Skyrim/T/TESFile.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class TESFile
	{
	public:
		enum class RecordFlags : std::uint32_t
		{
			kNone      = 0,
			kSmallFile = 1U << 9
		};
		static_assert(sizeof(RecordFlags) == 0x4);

		// Member variables
		std::uint64_t                                    unknown0;              // 0
		std::uint64_t                                    unknown8;              // 8
		std::uint64_t                                    unknown10;             // 10
		std::uint64_t                                    unknown18;             // 18
		std::uint64_t                                    unknown20;             // 20
		std::uint64_t                                    unknown28;             // 28
		std::uint64_t                                    unknown30;             // 30
		std::uint64_t                                    unknown38;             // 38
		std::uint64_t                                    unknown40;             // 40
		std::uint64_t                                    unknown48;             // 48
		std::uint64_t                                    unknown50;             // 50
		char                                             filename[MAX_PATH];    // 58
		char                                             path[MAX_PATH];        // 15C
		std::uint64_t                                    unknown260;            // 260
		std::uint64_t                                    unknown268;            // 268
		std::uint64_t                                    unknown270;            // 270
		std::uint64_t                                    unknown278;            // 278
		std::uint64_t                                    unknown280;            // 280
		std::uint64_t                                    unknown288;            // 288
		std::uint64_t                                    unknown290;            // 290
		std::uint64_t                                    unknown298;            // 298
		std::uint64_t                                    unknown2A0;            // 2A0
		std::uint64_t                                    unknown2A8;            // 2A8
		std::uint64_t                                    unknown2B0;            // 2B0
		std::uint64_t                                    unknown2B8;            // 2B8
		std::uint64_t                                    unknown2C0;            // 2C0
		std::uint64_t                                    unknown2C8;            // 2C8
		std::uint64_t                                    unknown2D0;            // 2D0
		std::uint64_t                                    unknown2D8;            // 2D8
		std::uint64_t                                    unknown2E0;            // 2E0
		std::uint32_t                                    unknown2E8;            // 2E8
		::WIN32_FIND_DATAA                               fileData;              // 2EC
		std::uint32_t                                    unknown42C;            // 42C
		std::uint64_t                                    unknown430;            // 430
		Utility::Enumeration<RecordFlags, std::uint32_t> recordFlags;           // 438
		std::uint32_t                                    unknown43C;            // 43C
		BSSimpleList<const char*>                        parentMasterNames;     // 440
		std::uint64_t                                    unknown450;            // 450
		std::uint64_t                                    unknown458;            // 458
		std::uint32_t                                    parentMasterCount;     // 460
		std::uint32_t                                    padding464;            // 464
		TESFile**                                        parentMasters;         // 468
		::FILETIME                                       deletedFormTime;       // 470
		std::uint8_t                                     compileIndex;          // 478
		std::uint8_t                                     padding479;            // 479
		std::uint16_t                                    smallFileCompileIndex; // 47A
		std::uint32_t                                    padding47C;            // 47C
		BSString                                         createdBy;             // 480
		BSString                                         summary;               // 490
		std::uint64_t                                    unknown4A0;            // 4A0
		std::uint64_t                                    unknown4A8;            // 4A8
		std::uint64_t                                    unknown4B0;            // 4B0
		std::uint64_t                                    unknown4B8;            // 4B8
		std::uint64_t                                    unknown4C0;            // 4C0
	};
	static_assert(offsetof(TESFile, filename) == 0x58);
	static_assert(offsetof(TESFile, path) == 0x15C);
	static_assert(offsetof(TESFile, fileData) == 0x2EC);
	static_assert(offsetof(TESFile, recordFlags) == 0x438);
	static_assert(offsetof(TESFile, parentMasterNames) == 0x440);
	static_assert(offsetof(TESFile, parentMasterCount) == 0x460);
	static_assert(offsetof(TESFile, parentMasters) == 0x468);
	static_assert(offsetof(TESFile, deletedFormTime) == 0x470);
	static_assert(offsetof(TESFile, compileIndex) == 0x478);
	static_assert(offsetof(TESFile, smallFileCompileIndex) == 0x47A);
	static_assert(offsetof(TESFile, createdBy) == 0x480);
	static_assert(offsetof(TESFile, summary) == 0x490);
	static_assert(sizeof(TESFile) == 0x4C8);
}
