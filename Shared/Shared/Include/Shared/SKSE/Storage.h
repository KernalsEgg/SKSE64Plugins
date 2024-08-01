#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/SKSE/ActionEvent.h"
#include "Shared/SKSE/CameraEvent.h"
#include "Shared/SKSE/CrosshairReferenceEvent.h"
#include "Shared/SKSE/Interface.h"
#include "Shared/SKSE/MessagingInterface.h"
#include "Shared/SKSE/ModCallbackEvent.h"
#include "Shared/SKSE/NiNodeUpdateEvent.h"
#include "Shared/SKSE/PluginHandle.h"
#include "Shared/SKSE/ScaleformInterface.h"
#include "Shared/SKSE/SerializationInterface.h"
#include "Shared/SKSE/TaskInterface.h"
#include "Shared/SKSE/TrampolineInterface.h"
#include "Shared/Skyrim/B/BSTEventSource.h"



namespace SKSE
{
	class Storage
	{
	public:
		static Storage& GetSingleton();

		void Load(Interface* interface);

		PluginHandle  GetPluginHandle() const;
		std::uint32_t GetReleaseIndex() const;

		const MessagingInterface*     GetMessagingInterface() const;
		const ScaleformInterface*     GetScaleformInterface() const;
		const SerializationInterface* GetSerializationInterface() const;
		const TaskInterface*          GetTaskInterface() const;
		const TrampolineInterface*    GetTrampolineInterface() const;

		Skyrim::BSTEventSource<ActionEvent>*             GetActionEventSource();
		Skyrim::BSTEventSource<CameraEvent>*             GetCameraEventSource();
		Skyrim::BSTEventSource<CrosshairReferenceEvent>* GetCrosshairReferenceEventSource();
		Skyrim::BSTEventSource<ModCallbackEvent>*        GetModCallbackEventSource();
		Skyrim::BSTEventSource<NiNodeUpdateEvent>*       GetNiNodeUpdateEventSource();

	private:
		PluginHandle  pluginHandle_{ SKSE::kInvalidPluginHandle };
		std::uint32_t releaseIndex_{ 0 };

		MessagingInterface*     messagingInterface_{ nullptr };
		ScaleformInterface*     scaleformInterface_{ nullptr };
		SerializationInterface* serializationInterface_{ nullptr };
		TaskInterface*          taskInterface_{ nullptr };
		TrampolineInterface*    trampolineInterface_{ nullptr };

		Skyrim::BSTEventSource<ActionEvent>*             actionEventSource_{ nullptr };
		Skyrim::BSTEventSource<CameraEvent>*             cameraEventSource_{ nullptr };
		Skyrim::BSTEventSource<CrosshairReferenceEvent>* crosshairReferenceEventSource_{ nullptr };
		Skyrim::BSTEventSource<ModCallbackEvent>*        modCallbackEventSource_{ nullptr };
		Skyrim::BSTEventSource<NiNodeUpdateEvent>*       niNodeUpdateEventSource_{ nullptr };
	};
}
