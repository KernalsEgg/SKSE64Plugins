#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/SKSE/PluginHandle.h"
#include "Shared/Skyrim/B/BSCoreTypes.h"



namespace SKSE
{
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
		bool          ResolveFormID(Skyrim::FormID oldFormID, Skyrim::FormID& newFormID) const;
		bool          ResolveHandle(Skyrim::VMHandle oldHandle, Skyrim::VMHandle& newHandle) const;
		void          SetFormDeleteCallback(FormDeleteCallback* formDeleteCallback) const;
		void          SetLoadCallback(EventCallback* eventCallback) const;
		void          SetRevertCallback(EventCallback* eventCallback) const;
		void          SetSaveCallback(EventCallback* eventCallback) const;
		void          SetUniqueID(std::uint32_t uniqueID) const;
		std::uint32_t Version() const;
		bool          WriteRecord(std::uint32_t type, std::uint32_t version, const void* buffer, std::uint32_t length) const;
		bool          WriteRecordData(const void* buffer, std::uint32_t length) const;

		template <class T>
			requires(!std::is_pointer_v<T>)
		std::uint32_t ReadRecordData(T& recordData) const
		{
			return this->ReadRecordData(std::addressof(recordData), sizeof(T));
		}

		template <class T, std::size_t COUNT>
			requires(std::is_array_v<T>)
		std::uint32_t ReadRecordData(T (&recordData)[COUNT]) const
		{
			return this->ReadRecordData(std::addressof(recordData), sizeof(T) * COUNT);
		}

		template <class T>
			requires(!std::is_pointer_v<T>)
		bool WriteRecord(std::uint32_t type, std::uint32_t version, const T& record) const
		{
			return this->WriteRecord(type, version, std::addressof(record), sizeof(T));
		}

		template <class T, std::size_t COUNT>
			requires(std::is_array_v<T>)
		bool WriteRecord(std::uint32_t type, std::uint32_t version, const T (&record)[COUNT]) const
		{
			return this->WriteRecord(type, version, std::addressof(record), sizeof(T) * COUNT);
		}

		template <class T>
			requires(!std::is_pointer_v<T>)
		bool WriteRecordData(const T& recordData) const
		{
			return this->WriteRecordData(std::addressof(recordData), sizeof(T));
		}

		template <class T, std::size_t COUNT>
			requires(std::is_array_v<T>)
		bool WriteRecordData(const T (&recordData)[COUNT]) const
		{
			return this->WriteRecordData(std::addressof(recordData), sizeof(T) * COUNT);
		}

	private:
		std::uint32_t version_;
		void (*setUniqueID_)(PluginHandle pluginHandle, std::uint32_t uniqueID);
		void (*setRevertCallback_)(PluginHandle pluginHandle, EventCallback* eventCallback);
		void (*setSaveCallback_)(PluginHandle pluginHandle, EventCallback* eventCallback);
		void (*setLoadCallback_)(PluginHandle pluginHandle, EventCallback* eventCallback);
		void (*setFormDeleteCallback_)(PluginHandle pluginHandle, FormDeleteCallback* formDeleteCallback);
		bool (*writeRecord_)(std::uint32_t type, std::uint32_t version, const void* buffer, std::uint32_t length);
		bool (*openRecord_)(std::uint32_t type, std::uint32_t version);
		bool (*writeRecordData_)(const void* buffer, std::uint32_t length);
		bool (*getNextRecordInformation_)(std::uint32_t* type, std::uint32_t* version, std::uint32_t* length);
		std::uint32_t (*readRecordData_)(void* buffer, std::uint32_t length);
		bool (*resolveHandle_)(Skyrim::VMHandle oldHandle, Skyrim::VMHandle* newHandle);
		bool (*resolveFormID_)(Skyrim::FormID oldFormID, Skyrim::FormID* newFormID);
	};
	static_assert(sizeof(SerializationInterface) == 0x68);
}
