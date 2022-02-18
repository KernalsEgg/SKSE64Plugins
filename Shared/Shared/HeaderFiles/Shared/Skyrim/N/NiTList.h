#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	template <class T>
	class NiTDefaultAllocator;

	template <class T>
	class NiTListItem
	{
	public:
		// Member variables
		NiTListItem* next;     // 0
		NiTListItem* previous; // 8
		T            item;     // 10
	};
	static_assert(offsetof(NiTListItem<void*>, next) == 0x0);
	static_assert(offsetof(NiTListItem<void*>, previous) == 0x8);
	static_assert(offsetof(NiTListItem<void*>, item) == 0x10);
	static_assert(sizeof(NiTListItem<void*>) == 0x18);

	template <class Allocator, class T>
	class NiTListBase
	{
	public:
		// Member variables
		NiTListItem<T>* head;    // 0
		NiTListItem<T>* tail;    // 8
		std::int64_t    unknown; // 10
	};
	static_assert(sizeof(NiTListBase<void, void*>) == 0x18);

	template <class Allocator, class T>
	class NiTPointerListBase :
		public NiTListBase<Allocator, T> // 0
	{
	};
	static_assert(sizeof(NiTPointerListBase<void, void*>) == 0x18);

	template <class T>
	class NiTList :
		public NiTPointerListBase<NiTDefaultAllocator<T>, T> // 0
	{
	};
	static_assert(sizeof(NiTList<void*>) == 0x18);
}
