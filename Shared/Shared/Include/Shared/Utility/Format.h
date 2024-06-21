#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Utility::Format
{
	template <class... Arguments>
	std::string Print(std::string_view format, Arguments... arguments)
	{
		std::vector<char> buffer(std::snprintf(nullptr, 0, format.data(), arguments...) + 1);

		std::snprintf(buffer.data(), buffer.size(), format.data(), arguments...);

		return std::string(buffer.data(), buffer.size() - 1);
	}
}
