#pragma once

#include "Shared/PCH.h"



// Based on std::iterator
namespace Skyrim
{
	template <class T>
	class BSSimpleList
	{
	public:
		template <class U>
		class iterator
		{
		public:
			using value_type        = T;
			using pointer           = std::conditional_t<std::is_const_v<U>, const value_type*, value_type*>;
			using reference         = std::conditional_t<std::is_const_v<U>, const value_type&, value_type&>;
			using iterator_category = std::forward_iterator_tag;

			constexpr iterator() noexcept                = default;
			constexpr iterator(const iterator&) noexcept = default;
			constexpr iterator(iterator&&) noexcept      = default;

			constexpr ~iterator() noexcept = default;

			constexpr iterator& operator=(const iterator&) noexcept = default;
			constexpr iterator& operator=(iterator&&) noexcept = default;

			constexpr iterator(U* node) noexcept :
				node_(node)
			{
			}

			constexpr reference operator*() const noexcept { return this->node_->item_; }
			constexpr pointer   operator->() const noexcept { return std::addressof(this->node_->item_); }

			friend constexpr bool operator==(const iterator& left, const iterator& right) noexcept { return left.node_ == right.node_; }
			friend constexpr bool operator!=(const iterator& left, const iterator& right) noexcept { return !(left == right); }

			constexpr iterator& operator++() noexcept
			{
				this->node_ = this->node_->next_;

				return *this;
			}

			constexpr iterator operator++(int) noexcept
			{
				iterator iterator(*this);
				++(*this);

				return iterator;
			}

		private:
			// Member variables
			U* node_{ nullptr };
		};

		// Iterators
		constexpr iterator<BSSimpleList>       begin() noexcept { return this->empty() ? this->end() : iterator<BSSimpleList>(this); }
		constexpr iterator<const BSSimpleList> begin() const noexcept { return this->empty() ? this->end() : iterator<const BSSimpleList>(this); }
		constexpr iterator<const BSSimpleList> cbegin() const noexcept { return this->begin(); }

		constexpr iterator<BSSimpleList>       end() noexcept { return iterator<BSSimpleList>(nullptr); }
		constexpr iterator<const BSSimpleList> end() const noexcept { return iterator<const BSSimpleList>(nullptr); }
		constexpr iterator<const BSSimpleList> cend() const noexcept { return this->end(); }

		// Capacity
		constexpr bool empty() const noexcept { return !this->next_ && !this->item_; }

	private:
		// Member variables
		T             item_; // 0
		BSSimpleList* next_; // 8
	};
	static_assert(sizeof(BSSimpleList<void*>) == 0x10);
}
