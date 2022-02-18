#pragma once

#include "Shared/PCH.h"



namespace Utility
{
	template <class Enum>
		requires(std::is_enum_v<Enum>)
	constexpr std::underlying_type_t<Enum> ToUnderlying(Enum enumerator) noexcept
	{
		return static_cast<std::underlying_type_t<Enum>>(enumerator);
	}
}
