#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/T/TaskQueueInterface.h"



namespace Skyrim
{
	TaskQueueInterface* TaskQueueInterface::GetSingleton()
	{
		auto** singleton{ reinterpret_cast<TaskQueueInterface**>(Addresses::TaskQueueInterface::Singleton) };

		return *singleton;
	}

	bool TaskQueueInterface::ShouldQueueTask()
	{
		auto* function{ reinterpret_cast<decltype(TaskQueueInterface::ShouldQueueTask)*>(Addresses::TaskQueueInterface::ShouldQueueTask) };

		return function();
	}
}
