#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/C/Color.h"



namespace Skyrim
{
	class Setting
	{
	public:
		// Add
		virtual ~Setting();              // 0
		virtual void Unknown1(Setting*); // 1

		// Member variables
		union
		{
		public:
			// Member variables
			bool          boolean;
			float         floatingPoint;
			std::int32_t  integer;
			Color         color;
			char*         string;
			std::uint32_t unsignedInteger;
		} value;    // 8
		char* name; // 10
	};
	static_assert(offsetof(Setting, value) == 0x8);
	static_assert(offsetof(Setting, name) == 0x10);
	static_assert(sizeof(Setting) == 0x18);
}
