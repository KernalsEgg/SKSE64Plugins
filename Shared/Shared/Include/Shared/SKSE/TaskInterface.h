#pragma once

#include "Shared/PrecompiledHeader.h"



namespace SKSE
{
	class TaskDelegate
	{
	public:
		virtual void Run()     = 0;
		virtual void Dispose() = 0;
	};
	static_assert(sizeof(TaskDelegate) == 0x8);

	class UITaskDelegate
	{
	public:
		virtual void Run()     = 0;
		virtual void Dispose() = 0;
	};
	static_assert(sizeof(UITaskDelegate) == 0x8);

	class TaskInterface
	{
	public:
		using TaskFunction = std::function<void()>;

		enum
		{
			kVersion = 2
		};

		void          AddTask(TaskFunction taskFunction) const;
		void          AddTask(TaskDelegate* taskDelegate) const;
		void          AddUITask(TaskFunction taskFunction) const;
		void          AddUITask(UITaskDelegate* taskDelegate) const;
		std::uint32_t Version() const;

	protected:
		class Task :
			public TaskDelegate
		{
		public:
			Task()            = delete;
			Task(const Task&) = delete;
			Task(Task&&)      = delete;

			~Task() = default;

			Task& operator=(const Task&) = delete;
			Task& operator=(Task&&)      = delete;

			explicit Task(TaskFunction&& taskFunction);

			virtual void Run() override;
			virtual void Dispose() override;

		private:
			TaskFunction taskFunction_;
		};

		class UITask :
			public UITaskDelegate
		{
		public:
			UITask()              = delete;
			UITask(const UITask&) = delete;
			UITask(UITask&&)      = delete;

			~UITask() = default;

			UITask& operator=(const UITask&) = delete;
			UITask& operator=(UITask&&)      = delete;

			explicit UITask(TaskFunction&& taskFunction);

			virtual void Run() override;
			virtual void Dispose() override;

		private:
			TaskFunction taskFunction_;
		};

	private:
		std::uint32_t version_;
		void (*addTask_)(TaskDelegate* taskDelegate);
		void (*addUITask_)(UITaskDelegate* taskDelegate);
	};
	static_assert(sizeof(TaskInterface) == 0x18);
}
