#include "Shared/PrecompiledHeader.h"

#include "Shared/SKSE/MessagingInterface.h"

#include "Shared/SKSE/Storage.h"
#include "Shared/Utility/InformationBox.h"



namespace SKSE
{
	bool MessagingInterface::Dispatch(std::uint32_t messageType, void* data, std::uint32_t dataLength, const char* receiver) const
	{
		auto result = this->dispatch_(Storage::GetSingleton().GetPluginHandle(), messageType, data, dataLength, receiver);

		if (!result)
		{
			if (receiver)
			{
				SPDLOG_ERROR("Failed to dispatch message to {}.", receiver);
			}
			else
			{
				SPDLOG_ERROR("Failed to dispatch message.");
			}
		}

		return result;
	}

	void* MessagingInterface::GetEventDispatcher(Utility::Enumeration<Dispatcher, std::uint32_t> dispatcherID) const
	{
		auto* result = this->getEventDispatcher_(dispatcherID);

		if (!result)
		{
			Utility::InformationBox::Error("Event dispatcher not found, {}.", dispatcherID.underlying());
		}

		return result;
	}

	bool MessagingInterface::RegisterListener(EventCallback* eventCallback) const
	{
		return this->RegisterListener("SKSE", eventCallback);
	}

	bool MessagingInterface::RegisterListener(const char* sender, EventCallback* eventCallback) const
	{
		auto result = this->registerListener_(Storage::GetSingleton().GetPluginHandle(), sender, eventCallback);

		if (!result)
		{
			if (sender)
			{
				SPDLOG_ERROR("Failed to register message listener for {}.", sender);
			}
			else
			{
				SPDLOG_ERROR("Failed to register message listener.");
			}
		}

		return result;
	}

	std::uint32_t MessagingInterface::Version() const
	{
		return this->version_;
	}
}
