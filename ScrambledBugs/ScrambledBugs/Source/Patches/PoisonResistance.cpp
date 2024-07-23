#include "PrecompiledHeader.h"

#include "Patches/PoisonResistance.h"

#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	void PoisonResistance::Patch(bool& poisonResistance)
	{
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::Actor::MagicTarget::VirtualFunctionTable(), 0xA, reinterpret_cast<std::uintptr_t>(std::addressof(PoisonResistance::CheckResistance)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::Character::MagicTarget::VirtualFunctionTable(), 0xA, reinterpret_cast<std::uintptr_t>(std::addressof(PoisonResistance::CheckResistance)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::PlayerCharacter::MagicTarget::VirtualFunctionTable(), 0xA, reinterpret_cast<std::uintptr_t>(std::addressof(PoisonResistance::CheckResistance)));
	}

	float PoisonResistance::CheckResistance(Skyrim::MagicTarget* magicTarget, Skyrim::MagicItem* magicItem, Skyrim::EffectItem* effectItem, Skyrim::TESBoundObject* boundObject)
	{
		// magicTarget != nullptr
		// magicItem != nullptr
		// effectItem != nullptr

		if (magicItem->hostileCount <= 0 || (boundObject && boundObject->formType == Skyrim::FormType::kArmor))
		{
			return 1.0F;
		}

		auto  spellType   = magicItem->GetSpellType();
		auto* alchemyItem = spellType == Skyrim::MagicSystem::SpellType::kPotion ? static_cast<Skyrim::AlchemyItem*>(magicItem) : nullptr;
		auto  isPoison    = alchemyItem && alchemyItem->IsPoison();

		if ((alchemyItem && !isPoison && !effectItem->IsHostile()) || (spellType == Skyrim::MagicSystem::SpellType::kIngredient && magicItem->IsFood()))
		{
			return 1.0F;
		}

		auto* actor = static_cast<Skyrim::Actor*>(magicTarget);

		float defaultResistance{ 0.0F };

		float resistance{ 0.0F };
		auto  resistanceActorValue = effectItem->effectSetting->resistanceActorValue;

		if (isPoison || spellType == Skyrim::MagicSystem::SpellType::kPoison)
		{
			if (resistanceActorValue != Skyrim::ActorValue::kNone)
			{
				resistance = actor->GetActorValue(resistanceActorValue);
			}
		}
		else
		{
			defaultResistance = actor->GetActorValue(Skyrim::ActorValue::kMagicResistance);

			if (resistanceActorValue != Skyrim::ActorValue::kNone && resistanceActorValue != Skyrim::ActorValue::kMagicResistance)
			{
				resistance = actor->GetActorValue(resistanceActorValue);
			}
		}

		if (actor == Skyrim::PlayerCharacter::GetSingleton())
		{
			static auto* playerMaximumResistance = Skyrim::GameSettingCollection::InitializeSetting("fPlayerMaxResistance");

			if (defaultResistance > playerMaximumResistance->GetFloat())
			{
				defaultResistance = playerMaximumResistance->GetFloat();
			}

			if (resistance > playerMaximumResistance->GetFloat())
			{
				resistance = playerMaximumResistance->GetFloat();
			}
		}

		return defaultResistance >= 100.0F || resistance >= 100.0F ? 0.0F : (1.0F - (defaultResistance / 100.0F)) * (1.0F - (resistance / 100.0F));
	}
}
