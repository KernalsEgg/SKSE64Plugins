#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	class Color
	{
	public:
		constexpr Color() noexcept             = default;
		constexpr Color(const Color&) noexcept = default;
		constexpr Color(Color&&) noexcept      = default;

		constexpr ~Color() noexcept = default;

		constexpr Color& operator=(const Color&) noexcept = default;
		constexpr Color& operator=(Color&&) noexcept      = default;

		constexpr Color(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha) noexcept :
			red(red), green(green), blue(blue), alpha(alpha)
		{
		}

		// Member variables
		std::uint8_t red{ 0 };
		std::uint8_t green{ 0 };
		std::uint8_t blue{ 0 };
		std::uint8_t alpha{ 0 };
	};
	static_assert(offsetof(Color, red) == 0x0);
	static_assert(offsetof(Color, green) == 0x1);
	static_assert(offsetof(Color, blue) == 0x2);
	static_assert(offsetof(Color, alpha) == 0x3);
	static_assert(sizeof(Color) == 0x4);

	constexpr bool operator==(const Color& left, const Color& right) noexcept { return (left.red == right.red) && (left.green == right.green) && (left.blue == right.blue) && (left.alpha == right.alpha); }
	constexpr bool operator!=(const Color& left, const Color& right) noexcept { return !(left == right); }
}
