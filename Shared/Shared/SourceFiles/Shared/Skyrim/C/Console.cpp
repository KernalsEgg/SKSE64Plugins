#include "Shared/PCH.h"

#include "Shared/Skyrim/C/Console.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	NiPointer<TESObjectREFR> Console::GetSelectedReference()
	{
		return Console::GetSelectedReferenceHandle().get();
	}

	ObjectReferenceHandle Console::GetSelectedReferenceHandle()
	{
		auto* selectedReferenceHandle{ reinterpret_cast<ObjectReferenceHandle*>(Addresses::Console::SelectedReferenceHandle) };

		return *selectedReferenceHandle;
	}
}
