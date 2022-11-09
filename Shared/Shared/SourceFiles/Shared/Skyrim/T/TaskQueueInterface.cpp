#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/T/TaskQueueInterface.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	TaskQueueInterface* TaskQueueInterface::GetSingleton()
	{
		auto** singleton{ reinterpret_cast<TaskQueueInterface**>(Addresses::TaskQueueInterface::Singleton) };

		return *singleton;
	}

	bool TaskQueueInterface::ShouldQueueTask()
	{
		auto* function{ reinterpret_cast<decltype(&TaskQueueInterface::ShouldQueueTask)>(Addresses::TaskQueueInterface::ShouldQueueTask) };

		return function();
	}

	void TaskQueueInterface::QueueScriptFunctionCall(std::uint32_t flags, TESObjectREFR* reference, ...)
	{
		std::va_list arguments;
		auto*        function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&TaskQueueInterface::QueueScriptFunctionCall)>::type>(Addresses::TaskQueueInterface::QueueScriptFunctionCall) };

		va_start(arguments, reference);
		function(this, flags, reference, arguments);
		va_end(arguments);
	}
}
