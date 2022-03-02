#pragma once

#include "PCH.h"



namespace ScrambledBugs::Patches
{
	class ReflectDamage
	{
	public:
		static void Patch(bool& reflectDamage);
	};
}
