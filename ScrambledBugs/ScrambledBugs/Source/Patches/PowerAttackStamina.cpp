#include "PrecompiledHeader.h"

#include "Patches/PowerAttackStamina.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	void PowerAttackStamina::Patch(bool& powerAttackStamina)
	{
		if (!Patterns::Patches::PowerAttackStamina::GetAttackStaminaActor() ||
			!Patterns::Patches::PowerAttackStamina::GetAttackStaminaPlayerCharacter() ||
			!Patterns::Patches::PowerAttackStamina::HasStaminaActor() ||
			!Patterns::Patches::PowerAttackStamina::HasStaminaPlayerCharacter())
		{
			powerAttackStamina = false;

			return;
		}

		Utility::Memory::SafeWrite(Addresses::Patches::PowerAttackStamina::HasStaminaActor, std::optional<std::uint8_t>{}, 0x00ui8);
		Utility::Memory::SafeWrite(Addresses::Patches::PowerAttackStamina::HasStaminaPlayerCharacter, std::optional<std::uint8_t>{}, 0x00ui8);

		PowerAttackStamina::getAttackStaminaActor_           = reinterpret_cast<decltype(PowerAttackStamina::getAttackStaminaActor_)>(Utility::Memory::ReadRelativeCall5(Addresses::Patches::PowerAttackStamina::GetAttackStaminaActor));
		PowerAttackStamina::getAttackStaminaPlayerCharacter_ = reinterpret_cast<decltype(PowerAttackStamina::getAttackStaminaPlayerCharacter_)>(Utility::Memory::ReadRelativeCall5(Addresses::Patches::PowerAttackStamina::GetAttackStaminaPlayerCharacter));

		const auto* trampolineInterface = SKSE::Storage::GetSingleton().GetTrampolineInterface();

		trampolineInterface->RelativeCall5(Addresses::Patches::PowerAttackStamina::GetAttackStaminaActor, reinterpret_cast<std::uintptr_t>(std::addressof(PowerAttackStamina::HasAttackStaminaActor)));
		trampolineInterface->RelativeCall5(Addresses::Patches::PowerAttackStamina::GetAttackStaminaPlayerCharacter, reinterpret_cast<std::uintptr_t>(std::addressof(PowerAttackStamina::HasAttackStaminaPlayerCharacter)));
	}

	float PowerAttackStamina::HasAttackStaminaActor(Skyrim::ActorValueOwner* actorValueOwner, Skyrim::BGSAttackData* attackData)
	{
		auto attackStamina = PowerAttackStamina::getAttackStaminaActor_(actorValueOwner, attackData);

		if (attackStamina <= 0.0F)
		{
			return attackStamina; // true
		}

		auto stamina = actorValueOwner->GetActorValue(Skyrim::ActorValue::kStamina);

		return stamina >= attackStamina ? 0.0F : attackStamina; // true, false
	}

	float PowerAttackStamina::HasAttackStaminaPlayerCharacter(Skyrim::ActorValueOwner* actorValueOwner, Skyrim::BGSAttackData* attackData)
	{
		auto attackStamina = PowerAttackStamina::getAttackStaminaPlayerCharacter_(actorValueOwner, attackData);

		if (attackStamina <= 0.0F)
		{
			return attackStamina; // true
		}

		auto stamina = actorValueOwner->GetActorValue(Skyrim::ActorValue::kStamina);

		return stamina >= attackStamina ? 0.0F : attackStamina; // true, false
	}

	decltype(PowerAttackStamina::HasAttackStaminaActor)*           PowerAttackStamina::getAttackStaminaActor_{ nullptr };
	decltype(PowerAttackStamina::HasAttackStaminaPlayerCharacter)* PowerAttackStamina::getAttackStaminaPlayerCharacter_{ nullptr };
}
