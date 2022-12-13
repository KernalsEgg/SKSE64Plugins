#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSTTuple.h"



// Based on std::unordered_map and std::unordered_set
namespace Skyrim
{
	template <class T>
	struct BSCRC32;

	template <
		class Hash,
		class KeyEqual,
		class Traits,
		template <std::size_t, std::size_t> class Allocator>
	class BSTScatterTable
	{
	public:
		using traits_type     = Traits;
		using key_type        = Traits::key_type;
		using mapped_type     = Traits::mapped_type;
		using value_type      = Traits::value_type;
		using size_type       = std::uint32_t;
		using hasher          = Hash;
		using key_equal       = KeyEqual;
		using reference       = value_type&;
		using const_reference = const value_type&;
		using pointer         = value_type*;
		using const_pointer   = const value_type*;

		static_assert(std::is_invocable_r_v<bool, const key_equal&, const key_type&, const key_type&>);

		// Based on std::optional
		struct entry_type
		{
		public:
			constexpr bool has_value() const noexcept { return this->next != nullptr; }

			// Member variables
			value_type  value; // 0
			entry_type* next;  // ?
		};

		using allocator_type = Allocator<sizeof(entry_type), sizeof(entry_type)>;

		template <class U>
		class iterator
		{
		public:
			using value_type        = U;
			using pointer           = value_type*;
			using reference         = value_type&;
			using iterator_category = std::forward_iterator_tag;

			constexpr iterator() noexcept                = default;
			constexpr iterator(const iterator&) noexcept = default;
			constexpr iterator(iterator&&) noexcept      = default;

			constexpr ~iterator() noexcept = default;

			constexpr iterator& operator=(const iterator&) noexcept = default;
			constexpr iterator& operator=(iterator&&) noexcept      = default;

			constexpr iterator(entry_type* head, entry_type* tail) noexcept :
				head_(head), tail_(tail)
			{
				if (this->head_ && this->tail_)
				{
					while (this->head_ != this->tail_ && !this->head_->has_value())
					{
						++this->head_;
					}
				}
			}

			constexpr reference operator*() const noexcept { return this->head_->value; }
			constexpr pointer   operator->() const noexcept { return std::addressof(this->head_->value); }

			friend constexpr bool operator==(const iterator& left, const iterator& right) noexcept { return left.head_ == right.head_; }
			friend constexpr bool operator!=(const iterator& left, const iterator& right) noexcept { return !(left == right); }

			constexpr iterator& operator++() noexcept
			{
				do
				{
					++this->head_;
				} while (this->head_ != this->tail_ && !this->head_->has_value());

				return *this;
			}

			constexpr iterator operator++(int) noexcept
			{
				iterator iterator(*this);

				++(*this);

				return iterator;
			}

		private:
			entry_type* head_{ nullptr };
			entry_type* tail_{ nullptr };
		};

		// Element access
		constexpr entry_type* get_entries() const noexcept { return static_cast<entry_type*>(this->allocator_.get_entries()); }

		// Iterators
		constexpr iterator<value_type> begin() noexcept
		{
			auto* head = this->get_entries();

			return iterator<value_type>(head, head + this->capacity_);
		}

		constexpr iterator<const value_type> begin() const noexcept
		{
			auto* head = this->get_entries();

			return iterator<const value_type>(head, head + this->capacity_);
		}

		constexpr iterator<const value_type> cbegin() const noexcept { return this->begin(); }

		constexpr iterator<value_type> end() noexcept
		{
			auto* tail = this->get_entries() + this->capacity_;

			return iterator<value_type>(tail, tail);
		}

		constexpr iterator<const value_type> end() const noexcept
		{
			auto* tail = this->get_entries() + this->capacity_;

			return iterator<const value_type>(tail, tail);
		}

		constexpr iterator<const value_type> cend() const noexcept { return this->end(); }

		// Capacity
		constexpr bool empty() const noexcept { return this->size() == 0; }

		constexpr size_type size() const noexcept { return this->capacity_ - this->free_; }

		constexpr size_type capacity() const noexcept { return this->capacity_; }

	private:
		// Member variables
		std::uint64_t     padding0_;  // 0
		std::uint32_t     padding8_;  // 8
		size_type         capacity_;  // C, total number of entries (always a power of 2)
		size_type         free_;      // 10, number of free entries
		size_type         good_;      // 14, last free index
		const entry_type* sentinel_;  // 18, signals end of list
		allocator_type    allocator_; // 20
	};

	template <class Key, class T>
	class BSTScatterTableTraits
	{
	public:
		using key_type    = Key;
		using mapped_type = T;
		using value_type  = BSTTuple<const key_type, mapped_type>;
	};

	template <class Key>
	class BSTSetTraits
	{
	public:
		using key_type    = Key;
		using mapped_type = void;
		using value_type  = key_type;
	};

	template <std::size_t S, std::size_t A>
	struct BSTScatterTableHeapAllocator
	{
	public:
		// Member functions
		constexpr void* get_entries() const noexcept { return this->entries_; }

	private:
		// Member variables
		std::uint64_t padding0_; // 0 (20)
		std::uint8_t* entries_;  // 8 (28)
	};

	template <
		class Key,
		class T,
		class Hash     = BSCRC32<Key>,
		class KeyEqual = std::equal_to<Key>>
	using BSTHashMap = BSTScatterTable<
		Hash,
		KeyEqual,
		BSTScatterTableTraits<Key, T>,
		BSTScatterTableHeapAllocator>;

	template <
		class Key,
		class Hash     = BSCRC32<Key>,
		class KeyEqual = std::equal_to<Key>>
	using BSTSet = BSTScatterTable<
		Hash,
		KeyEqual,
		BSTSetTraits<Key>,
		BSTScatterTableHeapAllocator>;
}
