#include "PrecompiledHeader.h"

#include "Patches/AttachHitEffectArt.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	void AttachHitEffectArt::Patch(bool& attachHitEffectArt)
	{
		if (!Patterns::Patches::AttachHitEffectArt::SetCastPermanentMagicFunctorFlags())
		{
			attachHitEffectArt = false;

			return;
		}

		/* Remove the CastPermanentMagicFunctor flag responsible for setting ActiveEffect flags to disable hit effect art */
		Utility::Memory::SafeWrite(
			Addresses::Patches::AttachHitEffectArt::SetCastPermanentMagicFunctorFlags,
			std::optional<std::uint8_t>{}, 0xF8ui8, // and al, F8
			std::optional<std::uint8_t>{}, 0x00ui8  // or al, 0
		);

		AttachHitEffectArt::pop_ = reinterpret_cast<decltype(AttachHitEffectArt::pop_)>(Utility::Memory::ReadVirtualFunction(Skyrim::Addresses::ModelReferenceEffect::VirtualFunctionTable(), 0x35));

		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::ModelReferenceEffect::VirtualFunctionTable(), 0x32, reinterpret_cast<std::uintptr_t>(std::addressof(AttachHitEffectArt::GetStackable)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::ModelReferenceEffect::VirtualFunctionTable(), 0x33, reinterpret_cast<std::uintptr_t>(std::addressof(AttachHitEffectArt::GetStackableMatch)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::ModelReferenceEffect::VirtualFunctionTable(), 0x35, reinterpret_cast<std::uintptr_t>(std::addressof(AttachHitEffectArt::Pop)));
	}

	bool AttachHitEffectArt::GetStackable(Skyrim::ModelReferenceEffect* modelReferenceEffect)
	{
		return true;
	}

	bool AttachHitEffectArt::GetStackableMatch(Skyrim::ModelReferenceEffect* left, Skyrim::BSTempEffect* right)
	{
		return true;
	}

	void AttachHitEffectArt::Pop(Skyrim::ModelReferenceEffect* modelReferenceEffect)
	{
		AttachHitEffectArt::pop_(modelReferenceEffect);

		modelReferenceEffect->SwitchFirstThirdPerson();
	}

	decltype(AttachHitEffectArt::Pop)* AttachHitEffectArt::pop_{ nullptr };
}
