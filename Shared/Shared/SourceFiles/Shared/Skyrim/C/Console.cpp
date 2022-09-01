#include "Shared/PCH.h"

#include "Shared/Skyrim/C/Console.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/T/TESObjectREFR.h"



namespace Skyrim
{
	NiPointer<TESObjectREFR> Console::GetSelectedReference()
	{
		return Console::GetSelectedReferenceHandle().get();
	}

	ObjectReferenceHandle Console::GetSelectedReferenceHandle()
	{
		auto* singleton{ reinterpret_cast<ObjectReferenceHandle*>(Addresses::Console::SelectedReferenceHandle) };

		return *singleton;
	}
}
