#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Patches
{
	class ReflectDamage
	{
	public:
		static void Patch(bool& reflectDamage);
	};
}
