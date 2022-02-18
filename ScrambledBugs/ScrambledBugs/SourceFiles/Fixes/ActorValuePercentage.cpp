#include "PCH.h"

#include "Fixes/ActorValuePercentage.h"

#include "Addresses.h"
#include "Shared/Skyrim/N/NiPointer.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Fixes
{
	bool ActorValuePercentage::Fix()
	{
		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Fixes::ActorValuePercentage::GetActorValuePercentage, reinterpret_cast<std::uintptr_t>(std::addressof(ActorValuePercentage::GetActorValuePercentage)));
		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Fixes::ActorValuePercentage::GetHealthPercentage, reinterpret_cast<std::uintptr_t>(std::addressof(ActorValuePercentage::GetHealthPercentage)));
		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Fixes::ActorValuePercentage::GetStaminaPercentage, reinterpret_cast<std::uintptr_t>(std::addressof(ActorValuePercentage::GetStaminaPercentage)));

		return true;
	}

	float ActorValuePercentage::GetActorValuePercentage(Skyrim::Actor* actor, Utility::Enumeration<Skyrim::ActorValue, std::uint32_t> actorValue)
	{
		auto permanentValue = actor->GetPermanentActorValue(actorValue);
		auto temporaryValue = actor->GetActorValueModifier(Skyrim::ActorValueModifier::kTemporary, actorValue);

		if (permanentValue + temporaryValue == 0.0F)
		{
			return 1.0F;
		}

		auto value = actor->GetActorValue(actorValue);

		return value / (permanentValue + temporaryValue);
	}

	float ActorValuePercentage::GetHealthPercentage(Skyrim::Actor* actor)
	{
		return ActorValuePercentage::GetActorValuePercentage(actor, Skyrim::ActorValue::kHealth);
	}

	float ActorValuePercentage::GetStaminaPercentage(Skyrim::Actor* actor)
	{
		Skyrim::NiPointer<Skyrim::Actor> movementActor;
		actor->GetMovementActor(movementActor);

		return ActorValuePercentage::GetActorValuePercentage(movementActor.get(), Skyrim::ActorValue::kStamina);
	}
}
