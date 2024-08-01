#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSSimpleList.h"
#include "Shared/Skyrim/F/ForEachResult.h"
#include "Shared/Skyrim/M/MagicSystem.h"
#include "Shared/Skyrim/N/NiPoint3.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	struct EffectItem;

	class ActiveEffect;
	class Actor;
	class MagicItem;
	class TESBoundObject;
	class TESObjectREFR;

	class MagicTarget
	{
	public:
		struct IPostCreationModification
		{
		public:
			// Add
			virtual ~IPostCreationModification();                        // 0
			virtual void ModifyActiveEffect(ActiveEffect* activeEffect); // 1
		};
		static_assert(sizeof(IPostCreationModification) == 0x8);

		struct ResultsCollector
		{
		public:
			MagicTarget*  magicTarget;             // 0
			Actor*        caster;                  // 8
			MagicItem*    magicItem;               // 10
			std::uint16_t effectItemResistedCount; // 18
			std::uint16_t effectItemCount;         // 1A
			std::uint32_t padding1C;               // 1C
		};
		static_assert(offsetof(ResultsCollector, magicTarget) == 0x0);
		static_assert(offsetof(ResultsCollector, caster) == 0x8);
		static_assert(offsetof(ResultsCollector, magicItem) == 0x10);
		static_assert(offsetof(ResultsCollector, effectItemResistedCount) == 0x18);
		static_assert(offsetof(ResultsCollector, effectItemCount) == 0x1A);
		static_assert(sizeof(ResultsCollector) == 0x20);

		struct AddTargetData
		{
		public:
			// Member variables
			Actor*                                                          caster;                   // 0
			MagicItem*                                                      magicItem;                // 8
			EffectItem*                                                     effectItem;               // 10
			TESBoundObject*                                                 boundObject;              // 18
			IPostCreationModification*                                      postCreationModification; // 20
			ResultsCollector*                                               resultsCollector;         // 28
			NiPoint3                                                        projectilePosition;       // 30
			float                                                           magnitude;                // 3C
			float                                                           effectiveness;            // 40
			Utility::Enumeration<MagicSystem::CastingSource, std::uint32_t> castingSource;            // 44
			std::uint8_t                                                    unknown48;                // 48
			bool                                                            dualCasted;               // 49
			std::uint32_t                                                   unknown4C;                // 4C
		};
		static_assert(offsetof(AddTargetData, caster) == 0x0);
		static_assert(offsetof(AddTargetData, magicItem) == 0x8);
		static_assert(offsetof(AddTargetData, effectItem) == 0x10);
		static_assert(offsetof(AddTargetData, boundObject) == 0x18);
		static_assert(offsetof(AddTargetData, postCreationModification) == 0x20);
		static_assert(offsetof(AddTargetData, resultsCollector) == 0x28);
		static_assert(offsetof(AddTargetData, projectilePosition) == 0x30);
		static_assert(offsetof(AddTargetData, magnitude) == 0x3C);
		static_assert(offsetof(AddTargetData, effectiveness) == 0x40);
		static_assert(offsetof(AddTargetData, castingSource) == 0x44);
		static_assert(offsetof(AddTargetData, dualCasted) == 0x49);
		static_assert(sizeof(AddTargetData) == 0x50);

		class ForEachActiveEffectVisitor
		{
		public:
			// Add
			virtual ~ForEachActiveEffectVisitor()                        = default; // 0
			virtual ForEachResult operator()(ActiveEffect* activeEffect) = 0;       // 1
		};
		static_assert(sizeof(ForEachActiveEffectVisitor) == 0x8);

		// Add
		virtual ~MagicTarget();                                                                                                          // 0
		virtual void                         Unknown1(MagicTarget*);                                                                     // 1
		virtual TESObjectREFR*               GetMagicTargetAsReference();                                                                // 2
		virtual bool                         MagicTargetIsActor() const;                                                                 // 3
		virtual bool                         IsInvulnerable() const;                                                                     // 4
		virtual void                         Unknown5(MagicTarget*);                                                                     // 5
		virtual void                         Unknown6(MagicTarget*) = 0;                                                                 // 6
		virtual BSSimpleList<ActiveEffect*>* GetActiveEffects()     = 0;                                                                 // 7
		virtual void                         Unknown8(MagicTarget*);                                                                     // 8
		virtual void                         Unknown9(MagicTarget*);                                                                     // 9
		virtual float                        CheckResistance(MagicItem* magicItem, EffectItem* effectItem, TESBoundObject* boundObject); // A
		virtual void                         UnknownB(MagicTarget*);                                                                     // B

		// Member functions
		Actor* GetMagicTargetAsActor();
		void   ForEachActiveEffect(ForEachActiveEffectVisitor& forEachActiveEffectVisitor);

		// Member variables
		std::uint64_t unknown8;  // 8
		std::uint64_t unknown10; // 10
	};
	static_assert(sizeof(MagicTarget) == 0x18);
}
