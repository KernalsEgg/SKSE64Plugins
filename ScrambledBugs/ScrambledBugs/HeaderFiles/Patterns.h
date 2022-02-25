#pragma once

#include "PCH.h"



namespace ScrambledBugs::Patterns
{
	namespace Fixes
	{
		namespace EnchantmentCost
		{
			bool Unequal();
		}

		namespace HarvestedFlags
		{
			bool RemoveHarvestedFlag();
		}

		namespace ImpactEffectCrash
		{
			bool DecalApplier();
			bool MainUpdate();
		}

		namespace KillCamera
		{
			bool HasWeapon();
		}

		namespace TerrainDecals
		{
			bool UnloadCellMopp();
		}

		namespace TrainingMenu
		{
			bool GetPermanentActorValue();
		}
	}

	namespace Patches
	{
		namespace AccumulatingMagnitude
		{
			bool Constructor();
		}

		namespace AlreadyCaughtPickpocketing
		{
			bool AttackOnSight();
			bool HasBeenPickpocketed();
		}

		namespace AttachHitEffectArt
		{
			bool AddNoHitEffectArtFlag();
			bool Attach();
			bool IsPerspectiveChange();
			bool IsPlayerAttach();
			bool IsPlayerUpdatePosition();
		}

		namespace CloakHitEffects
		{
			bool IsNotCostliestEffect();
		}

		namespace EquipBestAmmo
		{
			bool CompareDamageContainer();
			bool CompareDamageInventoryChanges();
			bool InitializeDamage();
			bool IsBoltContainer();
			bool IsBoltInventoryChanges();
		}

		namespace LockpickingExperience
		{
			bool HasNotBeenUnlocked();
		}

		namespace PausedGameHitEffects
		{
			bool ApplyHitEffects();
		}

		namespace PerkEntryPoints
		{
			namespace ApplyMultipleSpells
			{
				bool ApplyBashingSpell();
				bool ApplyCombatHitSpell();
				bool ApplyCombatHitSpellArrowProjectile();
				bool ApplyReanimateSpell();
				bool ApplySneakingSpell();
				bool ApplyWeaponSwingSpell();
			}

			namespace CastSpells
			{
				bool ApplyBashingSpell();
				bool ApplyCombatHitSpell();
				bool ApplyCombatHitSpellArrowProjectile();
				bool ApplyReanimateSpell();
				bool ApplyWeaponSwingSpell();
			}
		}

		namespace PowerAttackStamina
		{
			bool GetAttackStaminaActor();
			bool GetAttackStaminaPlayerCharacter();
			bool HasStaminaActor();
			bool HasStaminaPlayerCharacter();
		}

		namespace ReflectDamage
		{
			bool CompareReflectDamage();
		}

		namespace SteepSlopes
		{
			bool GetScale();
		}

		namespace UnderfilledSoulGems
		{
			bool CompareSoulLevelValue();
		}
	}
}
