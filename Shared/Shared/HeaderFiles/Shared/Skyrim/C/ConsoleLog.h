#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/B/BSString.h"
#include "Shared/Skyrim/B/BSTSingleton.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	class ConsoleLog :
		public BSTSingletonSDM<ConsoleLog> // 0
	{
	public:
		// Non-member functions
		static ConsoleLog* GetSingleton();
		static bool        IsConsoleOpen();

		// Member functions
		template <class... Arguments>
		void PrintLine(const char* format, Arguments... arguments)
		{
			auto* function{ reinterpret_cast<Utility::TypeTraits::AddVariadicArguments<Utility::TypeTraits::MakeFunctionPointer<decltype(&ConsoleLog::PrintLine<>)>::type>::type>(Addresses::ConsoleLog::PrintLine) };

			function(this, format, arguments...);
		}

		// Member variables
		char          lastMessage[0x400]; // 1
		std::uint8_t  padding401;         // 401
		std::uint16_t padding402;         // 402
		std::uint32_t padding404;         // 404
		BSString      buffer;             // 408
	};
	static_assert(offsetof(ConsoleLog, lastMessage) == 0x1);
	static_assert(offsetof(ConsoleLog, buffer) == 0x408);
	static_assert(sizeof(ConsoleLog) == 0x418);
}
