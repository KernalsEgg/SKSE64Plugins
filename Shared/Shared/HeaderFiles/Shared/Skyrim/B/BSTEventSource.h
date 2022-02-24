#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/B/BSAtomic.h"
#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	template <class T>
	class BSTEventSink;

	template <class T>
	class BSTEventSource
	{
	public:
		// Member functions
		void AddEventSink(BSTEventSink<T>* eventSink)
		{
			auto function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&BSTEventSource<T>::AddEventSink)>::type>(Addresses::BSTEventSource::AddEventSink) };

			function(this, eventSink);
		}

		void RemoveEventSink(BSTEventSink<T>* eventSink)
		{
			auto function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&BSTEventSource<T>::RemoveEventSink)>::type>(Addresses::BSTEventSource::RemoveEventSink) };

			function(this, eventSink);
		}

		void SendEvent(T* eventArguments)
		{
			auto function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&BSTEventSource<T>::SendEvent)>::type>(Addresses::BSTEventSource::SendEvent) };

			function(this, eventArguments);
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
