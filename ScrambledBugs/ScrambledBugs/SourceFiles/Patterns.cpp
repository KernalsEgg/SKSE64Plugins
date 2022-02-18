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
			bool Unequal()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Fixes::EnchantmentCost::Unequal, // 0x5
					0xE8ui8, std::optional<std::int32_t>{}      // call Effect::Unequal
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

		namespace KillCamera
		{
			bool HasWeapon()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Fixes::KillCamera::HasWeapon, // 7 + 3 + 2 = 0xC
					0x4Cui8, 0x8Bui8, 0x87ui8, 0x1B0ui32,    // mov r8, [rdi+1B0]
					0x4Dui8, 0x85ui8, 0xC0ui8,               // test r8, r8
					0x74ui8, 0x3Fui8                         // jz 3F
				);
			}
		}

		namespace TerrainDecals
		{
			bool UnloadCellMopp()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Fixes::TerrainDecals::UnloadCellMopp, // 0x5
					0xE9ui8, std::optional<std::int32_t>{}           // jmp
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
		namespace AccumulatingMagnitude
		{
			bool Constructor()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::AccumulatingMagnitude::Constructor, // 0x5
					0xE8ui8, std::optional<std::int32_t>{}                  // call AccumulatingValueModifierEffect::Constructor
				);
			}
		}

		namespace AlreadyCaughtPickpocketing
		{
			bool AttackOnSight()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::AlreadyCaughtPickpocketing::AttackOnSight, // 0x2
					0x75ui8, 0x2Eui8                                               // jne 2E
				);
			}

			bool HasBeenPickpocketed()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::AlreadyCaughtPickpocketing::HasBeenPickpocketed, // 0x2
					0x75ui8, 0x12ui8                                                     // jne 12
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

			bool Attach()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::AttachHitEffectArt::Attach, // 0x5
					0xE8ui8, std::optional<std::int32_t>{}          // call ModelReferenceEffect::Attach
				);
			}

			bool IsPerspectiveChange()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::AttachHitEffectArt::IsPerspectiveChange, // 0x2
					0x74ui8, 0x08ui8                                             // je 8
				);
			}

			bool IsPlayerAttach()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::AttachHitEffectArt::IsPlayerAttach, // 0x2
					0x75ui8, 0x55ui8                                        // jne 55
				);
			}

			bool IsPlayerUpdatePosition()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::AttachHitEffectArt::IsPlayerUpdatePosition, // 0x2
					0x75ui8, 0x3Bui8                                                // jne 3B
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
					Addresses::Patches::EquipBestAmmo::CompareDamageInventoryChanges, // 3 + 2 = 0x5
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
					Addresses::Patches::EquipBestAmmo::IsBoltContainer, // 8 + 3 + 2 + 2 + 3 + 2 = 0x14
					0x41ui8, 0x0Fui8, 0xB6ui8, 0x80ui8, 0x118ui32,      // movzx eax, byte ptr [r8+118]
					0xC0ui8, 0xE8ui8, 0x02ui8,                          // shr al, 2
					0xF6ui8, 0xD0ui8,                                   // not al
					0x24ui8, 0x01ui8,                                   // and al, 1
					0x40ui8, 0x3Aui8, 0xC7ui8,                          // cmp al, dil
					0x75ui8, 0x60ui8                                    // jne 60
				);
			}

			bool IsBoltInventoryChanges()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::EquipBestAmmo::IsBoltInventoryChanges, // 7 + 3 + 2 + 2 + 3 + 2 = 0x13
					0x0Fui8, 0xB6ui8, 0x85ui8, 0x118ui32,                      // movzx eax, byte ptr [rbp+118]
					0xC0ui8, 0xE8ui8, 0x02ui8,                                 // shr al, 2
					0xF6ui8, 0xD0ui8,                                          // not al
					0x24ui8, 0x01ui8,                                          // and al, 1
					0x40ui8, 0x3Aui8, 0xC7ui8,                                 // cmp al, dil
					0x75ui8, 0x7Eui8                                           // jne 7E
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
			bool ApplyHitEffects()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::PausedGameHitEffects::ApplyHitEffects, // 0x2
					0x74ui8, 0x3Fui8                                           // je 3F
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
					Addresses::Patches::ReflectDamage::CompareReflectDamage, // 0x2
					0x77ui8, 0x03ui8                                         // ja 3
				);
			}
		}

		namespace UnderfilledSoulGems
		{
			bool CompareSoulLevelValue()
			{
				return Relocation::AddressLibrary::MatchPattern(
					Addresses::Patches::UnderfilledSoulGems::CompareSoulLevelValue, // 0x2
					0x72ui8, 0x2Eui8                                                // jb 2E
				);
			}
		}
	}
}
