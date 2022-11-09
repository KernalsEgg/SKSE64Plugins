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
		if (!Patterns::Fixes::TerrainDecals::FreeCellMopp())
		{
			terrainDecals = false;

			return;
		}

		Utility::Memory::SafeWrite(Addresses::Fixes::TerrainDecals::FreeCellMopp, Utility::Assembly::NO_OPERATION_5);
	}
}
