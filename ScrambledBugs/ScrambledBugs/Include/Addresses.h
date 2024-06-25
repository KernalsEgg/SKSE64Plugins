#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Relocation/AddressLibrary.h"



namespace ScrambledBugs::Addresses
{
	namespace Fixes
	{
		namespace ActorValuePercentage
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x5D6500 (36347), 1.6.318.0: SkyrimSE.exe + 0x5FAE70</summary>
			inline const std::uintptr_t GetActorValuePercentage{ Relocation::AddressLibrary::GetSingleton().GetAddress(37337) }; // Actor::GetActorValuePercentage

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x5D6640 (36349), 1.6.318.0: SkyrimSE.exe + 0x5FAFC0</summary>
			inline const std::uintptr_t GetHealthPercentage{ Relocation::AddressLibrary::GetSingleton().GetAddress(37339) }; // Actor::GetHealthPercentage

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x5D6570 (36348), 1.6.318.0: SkyrimSE.exe + 0x5FAEE0</summary>
			inline const std::uintptr_t GetStaminaPercentage{ Relocation::AddressLibrary::GetSingleton().GetAddress(37338) }; // Actor::GetStaminaPercentage
		}

		namespace EnchantmentCost
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x5A1070 + 0x72 (35284), 1.6.318.0: SkyrimSE.exe + 0x5C1D20</summary>
			inline const std::uintptr_t Compare{ Relocation::AddressLibrary::GetSingleton().GetAddress(36184) + 0x99 }; // BGSCreatedObjectManager::AddEnchantment
		}

		namespace HitEffectRaceCondition
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x53E670 (33289), 1.6.318.0: SkyrimSE.exe + 0x5587B0</summary>
			inline const std::uintptr_t ShouldUpdate{ Relocation::AddressLibrary::GetSingleton().GetAddress(34064) }; // ActiveEffect::ShouldUpdate
		}

		namespace ImpactEffectCrash
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1AE090 + 0x92 (15040), 1.6.318.0: SkyrimSE.exe + 0x1B95C0</summary>
			inline const std::uintptr_t DecalApplier{ Relocation::AddressLibrary::GetSingleton().GetAddress(15214) + 0x92 };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1AE520 + 0x12D (15045), 1.6.318.0: SkyrimSE.exe + 0x1B9B70</summary>
			inline const std::uintptr_t UpdateDecals{ Relocation::AddressLibrary::GetSingleton().GetAddress(15220) + 0x122 };
		}

		namespace IngredientRespawn
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x278920 + 0x31C (18843), 1.6.318.0: SkyrimSE.exe + 0x28AD80</summary>
			inline const std::uintptr_t SetEmpty{ Relocation::AddressLibrary::GetSingleton().GetAddress(19286) + 0x345 }; // TESObjectREFR::HandleReferenceReset
		}

		namespace KillCamera
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x732400 + 0x261 (42547), 1.6.318.0: SkyrimSE.exe + 0x75D560</summary>
			inline const std::uintptr_t HasWeapon{ Relocation::AddressLibrary::GetSingleton().GetAddress(43710) + 0x2D0 }; // ArrowProjectile::AddImpact
		}

		namespace LeftHandPowerAttacks
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x3BEC90 (25863), 1.6.318.0: SkyrimSE.exe + 0x3D6720</summary>
			inline const std::uintptr_t GetAttackStamina{ Relocation::AddressLibrary::GetSingleton().GetAddress(26429) }; // ActorValueOwner::GetAttackStamina
		}

		namespace MagicEffectFlags
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x53DEB0 (33277), 1.6.318.0: SkyrimSE.exe + 0x557E00</summary>
			inline const std::uintptr_t Adjust{ Relocation::AddressLibrary::GetSingleton().GetAddress(34052) }; // ActiveEffect::Adjust

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x53E1B0 (33283), 1.6.318.0: SkyrimSE.exe + 0x558180</summary>
			inline const std::uintptr_t Restart{ Relocation::AddressLibrary::GetSingleton().GetAddress(34058) }; // ActiveEffect::Restart
		}

		namespace ModifyArmorWeightPerkEntryPoint
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1E9130 (15883), 1.6.318.0: SkyrimSE.exe + 0x1F4960</summary>
			inline const std::uintptr_t GetInventoryWeight{ Relocation::AddressLibrary::GetSingleton().GetAddress(16123) }; // InventoryChanges::GetInventoryWeight
		}

		namespace PowerCooldowns
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x6309C0 (37794), 1.6.318.0: SkyrimSE.exe + 0x6567B0</summary>
			inline const std::uintptr_t SaveCastPowers{ Relocation::AddressLibrary::GetSingleton().GetAddress(38743) }; // Actor::SaveCastPowers
		}

		namespace ProjectileFadeDuration
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x74C3D0 + 0x164 (42942), 1.6.318.0: SkyrimSE.exe + 0x779750</summary>
			inline const std::uintptr_t HasFaded{ Relocation::AddressLibrary::GetSingleton().GetAddress(44122) + 0x166 }; // Projectile::Update

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x74C3D0 + 0x185 (42942), 1.6.318.0: SkyrimSE.exe + 0x779750</summary>
			inline const std::uintptr_t HasProcessedImpacts{ Relocation::AddressLibrary::GetSingleton().GetAddress(44122) + 0x187 }; // Projectile::Update
		}

		namespace QuickShot
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x3BF020 (25868), 1.6.318.0: SkyrimSE.exe + 0x3D6AB0</summary>
			inline const std::uintptr_t GetArrowPower{ Relocation::AddressLibrary::GetSingleton().GetAddress(26435) }; // ArrowProjectile::GetArrowPower
		}

		namespace TerrainImpactEffects
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x271BE0 + 0xE7 (18711), 1.6.318.0: SkyrimSE.exe + 0x27FC50</summary>
			inline const std::uintptr_t FreeCellMopp{ Relocation::AddressLibrary::GetSingleton().GetAddress(19130) + 0x24E }; // TESObjectCELL::DetachHavok
		}

		namespace TrainingMenu
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x8CEA30 + 0x289 (51794), 1.6.318.0: SkyrimSE.exe + 0x8FDB40</summary>
			inline const std::uintptr_t GetPermanentActorValue{ Relocation::AddressLibrary::GetSingleton().GetAddress(52668) + 0x289 }; // TrainingMenu::UpdateText
		}

		namespace WeaponCharge
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x6313D0 (37803), 1.6.318.0: SkyrimSE.exe + 0x6572D0</summary>
			inline const std::uintptr_t UpdateEquippedEnchantmentCharge{ Relocation::AddressLibrary::GetSingleton().GetAddress(38752) }; // Actor::UpdateEquippedEnchantmentCharge
		}
	}

	namespace Patches
	{
		namespace AlreadyCaughtPickpocketing
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x360C10 + 0x694 (24211), 1.6.318.0: SkyrimSE.exe + 0x377A00</summary>
			inline const std::uintptr_t HasBeenPickpocketed{ Relocation::AddressLibrary::GetSingleton().GetAddress(24715) + 0x6B1 }; // TESNPC::Activate

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x360C10 + 0x678 (24211), 1.6.318.0: SkyrimSE.exe + 0x377A00</summary>
			inline const std::uintptr_t IsAngryWithPlayer{ Relocation::AddressLibrary::GetSingleton().GetAddress(24715) + 0x695 }; // TESNPC::Activate
		}

		namespace AttachHitEffectArt
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x6314F0 + 0x6F (37804), 1.6.318.0: SkyrimSE.exe + 0x657450</summary>
			inline const std::uintptr_t SetCastPermanentMagicFunctorFlags{ Relocation::AddressLibrary::GetSingleton().GetAddress(38753) + 0x6F }; // Actor::CastPermanentMagic
		}

		namespace CloakHitEffects
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x5468E0 + 0x15 (33471), 1.6.318.0: SkyrimSE.exe + 0x561730</summary>
			inline const std::uintptr_t IsNotCostliestEffect{ Relocation::AddressLibrary::GetSingleton().GetAddress(34250) + 0x15 }; // CloakEffectCallbackFunctor::ModifyActiveEffect
		}

		namespace DeferredHitEffects
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x6A31E0 (39432), 1.6.318.0: SkyrimSE.exe + 0x6CB900</summary>
			inline const std::uintptr_t AllowHitEffects{ Relocation::AddressLibrary::GetSingleton().GetAddress(40508) }; // PlayerCharacter::AllowHitEffects
		}

		namespace DifficultyMultipliers
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x5D6300 (36345), 1.6.318.0: SkyrimSE.exe + 0x5FAC30</summary>
			inline const std::uintptr_t DamageHealth{ Relocation::AddressLibrary::GetSingleton().GetAddress(37335) }; // Actor::DamageHealth
		}

		namespace EquipBestAmmunition
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1E3090 (15846), 1.6.318.0: SkyrimSE.exe + 0x1EE7F0</summary>
			inline const std::uintptr_t GetWorstAmmunition{ Relocation::AddressLibrary::GetSingleton().GetAddress(16086) }; // InventoryChanges::GetWorstAmmunition
		}

		namespace LeveledCharacters
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1384D0 (12448), 1.6.318.0: SkyrimSE.exe + 0x13EED0</summary>
			inline const std::uintptr_t GetAllBelowForce{ Relocation::AddressLibrary::GetSingleton().GetAddress(12582) }; // ExtraLevCreaModifier::GetAllBelowForce
		}

		namespace LockpickingExperience
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x897E10 + 0x2C (51088), 1.6.318.0: SkyrimSE.exe + 0x8C8730</summary>
			inline const std::uintptr_t HasNotBeenUnlocked{ Relocation::AddressLibrary::GetSingleton().GetAddress(51968) + 0x2C }; // LockpickingMenu::OnLockOpen
		}

		namespace PerkEntryPoints
		{
			namespace ApplySpells
			{
				/// <summary>1.5.97.0: SkyrimSE.exe + 0x628C20 + 0x40E (37673), 1.6.318.0: SkyrimSE.exe + 0x64E760</summary>
				inline const std::uintptr_t ApplyBashingSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(38627) + 0x4FA }; // Actor::CombatHit

				/// <summary>1.5.97.0: SkyrimSE.exe + 0x6310A0 + 0x61 (37799), 1.6.318.0: SkyrimSE.exe + 0x656EE0</summary>
				inline const std::uintptr_t ApplyCombatHitSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(38748) + 0x5B }; // Actor::ApplyWeaponHitSpells

				/// <summary>1.5.97.0: SkyrimSE.exe + 0x732400 + 0x28B (42547), 1.6.318.0: SkyrimSE.exe + 0x75D560</summary>
				inline const std::uintptr_t ApplyCombatHitSpellArrowProjectile{ Relocation::AddressLibrary::GetSingleton().GetAddress(43710) + 0x2F6 }; // ArrowProjectile::AddImpact

				/// <summary>1.5.97.0: SkyrimSE.exe + 0x634BF0 + 0xBA (37865), 1.6.318.0: SkyrimSE.exe + 0x65ACF0</summary>
				inline const std::uintptr_t ApplyReanimateSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(38820) + 0xBA }; // Actor::PostReanimate

				/// <summary>1.5.97.0: SkyrimSE.exe + 0x6089E0 + 0xB6 (36926), 1.6.318.0: SkyrimSE.exe + 0x6301D0</summary>
				inline const std::uintptr_t ApplySneakingSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(37951) + 0x72 }; // Actor::SetSneaking

				/// <summary>1.5.97.0: SkyrimSE.exe + 0x6260F0 + 0xAB (37628), 1.6.318.0: SkyrimSE.exe + 0x64B7F0</summary>
				inline const std::uintptr_t ApplyWeaponSwingSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(38581) + 0xAE }; // Actor::WeaponSwingCallback

				/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DD3B20 (675819), 1.6.318.0: SkyrimSE.exe + 0x1E67C10</summary>
				inline const std::uintptr_t SelectSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(369199) }; // BGSEntryPointFunction::SelectSpellFunction
			}

			namespace CastSpells
			{
				/// <summary>1.5.97.0: SkyrimSE.exe + 0x628C20 + 0x429 (37673), 1.6.318.0: SkyrimSE.exe + 0x64E760</summary>
				inline const std::uintptr_t ApplyBashingSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(38627) + 0x517 }; // Actor::CombatHit

				/// <summary>1.5.97.0: SkyrimSE.exe + 0x6310A0 + 0x79 (37799), 1.6.318.0: SkyrimSE.exe + 0x656EE0</summary>
				inline const std::uintptr_t ApplyCombatHitSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(38748) + 0x73 }; // Actor::ApplyWeaponHitSpells

				/// <summary>1.5.97.0: SkyrimSE.exe + 0x732400 + 0x2A7 (42547), 1.6.318.0: SkyrimSE.exe + 0x75D560</summary>
				inline const std::uintptr_t ApplyCombatHitSpellArrowProjectile{ Relocation::AddressLibrary::GetSingleton().GetAddress(43710) + 0x312 }; // ArrowProjectile::AddImpact

				/// <summary>1.5.97.0: SkyrimSE.exe + 0x634BF0 + 0xD2 (37865), 1.6.318.0: SkyrimSE.exe + 0x65ACF0</summary>
				inline const std::uintptr_t ApplyReanimateSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(38820) + 0xD2 }; // Actor::PostReanimate

				/// <summary>1.5.97.0: SkyrimSE.exe + 0x6260F0 + 0xC3 (37628), 1.6.318.0: SkyrimSE.exe + 0x64B7F0</summary>
				inline const std::uintptr_t ApplyWeaponSwingSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(38581) + 0xC6 }; // Actor::WeaponSwingCallback
			}
		}

		namespace PowerAttackStamina
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x80C020 + 0x29B (48139), 1.6.318.0: SkyrimSE.exe + 0x836670</summary>
			inline const std::uintptr_t GetAttackStaminaActor{ Relocation::AddressLibrary::GetSingleton().GetAddress(49170) + 0x27A }; // CombatBehaviorContextMelee::StartAttack

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x63CFB0 + 0xBB (38047), 1.6.318.0: SkyrimSE.exe + 0x663510</summary>
			inline const std::uintptr_t GetAttackStaminaPlayerCharacter{ Relocation::AddressLibrary::GetSingleton().GetAddress(39003) + 0xBB }; // ActorStateManager::TestInterpretedAction

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x80C020 + 0x293 (48139), 1.6.318.0: SkyrimSE.exe + 0x836670</summary>
			inline const std::uintptr_t HasStaminaActor{ Relocation::AddressLibrary::GetSingleton().GetAddress(49170) + 0x272 }; // CombatBehaviorContextMelee::StartAttack

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x63CFB0 + 0xE1 (38047), 1.6.318.0: SkyrimSE.exe + 0x663510</summary>
			inline const std::uintptr_t HasStaminaPlayerCharacter{ Relocation::AddressLibrary::GetSingleton().GetAddress(39003) + 0xE1 }; // ActorStateManager::TestInterpretedAction
		}

		namespace ReflectDamage
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x743510 + 0x544 (42842), 1.6.318.0: SkyrimSE.exe + 0x76FAE0</summary>
			inline const std::uintptr_t CompareReflectDamage{ Relocation::AddressLibrary::GetSingleton().GetAddress(44014) + 0x525 }; // HitData::ReduceDamage
		}

		namespace SteepSlopes
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x60EEF0 + 0x1A (37013), 1.6.318.0: SkyrimSE.exe + 0x62F770</summary>
			inline const std::uintptr_t GetScale{ Relocation::AddressLibrary::GetSingleton().GetAddress(37943) + 0x51 }; // Actor::ModifyMovementTypeBasedOnCurrentState
		}
	}
}
