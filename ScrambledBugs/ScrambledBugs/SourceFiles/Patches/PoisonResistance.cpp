#include "PCH.h"

#include "Patches/PoisonResistance.h"

#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/A/AlchemyItem.h"
#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/E/EffectSetting.h"
#include "Shared/Skyrim/G/GameSettingCollection.h"
#include "Shared/Skyrim/P/PlayerCharacter.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	bool PoisonResistance::Patch()
	{
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::Actor::MagicTargetVirtualFunctionTable, 0xA, reinterpret_cast<std::uintptr_t>(std::addressof(PoisonResistance::CheckResistance)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::Character::MagicTargetVirtualFunctionTable, 0xA, reinterpret_cast<std::uintptr_t>(std::addressof(PoisonResistance::CheckResistance)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::PlayerCharacter::MagicTargetVirtualFunctionTable, 0xA, reinterpret_cast<std::uintptr_t>(std::addressof(PoisonResistance::CheckResistance)));

		return true;
	}

	float PoisonResistance::CheckResistance(Skyrim::MagicTarget* magicTarget, Skyrim::MagicItem* magicItem, Skyrim::Effect* effect, Skyrim::TESBoundObject* item)
	{
		// magicTarget != nullptr
		// magicItem != nullptr
		// effect != nullptr

		if (magicItem->hostileCount <= 0 || (item && item->formType == Skyrim::FormType::kArmor))
		{
			return 1.0F;
		}

		auto spellType = magicItem->GetSpellType();
		auto potion    = spellType == Skyrim::MagicSystem::SpellType::kPotion ? static_cast<Skyrim::AlchemyItem*>(magicItem) : nullptr;
		auto isPoison  = potion && potion->IsPoison();

		if ((potion && !isPoison && !effect->IsHostile()) || (spellType == Skyrim::MagicSystem::SpellType::kIngredient && magicItem->IsFood()))
		{
			return 1.0F;
		}

		auto actor = static_cast<Skyrim::Actor*>(magicTarget);

		float magicResistance{ 0.0F };

		float effectResistance{ 0.0F };
		auto  effectResistanceActorValue = effect->baseEffect->resistanceActorValue;

		if (isPoison || spellType == Skyrim::MagicSystem::SpellType::kPoison)
		{
			if (effectResistanceActorValue != Skyrim::ActorValue::kNone)
			{
				effectResistance = actor->GetActorValue(effectResistanceActorValue);
			}
		}
		else
		{
			magicResistance = actor->GetActorValue(Skyrim::ActorValue::kMagicResist);

			if (effectResistanceActorValue != Skyrim::ActorValue::kNone && effectResistanceActorValue != Skyrim::ActorValue::kMagicResist)
			{
				effectResistance = actor->GetActorValue(effectResistanceActorValue);
			}
		}

		if (actor == Skyrim::PlayerCharacter::GetSingleton())
		{
			auto playerMaximumResistance = Skyrim::GameSettingCollection::PlayerMaximumResistance()->value.floatingPoint;

			if (magicResistance > playerMaximumResistance)
			{
				magicResistance = playerMaximumResistance;
			}

			if (effectResistance > playerMaximumResistance)
			{
				effectResistance = playerMaximumResistance;
			}
		}

		return magicResistance >= 100.0F || effectResistance >= 100.0F ? 0.0F : (1.0F - (magicResistance / 100.0F)) * (1.0F - (effectResistance / 100.0F));
	}
}
