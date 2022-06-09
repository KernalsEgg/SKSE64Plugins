#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/G/GridArray.h"



namespace Skyrim
{
	class TESObjectCELL;

	class GridCellArray :
		public GridArray // 0
	{
	public:
		// Override
		virtual ~GridCellArray() override; // 0

		// Override (GridArray)
		virtual void Unknown2(GridArray*) override; // 2
		virtual void Unknown3(GridArray*) override; // 3
		virtual void Unknown5(GridArray*) override; // 5
		virtual void Unknown6(GridArray*) override; // 6
		virtual void Unknown7(GridArray*) override; // 7
		virtual void Unknown8(GridArray*) override; // 8

		// Member functions
		TESObjectCELL* GetCell(std::uint32_t x, std::uint32_t y) const;

		// Member variables
		TESObjectCELL** cells;     // 18
		std::uint64_t   unknown20; // 20
		std::uint64_t   unknown28; // 28
	};
	static_assert(offsetof(GridCellArray, cells) == 0x18);
	static_assert(sizeof(GridCellArray) == 0x30);
}
