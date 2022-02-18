#include "PCH.h"

#include "Patches/ReflectDamage.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Assembly.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	bool ReflectDamage::Patch()
	{
		if (!Patterns::Patches::ReflectDamage::CompareReflectDamage())
		{
			return false;
		}

		Utility::Memory::SafeWrite(Addresses::Patches::ReflectDamage::CompareReflectDamage, Utility::Assembly::NoOperation2);

		return true;
	}
}
