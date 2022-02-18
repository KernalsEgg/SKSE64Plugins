#pragma once

#include "Shared/PCH.h"

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

	struct CameraEvent
	{
	public:
		Skyrim::TESCameraState* oldCameraState;
		Skyrim::TESCameraState* newCameraState;
	};

	struct CrosshairReferenceEvent
	{
	public:
		Skyrim::NiPointer<Skyrim::TESObjectREFR> crosshairReference;
	};

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

		enum class Slot : std::uint32_t
		{
			kLeft  = 0,
			kRight = 1,
			kVoice = 2
		};

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
}
