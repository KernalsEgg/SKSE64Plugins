#include "Shared/PrecompiledHeader.h"

#include "Shared/SKSE/SerializationInterface.h"

#include "Shared/SKSE/Storage.h"



namespace SKSE
{
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

	bool SerializationInterface::ResolveFormID(Skyrim::FormID oldFormID, Skyrim::FormID& newFormID) const
	{
		return this->resolveFormID_(oldFormID, std::addressof(newFormID));
	}

	bool SerializationInterface::ResolveHandle(Skyrim::VMHandle oldHandle, Skyrim::VMHandle& newHandle) const
	{
		return this->resolveHandle_(oldHandle, std::addressof(newHandle));
	}

	void SerializationInterface::SetFormDeleteCallback(FormDeleteCallback* formDeleteCallback) const
	{
		this->setFormDeleteCallback_(Storage::GetSingleton().GetPluginHandle(), formDeleteCallback);
	}

	void SerializationInterface::SetLoadCallback(EventCallback* eventCallback) const
	{
		this->setLoadCallback_(Storage::GetSingleton().GetPluginHandle(), eventCallback);
	}

	void SerializationInterface::SetRevertCallback(EventCallback* eventCallback) const
	{
		this->setRevertCallback_(Storage::GetSingleton().GetPluginHandle(), eventCallback);
	}

	void SerializationInterface::SetSaveCallback(EventCallback* eventCallback) const
	{
		this->setSaveCallback_(Storage::GetSingleton().GetPluginHandle(), eventCallback);
	}

	void SerializationInterface::SetUniqueID(std::uint32_t uniqueID) const
	{
		this->setUniqueID_(Storage::GetSingleton().GetPluginHandle(), uniqueID);
	}

	std::uint32_t SerializationInterface::Version() const
	{
		return this->version_;
	}

	bool SerializationInterface::WriteRecord(std::uint32_t type, std::uint32_t version, const void* buffer, std::uint32_t length) const
	{
		return this->writeRecord_(type, version, buffer, length);
	}

	bool SerializationInterface::WriteRecordData(const void* buffer, std::uint32_t length) const
	{
		return this->writeRecordData_(buffer, length);
	}
}
