#include "PrecompiledHeader.h"

#include "Patterns.h"

#include "Addresses.h"
#include "Shared/Relocation/AddressLibrary.h"
#include "Shared/Relocation/PreprocessorDirectives.h"



namespace ScrambledBugs::Patterns
{
	namespace Fixes
	{
		namespace EnchantmentCost
		{
			bool Compare()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Fixes::EnchantmentCost::Compare, // 0x5
					0xE8ui8, std::optional<std::int32_t>{}      // call EffectItem::Compare
				);
			}
		}

		namespace ImpactEffectCrash
		{
			bool DecalApplier()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Fixes::ImpactEffectCrash::DecalApplier, // 0x5
					0xE8ui8, std::optional<std::int32_t>{}             // call BSTempEffectSimpleDecal::Apply
				);
			}

			bool UpdateDecals()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Fixes::ImpactEffectCrash::UpdateDecals, // 0x5
					0xE8ui8, std::optional<std::int32_t>{}             // call BSTempEffectSimpleDecal::Apply
				);
			}
		}

		namespace IngredientRespawn
		{
			bool SetEmpty()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Fixes::IngredientRespawn::SetEmpty, // 0x5
					0xE8ui8, std::optional<std::int32_t>{}         // call TESForm::SetEmpty
				);
			}
		}

		namespace KillCamera
		{
			bool ApplyCombatHitSpell()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Fixes::KillCamera::ApplyCombatHitSpell, // 0x5
					0xE8ui8, std::optional<std::int32_t>{}             // call BGSEntryPoint::HandleEntryPoint
				);
			}

			bool GetWeapon()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Fixes::KillCamera::GetWeapon,
					SKYRIM_RELOCATE(
						SKYRIM_VARIADIC_ARGUMENTS(                                                                             // 0x7
							0x4Cui8, 0x8Bui8, 0x87ui8, static_cast<std::int32_t>(offsetof(Skyrim::Projectile, weaponSource))), // mov r8, [rdi+1B0]
						SKYRIM_VARIADIC_ARGUMENTS(                                                                             // 0x7
							0x4Cui8, 0x8Bui8, 0x86ui8, static_cast<std::int32_t>(offsetof(Skyrim::Projectile, weaponSource)))) // mov r8, [rsi+1B8]
				);
			}
		}

		namespace ProjectileFadeDuration
		{
			bool HasFaded()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Fixes::ProjectileFadeDuration::HasFaded, // 0x2
					0x72ui8, 0x32ui8                                    // jb 32
				);
			}

			bool HasProcessedImpacts()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Fixes::ProjectileFadeDuration::HasProcessedImpacts, // 0x2
					0x0Fui8, 0x84ui8, 0x183ui32                                    // je 183
				);
			}
		}

		namespace TerrainImpactEffects
		{
			bool FreeCellMopp()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Fixes::TerrainImpactEffects::FreeCellMopp, // 0x5
					0xE8ui8, std::optional<std::int32_t>{}                // call TESObjectCELL::FreeCellMopp
				);
			}
		}

		namespace TrainingMenu
		{
			bool GetPermanentActorValue()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Fixes::TrainingMenu::GetPermanentActorValue, // 0x3
					0xFFui8, 0x50ui8, 0x10ui8                               // call [rax+10] (ActorValueOwner::GetPermanentActorValue)
				);
			}
		}
	}

	namespace Patches
	{
		namespace AlreadyCaughtPickpocketing
		{
			bool HasBeenPickpocketed()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::AlreadyCaughtPickpocketing::HasBeenPickpocketed, // 0x2
					0x75ui8, 0x14ui8                                                     // jne 14
				);
			}

			bool IsAngryWithPlayer()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::AlreadyCaughtPickpocketing::IsAngryWithPlayer, // 0x2
					0x75ui8, 0x30ui8                                                   // jne 30
				);
			}
		}

		namespace AttachHitEffectArt
		{
			bool SetCastPermanentMagicFunctorFlags()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::AttachHitEffectArt::SetCastPermanentMagicFunctorFlags, // 2 + 2 = 0x4
					0x24ui8, 0xF9ui8,                                                          // and al, F9
					0x0Cui8, 0x01ui8                                                           // or al, 1
				);
			}
		}

		namespace CloakHitEffects
		{
			bool IsNotCostliestEffect()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::CloakHitEffects::IsNotCostliestEffect, // 0x2
					0x74ui8, 0x0Aui8                                           // je A
				);
			}
		}

		namespace LockpickingExperience
		{
			bool HasNotBeenUnlocked()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::LockpickingExperience::HasNotBeenUnlocked, // 0x2
					0x75ui8, 0x50ui8                                               // jne 50
				);
			}
		}

		namespace PerkEntryPoints
		{
			namespace ApplySpells
			{
				bool ApplyBashingSpell()
				{
					return Relocation::AddressLibrary::MatchPattern(
						Addresses::Patches::PerkEntryPoints::ApplySpells::ApplyBashingSpell, // 0x5
						0xE8ui8, std::optional<std::int32_t>{}                               // call BGSEntryPoint::HandleEntryPoint
					);
				}

				bool ApplyCombatHitSpell()
				{
					return Relocation::AddressLibrary::MatchPattern(
						Addresses::Patches::PerkEntryPoints::ApplySpells::ApplyCombatHitSpell, // 0x5
						0xE8ui8, std::optional<std::int32_t>{}                                 // call BGSEntryPoint::HandleEntryPoint
					);
				}

				bool ApplyCombatHitSpellArrowProjectile()
				{
					return Relocation::AddressLibrary::MatchPattern(
						Addresses::Patches::PerkEntryPoints::ApplySpells::ApplyCombatHitSpellArrowProjectile, // 0x5
						0xE8ui8, std::optional<std::int32_t>{}                                                // call BGSEntryPoint::HandleEntryPoint
					);
				}

				bool ApplyReanimateSpell()
				{
					return Relocation::AddressLibrary::MatchPattern(
						Addresses::Patches::PerkEntryPoints::ApplySpells::ApplyReanimateSpell, // 0x5
						0xE8ui8, std::optional<std::int32_t>{}                                 // call BGSEntryPoint::HandleEntryPoint
					);
				}

				bool ApplySneakingSpell()
				{
					return Relocation::AddressLibrary::MatchPattern(
						Addresses::Patches::PerkEntryPoints::ApplySpells::ApplySneakingSpell, // 0x5
						0xE8ui8, std::optional<std::int32_t>{}                                // call BGSEntryPoint::HandleEntryPoint
					);
				}

				bool ApplyWeaponSwingSpell()
				{
					return Relocation::AddressLibrary::MatchPattern(
						Addresses::Patches::PerkEntryPoints::ApplySpells::ApplyWeaponSwingSpell, // 0x5
						0xE8ui8, std::optional<std::int32_t>{}                                   // call BGSEntryPoint::HandleEntryPoint
					);
				}
			}

			namespace CastSpells
			{
				bool ApplyBashingSpell()
				{
					return Relocation::AddressLibrary::MatchPattern(
						Addresses::Patches::PerkEntryPoints::CastSpells::ApplyBashingSpell, // 0x5
						0xE8ui8, std::optional<std::int32_t>{}                              // call Actor::ApplySpellItem
					);
				}

				bool ApplyCombatHitSpell()
				{
					return Relocation::AddressLibrary::MatchPattern(
						Addresses::Patches::PerkEntryPoints::CastSpells::ApplyCombatHitSpell, // 0x5
						0xE8ui8, std::optional<std::int32_t>{}                                // call Actor::ApplySpellItem
					);
				}

				bool ApplyCombatHitSpellArrowProjectile()
				{
					return Relocation::AddressLibrary::MatchPattern(
						Addresses::Patches::PerkEntryPoints::CastSpells::ApplyCombatHitSpellArrowProjectile, // 0x5
						0xE8ui8, std::optional<std::int32_t>{}                                               // call Actor::ApplySpellItem
					);
				}

				bool ApplyReanimateSpell()
				{
					return Relocation::AddressLibrary::MatchPattern(
						Addresses::Patches::PerkEntryPoints::CastSpells::ApplyReanimateSpell, // 0x5
						0xE8ui8, std::optional<std::int32_t>{}                                // call Actor::ApplySpellItem
					);
				}

				bool ApplyWeaponSwingSpell()
				{
					return Relocation::AddressLibrary::MatchPattern(
						Addresses::Patches::PerkEntryPoints::CastSpells::ApplyWeaponSwingSpell, // 0x5
						0xE8ui8, std::optional<std::int32_t>{}                                  // call Actor::ApplySpellItem
					);
				}
			}
		}

		namespace PowerAttackStamina
		{
			bool GetAttackStaminaActor()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::PowerAttackStamina::GetAttackStaminaActor, // 0x5
					0xE8ui8, std::optional<std::int32_t>{}                         // call ActorValueOwner::GetAttackStamina
				);
			}

			bool GetAttackStaminaPlayerCharacter()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::PowerAttackStamina::GetAttackStaminaPlayerCharacter, // 0x5
					0xE8ui8, std::optional<std::int32_t>{}                                   // call ActorValueOwner::GetAttackStamina
				);
			}

			bool HasStaminaActor()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::PowerAttackStamina::HasStaminaActor, // 0x2
					0x75ui8, 0x10ui8                                         // jnz 10
				);
			}

			bool HasStaminaPlayerCharacter()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::PowerAttackStamina::HasStaminaPlayerCharacter, // 0x2
					0x77ui8, 0x19ui8                                                   // ja 19
				);
			}
		}

		namespace ReflectDamage
		{
			bool CompareReflectDamage()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::ReflectDamage::CompareReflectDamage,          // 0x8
					0xF3ui8, 0x0Fui8, 0x5Dui8, 0x05ui8, std::optional<std::int32_t>{} // minss xmm0, 100.0F
				);
			}
		}

		namespace SteepSlopes
		{
			bool GetScale()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::SteepSlopes::GetScale, // 0x5
					0xE8ui8, std::optional<std::int32_t>{}     // call TESObjectREFR::GetScale
				);
			}
		}
	}
}
