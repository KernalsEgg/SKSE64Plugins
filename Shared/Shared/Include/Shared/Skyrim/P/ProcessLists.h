#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSAtomic.h"
#include "Shared/Skyrim/B/BSPointerHandle.h"
#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/B/BSTSingleton.h"
#include "Shared/Skyrim/N/NiPointer.h"



namespace Skyrim
{
	class BSTempEffect;

	class ProcessLists :
		public BSTSingletonSDM<ProcessLists> // 0
	{
	public:
		// Member variables
		std::uint8_t                      padding1;                        // 1
		std::uint16_t                     padding2;                        // 2
		std::uint32_t                     padding4;                        // 4
		bool                              processHighActors;               // 8
		bool                              processLowActors;                // 9
		bool                              processMiddleHighActors;         // A
		bool                              processMiddleLowActors;          // B
		std::uint32_t                     unknownC;                        // C
		std::int32_t                      highActorCount;                  // 10
		std::uint32_t                     unknown14;                       // 14
		std::uint64_t                     unknown18;                       // 18
		std::uint64_t                     unknown20;                       // 20
		std::uint64_t                     unknown28;                       // 28
		BSTArray<ActorHandle>             highActorHandles;                // 30
		BSTArray<ActorHandle>             lowActorHandles;                 // 48
		BSTArray<ActorHandle>             middleHighActorHandles;          // 60
		BSTArray<ActorHandle>             middleLowActorHandles;           // 78
		BSTArray<ActorHandle>*            actorHandles[4];                 // 90
		std::uint64_t                     unknownB0;                       // B0
		std::uint64_t                     unknownB8;                       // B8
		std::uint64_t                     unknownC0;                       // C0
		std::uint64_t                     unknownC8;                       // C8
		std::uint64_t                     unknownD0;                       // D0
		std::uint64_t                     unknownD8;                       // D8
		std::uint64_t                     unknownE0;                       // E0
		BSTArray<NiPointer<BSTempEffect>> globalTemporaryEffects;          // E8
		mutable BSSpinLock                globalTemporaryEffectsLock;      // 100
		BSTArray<NiPointer<BSTempEffect>> magicEffectTemporaryEffects;     // 108
		mutable BSSpinLock                magicEffectTemporaryEffectsLock; // 120
		BSTArray<NiPointer<BSTempEffect>> interfaceTemporaryEffects;       // 128
		mutable BSSpinLock                interfaceTemporaryEffectsLock;   // 140
		std::uint64_t                     unknown148;                      // 148
		std::uint64_t                     unknown150;                      // 150
		std::uint64_t                     unknown158;                      // 158
		std::uint64_t                     unknown160;                      // 160
		std::uint64_t                     unknown168;                      // 168
		std::uint64_t                     unknown170;                      // 170
		std::uint64_t                     unknown178;                      // 178
		std::uint64_t                     unknown180;                      // 180
		std::uint64_t                     unknown188;                      // 188
		std::uint64_t                     unknown190;                      // 190
		std::uint64_t                     unknown198;                      // 198
		std::uint64_t                     unknown1A0;                      // 1A0
		std::uint64_t                     unknown1A8;                      // 1A8
		std::uint64_t                     unknown1B0;                      // 1B0
		std::uint64_t                     unknown1B8;                      // 1B8
		std::uint64_t                     unknown1C0;                      // 1C0
		std::uint64_t                     unknown1C8;                      // 1C8
		std::uint64_t                     unknown1D0;                      // 1D0
		std::uint64_t                     unknown1D8;                      // 1D8
		std::uint64_t                     unknown1E0;                      // 1E0
		std::uint64_t                     unknown1E8;                      // 1E8
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
	static_assert(offsetof(ProcessLists, globalTemporaryEffects) == 0xE8);
	static_assert(offsetof(ProcessLists, globalTemporaryEffectsLock) == 0x100);
	static_assert(offsetof(ProcessLists, magicEffectTemporaryEffects) == 0x108);
	static_assert(offsetof(ProcessLists, magicEffectTemporaryEffectsLock) == 0x120);
	static_assert(offsetof(ProcessLists, interfaceTemporaryEffects) == 0x128);
	static_assert(offsetof(ProcessLists, interfaceTemporaryEffectsLock) == 0x140);
	static_assert(sizeof(ProcessLists) == 0x1F0);
}
