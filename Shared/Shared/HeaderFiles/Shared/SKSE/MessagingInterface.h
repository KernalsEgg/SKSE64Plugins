#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/SKSE/PluginHandle.h"
#include "Shared/Skyrim/B/BSTEventSource.h"
#include "Shared/Utility/Enumeration.h"



namespace SKSE
{
	class MessagingInterface
	{
	public:
		enum
		{
			kVersion = 2
		};

		enum : std::uint32_t
		{
			kPostLoad     = 0, // Sent to all registered plugins after all plugins have been loaded
			kPostPostLoad = 1, // Sent after kPostLoad to facilitate the correct dispatching and registering of messages and listeners
			kPreLoadGame  = 2, // Sent before a save file is read
			kPostLoadGame = 3, // Sent after an attempt has been made to load a save file
			kSaveGame     = 4,
			kDeleteGame   = 5, // Sent before deleting a save file and SKSE co-save file
			kInputLoaded  = 6, // Sent after input has been loaded
			kNewGame      = 7, // Sent after a new game has been started
			kDataLoaded   = 8  // Sent after the data handler has loaded all forms
		};

		enum class Dispatcher : std::uint32_t
		{
			kModCallbackEvent        = 0,
			kCameraEvent             = 1,
			kCrosshairReferenceEvent = 2,
			kActionEvent             = 3,
			kNiNodeUpdateEvent       = 4
		};
		static_assert(sizeof(Dispatcher) == 0x4);

		struct Message
		{
		public:
			const char*   sender;
			std::uint32_t type;
			std::uint32_t dataLength;
			void*         data;
		};
		static_assert(offsetof(Message, sender) == 0x0);
		static_assert(offsetof(Message, type) == 0x8);
		static_assert(offsetof(Message, dataLength) == 0xC);
		static_assert(offsetof(Message, data) == 0x10);
		static_assert(sizeof(Message) == 0x18);

		using EventCallback = void(Message* message);

		bool          Dispatch(std::uint32_t messageType, void* data, std::uint32_t dataLength, const char* receiver) const;
		void*         GetEventDispatcher(Utility::Enumeration<Dispatcher, std::uint32_t> dispatcherID) const;
		bool          RegisterListener(EventCallback* eventCallback) const;
		bool          RegisterListener(const char* sender, EventCallback* eventCallback) const;
		std::uint32_t Version() const;

		template <class T>
		Skyrim::BSTEventSource<T>* GetEventDispatcher(Utility::Enumeration<Dispatcher, std::uint32_t> dispatcherID) const
		{
			return static_cast<Skyrim::BSTEventSource<T>*>(this->GetEventDispatcher(dispatcherID));
		}

	private:
		std::uint32_t version_;
		bool (*registerListener_)(PluginHandle listener, const char* sender, EventCallback* eventCallback);
		bool (*dispatch_)(PluginHandle sender, std::uint32_t messageType, void* data, std::uint32_t dataLength, const char* receiver);
		void* (*getEventDispatcher_)(Utility::Enumeration<Dispatcher, std::uint32_t> dispatcherID);
	};
	static_assert(sizeof(MessagingInterface) == 0x20);
}
