#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	class GridArray
	{
	public:
		// Add
		virtual ~GridArray();                  // 0
		virtual void Unknown1(GridArray*);     // 1
		virtual void Unknown2(GridArray*);     // 2
		virtual void Unknown3(GridArray*);     // 3
		virtual void Unknown4(GridArray*);     // 4
		virtual void Unknown5(GridArray*) = 0; // 5
		virtual void Unknown6(GridArray*) = 0; // 6
		virtual void Unknown7(GridArray*) = 0; // 7
		virtual void Unknown8(GridArray*) = 0; // 8

		// Member variables
		std::uint64_t unknown8;  // 8
		std::uint32_t size;      // 10, uGridsToLoad
		std::uint32_t padding14; // 14
	};
	static_assert(offsetof(GridArray, size) == 0x10);
	static_assert(sizeof(GridArray) == 0x18);
}
