#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/Events.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/Memory.h"



namespace Skyrim
{
	namespace Events
	{
		InitializeThread::InitializeThread() :
			raise_(reinterpret_cast<decltype(InitializeThread::Raise)*>(
				Utility::Memory::ReadVirtualFunction(
					Addresses::InitTESThread::VirtualFunctionTable(),
					0x1)))
		{
			Utility::Memory::SafeWriteVirtualFunction(
				Addresses::InitTESThread::VirtualFunctionTable(),
				0x1,
				reinterpret_cast<std::uintptr_t>(std::addressof(InitializeThread::Raise)));
		}

		InitializeThread& InitializeThread::GetSingleton()
		{
			static InitializeThread singleton;

			return singleton;
		}

		void InitializeThread::Raise(InitTESThread* initializeThread)
		{
			auto& singleton = InitializeThread::GetSingleton();

			singleton.before.Raise();
			singleton.raise_(initializeThread);
			singleton.after.Raise();
		}
	}
}
