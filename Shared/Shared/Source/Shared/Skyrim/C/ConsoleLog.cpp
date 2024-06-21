#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/C/ConsoleLog.h"



namespace Skyrim
{
	ConsoleLog* ConsoleLog::GetSingleton()
	{
		auto** singleton{ reinterpret_cast<ConsoleLog**>(Addresses::ConsoleLog::Singleton()) };

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

		auto*  threadLocalStorageIndex   = reinterpret_cast<std::uint32_t*>(Addresses::ThreadLocalStorageIndex());
		auto** threadLocalStoragePointer = reinterpret_cast<ThreadLocalStorage**>(::__readgsqword(0x58));

		return threadLocalStoragePointer[*threadLocalStorageIndex]->isConsoleOpen;
	}
}
