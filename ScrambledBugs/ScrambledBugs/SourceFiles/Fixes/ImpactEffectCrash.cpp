#include "PCH.h"

#include "Fixes/ImpactEffectCrash.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Memory.h"
#include "Shared/Utility/Trampoline.h"



namespace ScrambledBugs::Fixes
{
	bool ImpactEffectCrash::Fix()
	{
		if (!Patterns::Fixes::ImpactEffectCrash::DecalApplier() ||
			!Patterns::Fixes::ImpactEffectCrash::MainUpdate())
		{
			return false;
		}

		ImpactEffectCrash::decalApplier_ = reinterpret_cast<decltype(ImpactEffectCrash::decalApplier_)>(Utility::Memory::ReadRelativeCall(Addresses::Fixes::ImpactEffectCrash::DecalApplier));
		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Fixes::ImpactEffectCrash::DecalApplier, reinterpret_cast<std::uintptr_t>(std::addressof(ImpactEffectCrash::DecalApplier)));

		ImpactEffectCrash::mainUpdate_ = reinterpret_cast<decltype(ImpactEffectCrash::mainUpdate_)>(Utility::Memory::ReadRelativeCall(Addresses::Fixes::ImpactEffectCrash::MainUpdate));
		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Fixes::ImpactEffectCrash::MainUpdate, reinterpret_cast<std::uintptr_t>(std::addressof(ImpactEffectCrash::MainUpdate)));

		return true;
	}

	bool ImpactEffectCrash::DecalApplier(Skyrim::BSTempEffectSimpleDecal* tempEffectSimpleDecal)
	{
		return tempEffectSimpleDecal->textureSet ? ImpactEffectCrash::decalApplier_(tempEffectSimpleDecal) : false;
	}

	bool ImpactEffectCrash::MainUpdate(Skyrim::BSTempEffectSimpleDecal* tempEffectSimpleDecal)
	{
		return tempEffectSimpleDecal->textureSet ? ImpactEffectCrash::mainUpdate_(tempEffectSimpleDecal) : false;
	}

	decltype(&ImpactEffectCrash::DecalApplier) ImpactEffectCrash::decalApplier_;
	decltype(&ImpactEffectCrash::MainUpdate)   ImpactEffectCrash::mainUpdate_;
}
