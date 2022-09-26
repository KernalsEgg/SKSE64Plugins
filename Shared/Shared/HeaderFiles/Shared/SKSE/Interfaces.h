#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Relocation/Version.h"
#include "Shared/SKSE/Events.h"
#include "Shared/Skyrim/B/BSCoreTypes.h"
#include "Shared/Skyrim/B/BSTEventSource.h"
#include "Shared/Utility/Log.h"



namespace SKSE
{
	using PluginHandle = std::uint32_t;

	enum : PluginHandle
	{
		kInvalidPluginHandle = static_cast<PluginHandle>(-1),
	};

	struct PluginInformation
	{
	public:
		enum
		{
			kVersion = 1
		};

		std::uint32_t informationVersion; // 0
		const char*   name;               // 8
		std::uint32_t version;            // 10
	};
	static_assert(offsetof(PluginInformation, informationVersion) == 0x0);
	static_assert(offsetof(PluginInformation, name) == 0x8);
	static_assert(offsetof(PluginInformation, version) == 0x10);
	static_assert(sizeof(PluginInformation) == 0x18);

	class Interface
	{
	public:
		enum
		{
			kInvalid       = 0,
			kScaleform     = 1,
			kPapyrus       = 2,
			kSerialization = 3,
			kTask          = 4,
			kMessaging     = 5,
			kObject        = 6,
			kTrampoline    = 7,
			kTotal         = 8
		};

		std::uint32_t                     EditorVersion() const { return this->editorVersion_; }
		PluginHandle                      GetPluginHandle() const;
		const PluginInformation*          GetPluginInformation(const char* name) const;
		std::uint32_t                     GetReleaseIndex() const;
		std::uint32_t                     IsEditor() const { return this->isEditor_; }
		void*                             QueryInterface(std::uint32_t id) const;
		Relocation::Version<std::int32_t> RuntimeVersion() const;
		std::uint32_t                     SKSEVersion() const { return this->skseVersion_; }

		template <class T>
		T* QueryInterface(std::uint32_t id) const
		{
			auto* interface = static_cast<T*>(this->QueryInterface(id));

			if (interface && interface->Version() != T::kVersion)
			{
				Utility::Log::Warning("Unexpected {} version encountered, {}. Expected {}.", typeid(T).name(), interface->Version(), static_cast<std::uint32_t>(T::kVersion));
			}

			return interface;
		}

	private:
		std::uint32_t skseVersion_;
		std::uint32_t runtimeVersion_;
		std::uint32_t editorVersion_;
		std::uint32_t isEditor_;
		void* (*queryInterface_)(std::uint32_t id);
		PluginHandle (*getPluginHandle_)(); // Call in SKSEPlugin_Query or SKSEPlugin_Load
		std::uint32_t (*getReleaseIndex_)();
		const PluginInformation* (*getPluginInformation_)(const char* name); // Call after PostLoad event
	};
	static_assert(sizeof(Interface) == 0x30);

	class SerializationInterface
	{
	public:
		enum
		{
			kVersion = 4
		};

		using EventCallback      = void(SerializationInterface* serializationInterface);
		using FormDeleteCallback = void(Skyrim::VMHandle handle);

		bool          GetNextRecordInformation(std::uint32_t& type, std::uint32_t& version, std::uint32_t& length) const;
		bool          OpenRecord(std::uint32_t type, std::uint32_t version) const;
		std::uint32_t ReadRecordData(void* buffer, std::uint32_t length) const;
		bool          ResolveFormID(std::uint32_t oldFormID, std::uint32_t& newFormID) const;
		bool          ResolveHandle(Skyrim::VMHandle oldHandle, Skyrim::VMHandle& newHandle) const;
		void          SetFormDeleteCallback(FormDeleteCallback formDeleteCallback) const;
		void          SetLoadCallback(EventCallback eventCallback) const;
		void          SetRevertCallback(EventCallback eventCallback) const;
		void          SetSaveCallback(EventCallback eventCallback) const;
		void          SetUniqueID(std::uint32_t uniqueID) const;
		std::uint32_t Version() const { return this->version_; }
		bool          WriteRecord(std::uint32_t type, std::uint32_t version, const void* buffer, std::uint32_t length) const;
		bool          WriteRecordData(const void* buffer, std::uint32_t length) const;

		template <class T>
			requires(!std::is_pointer_v<T>)
		std::uint32_t ReadRecordData(T& recordData)
		const
		{
			return this->ReadRecordData(std::addressof(recordData), sizeof(T));
		}

		template <class T, std::size_t Count>
			requires(std::is_array_v<T>)
		std::uint32_t ReadRecordData(T (&recordData)[Count])
		const
		{
			return this->ReadRecordData(std::addressof(recordData), sizeof(T) * Count);
		}

		template <class T>
			requires(!std::is_pointer_v<T>)
		bool WriteRecord(std::uint32_t type, std::uint32_t version, const T& record) const
		{
			return this->WriteRecord(type, version, std::addressof(record), sizeof(T));
		}

		template <class T, std::size_t Count>
			requires(std::is_array_v<T>)
		bool WriteRecord(std::uint32_t type, std::uint32_t version, const T (&record)[Count]) const
		{
			return this->WriteRecord(type, version, std::addressof(record), sizeof(T) * Count);
		}

		template <class T>
			requires(!std::is_pointer_v<T>)
		bool WriteRecordData(const T& recordData) const
		{
			return this->WriteRecordData(std::addressof(recordData), sizeof(T));
		}

		template <class T, std::size_t Count>
			requires(std::is_array_v<T>)
		bool WriteRecordData(const T (&recordData)[Count]) const
		{
			return this->WriteRecordData(std::addressof(recordData), sizeof(T) * Count);
		}

	private:
		std::uint32_t version_;
		void (*setUniqueID_)(PluginHandle pluginHandle, std::uint32_t uniqueID);
		void (*setRevertCallback_)(PluginHandle pluginHandle, EventCallback eventCallback);
		void (*setSaveCallback_)(PluginHandle pluginHandle, EventCallback eventCallback);
		void (*setLoadCallback_)(PluginHandle pluginHandle, EventCallback eventCallback);
		void (*setFormDeleteCallback_)(PluginHandle pluginHandle, FormDeleteCallback formDeleteCallback);
		bool (*writeRecord_)(std::uint32_t type, std::uint32_t version, const void* buffer, std::uint32_t length);
		bool (*openRecord_)(std::uint32_t type, std::uint32_t version);
		bool (*writeRecordData_)(const void* buffer, std::uint32_t length);
		bool (*getNextRecordInformation_)(std::uint32_t* type, std::uint32_t* version, std::uint32_t* length);
		std::uint32_t (*readRecordData_)(void* buffer, std::uint32_t length);
		bool (*resolveHandle_)(Skyrim::VMHandle oldHandle, Skyrim::VMHandle* newHandle);
		bool (*resolveFormID_)(std::uint32_t oldFormID, std::uint32_t* newFormID);
	};
	static_assert(sizeof(SerializationInterface) == 0x68);

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
		std::uint32_t Version() const { return this->version_; }

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
		void (*addTask_)(void*);
		void (*addUITask_)(void*);
	};
	static_assert(sizeof(TaskInterface) == 0x18);

	class MessagingInterface
	{
	public:
		enum
		{
			kVersion = 2
		};

		enum
		{
			kPostLoad     = 0, // Sent to all registered plugins after all plugins have been loaded
			kPostPostLoad = 1, // Sent after kPostLoad to facilitate the correct dispatching and registering of messages and listeners
			kPreLoadGame  = 2, // Sent before a save file is read
			kPostLoadGame = 3, // Sent after an attempt has been made to load a save file
			kSaveGame     = 4,
			kDeleteGame   = 5, // Sent before deleting a save file and SKSE co-save
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
		void*         GetEventDispatcher(Dispatcher dispatcher) const;
		bool          RegisterListener(EventCallback* eventCallback) const;
		bool          RegisterListener(const char* sender, EventCallback* eventCallback) const;
		std::uint32_t Version() const { return this->version_; }

		template <class T>
		Skyrim::BSTEventSource<T>* GetEventDispatcher(Dispatcher dispatcher) const
		{
			return static_cast<Skyrim::BSTEventSource<T>*>(this->GetEventDispatcher(dispatcher));
		}

	private:
		std::uint32_t version_;
		bool (*registerListener_)(PluginHandle listener, const char* sender, EventCallback eventCallback);
		bool (*dispatch_)(PluginHandle sender, std::uint32_t messageType, void* data, std::uint32_t dataLength, const char* receiver);
		void* (*getEventDispatcher_)(Dispatcher dispatcher);
	};
	static_assert(sizeof(MessagingInterface) == 0x20);

#ifdef SKYRIM_ANNIVERSARY_EDITION
	struct PluginVersionData
	{
	public:
		enum
		{
			kVersion = 1
		};

		const std::uint32_t dataVersion{ PluginVersionData::kVersion };            // 0
		std::uint32_t       pluginVersion{ 0 };                                    // 4
		char                pluginName[256]{};                                     // 8
		char                author[256]{};                                         // 108
		char                supportEmail[252]{};                                   // 208
		std::uint32_t       backwardCompatible16629                 : 1 { false }; // 304 (0, 0)
		std::uint32_t       reservedVersionIndependenceExtendedFlags: 31 { 0 };    // 304 (0, 1)
		std::uint32_t       addressLibrary                          : 1 { false }; // 308 (0, 0)
		std::uint32_t       signatureScanning                       : 1 { false }; // 308 (0, 1)
		std::uint32_t       compatible16629                         : 1 { false }; // 308 (0, 2)
		std::uint32_t       reservedVersionIndependenceFlags        : 29 { 0 };    // 308 (0, 3)
		std::uint32_t       compatibleVersions[16]{};                              // 30C
		std::uint32_t       minimumSKSEVersion{ 0 };                               // 34C
	};
	static_assert(offsetof(PluginVersionData, dataVersion) == 0x0);
	static_assert(offsetof(PluginVersionData, pluginVersion) == 0x4);
	static_assert(offsetof(PluginVersionData, pluginName) == 0x8);
	static_assert(offsetof(PluginVersionData, author) == 0x108);
	static_assert(offsetof(PluginVersionData, supportEmail) == 0x208);
	static_assert(offsetof(PluginVersionData, compatibleVersions) == 0x30C);
	static_assert(offsetof(PluginVersionData, minimumSKSEVersion) == 0x34C);
	static_assert(sizeof(PluginVersionData) == 0x350);
#endif

	class Cache
	{
	public:
		static Cache& GetSingleton();

		void Initialize(Interface* interface);

		PluginHandle  GetPluginHandle() const { return this->pluginHandle_; }
		std::uint32_t GetReleaseIndex() const { return this->releaseIndex_; }

		const MessagingInterface*     GetMessagingInterface() const { return this->messagingInterface_; }
		const SerializationInterface* GetSerializationInterface() const { return this->serializationInterface_; }
		const TaskInterface*          GetTaskInterface() const { return this->taskInterface_; }

		Skyrim::BSTEventSource<ModCallbackEvent>*        GetModCallbackEventSource() { return this->modCallbackEventSource_; }
		Skyrim::BSTEventSource<CameraEvent>*             GetCameraEventSource() { return this->cameraEventSource_; }
		Skyrim::BSTEventSource<CrosshairReferenceEvent>* GetCrosshairReferenceEventSource() { return this->crosshairReferenceEventSource_; }
		Skyrim::BSTEventSource<ActionEvent>*             GetActionEventSource() { return this->actionEventSource_; }
		Skyrim::BSTEventSource<NiNodeUpdateEvent>*       GetNiNodeUpdateEventSource() { return this->niNodeUpdateEventSource_; }

	private:
		PluginHandle  pluginHandle_{ SKSE::kInvalidPluginHandle };
		std::uint32_t releaseIndex_{ 0 };

		MessagingInterface*     messagingInterface_{ nullptr };
		SerializationInterface* serializationInterface_{ nullptr };
		TaskInterface*          taskInterface_{ nullptr };

		Skyrim::BSTEventSource<ModCallbackEvent>*        modCallbackEventSource_{ nullptr };
		Skyrim::BSTEventSource<CameraEvent>*             cameraEventSource_{ nullptr };
		Skyrim::BSTEventSource<CrosshairReferenceEvent>* crosshairReferenceEventSource_{ nullptr };
		Skyrim::BSTEventSource<ActionEvent>*             actionEventSource_{ nullptr };
		Skyrim::BSTEventSource<NiNodeUpdateEvent>*       niNodeUpdateEventSource_{ nullptr };
	};
}
