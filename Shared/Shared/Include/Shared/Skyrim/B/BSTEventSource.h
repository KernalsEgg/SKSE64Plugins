#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSAtomic.h"
#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/B/BSTEventSink.h"



namespace Skyrim
{
	template <class T>
	class BSTEventSource
	{
	public:
		// Member functions
		void Notify(const T* eventArguments)
		{
			BSSpinLockGuard lockGuard(this->lock);

			auto notifying  = this->notifying;
			this->notifying = true;

			if (!notifying && !this->pendingRegistrations.empty())
			{
				for (auto& eventSink : this->pendingRegistrations)
				{
					if (std::find(this->eventSinks.begin(), this->eventSinks.end(), eventSink) == this->eventSinks.end())
					{
						this->eventSinks.push_back(eventSink);
					}
				}

				this->pendingRegistrations.clear();
			}

			for (auto& eventSink : this->eventSinks)
			{
				if (std::find(this->pendingUnregistrations.begin(), this->pendingUnregistrations.end(), eventSink) == this->pendingUnregistrations.end())
				{
					if (eventSink->ProcessEvent(eventArguments, this) == EventNotifyControl::kStop)
					{
						break;
					}
				}
			}

			this->notifying = notifying;

			if (!notifying && !this->pendingUnregistrations.empty())
			{
				for (auto& eventSink : this->pendingUnregistrations)
				{
					auto* iterator = std::find(this->eventSinks.begin(), this->eventSinks.end(), eventSink);

					if (iterator != this->eventSinks.end())
					{
						this->eventSinks.erase(iterator);
					}
				}

				this->pendingUnregistrations.clear();
			}
		}

		void RegisterSink(BSTEventSink<T>* eventSink)
		{
			if (!eventSink)
			{
				return;
			}

			BSSpinLockGuard lockGuard(this->lock);

			if (this->notifying)
			{
				if (std::find(this->pendingRegistrations.begin(), this->pendingRegistrations.end(), eventSink) == this->pendingRegistrations.end())
				{
					this->pendingRegistrations.push_back(eventSink);
				}
			}
			else
			{
				if (std::find(this->eventSinks.begin(), this->eventSinks.end(), eventSink) == this->eventSinks.end())
				{
					this->eventSinks.push_back(eventSink);
				}
			}

			auto* iterator = std::find(this->pendingUnregistrations.begin(), this->pendingUnregistrations.end(), eventSink);

			if (iterator != this->pendingUnregistrations.end())
			{
				this->pendingUnregistrations.erase(iterator);
			}
		}

		void UnregisterSink(BSTEventSink<T>* eventSink)
		{
			if (!eventSink)
			{
				return;
			}

			BSSpinLockGuard lockGuard(this->lock);

			if (this->notifying)
			{
				if (std::find(this->pendingUnregistrations.begin(), this->pendingUnregistrations.end(), eventSink) == this->pendingUnregistrations.end())
				{
					this->pendingUnregistrations.push_back(eventSink);
				}
			}
			else
			{
				auto* iterator = std::find(this->eventSinks.begin(), this->eventSinks.end(), eventSink);

				if (iterator != this->eventSinks.end())
				{
					this->eventSinks.erase(iterator);
				}
			}

			auto* iterator = std::find(this->pendingRegistrations.begin(), this->pendingRegistrations.end(), eventSink);

			if (iterator != this->pendingRegistrations.end())
			{
				this->pendingRegistrations.erase(iterator);
			}
		}

		// Member variables
		BSTArray<BSTEventSink<T>*> eventSinks{};             // 0
		BSTArray<BSTEventSink<T>*> pendingRegistrations{};   // 18
		BSTArray<BSTEventSink<T>*> pendingUnregistrations{}; // 30
		mutable BSSpinLock         lock{};                   // 48
		bool                       notifying{ false };       // 50
	};
	static_assert(offsetof(BSTEventSource<void>, eventSinks) == 0x0);
	static_assert(offsetof(BSTEventSource<void>, pendingRegistrations) == 0x18);
	static_assert(offsetof(BSTEventSource<void>, pendingUnregistrations) == 0x30);
	static_assert(offsetof(BSTEventSource<void>, lock) == 0x48);
	static_assert(offsetof(BSTEventSource<void>, notifying) == 0x50);
	static_assert(sizeof(BSTEventSource<void>) == 0x58);
}
