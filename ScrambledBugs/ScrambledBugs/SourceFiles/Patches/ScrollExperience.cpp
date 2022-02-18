#include "PCH.h"

#include "Patches/ScrollExperience.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	bool ScrollExperience::Patch()
	{
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::ScrollItem::VirtualFunctionTable, 0x60, Utility::Memory::ReadVirtualFunction(Skyrim::Addresses::SpellItem::VirtualFunctionTable, 0x60));

		return true;
	}
}
