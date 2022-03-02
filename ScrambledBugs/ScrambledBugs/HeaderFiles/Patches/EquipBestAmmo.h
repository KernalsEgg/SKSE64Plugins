#pragma once

#include "PCH.h"



namespace ScrambledBugs::Patches
{
	class EquipBestAmmo
	{
	public:
		static void Patch(bool& equipBestAmmo);
	};
}
