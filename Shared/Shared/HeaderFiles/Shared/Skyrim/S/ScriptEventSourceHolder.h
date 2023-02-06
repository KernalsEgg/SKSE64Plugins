#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSTEventSource.h"



namespace Skyrim
{
	struct BGSEventProcessedEvent;
	struct TESActivateEvent;
	struct TESActiveEffectApplyRemoveEvent;
	struct TESActorLocationChangeEvent;
	struct TESBookReadEvent;
	struct TESCellAttachDetachEvent;
	struct TESCellFullyLoadedEvent;
	struct TESCellReadyToApplyDecalsEvent;
	struct TESCombatEvent;
	struct TESContainerChangedEvent;
	struct TESDeathEvent;
	struct TESDestructionStageChangedEvent;
	struct TESEnterBleedoutEvent;
	struct TESEquipEvent;
	struct TESFastTravelEndEvent;
	struct TESFormDeleteEvent;
	struct TESFurnitureEvent;
	struct TESGrabReleaseEvent;
	struct TESHitEvent;
	struct TESInitScriptEvent;
	struct TESLoadGameEvent;
	struct TESLockChangedEvent;
	struct TESMagicEffectApplyEvent;
	struct TESMagicWardHitEvent;
	struct TESMoveAttachDetachEvent;
	struct TESObjectLoadedEvent;
	struct TESObjectREFRTranslationEvent;
	struct TESOpenCloseEvent;
	struct TESPackageEvent;
	struct TESPerkEntryRunEvent;
	struct TESPlayerBowShotEvent;
	struct TESQuestInitEvent;
	struct TESQuestStageEvent;
	struct TESQuestStageItemDoneEvent;
	struct TESQuestStartStopEvent;
	struct TESResetEvent;
	struct TESResolveNPCTemplatesEvent;
	struct TESSceneActionEvent;
	struct TESSceneEvent;
	struct TESScenePhaseEvent;
	struct TESSellEvent;
	struct TESSleepStartEvent;
	struct TESSleepStopEvent;
	struct TESSpellCastEvent;
	struct TESSwitchRaceCompleteEvent;
	struct TESTopicInformationEvent;
	struct TESTrackedStatisticsEvent;
	struct TESTrapHitEvent;
	struct TESTriggerEnterEvent;
	struct TESTriggerEvent;
	struct TESTriggerLeaveEvent;
	struct TESUniqueIDChangeEvent;
	struct TESWaitStartEvent;
	struct TESWaitStopEvent;

	class ScriptEventSourceHolder :
		public BSTEventSource<BGSEventProcessedEvent>,          // 0
		public BSTEventSource<TESActivateEvent>,                // 58
		public BSTEventSource<TESActiveEffectApplyRemoveEvent>, // B0
		public BSTEventSource<TESActorLocationChangeEvent>,     // 108
		public BSTEventSource<TESBookReadEvent>,                // 160
		public BSTEventSource<TESCellAttachDetachEvent>,        // 1B8
		public BSTEventSource<TESCellFullyLoadedEvent>,         // 210
		public BSTEventSource<TESCellReadyToApplyDecalsEvent>,  // 268
		public BSTEventSource<TESCombatEvent>,                  // 2C0
		public BSTEventSource<TESContainerChangedEvent>,        // 318
		public BSTEventSource<TESDeathEvent>,                   // 370
		public BSTEventSource<TESDestructionStageChangedEvent>, // 3C8
		public BSTEventSource<TESEnterBleedoutEvent>,           // 420
		public BSTEventSource<TESEquipEvent>,                   // 478
		public BSTEventSource<TESFormDeleteEvent>,              // 4D0
		public BSTEventSource<TESFurnitureEvent>,               // 528
		public BSTEventSource<TESGrabReleaseEvent>,             // 580
		public BSTEventSource<TESHitEvent>,                     // 5D8
		public BSTEventSource<TESInitScriptEvent>,              // 630
		public BSTEventSource<TESLoadGameEvent>,                // 688
		public BSTEventSource<TESLockChangedEvent>,             // 6E0
		public BSTEventSource<TESMagicEffectApplyEvent>,        // 738
		public BSTEventSource<TESMagicWardHitEvent>,            // 790
		public BSTEventSource<TESMoveAttachDetachEvent>,        // 7E8
		public BSTEventSource<TESObjectLoadedEvent>,            // 840
		public BSTEventSource<TESObjectREFRTranslationEvent>,   // 898
		public BSTEventSource<TESOpenCloseEvent>,               // 8F0
		public BSTEventSource<TESPackageEvent>,                 // 948
		public BSTEventSource<TESPerkEntryRunEvent>,            // 9A0
		public BSTEventSource<TESQuestInitEvent>,               // 9F8
		public BSTEventSource<TESQuestStageEvent>,              // A50
		public BSTEventSource<TESQuestStageItemDoneEvent>,      // AA8
		public BSTEventSource<TESQuestStartStopEvent>,          // B00
		public BSTEventSource<TESResetEvent>,                   // B58
		public BSTEventSource<TESResolveNPCTemplatesEvent>,     // BB0
		public BSTEventSource<TESSceneEvent>,                   // C08
		public BSTEventSource<TESSceneActionEvent>,             // C60
		public BSTEventSource<TESScenePhaseEvent>,              // CB8
		public BSTEventSource<TESSellEvent>,                    // D10
		public BSTEventSource<TESSleepStartEvent>,              // D68
		public BSTEventSource<TESSleepStopEvent>,               // DC0
		public BSTEventSource<TESSpellCastEvent>,               // E18
		public BSTEventSource<TESPlayerBowShotEvent>,           // E70
		public BSTEventSource<TESTopicInformationEvent>,        // EC8
		public BSTEventSource<TESTrackedStatisticsEvent>,       // F20
		public BSTEventSource<TESTrapHitEvent>,                 // F78
		public BSTEventSource<TESTriggerEvent>,                 // FD0
		public BSTEventSource<TESTriggerEnterEvent>,            // 1028
		public BSTEventSource<TESTriggerLeaveEvent>,            // 1080
		public BSTEventSource<TESUniqueIDChangeEvent>,          // 10D8
		public BSTEventSource<TESWaitStartEvent>,               // 1130
		public BSTEventSource<TESWaitStopEvent>,                // 1188
		public BSTEventSource<TESSwitchRaceCompleteEvent>,      // 11E0
		public BSTEventSource<TESFastTravelEndEvent>            // 1238
	{
	public:
		// Non-member functions
		static ScriptEventSourceHolder* GetSingleton();

		// Member functions
		template <class T>
		BSTEventSource<T>* GetEventSource()
		{
			return static_cast<BSTEventSource<T>*>(this);
		}

		template <class T>
		void Notify(T* eventArguments)
		{
			this->GetEventSource<T>()->Notify(eventArguments);
		}

		template <class T>
		void RegisterSink(BSTEventSink<T>* eventSink)
		{
			this->GetEventSource<T>()->RegisterSink(eventSink);
		}

		template <class T>
		void UnregisterSink(BSTEventSink<T>* eventSink)
		{
			this->GetEventSource<T>()->UnregisterSink(eventSink);
		}
	};
	static_assert(sizeof(ScriptEventSourceHolder) == 0x1290);
}
