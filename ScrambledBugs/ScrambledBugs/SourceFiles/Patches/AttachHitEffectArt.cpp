#include "PCH.h"

#include "Patches/AttachHitEffectArt.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/R/ReferenceEffectController.h"
#include "Shared/Utility/Assembly.h"
#include "Shared/Utility/Memory.h"
#include "Shared/Utility/Trampoline.h"



namespace ScrambledBugs::Patches
{
	void AttachHitEffectArt::Patch(bool& attachHitEffectArt)
	{
		if (!Patterns::Patches::AttachHitEffectArt::AddNoHitEffectArtFlag() ||
			!Patterns::Patches::AttachHitEffectArt::Attach() ||
			!Patterns::Patches::AttachHitEffectArt::IsPerspectiveChange() ||
			!Patterns::Patches::AttachHitEffectArt::IsPlayerAttach() ||
			!Patterns::Patches::AttachHitEffectArt::IsPlayerUpdatePosition())
		{
			attachHitEffectArt = false;

			return;
		}

		Utility::Memory::SafeWrite(Addresses::Patches::AttachHitEffectArt::IsPerspectiveChange, Utility::Assembly::NoOperation2);
		Utility::Memory::SafeWrite(Addresses::Patches::AttachHitEffectArt::IsPlayerAttach, Utility::Assembly::NoOperation2);
		Utility::Memory::SafeWrite(Addresses::Patches::AttachHitEffectArt::IsPlayerUpdatePosition, Utility::Assembly::NoOperation2);

		Utility::Memory::SafeWrite(
			Addresses::Patches::AttachHitEffectArt::AddNoHitEffectArtFlag,
			std::optional<std::uint8_t>{}, 0xF8ui8, // and al, F8 (1 << 2 (NoHitEffectArt), 1 << 4 (NoInitialFlare))
			Utility::Assembly::NoOperation2         // nop
		);

		AttachHitEffectArt::attach_ = reinterpret_cast<decltype(AttachHitEffectArt::attach_)>(Utility::Memory::ReadRelativeCall(Addresses::Patches::AttachHitEffectArt::Attach));
		Utility::Trampoline::GetSingleton().RelativeCall(Addresses::Patches::AttachHitEffectArt::Attach, reinterpret_cast<std::uintptr_t>(std::addressof(AttachHitEffectArt::Attach)));
	}

	void AttachHitEffectArt::Attach(Skyrim::ModelReferenceEffect* modelReferenceEffect)
	{
		// modelReferenceEffect != nullptr

		if (modelReferenceEffect->modelReferenceEffectFlags.none(Skyrim::ModelReferenceEffect::Flags::kInitialized))
		{
			return;
		}

		auto controller = modelReferenceEffect->controller;

		if (!controller)
		{
			return;
		}

		auto targetActor = modelReferenceEffect->GetTargetActor();

		if (!targetActor)
		{
			return;
		}

		auto attachObject = controller->GetAttachRoot();

		if (!attachObject)
		{
			attachObject = targetActor->GetCurrent3D();
		}

		Skyrim::NiNode* attachRoot{ nullptr };

		if (attachObject)
		{
			attachRoot = attachObject->AsNode();

			if (!attachRoot)
			{
				attachRoot = attachObject->parentNode;
			}
		}

		if (attachRoot != modelReferenceEffect->attachTechniqueInput.attachRoot.get())
		{
			AttachHitEffectArt::attach_(modelReferenceEffect);
		}
	}

	decltype(&AttachHitEffectArt::Attach) AttachHitEffectArt::attach_{ nullptr };
}
