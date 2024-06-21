#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GridCellArray.h"



namespace Skyrim
{
	TESObjectCELL* GridCellArray::GetCell(std::uint32_t x, std::uint32_t y) const
	{
		auto size = this->size;

		return x < size && y < size ? this->cells[(size * x) + y] : nullptr;
	}
}
