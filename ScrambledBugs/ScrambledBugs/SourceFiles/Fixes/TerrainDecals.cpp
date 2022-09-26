#include "PrecompiledHeader.h"

#include "Fixes/TerrainDecals.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Assembly.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Fixes
{
	void TerrainDecals::Fix(bool& terrainDecals)
	{
		if (!Patterns::Fixes::TerrainDecals::UnloadCellMopp())
		{
			terrainDecals = false;

			return;
		}

		Utility::Memory::SafeWrite(Addresses::Fixes::TerrainDecals::UnloadCellMopp, Utility::Assembly::NoOperation5);
	}
}
