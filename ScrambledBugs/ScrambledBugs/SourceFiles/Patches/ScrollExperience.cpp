#include "PrecompiledHeader.h"

#include "Patches/ScrollExperience.h"

#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	void ScrollExperience::Patch(bool& scrollExperience)
	{
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::ScrollItem::VirtualFunctionTable, 0x60, Utility::Memory::ReadVirtualFunction(Skyrim::Addresses::SpellItem::VirtualFunctionTable, 0x60));
	}
}
