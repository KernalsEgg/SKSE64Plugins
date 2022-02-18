#include "PCH.h"

#include "Fixes/TerrainDecals.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Fixes
{
	bool TerrainDecals::Fix()
	{
		if (!Patterns::Fixes::TerrainDecals::UnloadCellMopp())
		{
			return false;
		}

		Utility::Memory::SafeWrite(Addresses::Fixes::TerrainDecals::UnloadCellMopp, 0xC3ui8, 0xCCui8, 0xCCui8, 0xCCui8, 0xCCui8);

		return true;
	}
}
