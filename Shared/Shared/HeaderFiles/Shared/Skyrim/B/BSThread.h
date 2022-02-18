#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	class BSThread
	{
	public:
		// Add
		virtual ~BSThread();              // 0
		virtual void Unknown1(BSThread*); // 1
		virtual void Unknown2(BSThread*); // 2

		// Member variables
		std::int64_t unknown8;  // 8
		std::int64_t unknown10; // 10
		std::int64_t unknown18; // 18
		std::int64_t unknown20; // 20
		std::int64_t unknown28; // 28
		std::int64_t unknown30; // 30
		std::int64_t unknown38; // 38
		std::int64_t unknown40; // 40
		std::int64_t unknown48; // 48
	};
	static_assert(sizeof(BSThread) == 0x50);
}
