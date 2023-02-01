#include "PrecompiledHeader.h"

#include "Patches/AttachHitEffectArt.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Skyrim/N/NiAVObject.h"
#include "Shared/Skyrim/N/NiNode.h"
#include "Shared/Skyrim/R/ReferenceEffectController.h"
#include "Shared/Utility/Assembly.h"
#include "Shared/Utility/Memory.h"
#include "Shared/Utility/Trampoline.h"



namespace ScrambledBugs::Patches
{
	void AttachHitEffectArt::Patch(bool& attachHitEffectArt)
	{
		if (!Patterns::Patches::AttachHitEffectArt::GetTargetActor() ||
			!Patterns::Patches::AttachHitEffectArt::IsPerspectiveChange() ||
			!Patterns::Patches::AttachHitEffectArt::IsPlayerReattach() ||
			!Patterns::Patches::AttachHitEffectArt::IsPlayerUpdatePosition() ||
			!Patterns::Patches::AttachHitEffectArt::SetCastPermanentMagicFunctorFlags())
		{
			attachHitEffectArt = false;

			return;
		}

		Utility::Memory::SafeWrite(Addresses::Patches::AttachHitEffectArt::IsPerspectiveChange, Utility::Assembly::NO_OPERATION_2);
		Utility::Memory::SafeWrite(Addresses::Patches::AttachHitEffectArt::IsPlayerReattach, Utility::Assembly::NO_OPERATION_2);
		Utility::Memory::SafeWrite(Addresses::Patches::AttachHitEffectArt::IsPlayerUpdatePosition, Utility::Assembly::NO_OPERATION_6);

		/* Remove the CastPermanentMagicFunctor flag responsible for setting ActiveEffect flags to disable hit effect art */
		Utility::Memory::SafeWrite(
			Addresses::Patches::AttachHitEffectArt::SetCastPermanentMagicFunctorFlags,
			std::optional<std::uint8_t>{}, 0xF8ui8, // and al, F8
			Utility::Assembly::NO_OPERATION_2       // nop
		);

		AttachHitEffectArt::getTargetActor_ = reinterpret_cast<decltype(AttachHitEffectArt::getTargetActor_)>(
			Utility::Trampoline::GetSingleton().RelativeCall5(Addresses::Patches::AttachHitEffectArt::GetTargetActor, reinterpret_cast<std::uintptr_t>(std::addressof(AttachHitEffectArt::GetTargetActor))));
	}

	Skyrim::Actor* AttachHitEffectArt::GetTargetActor(Skyrim::ModelReferenceEffect* modelReferenceEffect)
	{
		// modelReferenceEffect != nullptr
		// modelReferenceEffect->controller != nullptr

		auto* targetActor = AttachHitEffectArt::getTargetActor_(modelReferenceEffect);

		if (!targetActor)
		{
			return nullptr;
		}

		auto* attachObject = modelReferenceEffect->controller->GetAttachRoot();

		if (!attachObject)
		{
			attachObject = targetActor->GetCurrent3D();
		}

		Skyrim::NiNode* attachRoot{ nullptr };

		if (attachObject)
		{
			attachRoot = attachObject->AsNiNode();

			if (!attachRoot)
			{
				attachRoot = attachObject->parentNode;
			}
		}

		return attachRoot != modelReferenceEffect->attachTechniqueInput.attachRoot.get() ? targetActor : nullptr;
	}

	decltype(&AttachHitEffectArt::GetTargetActor) AttachHitEffectArt::getTargetActor_{ nullptr };
}
