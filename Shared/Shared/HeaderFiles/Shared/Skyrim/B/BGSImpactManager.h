#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSTEventSink.h"
#include "Shared/Skyrim/B/BSTSingleton.h"



namespace Skyrim
{
	struct BGSCollisionSoundEvent;
	struct BGSCombatImpactEvent;
	struct BGSFootstepEvent;
	struct BSSoundHandle;

	class BGSImpactData;
	class NiAVObject;
	class NiPoint3;

	class BGSImpactManager :
		public BSTEventSink<BGSFootstepEvent>,       // 0
		public BSTEventSink<BGSCombatImpactEvent>,   // 8
		public BSTEventSink<BGSCollisionSoundEvent>, // 10
		public BSTSingletonSDM<BGSImpactManager>     // 18
	{
	public:
		struct SoundData
		{
		public:
			// Member variables
			BGSImpactData* impactData; // 0
			NiPoint3*      position;   // 8
			NiAVObject*    source;     // 10
			BSSoundHandle* sound1;     // 18
			BSSoundHandle* sound2;     // 20
			bool           playSound1; // 28
			bool           playSound2; // 29
			std::uint16_t  unknown2A;  // 2A
			std::uint32_t  padding2C;  // 2C
			std::uint64_t  unknown30;  // 30
		};
		static_assert(offsetof(SoundData, impactData) == 0x0);
		static_assert(offsetof(SoundData, position) == 0x8);
		static_assert(offsetof(SoundData, source) == 0x10);
		static_assert(offsetof(SoundData, sound1) == 0x18);
		static_assert(offsetof(SoundData, sound2) == 0x20);
		static_assert(offsetof(SoundData, playSound1) == 0x28);
		static_assert(offsetof(SoundData, playSound2) == 0x29);
		static_assert(sizeof(SoundData) == 0x38);

		// Override
		virtual ~BGSImpactManager() override; // 0

		// Override (BSTEventSink<BGSFootstepEvent>)
		virtual BSEventNotifyControl ProcessEvent(const BGSFootstepEvent* eventArguments, BSTEventSource<BGSFootstepEvent>* eventSource) override; // 1

		// Override (BSTEventSink<BGSCombatImpactEvent>)
		virtual BSEventNotifyControl ProcessEvent(const BGSCombatImpactEvent* eventArguments, BSTEventSource<BGSCombatImpactEvent>* eventSource) override; // 1

		// Override (BSTEventSink<BGSCollisionSoundEvent>)
		virtual BSEventNotifyControl ProcessEvent(const BGSCollisionSoundEvent* eventArguments, BSTEventSource<BGSCollisionSoundEvent>* eventSource) override; // 1

		// Non-member functions
		static BGSImpactManager* GetSingleton();

		// Member functions
		bool PlaySound(const SoundData& soundData) const;

		// Member variables
		std::uint8_t  unknown19; // 19
		std::uint16_t unknown1A; // 1A
		std::uint32_t unknown1C; // 1C
		std::uint64_t unknown20; // 20
		std::uint64_t unknown28; // 28
		std::uint64_t unknown30; // 30
		std::uint64_t unknown38; // 38
		std::uint64_t unknown40; // 40
		std::uint64_t unknown48; // 48
		std::uint64_t unknown50; // 50
	};
	static_assert(sizeof(BGSImpactManager) == 0x58);
}
