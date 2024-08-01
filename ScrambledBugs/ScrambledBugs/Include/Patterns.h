#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Patterns
{
	namespace Fixes
	{
		namespace EnchantmentCost
		{
			bool Compare();
		}

		namespace ImpactEffectCrash
		{
			bool DecalApplier();
			bool UpdateDecals();
		}

		namespace IngredientRespawn
		{
			bool SetEmpty();
		}

		namespace KillCamera
		{
			bool ApplyCombatHitSpell();
			bool GetWeapon();
		}

		namespace ProjectileFadeDuration
		{
			bool HasFaded();
			bool HasProcessedImpacts();
		}

		namespace TerrainImpactEffects
		{
			bool FreeCellMopp();
		}

		namespace TrainingMenu
		{
			bool GetPermanentActorValue();
		}
	}

	namespace Patches
	{
		namespace AlreadyCaughtPickpocketing
		{
			bool HasBeenPickpocketed();
			bool IsAngryWithPlayer();
		}

		namespace AttachHitEffectArt
		{
			bool SetCastPermanentMagicFunctorFlags();
		}

		namespace CloakHitEffects
		{
			bool IsNotCostliestEffect();
		}

		namespace LockpickingExperience
		{
			bool HasNotBeenUnlocked();
		}

		namespace PerkEntryPoints
		{
			namespace ApplySpells
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
	}
}
