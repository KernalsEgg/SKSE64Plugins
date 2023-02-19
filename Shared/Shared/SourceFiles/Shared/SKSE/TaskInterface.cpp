#include "Shared/PrecompiledHeader.h"

#include "Shared/SKSE/TaskInterface.h"



namespace SKSE
{
	void TaskInterface::AddTask(TaskFunction taskFunction) const
	{
		this->addTask_(new Task(std::move(taskFunction)));
	}

	void TaskInterface::AddTask(TaskDelegate* taskDelegate) const
	{
		this->addTask_(taskDelegate);
	}

	void TaskInterface::AddUITask(TaskFunction taskFunction) const
	{
		this->addUITask_(new UITask(std::move(taskFunction)));
	}

	void TaskInterface::AddUITask(UITaskDelegate* taskDelegate) const
	{
		this->addUITask_(taskDelegate);
	}

	std::uint32_t TaskInterface::Version() const
	{
		return this->version_;
	}

	TaskInterface::Task::Task(TaskFunction&& taskFunction) :
		taskFunction_(std::move(taskFunction))
	{
	}

	void TaskInterface::Task::Run()
	{
		this->taskFunction_();
	}

	void TaskInterface::Task::Dispose()
	{
		delete this;
	}

	TaskInterface::UITask::UITask(TaskFunction&& taskFunction) :
		taskFunction_(std::move(taskFunction))
	{
	}

	void TaskInterface::UITask::Run()
	{
		this->taskFunction_();
	}

	void TaskInterface::UITask::Dispose()
	{
		delete this;
	}
}
