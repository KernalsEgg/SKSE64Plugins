#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/E/EventNotifyControl.h"



namespace Skyrim
{
	template <class T>
	class BSTEventSource;

	template <class T>
	class BSTEventSink
	{
	public:
		// Add
		virtual ~BSTEventSink()                                                                          = default; // 0
		virtual EventNotifyControl ProcessEvent(const T* eventArguments, BSTEventSource<T>* eventSource) = 0;       // 1
	};
	static_assert(sizeof(BSTEventSink<void>) == 0x8);
}
