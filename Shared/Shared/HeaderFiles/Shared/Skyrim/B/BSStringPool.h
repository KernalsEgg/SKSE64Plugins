#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	struct BSStringPool
	{
	public:
		class Entry
		{
		public:
			enum
			{
				kWide = 1U << 15,

				kReferenceCountMask = 0x7FFF,
				kSizeMask           = 0xFFFFFF
			};

			// Non-member functions
			static void Release(const char*& string);
			// ReleaseW

			// Member functions
			void Acquire();

			constexpr std::uint16_t crc() const noexcept { return this->crc_; }

			const char* data() const noexcept { return reinterpret_cast<const char*>(this + 1); }

			constexpr std::uint32_t size() const noexcept { return this->size_ & Entry::kSizeMask; }

			constexpr bool wide() const noexcept { return (this->flags_ & Entry::kWide) == Entry::kWide; }

		private:
			// Member variables
			Entry*                 left_;  // 0
			volatile std::uint16_t flags_; // 8
			std::uint16_t          crc_;   // A
			union
			{
			public:
				// Member variables
				std::uint32_t size_;
				Entry*        right_;
			}; // 10
		};
		static_assert(sizeof(Entry) == 0x18);
	};
	static_assert(std::is_empty_v<BSStringPool>);
}
