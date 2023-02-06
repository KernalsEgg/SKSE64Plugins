#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Utility
{
	template <class... EventArguments>
	class EventSource
	{
	public:
		void Notify(EventArguments... eventArguments) const
		{
			for (const auto& eventSink : this->eventSinks_)
			{
				eventSink(eventArguments...);
			}
		}

		void RegisterSink(std::function<void(EventArguments...)> eventSink)
		{
			this->eventSinks_.push_back(eventSink);
		}

		void UnregisterSink(std::function<void(EventArguments...)> eventSink)
		{
			auto* target = eventSink.target();

			if (!target)
			{
				return;
			}

			std::erase_if(this->eventSinks_,
				[target](const std::function<void(EventArguments...)>& eventSink) -> bool
				{
					return eventSink.target() == target;
				});
		}

	private:
		std::vector<std::function<void(EventArguments...)>> eventSinks_{};
	};
}
