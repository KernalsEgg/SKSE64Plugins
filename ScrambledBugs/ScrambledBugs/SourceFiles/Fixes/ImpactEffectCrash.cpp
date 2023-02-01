#include "PrecompiledHeader.h"

#include "Fixes/ImpactEffectCrash.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Trampoline.h"



namespace ScrambledBugs::Fixes
{
	void ImpactEffectCrash::Fix(bool& impactEffectCrash)
	{
		if (!Patterns::Fixes::ImpactEffectCrash::DecalApplier() ||
			!Patterns::Fixes::ImpactEffectCrash::UpdateDecals())
		{
			impactEffectCrash = false;

			return;
		}

		ImpactEffectCrash::decalApplier_ = reinterpret_cast<decltype(ImpactEffectCrash::decalApplier_)>(
			Utility::Trampoline::GetSingleton().RelativeCall5(Addresses::Fixes::ImpactEffectCrash::DecalApplier, reinterpret_cast<std::uintptr_t>(std::addressof(ImpactEffectCrash::DecalApplier))));

		ImpactEffectCrash::updateDecals_ = reinterpret_cast<decltype(ImpactEffectCrash::updateDecals_)>(
			Utility::Trampoline::GetSingleton().RelativeCall5(Addresses::Fixes::ImpactEffectCrash::UpdateDecals, reinterpret_cast<std::uintptr_t>(std::addressof(ImpactEffectCrash::UpdateDecals))));
	}

	bool ImpactEffectCrash::DecalApplier(Skyrim::BSTempEffectSimpleDecal* temporaryEffectSimpleDecal)
	{
		if (temporaryEffectSimpleDecal->textureSet1)
		{
			return ImpactEffectCrash::decalApplier_(temporaryEffectSimpleDecal);
		}
		else
		{
			temporaryEffectSimpleDecal->state = 7;

			return false;
		}
	}

	bool ImpactEffectCrash::UpdateDecals(Skyrim::BSTempEffectSimpleDecal* temporaryEffectSimpleDecal)
	{
		if (temporaryEffectSimpleDecal->textureSet1)
		{
			return ImpactEffectCrash::updateDecals_(temporaryEffectSimpleDecal);
		}
		else
		{
			temporaryEffectSimpleDecal->state = 7;

			return false;
		}
	}

	decltype(&ImpactEffectCrash::DecalApplier) ImpactEffectCrash::decalApplier_{ nullptr };
	decltype(&ImpactEffectCrash::UpdateDecals) ImpactEffectCrash::updateDecals_{ nullptr };
}
