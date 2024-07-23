#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Utility/Enumeration.h"



namespace SKSE
{
	struct ActionEvent
	{
	public:
		enum class Type : std::uint32_t
		{
			kWeaponSwing  = 0,
			kSpellCast    = 1,
			kSpellFire    = 2,
			kVoiceCast    = 3,
			kVoiceFire    = 4,
			kBowDraw      = 5,
			kBowRelease   = 6,
			kBeginDraw    = 7,
			kEndDraw      = 8,
			kBeginSheathe = 9,
			kEndSheathe   = 10
		};
		static_assert(sizeof(Type) == 0x4);

		enum class Slot : std::uint32_t
		{
			kLeft  = 0,
			kRight = 1,
			kVoice = 2
		};
		static_assert(sizeof(Slot) == 0x4);

		Utility::Enumeration<Type, std::uint32_t> type;
		Skyrim::Actor*                            actor;
		Skyrim::TESForm*                          source;
		Utility::Enumeration<Slot, std::uint32_t> slot;
	};
	static_assert(offsetof(ActionEvent, type) == 0x0);
	static_assert(offsetof(ActionEvent, actor) == 0x8);
	static_assert(offsetof(ActionEvent, source) == 0x10);
	static_assert(offsetof(ActionEvent, slot) == 0x18);
	static_assert(sizeof(ActionEvent) == 0x20);
}
