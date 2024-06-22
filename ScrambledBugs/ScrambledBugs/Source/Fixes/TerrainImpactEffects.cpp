#include "PrecompiledHeader.h"

#include "Fixes/TerrainImpactEffects.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Assembly.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Fixes
{
	void TerrainImpactEffects::Fix(bool& terrainImpactEffects)
	{
		if (!Patterns::Fixes::TerrainImpactEffects::FreeCellMopp())
		{
			terrainImpactEffects = false;

			return;
		}

		Utility::Memory::SafeWrite(Addresses::Fixes::TerrainImpactEffects::FreeCellMopp, Utility::Assembly::NO_OPERATION_5);
	}
}
