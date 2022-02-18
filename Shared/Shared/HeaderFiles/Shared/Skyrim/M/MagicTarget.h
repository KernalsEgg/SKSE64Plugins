#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	template <class T>
	class BSSimpleList;

	class ActiveEffect;
	class Actor;
	class MagicItem;
	class TESBoundObject;
	class TESObjectREFR;

	struct Effect;

	class MagicTarget
	{
	public:
		class ForEachActiveEffectVisitor
		{
		public:
			enum class ReturnType : std::uint32_t
			{
				kStop     = 0,
				kContinue = 1
			};
			static_assert(sizeof(ReturnType) == 0x4);

			// Add
			virtual ~ForEachActiveEffectVisitor()                = default; // 0
			virtual ReturnType Visit(ActiveEffect* activeEffect) = 0;       // 1
		};
		static_assert(sizeof(ForEachActiveEffectVisitor) == 0x8);

		// Add
		virtual ~MagicTarget();                                                                                           // 0
		virtual void                         Unknown1(MagicTarget*);                                                      // 1
		virtual TESObjectREFR*               GetMagicTargetOwner();                                                       // 2
		virtual bool                         IsMagicTargetOwnerActor() const;                                             // 3
		virtual void                         Unknown4(MagicTarget*);                                                      // 4
		virtual void                         Unknown5(MagicTarget*);                                                      // 5
		virtual void                         Unknown6(MagicTarget*) = 0;                                                  // 6
		virtual BSSimpleList<ActiveEffect*>* GetActiveEffects()     = 0;                                                  // 7
		virtual void                         Unknown8(MagicTarget*);                                                      // 8
		virtual void                         Unknown9(MagicTarget*);                                                      // 9
		virtual float                        CheckResistance(MagicItem* magicItem, Effect* effect, TESBoundObject* item); // A
		virtual void                         UnknownB(MagicTarget*);                                                      // B

		// Member functions
		Actor* GetMagicTargetOwnerActor();
		void   VisitActiveEffects(ForEachActiveEffectVisitor* visitor);

		// Member variables
		std::int64_t unknown8;  // 8
		std::int64_t unknown10; // 10
	};
	static_assert(sizeof(MagicTarget) == 0x18);
}
