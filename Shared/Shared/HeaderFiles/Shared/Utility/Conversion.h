#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Utility::Conversion
{
	template <class T>
		requires(std::is_enum_v<T>)
	constexpr std::underlying_type_t<T> ToUnderlying(T enumeration) noexcept
	{
		return static_cast<std::underlying_type_t<T>>(enumeration);
	}
}
