#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	template <class T>
	class BSTFreeList;

	template <class T>
	struct BSTFreeListElement;

	template <class T>
	class BSTMessageQueue
	{
	public:
		// Add
		virtual ~BSTMessageQueue();           // 0
		virtual bool Push(T* element)    = 0; // 1
		virtual bool TryPush(T* element) = 0; // 2
		virtual bool Pop(T* element)     = 0; // 3
		virtual bool TryPop(T* element)  = 0; // 4
	};
	static_assert(sizeof(BSTMessageQueue<void*>) == 0x8);

	template <class T>
	class BSTCommonMessageQueue :
		public BSTMessageQueue<T> // 0
	{
	public:
		// Override
		virtual ~BSTCommonMessageQueue() override; // 0

		// Override (BSTMessageQueue<T>)
		virtual bool Push(T* element) override;    // 1
		virtual bool TryPush(T* element) override; // 2
		virtual bool Pop(T* element) override;     // 3
		virtual bool TryPop(T* element) override;  // 4

	protected:
		// Add
		virtual bool DoTryPush(T* element); // 5
		virtual bool DoTryPop(T* element);  // 6

	public:
		volatile mutable std::uint32_t lock;     // 8
		std::uint32_t                  paddingC; // C
	};
	static_assert(offsetof(BSTCommonMessageQueue<void*>, lock) == 0x8);
	static_assert(sizeof(BSTCommonMessageQueue<void*>) == 0x10);

	template <class T>
	class BSTCommonScrapHeapMessageQueue :
		public BSTCommonMessageQueue<T> // 0
	{
	public:
		// Override
		virtual ~BSTCommonScrapHeapMessageQueue() override; // 0

	protected:
		// Override (BSTCommonMessageQueue<T>)
		virtual bool DoTryPush(T* element) override; // 5
		virtual bool DoTryPop(T* element) override;  // 6

	public:
		// Member variables
		std::uint64_t padding10; // 10
		std::uint64_t padding18; // 18
		std::uint64_t padding20; // 20
	};
	static_assert(sizeof(BSTCommonScrapHeapMessageQueue<void*>) == 0x28);

	template <class T>
	class BSTCommonLLMessageQueue :
		public BSTCommonMessageQueue<T> // 0
	{
	public:
		// Override
		virtual ~BSTCommonLLMessageQueue() override; // 0

	protected:
		// Override (BSTCommonMessageQueue<T>)
		virtual bool DoTryPush(T* element) override; // 5
		virtual bool DoTryPop(T* element) override;  // 6

	public:
		// Member variables
		BSTFreeList<T>*        freeList; // 10
		BSTFreeListElement<T>* head;     // 18
		BSTFreeListElement<T>* tail;     // 20 (Pointer to pointer?)
	};
	static_assert(offsetof(BSTCommonLLMessageQueue<void*>, freeList) == 0x10);
	static_assert(offsetof(BSTCommonLLMessageQueue<void*>, head) == 0x18);
	static_assert(offsetof(BSTCommonLLMessageQueue<void*>, tail) == 0x20);
	static_assert(sizeof(BSTCommonLLMessageQueue<void*>) == 0x28);

	template <class T, std::size_t Count>
	class BSTCommonStaticMessageQueue :
		public BSTCommonMessageQueue<T> // 0
	{
	public:
		// Override
		virtual ~BSTCommonStaticMessageQueue() override; // 0

	protected:
		// Override (BSTCommonMessageQueue<T>)
		virtual bool DoTryPush(T* element) override; // 5
		virtual bool DoTryPop(T* element) override;  // 6

	public:
		// Member variables
		char          queueBuffer[sizeof(T) * Count]; // 10
		std::uint32_t elementCount;                   // ?
		std::uint32_t pushIndex;                      // ?
		std::uint32_t popIndex;                       // ?
	};
}
