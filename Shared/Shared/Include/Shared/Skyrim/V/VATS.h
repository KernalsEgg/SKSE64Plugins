#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/B/BSTSingleton.h"
#include "Shared/Skyrim/B/BSTSmartPointer.h"
#include "Shared/Skyrim/V/VATSCommand.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class VATS :
		public BSTSingletonSDM<VATS> // 0
	{
	public:
		enum class Mode : std::uint32_t
		{
			kNone       = 0,
			kKillCamera = 4
		};
		static_assert(sizeof(Mode) == 0x4);

		// Non-member functions
		static VATS* GetSingleton();

		// Member functions
		float GetPlayerUpdateMultiplier() const;
		void  SetMagicTimeSlowdown(float magicTimeSlowdown, float playerMagicTimeSlowdown);

		// Member variables
		std::uint8_t                              unknown1;                // 1
		std::uint16_t                             unknown2;                // 2
		std::uint32_t                             unknown4;                // 4
		BSTArray<BSTSmartPointer<VATSCommand>>    commands;                // 8
		Utility::Enumeration<Mode, std::uint32_t> mode;                    // 20
		std::uint32_t                             unknown24;               // 24
		std::uint64_t                             unknown28;               // 28
		std::uint64_t                             unknown30;               // 30
		std::uint64_t                             unknown38;               // 38
		std::uint64_t                             unknown40;               // 40
		std::uint64_t                             unknown48;               // 48
		std::uint64_t                             unknown50;               // 50
		std::uint64_t                             unknown58;               // 58
		std::uint64_t                             unknown60;               // 60
		std::uint64_t                             unknown68;               // 68
		std::uint64_t                             unknown70;               // 70
		std::uint64_t                             unknown78;               // 78
		float                                     magicTimeSlowdown;       // 80
		float                                     playerMagicTimeSlowdown; // 84
		std::uint64_t                             unknown88;               // 88
		std::uint64_t                             unknown90;               // 90
		std::uint64_t                             unknown98;               // 98
		std::uint64_t                             unknownA0;               // A0
		std::uint64_t                             unknownA8;               // A8
		std::uint64_t                             unknownB0;               // B0
		std::uint64_t                             unknownB8;               // B8
	};
	static_assert(offsetof(VATS, commands) == 0x8);
	static_assert(offsetof(VATS, mode) == 0x20);
	static_assert(offsetof(VATS, magicTimeSlowdown) == 0x80);
	static_assert(offsetof(VATS, playerMagicTimeSlowdown) == 0x84);
	static_assert(sizeof(VATS) == 0xC0);
}
