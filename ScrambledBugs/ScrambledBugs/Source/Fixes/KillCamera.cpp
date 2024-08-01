#include "PrecompiledHeader.h"

#include "Fixes/KillCamera.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Relocation/PreprocessorDirectives.h"
#include "Shared/Utility/Assembly.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Fixes
{
	void KillCamera::Fix(bool& killCamera)
	{
		if (!Patterns::Fixes::KillCamera::ApplyCombatHitSpell() ||
			!Patterns::Fixes::KillCamera::GetWeapon())
		{
			killCamera = false;

			return;
		}

		Utility::Memory::SafeWrite(
			Addresses::Fixes::KillCamera::GetWeapon,
			SKYRIM_RELOCATE(
				SKYRIM_VARIADIC_ARGUMENTS(              // 3 + 4 = 0x7
					0x4Cui8, 0x8Bui8, 0xC7ui8,          // mov r8, rdi
					Utility::Assembly::NO_OPERATION_4), // nop
				SKYRIM_VARIADIC_ARGUMENTS(              // 3 + 4 = 0x7
					0x4Cui8, 0x8Bui8, 0xC6ui8,          // mov r8, rsi
					Utility::Assembly::NO_OPERATION_4)) // nop
		);

		KillCamera::applyCombatHitSpell_ = reinterpret_cast<decltype(KillCamera::applyCombatHitSpell_)>(
			Utility::Memory::ReadRelativeCall5(
				Addresses::Fixes::KillCamera::ApplyCombatHitSpell));
		SKSE::Storage::GetSingleton().GetTrampolineInterface()->RelativeCall5(
			Addresses::Fixes::KillCamera::ApplyCombatHitSpell,
			reinterpret_cast<std::uintptr_t>(std::addressof(KillCamera::ApplyCombatHitSpell)));
	}

	void KillCamera::ApplyCombatHitSpell(
		Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint,
		Skyrim::Actor*                                                         perkOwner,
		Skyrim::TESObjectWEAP*                                                 weapon,
		Skyrim::Actor*                                                         target,
		Skyrim::SpellItem**                                                    result)
	{
		auto* arrowProjectile = reinterpret_cast<Skyrim::ArrowProjectile*>(weapon);

		if (arrowProjectile->projectileFlags.all(Skyrim::Projectile::Flags::k3DLoaded) && arrowProjectile->weaponSource)
		{
			KillCamera::applyCombatHitSpell_(entryPoint, perkOwner, arrowProjectile->weaponSource, target, result);
		}
	}

	decltype(KillCamera::ApplyCombatHitSpell)* KillCamera::applyCombatHitSpell_{ nullptr };
}
