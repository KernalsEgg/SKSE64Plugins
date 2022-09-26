#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/Events.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/Memory.h"



namespace Skyrim::Events
{
	InitializeThread::InitializeThread() :
		event_(reinterpret_cast<decltype(&InitializeThread::Event)>(Utility::Memory::ReadVirtualFunction(Addresses::InitTESThread::VirtualFunctionTable, 0x1)))
	{
		Utility::Memory::SafeWriteVirtualFunction(Addresses::InitTESThread::VirtualFunctionTable, 0x1, reinterpret_cast<std::uintptr_t>(std::addressof(InitializeThread::Event)));
	}

	InitializeThread& InitializeThread::GetSingleton()
	{
		static InitializeThread singleton;

		return singleton;
	}

	void InitializeThread::Event(InitTESThread* initializeThread)
	{
		const auto& singleton = InitializeThread::GetSingleton();

		singleton.before_.SendEvent();
		singleton.event_(initializeThread);
		singleton.after_.SendEvent();
	}
}
