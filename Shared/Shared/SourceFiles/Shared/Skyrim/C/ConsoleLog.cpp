#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/C/ConsoleLog.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	ConsoleLog* ConsoleLog::GetSingleton()
	{
		auto** singleton{ reinterpret_cast<ConsoleLog**>(Addresses::ConsoleLog::Singleton) };

		return *singleton;
	}

	bool ConsoleLog::IsConsoleOpen()
	{
		struct ThreadLocalStorage
		{
		public:
			std::uint8_t unknown0[0x600]; // 0
			bool         isConsoleOpen;   // 600
		};
		static_assert(offsetof(ThreadLocalStorage, isConsoleOpen) == 0x600);

		auto*  tlsIndex                  = reinterpret_cast<std::uint32_t*>(Addresses::ThreadLocalStorageIndex);
		auto** threadLocalStoragePointer = reinterpret_cast<ThreadLocalStorage**>(::__readgsqword(0x58));

		return threadLocalStoragePointer[*tlsIndex]->isConsoleOpen;
	}

	void ConsoleLog::PrintLine(const char* format, ...)
	{
		std::va_list arguments;
		auto*        function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&ConsoleLog::PrintLine)>::type>(Addresses::ConsoleLog::PrintLine) };

		va_start(arguments, format);
		function(this, format, arguments);
		va_end(arguments);
	}
}
