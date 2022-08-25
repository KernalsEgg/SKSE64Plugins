#pragma once

#include "Shared/Skyrim/I/IMemoryStore.h"



namespace Skyrim
{
	class ScrapHeap :
		public IMemoryStore // 0
	{
	public:
		struct Block
		{
		public:
			// Member variables
			std::size_t sizeFlags; // 0
			Block*      previous;  // 8
		};
		static_assert(offsetof(Block, sizeFlags) == 0x0);
		static_assert(offsetof(Block, previous) == 0x8);
		static_assert(sizeof(Block) == 0x10);

		struct FreeBlock :
			public Block // 0
		{
		public:
			// Member variables
			FreeBlock* left;  // 10
			FreeBlock* right; // 18
		};
		static_assert(offsetof(FreeBlock, left) == 0x10);
		static_assert(offsetof(FreeBlock, right) == 0x18);
		static_assert(sizeof(FreeBlock) == 0x20);

		struct FreeTreeNode :
			public Block // 0
		{
		public:
			// Member variables
			FreeTreeNode** root;           // 10
			FreeTreeNode*  left;           // 18
			FreeTreeNode*  right;          // 20
			std::size_t    parentAndBlack; // 28
		};
		static_assert(offsetof(FreeTreeNode, root) == 0x10);
		static_assert(offsetof(FreeTreeNode, left) == 0x18);
		static_assert(offsetof(FreeTreeNode, right) == 0x20);
		static_assert(offsetof(FreeTreeNode, parentAndBlack) == 0x28);
		static_assert(sizeof(FreeTreeNode) == 0x30);

		// Override
		virtual ~ScrapHeap() override; // 0

		// Override (IMemoryStore)
		virtual std::size_t Size(const void* pointer) const override;                                          // 1
		virtual void        GetMemoryStatistics(MemoryStatistics* memoryStatistics) override;                  // 2
		virtual bool        ContainsBlockImplementation(const void* block) const override;                     // 3
		virtual void*       AllocateAlignedImplementation(std::size_t size, std::uint32_t alignment) override; // 4
		virtual void        DeallocateAlignedImplementation(void*& block) override;                            // 5

		// Member functions
		void* Allocate(std::size_t size, std::size_t alignment);
		void  Deallocate(void* pointer);

		// Member variables
		FreeBlock*    freeSmallBlocks[6];  // 8
		FreeTreeNode* freeTreeNodes;       // 38
		Block*        lastBlock;           // 40
		void*         baseAddress;         // 48
		void*         endAddress;          // 50
		void*         commitEndAddress;    // 58
		std::size_t   reservedSize;        // 60
		std::size_t   minimumCommitSize;   // 68
		std::size_t   allocatedSize;       // 70
		std::uint32_t keepPagesCount;      // 78
		std::uint32_t freeBlockCount;      // 7C
		std::uint32_t freeSmallBlockCount; // 80
		std::uint32_t allocatedBlockCount; // 84
		std::uint32_t pmpBarrier;          // 88
		std::uint32_t padding8C;           // 8C
	};
	static_assert(offsetof(ScrapHeap, freeSmallBlocks) == 0x8);
	static_assert(offsetof(ScrapHeap, freeTreeNodes) == 0x38);
	static_assert(offsetof(ScrapHeap, lastBlock) == 0x40);
	static_assert(offsetof(ScrapHeap, baseAddress) == 0x48);
	static_assert(offsetof(ScrapHeap, endAddress) == 0x50);
	static_assert(offsetof(ScrapHeap, commitEndAddress) == 0x58);
	static_assert(offsetof(ScrapHeap, reservedSize) == 0x60);
	static_assert(offsetof(ScrapHeap, minimumCommitSize) == 0x68);
	static_assert(offsetof(ScrapHeap, allocatedSize) == 0x70);
	static_assert(offsetof(ScrapHeap, keepPagesCount) == 0x78);
	static_assert(offsetof(ScrapHeap, freeBlockCount) == 0x7C);
	static_assert(offsetof(ScrapHeap, freeSmallBlockCount) == 0x80);
	static_assert(offsetof(ScrapHeap, allocatedBlockCount) == 0x84);
	static_assert(offsetof(ScrapHeap, pmpBarrier) == 0x88);
	static_assert(sizeof(ScrapHeap) == 0x90);
}
