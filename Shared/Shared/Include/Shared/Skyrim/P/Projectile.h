#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Relocation/PreprocessorDirectives.h"
#include "Shared/Skyrim/B/BGSBodyPartDefinitions.h"
#include "Shared/Skyrim/B/BSPointerHandle.h"
#include "Shared/Skyrim/B/BSSimpleList.h"
#include "Shared/Skyrim/C/CollisionLayer.h"
#include "Shared/Skyrim/H/hkBaseTypes.h"
#include "Shared/Skyrim/I/ImpactResult.h"
#include "Shared/Skyrim/N/NiPoint3.h"
#include "Shared/Skyrim/T/TESObjectREFR.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSMaterialType;
	class EffectSetting;
	class hkpCollidable;
	class hkpWorldObject;
	class MagicItem;
	class NiNode;
	class TESAmmo;
	class TESObjectWEAP;

	class Projectile :
		public TESObjectREFR // 0
	{
	public:
		enum class Flags : std::uint32_t
		{
			kNone             = 0,
			k3DLoaded         = 1U << 8, // 1.5.97.0: SkyrimSE.exe + 0x754820 + 0xD3 (43030), 1.6.318.0: SkyrimSE.exe + 0x7821A0 + 0x1D7 (44222), Projectile::Do3DLoaded
			kProcessedImpacts = 1U << 22,
			kKilled           = 1U << 25,
			kDualCasted       = 1U << 28
		};
		static_assert(sizeof(Flags) == 0x4);

		struct ImpactData
		{
		public:
			// Member variables
			NiPoint3                                                          desiredTargetPosition; // 0
			NiPoint3                                                          negativeVelocity;      // C
			ObjectReferenceHandle                                             desiredTargetHandle;   // 18
			hkpWorldObject*                                                   worldObject;           // 20
			BGSMaterialType*                                                  materialAtImpact;      // 28
			Utility::Enumeration<BGSBodyPartDefinitions::Limb, std::uint32_t> damageLocation;        // 30
			Utility::Enumeration<CollisionLayer, std::uint32_t>               collisionLayer;        // 34
			NiNode*                                                           closestBone;           // 38
			Utility::Enumeration<ImpactResult, std::uint32_t>                 impactResult;          // 40
			std::uint32_t                                                     unknown44;             // 44
			std::uint8_t                                                      unknown48;             // 48
			bool                                                              spellCollided;         // 49
			std::uint16_t                                                     unknown4A;             // 4A
			std::uint32_t                                                     unknown4C;             // 4C
		};
		static_assert(offsetof(ImpactData, desiredTargetPosition) == 0x0);
		static_assert(offsetof(ImpactData, negativeVelocity) == 0xC);
		static_assert(offsetof(ImpactData, desiredTargetHandle) == 0x18);
		static_assert(offsetof(ImpactData, worldObject) == 0x20);
		static_assert(offsetof(ImpactData, materialAtImpact) == 0x28);
		static_assert(offsetof(ImpactData, damageLocation) == 0x30);
		static_assert(offsetof(ImpactData, collisionLayer) == 0x34);
		static_assert(offsetof(ImpactData, closestBone) == 0x38);
		static_assert(offsetof(ImpactData, impactResult) == 0x40);
		static_assert(offsetof(ImpactData, spellCollided) == 0x49);
		static_assert(sizeof(ImpactData) == 0x50);

		// Override
		virtual ~Projectile() override; // 0

		// Override (TESObjectREFR)
		virtual bool         Load(TESFile* file) override;                                                                           // 6
		virtual void         SaveGame(BGSSaveFormBuffer* saveFormBuffer) override;                                                   // E
		virtual void         LoadGame(BGSLoadFormBuffer* loadFormBuffer) override;                                                   // F
		virtual void         InitializeLoadGame(BGSLoadFormBuffer* loadFormBuffer) override;                                         // 10
		virtual void         FinishLoadGame(BGSLoadFormBuffer* loadFormBuffer) override;                                             // 11
		virtual void         Revert(BGSLoadFormBuffer* loadFormBuffer) override;                                                     // 12
		virtual void         Unknown47(TESObjectREFR*) override;                                                                     // 47
		virtual void         Unknown48(TESObjectREFR*) override;                                                                     // 48
		virtual void         Unknown50(TESObjectREFR*) override;                                                                     // 50
		virtual void         Unknown51(TESObjectREFR*) override;                                                                     // 51
		virtual MagicCaster* GetMagicCaster(Utility::Enumeration<MagicSystem::CastingSource, std::uint32_t> castingSource) override; // 5C
		virtual void         Unknown65(TESObjectREFR*) override;                                                                     // 65
		virtual void         Unknown66(TESObjectREFR*) override;                                                                     // 66
		virtual void         Unknown6A(TESObjectREFR*) override;                                                                     // 6A
		virtual void         Unknown6C(TESObjectREFR*) override;                                                                     // 6C
		virtual void         Unknown85(TESObjectREFR*) override;                                                                     // 85
		virtual void         Unknown86(TESObjectREFR*) override;                                                                     // 86
		virtual void         Unknown8B(TESObjectREFR*) override;                                                                     // 8B
		virtual void         Unknown8F(TESObjectREFR*) override;                                                                     // 8F
		virtual void         Unknown90(TESObjectREFR*) override;                                                                     // 90

		// Add
		virtual void                    UnknownA2(Projectile*);                                                                                                                                                  // A2
		virtual void                    UnknownA3(Projectile*);                                                                                                                                                  // A3
		virtual void                    UnknownA4(Projectile*);                                                                                                                                                  // A4
		virtual void                    UnknownA5(Projectile*);                                                                                                                                                  // A5
		virtual void                    UnknownA6(Projectile*);                                                                                                                                                  // A6
		virtual void                    UnknownA7(Projectile*);                                                                                                                                                  // A7
		virtual void                    UnknownA8(Projectile*);                                                                                                                                                  // A8
		virtual void                    UnknownA9(Projectile*);                                                                                                                                                  // A9
		virtual void                    UnknownAA(Projectile*);                                                                                                                                                  // AA
		virtual void                    UnknownAB(Projectile*) = 0;                                                                                                                                              // AB
		virtual void                    UnknownAC(Projectile*);                                                                                                                                                  // AC
		virtual void                    UnknownAD(Projectile*);                                                                                                                                                  // AD
		virtual void                    UnknownAE(Projectile*);                                                                                                                                                  // AE
		virtual void                    UnknownAF(Projectile*);                                                                                                                                                  // AF
		virtual void                    UnknownB0(Projectile*);                                                                                                                                                  // B0
		virtual void                    UnknownB1(Projectile*);                                                                                                                                                  // B1
		virtual void                    UnknownB2(Projectile*);                                                                                                                                                  // B2
		virtual void                    UnknownB3(Projectile*);                                                                                                                                                  // B3
		virtual void                    UnknownB4(Projectile*);                                                                                                                                                  // B4
		virtual void                    UnknownB5(Projectile*);                                                                                                                                                  // B5
		virtual void                    UnknownB6(Projectile*);                                                                                                                                                  // B6
		virtual void                    UnknownB7(Projectile*);                                                                                                                                                  // B7
		virtual void                    UnknownB8(Projectile*);                                                                                                                                                  // B8
		virtual void                    UnknownB9(Projectile*);                                                                                                                                                  // B9
		virtual void                    UnknownBA(Projectile*);                                                                                                                                                  // BA
		virtual void                    UnknownBB(Projectile*);                                                                                                                                                  // BB
		virtual void                    UnknownBC(Projectile*);                                                                                                                                                  // BC
		virtual Projectile::ImpactData* AddImpact(TESObjectREFR* target, const NiPoint3& targetPosition, const NiPoint3& negativeVelocity, hkpCollidable* collidable, hkpShapeKey shapeKey, bool spellCollided); // BD
		virtual void                    UnknownBE(Projectile*);                                                                                                                                                  // BE
		virtual void                    UnknownBF(Projectile*);                                                                                                                                                  // BF
		virtual void                    UnknownC0(Projectile*);                                                                                                                                                  // C0
		virtual void                    UnknownC1(Projectile*);                                                                                                                                                  // C1

		// Member variables
		BSSimpleList<ImpactData*>                  impacts;                // 98, A0
		std::uint64_t                              unknownB0;              // A8, B0
		std::uint64_t                              unknownB8;              // B0, B8
		std::uint64_t                              unknownC0;              // B8, C0
		std::uint64_t                              unknownC8;              // C0, C8
		std::uint64_t                              unknownD0;              // C8, D0
		std::uint64_t                              unknownD8;              // D0, D8
		std::uint64_t                              unknownE0;              // D8, E0
		std::uint64_t                              unknownE8;              // E0, E8
		std::uint64_t                              unknownF0;              // E8, F0
		NiPoint3                                   velocity;               // F0, F8
		NiPoint3                                   linearVelocity;         // FC, 104
		std::uint64_t                              unknown110;             // 108, 110
		std::uint64_t                              unknown118;             // 110, 118
		std::uint64_t                              unknown120;             // 118, 120
		std::uint32_t                              unknown128;             // 120, 128
		ObjectReferenceHandle                      desiredTargetHandle;    // 124, 12C
		std::uint64_t                              unknown130;             // 128, 130
		std::uint64_t                              unknown138;             // 130, 138
		std::uint64_t                              unknown140;             // 138, 140
		std::uint64_t                              unknown148;             // 140, 148
		std::uint64_t                              unknown150;             // 148, 150
		std::uint64_t                              unknown158;             // 150, 158
		MagicItem*                                 magicItem;              // 158, 160
		std::uint64_t                              unknown168;             // 160, 168
		EffectSetting*                             costliestEffectSetting; // 168, 170
		std::uint64_t                              unknown178;             // 170, 178
		std::uint64_t                              unknown180;             // 178, 180
		std::uint64_t                              unknown188;             // 180, 188
		std::uint64_t                              unknown190;             // 188, 190
		std::uint64_t                              unknown198;             // 190, 198
		float                                      damage;                 // 198, 1A0
		float                                      alpha;                  // 19C, 1A4
		std::uint64_t                              unknown1A8;             // 1A0, 1A8
		std::uint64_t                              unknown1B0;             // 1A8, 1B0
		TESObjectWEAP*                             weaponSource;           // 1B0, 1B8
		TESAmmo*                                   ammunitionSource;       // 1B8, 1C0
		std::uint64_t                              unknown1C8;             // 1C0, 1C8
		std::uint32_t                              unknown1D0;             // 1C8, 1D0
		Utility::Enumeration<Flags, std::uint32_t> projectileFlags;        // 1CC, 1D4
		bool                                       artRequested;           // 1D0, 1D8 (1.5.97.0: SkyrimSE.exe + 0x754DC0 + 0x1CB (43035), 1.6.318.0: SkyrimSE.exe + 0x782B00 + 0x1C7 (44227), Projectile::RequestArt)
		bool                                       animationsLoaded;       // 1D1, 1D9 (1.5.97.0: SkyrimSE.exe + 0x754FF0 + 0x5 (43036), 1.6.318.0: SkyrimSE.exe + 0x782D20 + 0x5 (44228), Projectile::AnimationsLoadedCallback)
		std::uint16_t                              unknown1DA;             // 1D2, 1DA
		std::uint32_t                              unknown1DC;             // 1D4, 1DC
	};
	static_assert(offsetof(Projectile, impacts) == SKYRIM_RELOCATE(0x98, 0xA0));
	static_assert(offsetof(Projectile, velocity) == SKYRIM_RELOCATE(0xF0, 0xF8));
	static_assert(offsetof(Projectile, linearVelocity) == SKYRIM_RELOCATE(0xFC, 0x104));
	static_assert(offsetof(Projectile, desiredTargetHandle) == SKYRIM_RELOCATE(0x124, 0x12C));
	static_assert(offsetof(Projectile, magicItem) == SKYRIM_RELOCATE(0x158, 0x160));
	static_assert(offsetof(Projectile, costliestEffectSetting) == SKYRIM_RELOCATE(0x168, 0x170));
	static_assert(offsetof(Projectile, damage) == SKYRIM_RELOCATE(0x198, 0x1A0));
	static_assert(offsetof(Projectile, alpha) == SKYRIM_RELOCATE(0x19C, 0x1A4));
	static_assert(offsetof(Projectile, weaponSource) == SKYRIM_RELOCATE(0x1B0, 0x1B8));
	static_assert(offsetof(Projectile, ammunitionSource) == SKYRIM_RELOCATE(0x1B8, 0x1C0));
	static_assert(offsetof(Projectile, projectileFlags) == SKYRIM_RELOCATE(0x1CC, 0x1D4));
	static_assert(offsetof(Projectile, artRequested) == SKYRIM_RELOCATE(0x1D0, 0x1D8));
	static_assert(offsetof(Projectile, animationsLoaded) == SKYRIM_RELOCATE(0x1D1, 0x1D9));
	static_assert(sizeof(Projectile) == SKYRIM_RELOCATE(0x1D8, 0x1E0));
}
