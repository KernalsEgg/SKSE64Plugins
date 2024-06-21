#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	struct BSSoundHandle
	{
	public:
		enum : std::uint32_t
		{
			kInvalidID = static_cast<std::uint32_t>(-1)
		};

		enum class AssumedState
		{
			kInitialized = 0,
			kPlaying     = 1,
			kStopped     = 2,
			kPaused      = 3
		};

		enum class LoopType
		{
			kNone         = 0,
			kLoop         = 1,
			kEnvelopeFast = 2,
			kEnvelopeSlow = 3
		};

		// Member functions
		bool Play();

		// Member variables
		std::uint32_t                                     soundID{ BSSoundHandle::kInvalidID }; // 0
		bool                                              assumeSuccess{ false };               // 4
		std::uint8_t                                      padding5;                             // 5
		std::uint16_t                                     padding6;                             // 6
		Utility::Enumeration<AssumedState, std::uint32_t> state{ AssumedState::kInitialized };  // 8
	};
	static_assert(offsetof(BSSoundHandle, soundID) == 0x0);
	static_assert(offsetof(BSSoundHandle, assumeSuccess) == 0x4);
	static_assert(offsetof(BSSoundHandle, state) == 0x8);
	static_assert(sizeof(BSSoundHandle) == 0xC);
}
