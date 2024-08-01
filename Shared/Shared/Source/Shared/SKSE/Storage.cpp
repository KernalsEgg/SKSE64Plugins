#include "Shared/PrecompiledHeader.h"

#include "Shared/SKSE/Storage.h"



namespace SKSE
{
	Storage& Storage::GetSingleton()
	{
		static Storage singleton;

		return singleton;
	}

	void Storage::Load(Interface* interface)
	{
		this->pluginHandle_ = interface->GetPluginHandle();
		this->releaseIndex_ = interface->GetReleaseIndex();

		this->messagingInterface_     = interface->QueryInterface<MessagingInterface>(Interface::kMessaging);
		this->scaleformInterface_     = interface->QueryInterface<ScaleformInterface>(Interface::kScaleform);
		this->serializationInterface_ = interface->QueryInterface<SerializationInterface>(Interface::kSerialization);
		this->taskInterface_          = interface->QueryInterface<TaskInterface>(Interface::kTask);
		this->trampolineInterface_    = interface->QueryInterface<TrampolineInterface>(Interface::kTrampoline);

		this->actionEventSource_             = this->messagingInterface_->GetEventDispatcher<ActionEvent>(MessagingInterface::Dispatcher::kActionEvent);
		this->cameraEventSource_             = this->messagingInterface_->GetEventDispatcher<CameraEvent>(MessagingInterface::Dispatcher::kCameraEvent);
		this->crosshairReferenceEventSource_ = this->messagingInterface_->GetEventDispatcher<CrosshairReferenceEvent>(MessagingInterface::Dispatcher::kCrosshairReferenceEvent);
		this->modCallbackEventSource_        = this->messagingInterface_->GetEventDispatcher<ModCallbackEvent>(MessagingInterface::Dispatcher::kModCallbackEvent);
		this->niNodeUpdateEventSource_       = this->messagingInterface_->GetEventDispatcher<NiNodeUpdateEvent>(MessagingInterface::Dispatcher::kNiNodeUpdateEvent);
	}

	PluginHandle Storage::GetPluginHandle() const
	{
		return this->pluginHandle_;
	}

	std::uint32_t Storage::GetReleaseIndex() const
	{
		return this->releaseIndex_;
	}

	const MessagingInterface* Storage::GetMessagingInterface() const
	{
		return this->messagingInterface_;
	}

	const ScaleformInterface* Storage::GetScaleformInterface() const
	{
		return this->scaleformInterface_;
	}

	const SerializationInterface* Storage::GetSerializationInterface() const
	{
		return this->serializationInterface_;
	}

	const TaskInterface* Storage::GetTaskInterface() const
	{
		return this->taskInterface_;
	}

	const TrampolineInterface* Storage::GetTrampolineInterface() const
	{
		return this->trampolineInterface_;
	}

	Skyrim::BSTEventSource<ActionEvent>* Storage::GetActionEventSource()
	{
		return this->actionEventSource_;
	}

	Skyrim::BSTEventSource<CameraEvent>* Storage::GetCameraEventSource()
	{
		return this->cameraEventSource_;
	}

	Skyrim::BSTEventSource<CrosshairReferenceEvent>* Storage::GetCrosshairReferenceEventSource()
	{
		return this->crosshairReferenceEventSource_;
	}

	Skyrim::BSTEventSource<ModCallbackEvent>* Storage::GetModCallbackEventSource()
	{
		return this->modCallbackEventSource_;
	}

	Skyrim::BSTEventSource<NiNodeUpdateEvent>* Storage::GetNiNodeUpdateEventSource()
	{
		return this->niNodeUpdateEventSource_;
	}
}
