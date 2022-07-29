#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	template <class T>
	class NiTNewInterface;

	template <class T>
	class NiTMallocInterface;

	template <class T, class Allocator>
	class NiTArray
	{
	public:
		using size_type       = std::uint16_t;
		using value_type      = T;
		using pointer         = value_type*;
		using const_pointer   = const value_type*;
		using reference       = value_type&;
		using const_reference = const value_type&;

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
			constexpr iterator& operator=(iterator&&) noexcept = default;

			constexpr iterator(pointer head, pointer tail) noexcept :
				head_(head), tail_(tail)
			{
				if (this->head_ && this->tail_)
				{
					while (this->head_ != this->tail_ && !*(this->head_))
					{
						++this->head_;
					}
				}
			}

			constexpr reference operator*() const noexcept { return *(this->head_); }
			constexpr pointer   operator->() const noexcept { return this->head_; }

			friend constexpr bool operator==(const iterator& left, const iterator& right) noexcept { return left.head_ == right.head_; }
			friend constexpr bool operator!=(const iterator& left, const iterator& right) noexcept { return !(left == right); }

			constexpr iterator& operator++() noexcept
			{
				do
				{
					++this->head_;
				} while (this->head_ != this->tail_ && !*(this->head_));

				return *this;
			}

			constexpr iterator operator++(int) noexcept
			{
				iterator iterator{ *this };
				++(*this);

				return iterator;
			}

		private:
			pointer head_{ nullptr };
			pointer tail_{ nullptr };
		};

		// Add
		virtual ~NiTArray(); // 0

		// Iterators
		constexpr iterator<value_type> begin() noexcept
		{
			auto* head = this->data();

			return iterator<value_type>(head, head + this->freeIndex_);
		}

		constexpr iterator<const value_type> begin() const noexcept
		{
			const auto* head = this->data();

			return iterator<const value_type>(head, head + this->freeIndex_);
		}

		constexpr iterator<const value_type> cbegin() const noexcept { return this->begin(); }

		constexpr iterator<value_type> end() noexcept
		{
			auto* tail = this->data() + this->freeIndex_;

			return iterator<value_type>(tail, tail);
		}

		constexpr iterator<const value_type> end() const noexcept
		{
			const auto* tail = this->data() + this->freeIndex_;

			return iterator<const value_type>(tail, tail);
		}

		constexpr iterator<const value_type> cend() const noexcept { return this->end(); }

		// Element access
		constexpr pointer       data() noexcept { return this->data_; }
		constexpr const_pointer data() const noexcept { return this->data_; }

		// Capacity
		constexpr bool empty() const noexcept { return this->size() == 0; }

		constexpr size_type size() const noexcept { return this->size_; }

		constexpr size_type capacity() const noexcept { return this->capacity_; }

	private:
		// Member variables
		pointer   data_;       // 8
		size_type capacity_;   // 10
		size_type freeIndex_;  // 12
		size_type size_;       // 14
		size_type growthSize_; // 16
	};
	static_assert(sizeof(NiTArray<void*, void>) == 0x18);

	template <class T>
	class NiTObjectArray :
		public NiTArray<T, NiTNewInterface<T>> // 0
	{
	};
	static_assert(sizeof(NiTObjectArray<void*>) == 0x18);

	template <class T>
	class NiTPrimitiveArray :
		public NiTArray<T, NiTMallocInterface<T>> // 0
	{
	};
	static_assert(sizeof(NiTPrimitiveArray<void*>) == 0x18);
}
