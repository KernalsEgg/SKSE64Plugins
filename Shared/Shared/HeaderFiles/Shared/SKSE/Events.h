#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/N/NiPointer.h"
#include "Shared/Skyrim/T/TESCameraState.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Skyrim/T/TESObjectREFR.h"
#include "Shared/Utility/Enumeration.h"



namespace SKSE
{
	struct ModCallbackEvent
	{
	public:
		Skyrim::BSFixedString eventName;
		Skyrim::BSFixedString stringArgument;
		float                 numericalArgument;
		Skyrim::TESForm*      sender;
	};
	static_assert(offsetof(ModCallbackEvent, eventName) == 0x0);
	static_assert(offsetof(ModCallbackEvent, stringArgument) == 0x8);
	static_assert(offsetof(ModCallbackEvent, numericalArgument) == 0x10);
	static_assert(offsetof(ModCallbackEvent, sender) == 0x18);
	static_assert(sizeof(ModCallbackEvent) == 0x20);

	struct CameraEvent
	{
	public:
		Skyrim::TESCameraState* oldCameraState;
		Skyrim::TESCameraState* newCameraState;
	};
	static_assert(offsetof(CameraEvent, oldCameraState) == 0x0);
	static_assert(offsetof(CameraEvent, newCameraState) == 0x8);
	static_assert(sizeof(CameraEvent) == 0x10);

	struct CrosshairReferenceEvent
	{
	public:
		Skyrim::NiPointer<Skyrim::TESObjectREFR> crosshairReference;
	};
	static_assert(offsetof(CrosshairReferenceEvent, crosshairReference) == 0x0);
	static_assert(sizeof(CrosshairReferenceEvent) == 0x8);

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

	struct NiNodeUpdateEvent
	{
	public:
		Skyrim::TESObjectREFR* reference;
	};
	static_assert(offsetof(NiNodeUpdateEvent, reference) == 0x0);
	static_assert(sizeof(NiNodeUpdateEvent) == 0x8);
}
