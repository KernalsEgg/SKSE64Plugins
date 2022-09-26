#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Patches
{
	class EquipBestAmmo
	{
	public:
		static void Patch(bool& equipBestAmmo);
	};
}
