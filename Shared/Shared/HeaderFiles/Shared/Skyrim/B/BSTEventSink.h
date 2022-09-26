#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	template <class T>
	class BSTEventSource;

	enum class BSEventNotifyControl : std::uint32_t
	{
		kContinue = 0,
		kStop     = 1
	};
	static_assert(sizeof(BSEventNotifyControl) == 0x4);

	template <class T>
	class BSTEventSink
	{
	public:
		// Add
		virtual ~BSTEventSink()                                                                            = default; // 0
		virtual BSEventNotifyControl ProcessEvent(const T* eventArguments, BSTEventSource<T>* eventSource) = 0;       // 1
	};
	static_assert(sizeof(BSTEventSink<void>) == 0x8);
}
