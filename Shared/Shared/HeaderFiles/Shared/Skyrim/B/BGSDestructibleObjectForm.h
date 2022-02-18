#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BaseFormComponent.h"
#include "Shared/Skyrim/N/NiPointer.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSDebris;
	class BGSExplosion;
	class QueuedFile;
	class TESModelTextureSwap;

	struct DestructibleObjectStage
	{
	public:
		enum class Flags : std::uint8_t
		{
			kNone                 = 0,
			kCapDamage            = 1U << 0,
			kDisableObject        = 1U << 1,
			kDestroyObject        = 1U << 2,
			kIgnoreExternalDamage = 1U << 3
		};
		static_assert(sizeof(Flags) == 0x1);

		// Member variables
		std::int8_t                               modelDamageStage;             // 0
		std::int8_t                               healthPercentage;             // 1
		Utility::Enumeration<Flags, std::uint8_t> destructibleObjectStageFlags; // 2
		std::int8_t                               padding3;                     // 3
		std::uint32_t                             selfDamagePerSecond;          // 4
		BGSExplosion*                             explosion;                    // 8
		BGSDebris*                                debris;                       // 10
		std::uint32_t                             debrisCount;                  // 18
		std::int32_t                              padding1C;                    // 1C
		TESModelTextureSwap*                      replacementModel;             // 20
	};
	static_assert(offsetof(DestructibleObjectStage, modelDamageStage) == 0x0);
	static_assert(offsetof(DestructibleObjectStage, healthPercentage) == 0x1);
	static_assert(offsetof(DestructibleObjectStage, destructibleObjectStageFlags) == 0x2);
	static_assert(offsetof(DestructibleObjectStage, selfDamagePerSecond) == 0x4);
	static_assert(offsetof(DestructibleObjectStage, explosion) == 0x8);
	static_assert(offsetof(DestructibleObjectStage, debris) == 0x10);
	static_assert(offsetof(DestructibleObjectStage, debrisCount) == 0x18);
	static_assert(offsetof(DestructibleObjectStage, replacementModel) == 0x20);
	static_assert(sizeof(DestructibleObjectStage) == 0x28);

	struct DestructibleObjectData
	{
	public:
		enum class Flags : std::uint8_t
		{
			kNone           = 0,
			kVATSTargetable = 1U << 0
		};
		static_assert(sizeof(Flags) == 0x1);

		// Member variables
		std::uint32_t                             health;                         // 0
		std::int8_t                               stageCount;                     // 4
		Utility::Enumeration<Flags, std::uint8_t> destructibleObjectDataFlags;    // 5
		std::int16_t                              padding6;                       // 6
		DestructibleObjectStage**                 stages;                         // 8
		volatile std::int32_t                     replacementModelReferenceCount; // 10
		std::int32_t                              padding14;                      // 14
		NiPointer<QueuedFile>                     preloadedReplacementModels;     // 18
	};
	static_assert(offsetof(DestructibleObjectData, health) == 0x0);
	static_assert(offsetof(DestructibleObjectData, stageCount) == 0x4);
	static_assert(offsetof(DestructibleObjectData, destructibleObjectDataFlags) == 0x5);
	static_assert(offsetof(DestructibleObjectData, stages) == 0x8);
	static_assert(offsetof(DestructibleObjectData, replacementModelReferenceCount) == 0x10);
	static_assert(offsetof(DestructibleObjectData, preloadedReplacementModels) == 0x18);
	static_assert(sizeof(DestructibleObjectData) == 0x20);

	class BGSDestructibleObjectForm :
		public BaseFormComponent // 0
	{
	public:
		// Override
		virtual ~BGSDestructibleObjectForm() override; // 0

		// Override (BaseFormComponent)
		virtual void Unknown1(BaseFormComponent*) override; // 1
		virtual void Unknown2(BaseFormComponent*) override; // 2
		virtual void Unknown3(BaseFormComponent*) override; // 3

		// Member variables
		DestructibleObjectData* destructibleObjectData; // 8
	};
	static_assert(offsetof(BGSDestructibleObjectForm, destructibleObjectData) == 0x8);
	static_assert(sizeof(BGSDestructibleObjectForm) == 0x10);
}
