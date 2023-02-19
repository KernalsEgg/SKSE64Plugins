#include "PrecompiledHeader.h"

#include "Patches/PoisonResistance.h"

#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	void PoisonResistance::Patch(bool& poisonResistance)
	{
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::Actor::MagicTarget::VirtualFunctionTable, 0xA, reinterpret_cast<std::uintptr_t>(std::addressof(PoisonResistance::CheckResistance)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::Character::MagicTarget::VirtualFunctionTable, 0xA, reinterpret_cast<std::uintptr_t>(std::addressof(PoisonResistance::CheckResistance)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::PlayerCharacter::MagicTarget::VirtualFunctionTable, 0xA, reinterpret_cast<std::uintptr_t>(std::addressof(PoisonResistance::CheckResistance)));
	}

	float PoisonResistance::CheckResistance(Skyrim::MagicTarget* magicTarget, Skyrim::MagicItem* magicItem, Skyrim::EffectItem* effect, Skyrim::TESBoundObject* item)
	{
		// magicTarget != nullptr
		// magicItem != nullptr
		// effect != nullptr

		if (magicItem->hostileCount <= 0 || (item && item->formType == Skyrim::FormType::kArmor))
		{
			return 1.0F;
		}

		auto  spellType = magicItem->GetSpellType();
		auto* potion    = spellType == Skyrim::MagicSystem::SpellType::kPotion ? static_cast<Skyrim::AlchemyItem*>(magicItem) : nullptr;
		auto  isPoison  = potion && potion->IsPoison();

		if ((potion && !isPoison && !effect->IsHostile()) || (spellType == Skyrim::MagicSystem::SpellType::kIngredient && magicItem->IsFood()))
		{
			return 1.0F;
		}

		auto* actor = static_cast<Skyrim::Actor*>(magicTarget);

		float defaultResistance{ 0.0F };

		float resistance{ 0.0F };
		auto  resistanceActorValue = effect->effectSetting->resistanceActorValue;

		if (isPoison || spellType == Skyrim::MagicSystem::SpellType::kPoison)
		{
			if (resistanceActorValue != Skyrim::ActorValue::kNone)
			{
				resistance = actor->GetActorValue(resistanceActorValue);
			}
		}
		else
		{
			defaultResistance = actor->GetActorValue(Skyrim::ActorValue::kMagicResist);

			if (resistanceActorValue != Skyrim::ActorValue::kNone && resistanceActorValue != Skyrim::ActorValue::kMagicResist)
			{
				resistance = actor->GetActorValue(resistanceActorValue);
			}
		}

		if (actor == Skyrim::PlayerCharacter::GetSingleton())
		{
			auto playerMaximumResistance = Skyrim::GameSettingCollection::PlayerMaximumResistance()->GetFloat();

			if (defaultResistance > playerMaximumResistance)
			{
				defaultResistance = playerMaximumResistance;
			}

			if (resistance > playerMaximumResistance)
			{
				resistance = playerMaximumResistance;
			}
		}

		return defaultResistance >= 100.0F || resistance >= 100.0F ? 0.0F : (1.0F - (defaultResistance / 100.0F)) * (1.0F - (resistance / 100.0F));
	}
}
