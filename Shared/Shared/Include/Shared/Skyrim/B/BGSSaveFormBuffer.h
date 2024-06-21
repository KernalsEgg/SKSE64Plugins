#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSSaveGameBuffer.h"



namespace Skyrim
{
	class BGSSaveFormBuffer :
		public BGSSaveGameBuffer // 0
	{
	public:
		// Override
		virtual ~BGSSaveFormBuffer() override; // 0

		// Override (BGSSaveGameBuffer)
		virtual void Unknown1(BGSSaveGameBuffer*) override; // 1
		virtual void Unknown2(BGSSaveGameBuffer*) override; // 2
		virtual void Unknown3(BGSSaveGameBuffer*) override; // 3

		// Member variables
		std::uint64_t unknown18; // 18
		std::uint64_t unknown20; // 20
		std::uint64_t unknown28; // 28
	};
	static_assert(sizeof(BGSSaveFormBuffer) == 0x30);
}
