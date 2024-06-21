#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/C/ContainerMenu.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/T/TESObjectREFR.h"



namespace Skyrim
{
	NiPointer<TESObjectREFR> ContainerMenu::GetTargetReference()
	{
		return ContainerMenu::GetTargetReferenceHandle().get();
	}

	ObjectReferenceHandle ContainerMenu::GetTargetReferenceHandle()
	{
		auto* singleton{ reinterpret_cast<ObjectReferenceHandle*>(Addresses::ContainerMenu::TargetReferenceHandle()) };

		return *singleton;
	}
}
