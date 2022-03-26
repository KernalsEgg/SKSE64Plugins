#include "PCH.h"

#include "Patterns.h"

#include "Addresses.h"
#include "Shared/Relocation/AddressLibrary.h"



namespace ScrambledBugs::Patterns
{
	namespace Fixes
	{
		namespace EnchantmentCost
		{
			bool NotEqual()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Fixes::EnchantmentCost::NotEqual, // 0x5
					0xE8ui8, std::optional<std::int32_t>{}       // call Effect::NotEqual
				);
			}
		}

		namespace HarvestedFlags
		{
			bool RemoveHarvestedFlag()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Fixes::HarvestedFlags::RemoveHarvestedFlag, // 0x5
					0xE8ui8, std::optional<std::int32_t>{}                 // call TESObjectREFR::SetHarvestedFlag
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

			bool MainUpdate()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Fixes::ImpactEffectCrash::MainUpdate, // 0x5
					0xE8ui8, std::optional<std::int32_t>{}           // call BSTempEffectSimpleDecal::Apply
				);
			}
		}

		namespace KillCamera
		{
			bool HasWeapon()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Fixes::KillCamera::HasWeapon, // 7 + 3 = 0xA
					0x4Cui8, 0x8Bui8, 0x86ui8, 0x1B0ui32,    // mov r8, [rsi+1B0]
					0x4Dui8, 0x85ui8, 0xC0ui8                // test r8, r8
				);
			}
		}

		namespace TerrainDecals
		{
			bool UnloadCellMopp()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Fixes::TerrainDecals::UnloadCellMopp, // 0x5
					0xE8ui8, std::optional<std::int32_t>{}           // call TESObjectCell::UnloadCellMopp
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
			bool AttackOnSight()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::AlreadyCaughtPickpocketing::AttackOnSight, // 0x2
					0x75ui8, 0x30ui8                                               // jne 30
				);
			}

			bool HasBeenPickpocketed()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::AlreadyCaughtPickpocketing::HasBeenPickpocketed, // 0x2
					0x75ui8, 0x14ui8                                                     // jne 14
				);
			}
		}

		namespace AttachHitEffectArt
		{
			bool AddNoHitEffectArtFlag()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::AttachHitEffectArt::AddNoHitEffectArtFlag, // 2 + 2 = 0x4
					0x24ui8, 0xF9ui8,                                              // and al, F9
					0x0Cui8, 0x01ui8                                               // or al, 1
				);
			}

			bool GetTargetActor()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::AttachHitEffectArt::GetTargetActor, // 0x5
					0xE8ui8, std::optional<std::int32_t>{}                  // call ModelReferenceEffect::GetTargetActor
				);
			}

			bool IsPerspectiveChange()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::AttachHitEffectArt::IsPerspectiveChange, // 0x2
					0x74ui8, 0x6Fui8                                             // je 6F
				);
			}

			bool IsPlayerAttach()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::AttachHitEffectArt::IsPlayerAttach, // 0x2
					0x75ui8, 0x4Bui8                                        // jne 4B
				);
			}

			bool IsPlayerUpdatePosition()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::AttachHitEffectArt::IsPlayerUpdatePosition, // 0x6
					0x0Fui8, 0x85ui8, 0xA8ui32                                      // jne A8
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

		namespace EquipBestAmmo
		{
			bool CompareDamageContainer()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::EquipBestAmmo::CompareDamageContainer, // 0x2
					0x73ui8, 0x06ui8                                           // jnb 6
				);
			}

			bool CompareDamageInventoryChanges()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::EquipBestAmmo::CompareDamageInventoryChanges, // 0x2
					0x73ui8, 0x10ui8                                                  // jnb 10
				);
			}

			bool InitializeDamage()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::EquipBestAmmo::InitializeDamage,              // 0x8
					0xF3ui8, 0x0Fui8, 0x10ui8, 0x35ui8, std::optional<std::int32_t>{} // movss xmm6, std::numeric_limits<float>::max()
				);
			}

			bool IsBoltContainer()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::EquipBestAmmo::IsBoltContainer, // 8 + 3 + 2 + 2 + 3 = 0x12
					0x41ui8, 0x0Fui8, 0xB6ui8, 0x80ui8, 0x118ui32,      // movzx eax, byte ptr [r8+118]
					0xC0ui8, 0xE8ui8, 0x02ui8,                          // shr al, 2
					0xF6ui8, 0xD0ui8,                                   // not al
					0x24ui8, 0x01ui8,                                   // and al, 1
					0x40ui8, 0x3Aui8, 0xC7ui8                           // cmp al, dil
				);
			}

			bool IsBoltInventoryChanges()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::EquipBestAmmo::IsBoltInventoryChanges, // 7 + 3 + 2 + 2 + 3 = 0x11
					0x0Fui8, 0xB6ui8, 0x85ui8, 0x118ui32,                      // movzx eax, byte ptr [rbp+118]
					0xC0ui8, 0xE8ui8, 0x02ui8,                                 // shr al, 2
					0xF6ui8, 0xD0ui8,                                          // not al
					0x24ui8, 0x01ui8,                                          // and al, 1
					0x40ui8, 0x3Aui8, 0xC7ui8                                  // cmp al, dil
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

		namespace PausedGameHitEffects
		{
			bool ShouldApplyHitEffects()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::PausedGameHitEffects::ShouldApplyHitEffects, // 0x6
					0x0Fui8, 0x84ui8, 0x114ui32                                      // je 114
				);
			}
		}

		namespace PerkEntryPoints
		{
			namespace ApplyMultipleSpells
			{
				bool ApplyBashingSpell()
				{
					return Relocation::AddressLibrary::MatchPattern(
						Addresses::Patches::PerkEntryPoints::ApplyMultipleSpells::ApplyBashingSpell, // 0x5
						0xE8ui8, std::optional<std::int32_t>{}                                       // call BGSEntryPointPerkEntry::HandleEntryPoint
					);
				}

				bool ApplyCombatHitSpell()
				{
					return Relocation::AddressLibrary::MatchPattern(
						Addresses::Patches::PerkEntryPoints::ApplyMultipleSpells::ApplyCombatHitSpell, // 0x5
						0xE8ui8, std::optional<std::int32_t>{}                                         // call BGSEntryPointPerkEntry::HandleEntryPoint
					);
				}

				bool ApplyCombatHitSpellArrowProjectile()
				{
					return Relocation::AddressLibrary::MatchPattern(
						Addresses::Patches::PerkEntryPoints::ApplyMultipleSpells::ApplyCombatHitSpellArrowProjectile, // 0x5
						0xE8ui8, std::optional<std::int32_t>{}                                                        // call BGSEntryPointPerkEntry::HandleEntryPoint
					);
				}

				bool ApplyReanimateSpell()
				{
					return Relocation::AddressLibrary::MatchPattern(
						Addresses::Patches::PerkEntryPoints::ApplyMultipleSpells::ApplyReanimateSpell, // 0x5
						0xE8ui8, std::optional<std::int32_t>{}                                         // call BGSEntryPointPerkEntry::HandleEntryPoint
					);
				}

				bool ApplySneakingSpell()
				{
					return Relocation::AddressLibrary::MatchPattern(
						Addresses::Patches::PerkEntryPoints::ApplyMultipleSpells::ApplySneakingSpell, // 0x5
						0xE8ui8, std::optional<std::int32_t>{}                                        // call BGSEntryPointPerkEntry::HandleEntryPoint
					);
				}

				bool ApplyWeaponSwingSpell()
				{
					return Relocation::AddressLibrary::MatchPattern(
						Addresses::Patches::PerkEntryPoints::ApplyMultipleSpells::ApplyWeaponSwingSpell, // 0x5
						0xE8ui8, std::optional<std::int32_t>{}                                           // call BGSEntryPointPerkEntry::HandleEntryPoint
					);
				}
			}

			namespace CastSpells
			{
				bool ApplyBashingSpell()
				{
					return Relocation::AddressLibrary::MatchPattern(
						Addresses::Patches::PerkEntryPoints::CastSpells::ApplyBashingSpell, // 0x5
						0xE8ui8, std::optional<std::int32_t>{}                              // call Actor::ApplySpell
					);
				}

				bool ApplyCombatHitSpell()
				{
					return Relocation::AddressLibrary::MatchPattern(
						Addresses::Patches::PerkEntryPoints::CastSpells::ApplyCombatHitSpell, // 0x5
						0xE8ui8, std::optional<std::int32_t>{}                                // call Actor::ApplySpell
					);
				}

				bool ApplyCombatHitSpellArrowProjectile()
				{
					return Relocation::AddressLibrary::MatchPattern(
						Addresses::Patches::PerkEntryPoints::CastSpells::ApplyCombatHitSpellArrowProjectile, // 0x5
						0xE8ui8, std::optional<std::int32_t>{}                                               // call Actor::ApplySpell
					);
				}

				bool ApplyReanimateSpell()
				{
					return Relocation::AddressLibrary::MatchPattern(
						Addresses::Patches::PerkEntryPoints::CastSpells::ApplyReanimateSpell, // 0x5
						0xE8ui8, std::optional<std::int32_t>{}                                // call Actor::ApplySpell
					);
				}

				bool ApplyWeaponSwingSpell()
				{
					return Relocation::AddressLibrary::MatchPattern(
						Addresses::Patches::PerkEntryPoints::CastSpells::ApplyWeaponSwingSpell, // 0x5
						0xE8ui8, std::optional<std::int32_t>{}                                  // call Actor::ApplySpell
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
