#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	struct BSSoundHandle;

	class BSAudioManager
	{
	public:
		// Non-member functions
		static BSAudioManager* GetSingleton();

		// Member functions
		void GetSoundHandleFromName(BSSoundHandle& soundHandle, const char* editorID, std::uint32_t flags);

		// Member variables
		std::uint64_t unknown0;   // 0
		std::uint64_t unknown8;   // 8
		std::uint64_t unknown10;  // 10
		std::uint64_t unknown18;  // 18
		std::uint64_t unknown20;  // 20
		std::uint64_t unknown28;  // 28
		std::uint64_t unknown30;  // 30
		std::uint64_t unknown38;  // 38
		std::uint64_t unknown40;  // 40
		std::uint64_t unknown48;  // 48
		std::uint64_t unknown50;  // 50
		std::uint64_t unknown58;  // 58
		std::uint64_t unknown60;  // 60
		std::uint64_t unknown68;  // 68
		std::uint64_t unknown70;  // 70
		std::uint64_t unknown78;  // 78
		std::uint64_t unknown80;  // 80
		std::uint64_t unknown88;  // 88
		std::uint64_t unknown90;  // 90
		std::uint64_t unknown98;  // 98
		std::uint64_t unknownA0;  // A0
		std::uint64_t unknownA8;  // A8
		std::uint64_t unknownB0;  // B0
		std::uint64_t unknownB8;  // B8
		std::uint64_t unknownC0;  // C0
		std::uint64_t unknownC8;  // C8
		std::uint64_t unknownD0;  // D0
		std::uint64_t unknownD8;  // D8
		std::uint64_t unknownE0;  // E0
		std::uint64_t unknownE8;  // E8
		std::uint64_t unknownF0;  // F0
		std::uint64_t unknownF8;  // F8
		std::uint64_t unknown100; // 100
		std::uint64_t unknown108; // 108
		std::uint64_t unknown110; // 110
		std::uint64_t unknown118; // 118
		std::uint64_t unknown120; // 120
		std::uint64_t unknown128; // 128
		std::uint64_t unknown130; // 130
		std::uint64_t unknown138; // 138
		std::uint64_t unknown140; // 140
		std::uint64_t unknown148; // 148
		std::uint64_t unknown150; // 150
		std::uint64_t unknown158; // 158
		std::uint64_t unknown160; // 160
		std::uint64_t unknown168; // 168
		std::uint64_t unknown170; // 170
		std::uint64_t unknown178; // 178
		std::uint64_t unknown180; // 180
		std::uint64_t unknown188; // 188
	};
	static_assert(sizeof(BSAudioManager) == 0x190);
}
