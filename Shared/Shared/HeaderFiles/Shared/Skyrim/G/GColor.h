#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	class GColor
	{
	public:
		struct RGB32
		{
		public:
			// Member variables
			std::uint8_t blue;  // 0
			std::uint8_t green; // 1
			std::uint8_t red;   // 2
			std::uint8_t alpha; // 3
		};
		static_assert(offsetof(RGB32, blue) == 0x0);
		static_assert(offsetof(RGB32, green) == 0x1);
		static_assert(offsetof(RGB32, red) == 0x2);
		static_assert(offsetof(RGB32, alpha) == 0x3);
		static_assert(sizeof(RGB32) == 0x4);

		union ColorData
		{
		public:
			// Member variables
			RGB32         channels;
			std::uint32_t raw;
		};
		static_assert(sizeof(ColorData) == 0x4);

		// Member variables
		ColorData colorData; // 0
	};
	static_assert(offsetof(GColor, colorData) == 0x0);
	static_assert(sizeof(GColor) == 0x4);
}
