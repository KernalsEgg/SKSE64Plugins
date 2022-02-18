#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSAtomic.h"
#include "Shared/Skyrim/B/BSPointerHandle.h"
#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/B/BSTSingleton.h"
#include "Shared/Skyrim/N/NiPointer.h"



namespace Skyrim
{
	class Actor;
	class BSTempEffect;

	class ProcessLists :
		public BSTSingletonSDM<ProcessLists> // 0
	{
	public:
		// Member variables
		std::int8_t                       padding1;                 // 1
		std::int16_t                      padding2;                 // 2
		std::int32_t                      padding4;                 // 4
		bool                              processHighActors;        // 8
		bool                              processLowActors;         // 9
		bool                              processMiddleHighActors;  // A
		bool                              processMiddleLowActors;   // B
		std::int32_t                      unknownC;                 // C
		std::int32_t                      highActorCount;           // 10
		std::int32_t                      unknown14;                // 14
		std::int64_t                      unknown18;                // 18
		std::int64_t                      unknown20;                // 20
		std::int64_t                      unknown28;                // 28
		BSTArray<ActorHandle>             highActorHandles;         // 30
		BSTArray<ActorHandle>             lowActorHandles;          // 48
		BSTArray<ActorHandle>             middleHighActorHandles;   // 60
		BSTArray<ActorHandle>             middleLowActorHandles;    // 78
		BSTArray<ActorHandle>*            actorHandles[4];          // 90
		std::int64_t                      unknownB0;                // B0
		std::int64_t                      unknownB8;                // B8
		std::int64_t                      unknownC0;                // C0
		std::int64_t                      unknownC8;                // C8
		std::int64_t                      unknownD0;                // D0
		std::int64_t                      unknownD8;                // D8
		std::int64_t                      unknownE0;                // E0
		BSTArray<NiPointer<BSTempEffect>> globalTempEffects;        // E8
		mutable BSSpinLock                globalTempEffectsLock;    // 100
		BSTArray<NiPointer<BSTempEffect>> magicTempEffects;         // 108
		mutable BSSpinLock                magicTempEffectsLock;     // 120
		BSTArray<NiPointer<BSTempEffect>> interfaceTempEffects;     // 128
		mutable BSSpinLock                interfaceTempEffectsLock; // 140
		std::int64_t                      unknown148;               // 148
		std::int64_t                      unknown150;               // 150
		std::int64_t                      unknown158;               // 158
		std::int64_t                      unknown160;               // 160
		std::int64_t                      unknown168;               // 168
		std::int64_t                      unknown170;               // 170
		std::int64_t                      unknown178;               // 178
		std::int64_t                      unknown180;               // 180
		std::int64_t                      unknown188;               // 188
		std::int64_t                      unknown190;               // 190
		std::int64_t                      unknown198;               // 198
		std::int64_t                      unknown1A0;               // 1A0
		std::int64_t                      unknown1A8;               // 1A8
		std::int64_t                      unknown1B0;               // 1B0
		std::int64_t                      unknown1B8;               // 1B8
		std::int64_t                      unknown1C0;               // 1C0
		std::int64_t                      unknown1C8;               // 1C8
		std::int64_t                      unknown1D0;               // 1D0
		std::int64_t                      unknown1D8;               // 1D8
		std::int64_t                      unknown1E0;               // 1E0
		std::int64_t                      unknown1E8;               // 1E8
	};
	static_assert(offsetof(ProcessLists, processHighActors) == 0x8);
	static_assert(offsetof(ProcessLists, processLowActors) == 0x9);
	static_assert(offsetof(ProcessLists, processMiddleHighActors) == 0xA);
	static_assert(offsetof(ProcessLists, processMiddleLowActors) == 0xB);
	static_assert(offsetof(ProcessLists, highActorCount) == 0x10);
	static_assert(offsetof(ProcessLists, highActorHandles) == 0x30);
	static_assert(offsetof(ProcessLists, lowActorHandles) == 0x48);
	static_assert(offsetof(ProcessLists, middleHighActorHandles) == 0x60);
	static_assert(offsetof(ProcessLists, middleLowActorHandles) == 0x78);
	static_assert(offsetof(ProcessLists, actorHandles) == 0x90);
	static_assert(offsetof(ProcessLists, globalTempEffects) == 0xE8);
	static_assert(offsetof(ProcessLists, globalTempEffectsLock) == 0x100);
	static_assert(offsetof(ProcessLists, magicTempEffects) == 0x108);
	static_assert(offsetof(ProcessLists, magicTempEffectsLock) == 0x120);
	static_assert(offsetof(ProcessLists, interfaceTempEffects) == 0x128);
	static_assert(offsetof(ProcessLists, interfaceTempEffectsLock) == 0x140);
	static_assert(sizeof(ProcessLists) == 0x1F0);
}
