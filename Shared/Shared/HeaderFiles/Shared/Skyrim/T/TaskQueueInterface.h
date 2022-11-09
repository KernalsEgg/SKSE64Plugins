#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	struct BSPackedTaskQueue;

	class TESObjectREFR;

	class TaskQueueInterface
	{
	public:
		// Non-member functions
		static TaskQueueInterface* GetSingleton();
		static bool                ShouldQueueTask();

		// Member functions
		void QueueScriptFunctionCall(std::uint32_t flags, TESObjectREFR* reference, ...);

		// Member variables
		BSPackedTaskQueue* packedTaskQueue;          // 0
		BSPackedTaskQueue* secondaryPackedTaskQueue; // 8
		BSPackedTaskQueue* activePackedTaskQueue;    // 10
	};
	static_assert(offsetof(TaskQueueInterface, packedTaskQueue) == 0x0);
	static_assert(offsetof(TaskQueueInterface, secondaryPackedTaskQueue) == 0x8);
	static_assert(offsetof(TaskQueueInterface, activePackedTaskQueue) == 0x10);
	static_assert(sizeof(TaskQueueInterface) == 0x18);
}
