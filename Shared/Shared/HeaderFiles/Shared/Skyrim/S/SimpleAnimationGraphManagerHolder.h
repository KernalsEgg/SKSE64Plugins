#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/I/IAnimationGraphManagerHolder.h"



namespace Skyrim
{
	class SimpleAnimationGraphManagerHolder :
		public IAnimationGraphManagerHolder // 0
	{
	public:
		// Override
		virtual ~SimpleAnimationGraphManagerHolder() override; // 0

		// Override (IAnimationGraphManagerHolder)
		virtual void Unknown2(IAnimationGraphManagerHolder*) override; // 2
		virtual void Unknown3(IAnimationGraphManagerHolder*) override; // 3
		virtual void Unknown5(IAnimationGraphManagerHolder*) override; // 5

		// Add
		virtual void Unknown13(SimpleAnimationGraphManagerHolder*); // 13

		// Member variables
		std::uint64_t unknown8;  // 8
		std::uint64_t unknown10; // 10
	};
	static_assert(sizeof(SimpleAnimationGraphManagerHolder) == 0x18);
}
