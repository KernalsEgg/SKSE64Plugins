#pragma once

#include "PCH.h"

#include "Shared/Relocation/AddressLibrary.h"



namespace ScrambledBugs::Addresses
{
	namespace Fixes
	{
		namespace ActorValuePercentage
		{
			/// <summary>Actor::GetActorValuePercentage (SkyrimSE.exe + 0x5D6500)</summary>
			inline const std::uintptr_t GetActorValuePercentage{ Relocation::AddressLibrary::GetSingleton().GetAddress(36347) + 0x0 };

			/// <summary>Actor::GetHealthPercentage (SkyrimSE.exe + 0x5D6640)</summary>
			inline const std::uintptr_t GetHealthPercentage{ Relocation::AddressLibrary::GetSingleton().GetAddress(36349) + 0x0 };

			/// <summary>Actor::GetStaminaPercentage (SkyrimSE.exe + 0x5D6570)</summary>
			inline const std::uintptr_t GetStaminaPercentage{ Relocation::AddressLibrary::GetSingleton().GetAddress(36348) + 0x0 };
		}

		namespace EnchantmentCost
		{
			/// <summary>PersistentFormManager::GetIndex (SkyrimSE.exe + 0x5A1070)</summary>
			inline const std::uintptr_t Unequal{ Relocation::AddressLibrary::GetSingleton().GetAddress(35284) + 0x72 };
		}

		namespace HarvestedFlags
		{
			/// <summary>TESObjectREFR::Respawn (SkyrimSE.exe + 0x278920)</summary>
			inline const std::uintptr_t RemoveHarvestedFlag{ Relocation::AddressLibrary::GetSingleton().GetAddress(18843) + 0x31C };
		}

		namespace HitEffectRaceCondition
		{
			/// <summary>ActiveEffect::ShouldUpdate (SkyrimSE.exe + 0x53E670)</summary>
			inline const std::uintptr_t ShouldUpdate{ Relocation::AddressLibrary::GetSingleton().GetAddress(33289) + 0x0 };
		}

		namespace KillCamera
		{
			/// <summary>ArrowProjectile::GetImpactData (SkyrimSE.exe + 0x732400)</summary>
			inline const std::uintptr_t HasWeapon{ Relocation::AddressLibrary::GetSingleton().GetAddress(42547) + 0x261 };
		}

		namespace MagicEffectFlags
		{
			/// <summary>ActiveEffect::SetEffectiveness (SkyrimSE.exe + 0x540360)</summary>
			inline const std::uintptr_t SetEffectiveness{ Relocation::AddressLibrary::GetSingleton().GetAddress(33320) + 0x0 };
		}

		namespace ModArmorWeightPerkEntryPoint
		{
			/// <summary>InventoryChanges::UpdateInventoryWeight (SkyrimSE.exe + 0x1E9130)</summary>
			inline const std::uintptr_t UpdateInventoryWeight{ Relocation::AddressLibrary::GetSingleton().GetAddress(15883) + 0x0 };
		}

		namespace QuickShot
		{
			/// <summary>ArrowProjectile::GetArrowPower (SkyrimSE.exe + 0x3BF020)</summary>
			inline const std::uintptr_t GetArrowPower{ Relocation::AddressLibrary::GetSingleton().GetAddress(25868) + 0x0 };
		}

		namespace TerrainDecals
		{
			/// <summary>SkyrimSE.exe + 0x271BE0</summary>
			inline const std::uintptr_t UnloadCellMopp{ Relocation::AddressLibrary::GetSingleton().GetAddress(18711) + 0xE7 };
		}

		namespace TrainingMenu
		{
			/// <summary>TrainingMenu::UpdateText (SkyrimSE.exe + 0x8CEA30)</summary>
			inline const std::uintptr_t GetPermanentActorValue{ Relocation::AddressLibrary::GetSingleton().GetAddress(51794) + 0x289 };
		}

		namespace WeaponCharge
		{
			/// <summary>Actor::UpdateWeaponEnchantments (SkyrimSE.exe + 0x6313D0)</summary>
			inline const std::uintptr_t UpdateWeaponEnchantments{ Relocation::AddressLibrary::GetSingleton().GetAddress(37803) + 0x0 };
		}
	}

	namespace Patches
	{
		namespace AccumulatingMagnitude
		{
			/// <summary>AccumulatingValueModifierEffect::Allocate (SkyrimSE.exe + 0x53D370)</summary>
			inline const std::uintptr_t Constructor{ Relocation::AddressLibrary::GetSingleton().GetAddress(33257) + 0x96 };
		}

		namespace AlreadyCaughtPickpocketing
		{
			/// <summary>TESNPC::Activate (SkyrimSE.exe + 0x360C10)</summary>
			inline const std::uintptr_t AttackOnSight{ Relocation::AddressLibrary::GetSingleton().GetAddress(24211) + 0x678 };

			/// <summary>TESNPC::Activate (SkyrimSE.exe + 0x360C10)</summary>
			inline const std::uintptr_t HasBeenPickpocketed{ Relocation::AddressLibrary::GetSingleton().GetAddress(24211) + 0x694 };
		}

		namespace AttachHitEffectArt
		{
			/// <summary>SkyrimSE.exe + 0x6314F0</summary>
			inline const std::uintptr_t AddNoHitEffectArtFlag{ Relocation::AddressLibrary::GetSingleton().GetAddress(37804) + 0x6F };

			/// <summary>ModelReferenceEffect::UpdatePosition (SkyrimSE.exe + 0x558220)</summary>
			inline const std::uintptr_t Attach{ Relocation::AddressLibrary::GetSingleton().GetAddress(33862) + 0x9F };

			/// <summary>ModelReferenceEffect::UpdatePosition (SkyrimSE.exe + 0x558220)</summary>
			inline const std::uintptr_t IsPerspectiveChange{ Relocation::AddressLibrary::GetSingleton().GetAddress(33862) + 0x9A };

			/// <summary>ModelReferenceEffect::Attach (SkyrimSE.exe + 0x558F20)</summary>
			inline const std::uintptr_t IsPlayerAttach{ Relocation::AddressLibrary::GetSingleton().GetAddress(33872) + 0x32 };

			/// <summary>ModelReferenceEffect::UpdatePosition (SkyrimSE.exe + 0x558220)</summary>
			inline const std::uintptr_t IsPlayerUpdatePosition{ Relocation::AddressLibrary::GetSingleton().GetAddress(33862) + 0x7C };
		}

		namespace CloakHitEffects
		{
			/// <summary>SkyrimSE.exe + 0x5468E0</summary>
			inline const std::uintptr_t IsNotCostliestEffect{ Relocation::AddressLibrary::GetSingleton().GetAddress(33471) + 0x15 };
		}

		namespace EquipBestAmmo
		{
			/// <summary>InventoryChanges::GetWorstAmmo (SkyrimSE.exe + 0x1E3090)</summary>
			inline const std::uintptr_t CompareDamageContainer{ Relocation::AddressLibrary::GetSingleton().GetAddress(15846) + 0x11A };

			/// <summary>InventoryChanges::GetWorstAmmo (SkyrimSE.exe + 0x1E3090)</summary>
			inline const std::uintptr_t CompareDamageInventoryChanges{ Relocation::AddressLibrary::GetSingleton().GetAddress(15846) + 0x1E1 };

			/// <summary>SkyrimSE.exe + 0x1536BB4</summary>
			inline const std::uintptr_t FloatMinimumValue{ Relocation::AddressLibrary::GetSingleton().GetAddress(230697) };

			/// <summary>InventoryChanges::GetWorstAmmo (SkyrimSE.exe + 0x1E3090)</summary>
			inline const std::uintptr_t InitializeDamage{ Relocation::AddressLibrary::GetSingleton().GetAddress(15846) + 0x5F };

			/// <summary>InventoryChanges::GetWorstAmmo (SkyrimSE.exe + 0x1E3090)</summary>
			inline const std::uintptr_t IsBoltContainer{ Relocation::AddressLibrary::GetSingleton().GetAddress(15846) + 0xAE };

			/// <summary>InventoryChanges::GetWorstAmmo (SkyrimSE.exe + 0x1E3090)</summary>
			inline const std::uintptr_t IsBoltInventoryChanges{ Relocation::AddressLibrary::GetSingleton().GetAddress(15846) + 0x162 };
		}

		namespace LeveledCharacters
		{
			/// <summary>ExtraLevCreaModifier::GetLeveledCreatureModifier (SkyrimSE.exe + 0x1384D0)</summary>
			inline const std::uintptr_t GetLeveledCreatureModifier{ Relocation::AddressLibrary::GetSingleton().GetAddress(12448) + 0x0 };
		}

		namespace LockpickingExperience
		{
			/// <summary>SkyrimSE.exe + 0x897E10</summary>
			inline const std::uintptr_t HasNotBeenUnlocked{ Relocation::AddressLibrary::GetSingleton().GetAddress(51088) + 0x2C };
		}

		namespace PausedGameHitEffects
		{
			/// <summary>SkyrimSE.exe + 0x5402D0</summary>
			inline const std::uintptr_t ApplyHitEffects{ Relocation::AddressLibrary::GetSingleton().GetAddress(33319) + 0x37 };
		}

		namespace PerkEntryPoints
		{
			namespace ApplyMultipleSpells
			{
				/// <summary>Actor::WeaponHit (SkyrimSE.exe + 0x628C20)</summary>
				inline const std::uintptr_t ApplyBashingSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(37673) + 0x40E };

				/// <summary>Actor::ApplyWeaponHitSpells (SkyrimSE.exe + 0x6310A0)</summary>
				inline const std::uintptr_t ApplyCombatHitSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(37799) + 0x61 };

				/// <summary>ArrowProjectile::GetImpactData (SkyrimSE.exe + 0x732400)</summary>
				inline const std::uintptr_t ApplyCombatHitSpellArrowProjectile{ Relocation::AddressLibrary::GetSingleton().GetAddress(42547) + 0x28B };

				/// <summary>ReanimateEffect::GetUp (SkyrimSE.exe + 0x634BF0)</summary>
				inline const std::uintptr_t ApplyReanimateSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(37865) + 0xBA };

				/// <summary>Actor::SetSneaking (SkyrimSE.exe + 0x6089E0)</summary>
				inline const std::uintptr_t ApplySneakingSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(36926) + 0xB6 };

				/// <summary>Actor::WeaponSwing (SkyrimSE.exe + 0x6260F0)</summary>
				inline const std::uintptr_t ApplyWeaponSwingSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(37628) + 0xAB };

				/// <summary>SkyrimSE.exe + 0x1DD3B20</summary>
				inline const std::uintptr_t SelectSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(675819) };

				/// <summary>SkyrimSE.exe + 0x1DD3BB0</summary>
				inline const std::uintptr_t SelectSpellResultCount{ Relocation::AddressLibrary::GetSingleton().GetAddress(502190) };
			}

			namespace CastSpells
			{
				/// <summary>Actor::WeaponHit (SkyrimSE.exe + 0x628C20)</summary>
				inline const std::uintptr_t ApplyBashingSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(37673) + 0x429 };

				/// <summary>Actor::ApplyWeaponHitSpells (SkyrimSE.exe + 0x6310A0)</summary>
				inline const std::uintptr_t ApplyCombatHitSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(37799) + 0x79 };

				/// <summary>ArrowProjectile::GetImpactData (SkyrimSE.exe + 0x732400)</summary>
				inline const std::uintptr_t ApplyCombatHitSpellArrowProjectile{ Relocation::AddressLibrary::GetSingleton().GetAddress(42547) + 0x2A7 };

				/// <summary>ReanimateEffect::GetUp (SkyrimSE.exe + 0x634BF0)</summary>
				inline const std::uintptr_t ApplyReanimateSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(37865) + 0xD2 };

				/// <summary>Actor::WeaponSwing (SkyrimSE.exe + 0x6260F0)</summary>
				inline const std::uintptr_t ApplyWeaponSwingSpell{ Relocation::AddressLibrary::GetSingleton().GetAddress(37628) + 0xC3 };
			}
		}

		namespace PowerAttackStamina
		{
			/// <summary>SkyrimSE.exe + 0x80C020</summary>
			inline const std::uintptr_t GetAttackStaminaActor{ Relocation::AddressLibrary::GetSingleton().GetAddress(48139) + 0x29B };

			/// <summary>SkyrimSE.exe + 0x63CFB0</summary>
			inline const std::uintptr_t GetAttackStaminaPlayerCharacter{ Relocation::AddressLibrary::GetSingleton().GetAddress(38047) + 0xBB };

			/// <summary>SkyrimSE.exe + 0x80C020</summary>
			inline const std::uintptr_t HasStaminaActor{ Relocation::AddressLibrary::GetSingleton().GetAddress(48139) + 0x293 };

			/// <summary>SkyrimSE.exe + 0x63CFB0</summary>
			inline const std::uintptr_t HasStaminaPlayerCharacter{ Relocation::AddressLibrary::GetSingleton().GetAddress(38047) + 0xE1 };
		}

		namespace ReflectDamage
		{
			/// <summary>SkyrimSE.exe + 0x743510</summary>
			inline const std::uintptr_t CompareReflectDamage{ Relocation::AddressLibrary::GetSingleton().GetAddress(42842) + 0x544 };
		}

		namespace TeammateDifficulty
		{
			/// <summary>Actor::MultiplyDamage (SkyrimSE.exe + 0x5E4800)</summary>
			inline const std::uintptr_t MultiplyDamage{ Relocation::AddressLibrary::GetSingleton().GetAddress(36506) + 0x0 };
		}

		namespace UnderfilledSoulGems
		{
			/// <summary>SkyrimSE.exe + 0x1E5050</summary>
			inline const std::uintptr_t CompareSoulLevelValue{ Relocation::AddressLibrary::GetSingleton().GetAddress(15854) + 0xE6 };
		}
	}
}
