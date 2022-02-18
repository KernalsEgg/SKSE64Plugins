#pragma once

#include "Shared/PCH.h"



namespace Math
{
	template <class T1, class T2>
		requires(std::is_integral_v<T1>&& std::is_integral_v<T2>)
	constexpr T1 Ceiling(T1 value, T2 multiple)
	{
		if (multiple == 0)
		{
			return 0;
		}

		auto remainder = value % multiple;

		return remainder == 0 ? value : value + multiple - remainder;
	}

	template <class T1, class T2>
		requires(std::is_integral_v<T1>&& std::is_integral_v<T2>)
	constexpr T1 Floor(T1 value, T2 multiple)
	{
		if (multiple == 0)
		{
			return 0;
		}

		auto remainder = value % multiple;

		return remainder == 0 ? value : value - remainder;
	}
}
