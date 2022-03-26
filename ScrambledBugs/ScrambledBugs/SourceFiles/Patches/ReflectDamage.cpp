#include "PCH.h"

#include "Patches/ReflectDamage.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Assembly.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	void ReflectDamage::Patch(bool& reflectDamage)
	{
		if (!Patterns::Patches::ReflectDamage::CompareReflectDamage())
		{
			reflectDamage = false;

			return;
		}

		Utility::Memory::SafeWrite(Addresses::Patches::ReflectDamage::CompareReflectDamage, Utility::Assembly::NoOperation8);
	}
}
