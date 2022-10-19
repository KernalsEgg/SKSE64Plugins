#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Patches
{
	class EquipBestAmmunition
	{
	public:
		static void Patch(bool& equipBestAmmunition);
	};
}
