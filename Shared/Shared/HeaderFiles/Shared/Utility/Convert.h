#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Utility
{
	template <class Enumeration>
		requires(std::is_enum_v<Enumeration>)
	constexpr std::underlying_type_t<Enumeration> ToUnderlying(Enumeration enumeration) noexcept
	{
		return static_cast<std::underlying_type_t<Enumeration>>(enumeration);
	}
}
