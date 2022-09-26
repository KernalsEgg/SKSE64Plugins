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
			inline const std::uintptr_t NotEqual{ Relocation::AddressLibrary::GetSingleton().GetAddress(36184) + 0x99 }; // PersistentFormManager::AddEnchantment
		}

		namespace HarvestedFlags
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x278920 + 0x31C (18843), 1.6.318.0: SkyrimSE.exe + 0x28AD80</summary>
			inline const std::uintptr_t RemoveHarvestedFlag{ Relocation::AddressLibrary::GetSingleton().GetAddress(19286) + 0x345 }; // TESObjectREFR::Respawn
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
			inline const std::uintptr_t MainUpdate{ Relocation::AddressLibrary::GetSingleton().GetAddress(15220) + 0x122 };
		}

		namespace KillCamera
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x732400 + 0x261 (42547), 1.6.318.0: SkyrimSE.exe + 0x75D560</summary>
			inline const std::uintptr_t HasWeapon{ Relocation::AddressLibrary::GetSingleton().GetAddress(43710) + 0x2D0 }; // ArrowProjectile::GetImpactData
		}

		namespace LeftHandPowerAttacks
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x3BEC90 (25863), 1.6.318.0: SkyrimSE.exe + 0x3D6720</summary>
			inline const std::uintptr_t GetAttackStamina{ Relocation::AddressLibrary::GetSingleton().GetAddress(26429) }; // ActorValueOwner::GetAttackStamina
		}

		namespace MagicEffectFlags
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x53E1B0 (33283), 1.6.318.0: SkyrimSE.exe + 0x558180</summary>
			inline const std::uintptr_t ResetElapsedTime{ Relocation::AddressLibrary::GetSingleton().GetAddress(34058) }; // ActiveEffect::ResetElapsedTime

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x53DEB0 (33277), 1.6.318.0: SkyrimSE.exe + 0x557E00</summary>
			inline const std::uintptr_t SetEffectiveness{ Relocation::AddressLibrary::GetSingleton().GetAddress(34052) }; // ActiveEffect::SetEffectiveness
		}

		namespace ModArmorWeightPerkEntryPoint
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1E9130 (15883), 1.6.318.0: SkyrimSE.exe + 0x1F4960</summary>
			inline const std::uintptr_t GetInventoryWeight{ Relocation::AddressLibrary::GetSingleton().GetAddress(16123) }; // InventoryChanges::GetInventoryWeight
		}

		namespace PowerCooldowns
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x6309C0 (37794), 1.6.318.0: SkyrimSE.exe + 0x6567B0</summary>
			inline const std::uintptr_t SavePowerCooldowns{ Relocation::AddressLibrary::GetSingleton().GetAddress(38743) }; // Actor::SavePowerCooldowns
		}

		namespace QuickShot
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x3BF020 (25868), 1.6.318.0: SkyrimSE.exe + 0x3D6AB0</summary>
			inline const std::uintptr_t GetArrowPower{ Relocation::AddressLibrary::GetSingleton().GetAddress(26435) }; // ArrowProjectile::GetArrowPower
		}

		namespace TerrainDecals
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x271BE0 + 0xE7 (18711), 1.6.318.0: SkyrimSE.exe + 0x27FC50</summary>
			inline const std::uintptr_t UnloadCellMopp{ Relocation::AddressLibrary::GetSingleton().GetAddress(19130) + 0x24E };
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
		namespace AccumulatingMagnitude
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x2F25D50 (516691), 1.6.318.0: SkyrimSE.exe + 0x2FC0140</summary>
			inline const std::uintptr_t ActiveEffectAllocateFunctions{ Relocation::AddressLibrary::GetSingleton().GetAddress(402892) };
		}

		namespace AlreadyCaughtPickpocketing
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x360C10 + 0x678 (24211), 1.6.318.0: SkyrimSE.exe + 0x377A00</summary>
			inline const std::uintptr_t AttackOnSight{ Relocation::AddressLibrary::GetSingleton().GetAddress(24715) + 0x695 }; // TESNPC::Activate

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x360C10 + 0x694 (24211), 1.6.318.0: SkyrimSE.exe + 0x377A00</summary>
			inline const std::uintptr_t HasBeenPickpocketed{ Relocation::AddressLibrary::GetSingleton().GetAddress(24715) + 0x6B1 }; // TESNPC::Activate
		}

		namespace AttachHitEffectArt
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x6314F0 + 0x6F (37804), 1.6.318.0: SkyrimSE.exe + 0x657450</summary>
			inline const std::uintptr_t AddNoHitEffectArtFlag{ Relocation::AddressLibrary::GetSingleton().GetAddress(38753) + 0x6F };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x558F20 + 0x1E (33872), 1.6.318.0: SkyrimSE.exe + 0x573E60</summary>
			inline const std::uintptr_t GetTargetActor{ Relocation::AddressLibrary::GetSingleton().GetAddress(34658) + 0xB9 }; // ModelReferenceEffect::UpdatePosition

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x558220 + 0x9A (33862), 1.6.318.0: SkyrimSE.exe + 0x573E60</summary>
			inline const std::uintptr_t IsPerspectiveChange{ Relocation::AddressLibrary::GetSingleton().GetAddress(34658) + 0xA9 }; // ModelReferenceEffect::UpdatePosition

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x558F20 + 0x32 (33872), 1.6.318.0: SkyrimSE.exe + 0x573E60</summary>
			inline const std::uintptr_t IsPlayerAttach{ Relocation::AddressLibrary::GetSingleton().GetAddress(34658) + 0xCD }; // ModelReferenceEffect::UpdatePosition

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x558220 + 0x7C (33862), 1.6.318.0: SkyrimSE.exe + 0x573E60</summary>
			inline const std::uintptr_t IsPlayerUpdatePosition{ Relocation::AddressLibrary::GetSingleton().GetAddress(34658) + 0x83 }; // ModelReferenceEffect::UpdatePosition
		}

		namespace CloakHitEffects
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x5468E0 + 0x15 (33471), 1.6.318.0: SkyrimSE.exe + 0x561730</summary>
			inline const std::uintptr_t IsNotCostliestEffect{ Relocation::AddressLibrary::GetSingleton().GetAddress(34250) + 0x15 };
		}

		namespace EquipBestAmmo
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1E3090 + 0x11A (15846), 1.6.318.0: SkyrimSE.exe + 0x1EE7F0</summary>
			inline const std::uintptr_t CompareDamageContainer{ Relocation::AddressLibrary::GetSingleton().GetAddress(16086) + 0x11A }; // InventoryChanges::GetWorstAmmo

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1E3090 + 0x1E1 (15846), 1.6.318.0: SkyrimSE.exe + 0x1EE7F0</summary>
			inline const std::uintptr_t CompareDamageInventoryChanges{ Relocation::AddressLibrary::GetSingleton().GetAddress(16086) + 0x1E1 }; // InventoryChanges::GetWorstAmmo

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1536BB4 (230697), 1.6.318.0: SkyrimSE.exe + 0x162DF5C</summary>
			inline const std::uintptr_t FloatMinimumValue{ Relocation::AddressLibrary::GetSingleton().GetAddress(187412) };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1E3090 + 0x5F (15846), 1.6.318.0: SkyrimSE.exe + 0x1EE7F0</summary>
			inline const std::uintptr_t InitializeDamage{ Relocation::AddressLibrary::GetSingleton().GetAddress(16086) + 0x5F }; // InventoryChanges::GetWorstAmmo

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1E3090 + 0xAE (15846), 1.6.318.0: SkyrimSE.exe + 0x1EE7F0</summary>
			inline const std::uintptr_t IsBoltContainer{ Relocation::AddressLibrary::GetSingleton().GetAddress(16086) + 0xAE }; // InventoryChanges::GetWorstAmmo

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1E3090 + 0x162 (15846), 1.6.318.0: SkyrimSE.exe + 0x1EE7F0</summary>
			inline const std::uintptr_t IsBoltInventoryChanges{ Relocation::AddressLibrary::GetSingleton().GetAddress(16086) + 0x162 }; // InventoryChanges::GetWorstAmmo
		}

		namespace LeveledCharacters
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x1384D0 (12448), 1.6.318.0: SkyrimSE.exe + 0x13EED0</summary>
			inline const std::uintptr_t GetLeveledCreatureModifier{ Relocation::AddressLibrary::GetSingleton().GetAddress(12582) }; // ExtraLevCreaModifier::GetLeveledCreatureModifier
		}

		namespace LockpickingExperience
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x897E10 + 0x2C (51088), 1.6.318.0: SkyrimSE.exe + 0x8C8730</summary>
			inline const std::uintptr_t HasNotBeenUnlocked{ Relocation::AddressLibrary::GetSingleton().GetAddress(51968) + 0x2C }; // LockpickingMenu::Unlock
		}

		namespace PausedGameHitEffects
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x5402D0 + 0x37 (33319), 1.6.318.0: SkyrimSE.exe + 0x55A710</summary>
			inline const std::uintptr_t ShouldApplyHitEffects{ Relocation::AddressLibrary::GetSingleton().GetAddress(34094) + 0x52 }; // ActiveEffect::ApplyVisualEffects
		}

		namespace PerkEntryPoints
		{
			namespace ApplyMultipleSpells
			{
				/// <summary>1.5.97.0: SkyrimSE.exe + 0x628C20 + 0x40E (37673), 1.6.318.0: SkyrimSE.exe + 0x64E760</summary>
				inline const std::uintptr_t ApplyBashingSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(38627) + 0x4FA }; // Actor::WeaponHit

				/// <summary>1.5.97.0: SkyrimSE.exe + 0x6310A0 + 0x61 (37799), 1.6.318.0: SkyrimSE.exe + 0x656EE0</summary>
				inline const std::uintptr_t ApplyCombatHitSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(38748) + 0x5B }; // Actor::ApplyWeaponHitSpells

				/// <summary>1.5.97.0: SkyrimSE.exe + 0x732400 + 0x28B (42547), 1.6.318.0: SkyrimSE.exe + 0x75D560</summary>
				inline const std::uintptr_t ApplyCombatHitSpellArrowProjectile{ Relocation::AddressLibrary::GetSingleton().GetAddress(43710) + 0x2F6 }; // ArrowProjectile::GetImpactData

				/// <summary>1.5.97.0: SkyrimSE.exe + 0x634BF0 + 0xBA (37865), 1.6.318.0: SkyrimSE.exe + 0x65ACF0</summary>
				inline const std::uintptr_t ApplyReanimateSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(38820) + 0xBA }; // ReanimateEffect::GetUp

				/// <summary>1.5.97.0: SkyrimSE.exe + 0x6089E0 + 0xB6 (36926), 1.6.318.0: SkyrimSE.exe + 0x6301D0</summary>
				inline const std::uintptr_t ApplySneakingSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(37951) + 0x72 }; // Actor::SetSneaking

				/// <summary>1.5.97.0: SkyrimSE.exe + 0x6260F0 + 0xAB (37628), 1.6.318.0: SkyrimSE.exe + 0x64B7F0</summary>
				inline const std::uintptr_t ApplyWeaponSwingSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(38581) + 0xAE }; // Actor::WeaponSwing

				/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DD3B20 (675819), 1.6.318.0: SkyrimSE.exe + 0x1E67C10</summary>
				inline const std::uintptr_t SelectSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(369199) }; // BGSEntryPointFunction::SelectSpellFunction

				/// <summary>1.5.97.0: SkyrimSE.exe + 0x1DD3BB0 (502190), 1.6.318.0: SkyrimSE.exe + 0x1E67CA0</summary>
				inline const std::uintptr_t SelectSpellResultCount{ Relocation::AddressLibrary::GetSingleton().GetAddress(369213) };
			}

			namespace CastSpells
			{
				/// <summary>1.5.97.0: SkyrimSE.exe + 0x628C20 + 0x429 (37673), 1.6.318.0: SkyrimSE.exe + 0x64E760</summary>
				inline const std::uintptr_t ApplyBashingSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(38627) + 0x517 }; // Actor::WeaponHit

				/// <summary>1.5.97.0: SkyrimSE.exe + 0x6310A0 + 0x79 (37799), 1.6.318.0: SkyrimSE.exe + 0x656EE0</summary>
				inline const std::uintptr_t ApplyCombatHitSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(38748) + 0x73 }; // Actor::ApplyWeaponHitSpells

				/// <summary>1.5.97.0: SkyrimSE.exe + 0x732400 + 0x2A7 (42547), 1.6.318.0: SkyrimSE.exe + 0x75D560</summary>
				inline const std::uintptr_t ApplyCombatHitSpellArrowProjectile{ Relocation::AddressLibrary::GetSingleton().GetAddress(43710) + 0x312 }; // ArrowProjectile::GetImpactData

				/// <summary>1.5.97.0: SkyrimSE.exe + 0x634BF0 + 0xD2 (37865), 1.6.318.0: SkyrimSE.exe + 0x65ACF0</summary>
				inline const std::uintptr_t ApplyReanimateSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(38820) + 0xD2 }; // ReanimateEffect::GetUp

				/// <summary>1.5.97.0: SkyrimSE.exe + 0x6260F0 + 0xC3 (37628), 1.6.318.0: SkyrimSE.exe + 0x64B7F0</summary>
				inline const std::uintptr_t ApplyWeaponSwingSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(38581) + 0xC6 }; // Actor::WeaponSwing
			}
		}

		namespace PowerAttackStamina
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x80C020 + 0x29B (48139), 1.6.318.0: SkyrimSE.exe + 0x836670</summary>
			inline const std::uintptr_t GetAttackStaminaActor{ Relocation::AddressLibrary::GetSingleton().GetAddress(49170) + 0x27A };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x63CFB0 + 0xBB (38047), 1.6.318.0: SkyrimSE.exe + 0x663510</summary>
			inline const std::uintptr_t GetAttackStaminaPlayerCharacter{ Relocation::AddressLibrary::GetSingleton().GetAddress(39003) + 0xBB };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x80C020 + 0x293 (48139), 1.6.318.0: SkyrimSE.exe + 0x836670</summary>
			inline const std::uintptr_t HasStaminaActor{ Relocation::AddressLibrary::GetSingleton().GetAddress(49170) + 0x272 };

			/// <summary>1.5.97.0: SkyrimSE.exe + 0x63CFB0 + 0xE1 (38047), 1.6.318.0: SkyrimSE.exe + 0x663510</summary>
			inline const std::uintptr_t HasStaminaPlayerCharacter{ Relocation::AddressLibrary::GetSingleton().GetAddress(39003) + 0xE1 };
		}

		namespace ReflectDamage
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x743510 + 0x544 (42842), 1.6.318.0: SkyrimSE.exe + 0x76FAE0</summary>
			inline const std::uintptr_t CompareReflectDamage{ Relocation::AddressLibrary::GetSingleton().GetAddress(44014) + 0x525 };
		}

		namespace SteepSlopes
		{
			/// <summary>1.5.97.0: SkyrimSE.exe + 0x60EEF0 + 0x1A (37013), 1.6.318.0: SkyrimSE.exe + 0x62F770</summary>
			inline const std::uintptr_t GetScale{ Relocation::AddressLibrary::GetSingleton().GetAddress(37943) + 0x51 }; // Actor::SetMaximumMovementSpeed
		}
	}
}
