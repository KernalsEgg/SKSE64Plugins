#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BGSDestructibleObjectForm.h"
#include "Shared/Skyrim/B/BGSPreloadable.h"
#include "Shared/Skyrim/S/SoundLevel.h"
#include "Shared/Skyrim/T/TESBoundObject.h"
#include "Shared/Skyrim/T/TESFullName.h"
#include "Shared/Skyrim/T/TESModel.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSCollisionLayer;
	class BGSExplosion;
	class BGSSoundDescriptorForm;
	class BGSTextureSet;
	class TESObjectLIGH;
	class TESObjectWEAP;

	class BGSProjectile :
		public TESBoundObject,           // 0
		public TESFullName,              // 30
		public TESModel,                 // 40
		public BGSPreloadable,           // 68
		public BGSDestructibleObjectForm // 70
	{
	public:
		enum class Flags : std::uint16_t
		{
			kNone                        = 0,
			kHitscan                     = 1U << 0,
			kExplosion                   = 1U << 1,
			kExplosionAlternateTrigger   = 1U << 2,
			kMuzzleFlash                 = 1U << 3,
			kCanBeDisabled               = 1U << 5,
			kCanBePickedUp               = 1U << 6,
			kSupersonic                  = 1U << 7,
			kCriticalEffectPinsLimbs     = 1U << 8,
			kPassThroughSmallTransparent = 1U << 9,
			kDisableCombatAimCorrection  = 1U << 10
		};
		static_assert(sizeof(Flags) == 0x2);

		enum class Type : std::uint16_t
		{
			kMissile = 1U << 0,
			kLobber  = 1U << 1,
			kBeam    = 1U << 2,
			kFlame   = 1U << 3,
			kCone    = 1U << 4,
			kBarrier = 1U << 5,
			kArrow   = 1U << 6
		};
		static_assert(sizeof(Type) == 0x2);

		// Override
		virtual ~BGSProjectile() override; // 0

		// Override (TESBoundObject)
		virtual void InitializeData() override;                                                                                                       // 4
		virtual void ClearData() override;                                                                                                            // 5
		virtual void Unknown6(TESForm*) override;                                                                                                     // 6
		virtual void Unknown13(TESForm*) override;                                                                                                    // 13
		virtual bool Activate(TESObjectREFR* target, TESObjectREFR* activator, bool deferred, TESBoundObject* item, std::int32_t itemCount) override; // 37
		virtual void Unknown40(TESObject*) override;                                                                                                  // 40
		virtual void Unknown41(TESObject*) override;                                                                                                  // 41
		virtual void Unknown4C(TESBoundObject*) override;                                                                                             // 4C

		// Override (BGSPreloadable)
		virtual void Unknown4(BGSPreloadable*) override; // 4

		// Member variables
		Utility::Enumeration<Flags, std::uint16_t>      projectileFlags;         // 80
		Utility::Enumeration<Type, std::uint16_t>       projectileType;          // 82
		float                                           gravity;                 // 84
		float                                           speed;                   // 88
		float                                           range;                   // 8C
		TESObjectLIGH*                                  light;                   // 90
		TESObjectLIGH*                                  muzzleFlashLight;        // 98
		float                                           tracerChance;            // A0
		float                                           explosionProximity;      // A4
		float                                           explosionTimer;          // A8
		std::uint32_t                                   paddingAC;               // AC
		BGSExplosion*                                   explosion;               // B0
		BGSSoundDescriptorForm*                         sound;                   // B8
		float                                           muzzleFlashDuration;     // C0
		float                                           fadeDuration;            // C4
		float                                           impactForce;             // C8
		std::uint32_t                                   paddingCC;               // CC
		BGSSoundDescriptorForm*                         explosionCountdownSound; // D0
		BGSSoundDescriptorForm*                         disableSound;            // D8
		TESObjectWEAP*                                  defaultWeaponSource;     // E0
		float                                           coneSpread;              // E8
		float                                           collisionRadius;         // EC
		float                                           lifetime;                // F0
		float                                           relaunchInterval;        // F4
		BGSTextureSet*                                  decalData;               // F8
		BGSCollisionLayer*                              collisionLayer;          // 100
		TESModel                                        muzzleFlashModel;        // 108
		Utility::Enumeration<SoundLevel, std::uint32_t> detectionSoundLevel;     // 130
		std::uint32_t                                   padding134;              // 134
	};
	static_assert(offsetof(BGSProjectile, projectileFlags) == 0x80);
	static_assert(offsetof(BGSProjectile, projectileType) == 0x82);
	static_assert(offsetof(BGSProjectile, gravity) == 0x84);
	static_assert(offsetof(BGSProjectile, speed) == 0x88);
	static_assert(offsetof(BGSProjectile, range) == 0x8C);
	static_assert(offsetof(BGSProjectile, light) == 0x90);
	static_assert(offsetof(BGSProjectile, muzzleFlashLight) == 0x98);
	static_assert(offsetof(BGSProjectile, tracerChance) == 0xA0);
	static_assert(offsetof(BGSProjectile, explosionProximity) == 0xA4);
	static_assert(offsetof(BGSProjectile, explosionTimer) == 0xA8);
	static_assert(offsetof(BGSProjectile, explosion) == 0xB0);
	static_assert(offsetof(BGSProjectile, sound) == 0xB8);
	static_assert(offsetof(BGSProjectile, muzzleFlashDuration) == 0xC0);
	static_assert(offsetof(BGSProjectile, fadeDuration) == 0xC4);
	static_assert(offsetof(BGSProjectile, impactForce) == 0xC8);
	static_assert(offsetof(BGSProjectile, explosionCountdownSound) == 0xD0);
	static_assert(offsetof(BGSProjectile, disableSound) == 0xD8);
	static_assert(offsetof(BGSProjectile, defaultWeaponSource) == 0xE0);
	static_assert(offsetof(BGSProjectile, coneSpread) == 0xE8);
	static_assert(offsetof(BGSProjectile, collisionRadius) == 0xEC);
	static_assert(offsetof(BGSProjectile, lifetime) == 0xF0);
	static_assert(offsetof(BGSProjectile, relaunchInterval) == 0xF4);
	static_assert(offsetof(BGSProjectile, decalData) == 0xF8);
	static_assert(offsetof(BGSProjectile, collisionLayer) == 0x100);
	static_assert(offsetof(BGSProjectile, muzzleFlashModel) == 0x108);
	static_assert(offsetof(BGSProjectile, detectionSoundLevel) == 0x130);
	static_assert(sizeof(BGSProjectile) == 0x138);
}
