#pragma once

#include "Shared/PCH.h"



namespace Utility
{
	struct Message
	{
	public:
		template <class T>
			requires(std::is_convertible_v<const T&, std::string_view>)
		Message(const T& stringView, std::source_location sourceLocation = std::source_location::current()) :
			stringView(static_cast<std::string_view>(stringView)), sourceLocation(sourceLocation)
		{
		}

		std::string_view     stringView;
		std::source_location sourceLocation;
	};
}
