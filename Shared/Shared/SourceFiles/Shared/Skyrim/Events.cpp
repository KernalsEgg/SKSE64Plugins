#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/Events.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/Memory.h"



namespace Skyrim
{
	namespace Events
	{
		InitializeThread::InitializeThread() :
			notify_(reinterpret_cast<decltype(InitializeThread::Notify)*>(Utility::Memory::ReadVirtualFunction(Addresses::InitTESThread::VirtualFunctionTable, 0x1)))
		{
			Utility::Memory::SafeWriteVirtualFunction(Addresses::InitTESThread::VirtualFunctionTable, 0x1, reinterpret_cast<std::uintptr_t>(std::addressof(InitializeThread::Notify)));
		}

		InitializeThread& InitializeThread::GetSingleton()
		{
			static InitializeThread singleton;

			return singleton;
		}

		Utility::EventSource<>& InitializeThread::After()
		{
			return this->after_;
		}

		Utility::EventSource<>& InitializeThread::Before()
		{
			return this->before_;
		}

		void InitializeThread::Notify(InitTESThread* initializeThread)
		{
			const auto& singleton = InitializeThread::GetSingleton();

			singleton.before_.Notify();
			singleton.notify_(initializeThread);
			singleton.after_.Notify();
		}
	}
}
