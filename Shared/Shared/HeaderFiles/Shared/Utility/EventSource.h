#pragma once

#include "Shared/PCH.h"



namespace Utility
{
	template <class... EventArguments>
	class EventSource
	{
	public:
		void AddEventSink(std::function<void(EventArguments...)> eventSink)
		{
			this->eventSinks_.push_back(eventSink);
		}

		void SendEvent(EventArguments... eventArguments) const
		{
			for (const auto& eventSink : eventSinks_)
			{
				eventSink(eventArguments...);
			}
		}

	private:
		std::vector<std::function<void(EventArguments...)>> eventSinks_;
	};
}
