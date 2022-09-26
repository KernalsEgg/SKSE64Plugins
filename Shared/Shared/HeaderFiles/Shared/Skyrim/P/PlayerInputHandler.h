#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	class PlayerInputHandler
	{
	public:
		// Add
		virtual ~PlayerInputHandler();                  // 0
		virtual void Unknown1(PlayerInputHandler*) = 0; // 1
		virtual void Unknown2(PlayerInputHandler*);     // 2
		virtual void Unknown3(PlayerInputHandler*);     // 3
		virtual void Unknown4(PlayerInputHandler*);     // 4

		// Member variables
		bool          handleInputEvents; // 8
		std::uint8_t  padding9;          // 9
		std::uint16_t paddingA;          // A
		std::uint32_t paddingC;          // C
	};
	static_assert(offsetof(PlayerInputHandler, handleInputEvents) == 0x8);
	static_assert(sizeof(PlayerInputHandler) == 0x10);
}
