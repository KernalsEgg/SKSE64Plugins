#include "Shared/PrecompiledHeader.h"

#include "Shared/SKSE/Interfaces.h"



namespace SKSE
{
	PluginHandle Interface::GetPluginHandle() const
	{
		return this->getPluginHandle_();
	}

	const PluginInformation* Interface::GetPluginInformation(const char* name) const
	{
		return this->getPluginInformation_(name);
	}

	std::uint32_t Interface::GetReleaseIndex() const
	{
		return this->getReleaseIndex_();
	}

	void* Interface::QueryInterface(std::uint32_t id) const
	{
		return this->queryInterface_(id);
	}

	Relocation::Version<std::int32_t> Interface::RuntimeVersion() const
	{
		return Relocation::Version<std::int32_t>(
			static_cast<std::int32_t>((this->runtimeVersion_ & 0xFF000000) >> 24),
			static_cast<std::int32_t>((this->runtimeVersion_ & 0x00FF0000) >> 16),
			static_cast<std::int32_t>((this->runtimeVersion_ & 0x0000FFF0) >> 4),
			static_cast<std::int32_t>((this->runtimeVersion_ & 0x0000000F) >> 0));
	}

	bool SerializationInterface::GetNextRecordInformation(std::uint32_t& type, std::uint32_t& version, std::uint32_t& length) const
	{
		return this->getNextRecordInformation_(std::addressof(type), std::addressof(version), std::addressof(length));
	}

	bool SerializationInterface::OpenRecord(std::uint32_t type, std::uint32_t version) const
	{
		return this->openRecord_(type, version);
	}

	std::uint32_t SerializationInterface::ReadRecordData(void* buffer, std::uint32_t length) const
	{
		return this->readRecordData_(buffer, length);
	}

	bool SerializationInterface::ResolveFormID(std::uint32_t oldFormID, std::uint32_t& newFormID) const
	{
		return this->resolveFormID_(oldFormID, std::addressof(newFormID));
	}

	bool SerializationInterface::ResolveHandle(Skyrim::VMHandle oldHandle, Skyrim::VMHandle& newHandle) const
	{
		return this->resolveHandle_(oldHandle, std::addressof(newHandle));
	}

	void SerializationInterface::SetFormDeleteCallback(FormDeleteCallback formDeleteCallback) const
	{
		this->setFormDeleteCallback_(Cache::GetSingleton().GetPluginHandle(), formDeleteCallback);
	}

	void SerializationInterface::SetLoadCallback(EventCallback eventCallback) const
	{
		this->setLoadCallback_(Cache::GetSingleton().GetPluginHandle(), eventCallback);
	}

	void SerializationInterface::SetRevertCallback(EventCallback eventCallback) const
	{
		this->setRevertCallback_(Cache::GetSingleton().GetPluginHandle(), eventCallback);
	}

	void SerializationInterface::SetSaveCallback(EventCallback eventCallback) const
	{
		this->setSaveCallback_(Cache::GetSingleton().GetPluginHandle(), eventCallback);
	}

	void SerializationInterface::SetUniqueID(std::uint32_t uniqueID) const
	{
		this->setUniqueID_(Cache::GetSingleton().GetPluginHandle(), uniqueID);
	}

	bool SerializationInterface::WriteRecord(std::uint32_t type, std::uint32_t version, const void* buffer, std::uint32_t length) const
	{
		return this->writeRecord_(type, version, buffer, length);
	}

	bool SerializationInterface::WriteRecordData(const void* buffer, std::uint32_t length) const
	{
		return this->writeRecordData_(buffer, length);
	}

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

	bool MessagingInterface::Dispatch(std::uint32_t messageType, void* data, std::uint32_t dataLength, const char* receiver) const
	{
		auto result = this->dispatch_(Cache::GetSingleton().GetPluginHandle(), messageType, data, dataLength, receiver);

		if (!result)
		{
			if (receiver)
			{
				Utility::Log::Error()("Failed to dispatch message to {}.", receiver);
			}
			else
			{
				Utility::Log::Error()("Failed to dispatch message.");
			}
		}

		return result;
	}

	void* MessagingInterface::GetEventDispatcher(Dispatcher dispatcher) const
	{
		return this->getEventDispatcher_(dispatcher);
	}

	bool MessagingInterface::RegisterListener(EventCallback* eventCallback) const
	{
		return this->RegisterListener("SKSE", eventCallback);
	}

	bool MessagingInterface::RegisterListener(const char* sender, EventCallback* eventCallback) const
	{
		auto result = this->registerListener_(Cache::GetSingleton().GetPluginHandle(), sender, eventCallback);

		if (!result)
		{
			if (sender)
			{
				Utility::Log::Error()("Failed to register message listener for {}.", sender);
			}
			else
			{
				Utility::Log::Error()("Failed to register message listener.");
			}
		}

		return result;
	}

	Cache& Cache::GetSingleton()
	{
		static Cache singleton;

		return singleton;
	}

	void Cache::Initialize(Interface* interface)
	{
		this->pluginHandle_ = interface->GetPluginHandle();
		this->releaseIndex_ = interface->GetReleaseIndex();

		this->messagingInterface_     = interface->QueryInterface<MessagingInterface>(Interface::kMessaging);
		this->serializationInterface_ = interface->QueryInterface<SerializationInterface>(Interface::kSerialization);
		this->taskInterface_          = interface->QueryInterface<TaskInterface>(Interface::kTask);

		if (this->messagingInterface_)
		{
			this->modCallbackEventSource_        = this->messagingInterface_->GetEventDispatcher<ModCallbackEvent>(MessagingInterface::Dispatcher::kModCallbackEvent);
			this->cameraEventSource_             = this->messagingInterface_->GetEventDispatcher<CameraEvent>(MessagingInterface::Dispatcher::kCameraEvent);
			this->crosshairReferenceEventSource_ = this->messagingInterface_->GetEventDispatcher<CrosshairReferenceEvent>(MessagingInterface::Dispatcher::kCrosshairReferenceEvent);
			this->actionEventSource_             = this->messagingInterface_->GetEventDispatcher<ActionEvent>(MessagingInterface::Dispatcher::kActionEvent);
			this->niNodeUpdateEventSource_       = this->messagingInterface_->GetEventDispatcher<NiNodeUpdateEvent>(MessagingInterface::Dispatcher::kNiNodeUpdateEvent);
		}
	}
}
