#include "PrecompiledHeader.h"

#include "Fixes/ActorValuePercentage.h"

#include "Addresses.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Fixes
{
	void ActorValuePercentage::Fix(bool& actorValuePercentage)
	{
		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Fixes::ActorValuePercentage::GetActorValuePercentage, reinterpret_cast<std::uintptr_t>(std::addressof(ActorValuePercentage::GetActorValuePercentage)));
		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Fixes::ActorValuePercentage::GetHealthPercentage, reinterpret_cast<std::uintptr_t>(std::addressof(ActorValuePercentage::GetHealthPercentage)));
		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Fixes::ActorValuePercentage::GetStaminaPercentage, reinterpret_cast<std::uintptr_t>(std::addressof(ActorValuePercentage::GetStaminaPercentage)));
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
		Skyrim::NiPointer<Skyrim::Actor> controllingActor;
		actor->GetControllingActor(controllingActor);

		return ActorValuePercentage::GetActorValuePercentage(controllingActor.get(), Skyrim::ActorValue::kStamina);
	}
}
