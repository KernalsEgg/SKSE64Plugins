#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSAtomic.h"
#include "Shared/Skyrim/B/BSTArray.h"



namespace Skyrim
{
	class AlchemyItem;
	class EnchantmentItem;

	class BGSCreatedObjectManager
	{
	public:
		struct EnchantmentEntry
		{
		public:
			// Member variables
			EnchantmentItem*       enchantment;    // 0
			volatile std::uint32_t referenceCount; // 8
			std::uint32_t          paddingC;       // C
		};
		static_assert(offsetof(EnchantmentEntry, enchantment) == 0x0);
		static_assert(offsetof(EnchantmentEntry, referenceCount) == 0x8);
		static_assert(sizeof(EnchantmentEntry) == 0x10);

		// Non-member functions
		static BGSCreatedObjectManager* GetSingleton();

		// Member functions
		void DecrementReference(AlchemyItem* potion);

		// Member variables
		std::uint64_t              unknown0;           // 0
		BSTArray<EnchantmentEntry> weaponEnchantments; // 8
		BSTArray<EnchantmentEntry> armorEnchantments;  // 20
		std::uint64_t              unknown38;          // 38
		std::uint64_t              unknown40;          // 40
		std::uint64_t              unknown48;          // 48
		std::uint64_t              unknown50;          // 50
		std::uint64_t              unknown58;          // 58
		std::uint64_t              unknown60;          // 60
		std::uint64_t              unknown68;          // 68
		std::uint64_t              unknown70;          // 70
		std::uint64_t              unknown78;          // 78
		std::uint64_t              unknown80;          // 80
		std::uint64_t              unknown88;          // 88
		std::uint64_t              unknown90;          // 90
		std::uint64_t              unknown98;          // 98
		std::uint64_t              unknownA0;          // A0
		std::uint64_t              unknownA8;          // A8
		std::uint64_t              unknownB0;          // B0
		std::uint64_t              unknownB8;          // B8
		std::uint64_t              unknownC0;          // C0
		mutable BSSpinLock         lock;               // C8
	};
	static_assert(offsetof(BGSCreatedObjectManager, weaponEnchantments) == 0x8);
	static_assert(offsetof(BGSCreatedObjectManager, armorEnchantments) == 0x20);
	static_assert(offsetof(BGSCreatedObjectManager, lock) == 0xC8);
	static_assert(sizeof(BGSCreatedObjectManager) == 0xD0);
}
