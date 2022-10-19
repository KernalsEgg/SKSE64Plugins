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
		void AddEventSink(BSTEventSink<T>* eventSink)
		{
			if (!eventSink)
			{
				return;
			}

			BSSpinLockGuard lockGuard(this->lock);

			if (this->notifying)
			{
				if (std::find(this->pendingRegisters.begin(), this->pendingRegisters.end(), eventSink) == this->pendingRegisters.end())
				{
					this->pendingRegisters.push_back(eventSink);
				}
			}
			else
			{
				if (std::find(this->eventSinks.begin(), this->eventSinks.end(), eventSink) == this->eventSinks.end())
				{
					this->eventSinks.push_back(eventSink);
				}
			}

			auto* iterator = std::find(this->pendingUnregisters.begin(), this->pendingUnregisters.end(), eventSink);

			if (iterator != this->pendingUnregisters.end())
			{
				this->pendingUnregisters.erase(iterator);
			}
		}

		void RemoveEventSink(BSTEventSink<T>* eventSink)
		{
			if (!eventSink)
			{
				return;
			}

			BSSpinLockGuard lockGuard(this->lock);

			if (this->notifying)
			{
				if (std::find(this->pendingUnregisters.begin(), this->pendingUnregisters.end(), eventSink) == this->pendingUnregisters.end())
				{
					this->pendingUnregisters.push_back(eventSink);
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

			auto* iterator = std::find(this->pendingRegisters.begin(), this->pendingRegisters.end(), eventSink);

			if (iterator != this->pendingRegisters.end())
			{
				this->pendingRegisters.erase(iterator);
			}
		}

		void SendEvent(const T* eventArguments)
		{
			BSSpinLockGuard lockGuard(this->lock);

			auto notifying  = this->notifying;
			this->notifying = true;

			if (!notifying && !this->pendingRegisters.empty())
			{
				for (auto& eventSink : this->pendingRegisters)
				{
					if (std::find(this->eventSinks.begin(), this->eventSinks.end(), eventSink) == this->eventSinks.end())
					{
						this->eventSinks.push_back(eventSink);
					}
				}

				this->pendingRegisters.clear();
			}

			for (auto& eventSink : this->eventSinks)
			{
				if (std::find(this->pendingUnregisters.begin(), this->pendingUnregisters.end(), eventSink) == this->pendingUnregisters.end())
				{
					if (eventSink->ProcessEvent(eventArguments, this) == BSEventNotifyControl::kStop)
					{
						break;
					}
				}
			}

			this->notifying = notifying;

			if (!notifying && !this->pendingUnregisters.empty())
			{
				for (auto& eventSink : this->pendingUnregisters)
				{
					auto* iterator = std::find(this->eventSinks.begin(), this->eventSinks.end(), eventSink);

					if (iterator != this->eventSinks.end())
					{
						this->eventSinks.erase(iterator);
					}
				}

				this->pendingUnregisters.clear();
			}
		}

		// Member variables
		BSTArray<BSTEventSink<T>*> eventSinks;         // 0
		BSTArray<BSTEventSink<T>*> pendingRegisters;   // 18
		BSTArray<BSTEventSink<T>*> pendingUnregisters; // 30
		mutable BSSpinLock         lock;               // 48
		bool                       notifying;          // 50
		std::uint8_t               padding51;          // 51
		std::uint16_t              padding52;          // 52
		std::uint32_t              padding54;          // 54
	};
	static_assert(offsetof(BSTEventSource<void>, eventSinks) == 0x0);
	static_assert(offsetof(BSTEventSource<void>, pendingRegisters) == 0x18);
	static_assert(offsetof(BSTEventSource<void>, pendingUnregisters) == 0x30);
	static_assert(offsetof(BSTEventSource<void>, lock) == 0x48);
	static_assert(offsetof(BSTEventSource<void>, notifying) == 0x50);
	static_assert(sizeof(BSTEventSource<void>) == 0x58);
}
