#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	template <class T>
	struct GListNode
	{
	public:
		using value_type = T;
		using reference  = value_type&;
		using pointer    = value_type*;

		void Remove()
		{
			this->previous->next = this->next;
			this->next->previous = this->previous;
		}

		// Member variables
		pointer previous{ nullptr }; // 0
		pointer next{ nullptr };     // 8
	};
	static_assert(offsetof(GListNode<void*>, previous) == 0x0);
	static_assert(offsetof(GListNode<void*>, next) == 0x8);
	static_assert(sizeof(GListNode<void*>) == 0x10);

	// Doubly-linked intrusive list
	// Classes must derive from GListNode
	template <class T>
	class GList
	{
	public:
		using size_type       = std::size_t;
		using value_type      = T;
		using reference       = value_type&;
		using const_reference = const value_type&;
		using pointer         = value_type*;
		using const_pointer   = const value_type*;

		template <class U>
		class iterator
		{
		public:
			using difference_type   = std::ptrdiff_t;
			using value_type        = U;
			using reference         = value_type&;
			using pointer           = value_type*;
			using iterator_category = std::bidirectional_iterator_tag;

			constexpr iterator() noexcept                = default;
			constexpr iterator(const iterator&) noexcept = default;
			constexpr iterator(iterator&&) noexcept      = default;

			constexpr ~iterator() noexcept = default;

			constexpr iterator& operator=(const iterator&) noexcept = default;
			constexpr iterator& operator=(iterator&&) noexcept      = default;

			constexpr iterator(pointer current) noexcept :
				current_(current)
			{
			}

			constexpr reference operator*() const noexcept
			{
				return *this->current_;
			}

			constexpr pointer operator->() const noexcept
			{
				return this->current_;
			}

			friend constexpr bool operator==(const iterator& left, const iterator& right) noexcept
			{
				return left.current_ == right.current_;
			}

			friend constexpr bool operator!=(const iterator& left, const iterator& right) noexcept
			{
				return !(left == right);
			}

			constexpr iterator& operator++() noexcept
			{
				this->current_ = this->current_->next;

				return *this;
			}

			constexpr iterator operator++(int) noexcept
			{
				iterator iterator{ *this };

				++(*this);

				return iterator;
			}

			constexpr iterator& operator--() noexcept
			{
				this->current_ = this->current_->previous;

				return *this;
			}

			constexpr iterator operator--(int) noexcept
			{
				iterator iterator{ *this };

				--(*this);

				return iterator;
			}

		private:
			// Member variables
			pointer current_{ nullptr }; // 0
		};

		constexpr GList() noexcept
		{
			this->clear();
		}

		constexpr GList(const GList&) noexcept = delete;
		constexpr GList(GList&&) noexcept      = delete;

		constexpr ~GList() noexcept = default;

		constexpr GList& operator=(const GList&) noexcept = delete;
		constexpr GList& operator=(GList&&) noexcept      = delete;

		constexpr reference front() noexcept
		{
			return *this->root_.next;
		}

		constexpr const_reference front() const noexcept
		{
			return *this->root_.next;
		}

		constexpr reference back() noexcept
		{
			return *this->root_.previous;
		}

		constexpr const_reference back() const noexcept
		{
			return *this->root_.previous;
		}

		constexpr iterator<value_type> begin() noexcept
		{
			return iterator<value_type>(this->root_.next);
		}

		constexpr iterator<const value_type> begin() const noexcept
		{
			return iterator<const value_type>(this->root_.next);
		}

		constexpr iterator<const value_type> cbegin() const noexcept
		{
			return this->begin();
		}

		constexpr iterator<value_type> end() noexcept
		{
			return iterator<value_type>(static_cast<pointer>(std::addressof(this->root_)));
		}

		constexpr iterator<const value_type> end() const noexcept
		{
			return iterator<const value_type>(static_cast<const_pointer>(std::addressof(this->root_)));
		}

		constexpr iterator<const value_type> cend() const noexcept
		{
			return this->end();
		}

		constexpr std::reverse_iterator<iterator<value_type>> rbegin() noexcept
		{
			return std::reverse_iterator<iterator<value_type>>(this->end());
		}

		constexpr std::reverse_iterator<iterator<const value_type>> rbegin() const noexcept
		{
			return std::reverse_iterator<iterator<const value_type>>(this->end());
		}

		constexpr std::reverse_iterator<iterator<const value_type>> crbegin() const noexcept
		{
			return this->rbegin();
		}

		constexpr std::reverse_iterator<iterator<value_type>> rend() noexcept
		{
			return std::reverse_iterator<iterator<value_type>>(this->begin());
		}

		constexpr std::reverse_iterator<iterator<const value_type>> rend() const noexcept
		{
			return std::reverse_iterator<iterator<const value_type>>(this->begin());
		}

		constexpr std::reverse_iterator<iterator<const value_type>> crend() const noexcept
		{
			return this->rend();
		}

		constexpr bool empty() const noexcept
		{
			return this->root_.next == std::addressof(this->root_);
		}

		constexpr void clear() noexcept
		{
			this->root_.next     = static_cast<pointer>(std::addressof(this->root_));
			this->root_.previous = static_cast<pointer>(std::addressof(this->root_));
		}

		constexpr void push_back(pointer value)
		{
			value->previous = this->root_.previous;
			value->next     = static_cast<pointer>(std::addressof(this->root_));

			this->root_.previous->next = value;
			this->root_.previous       = value;
		}

		constexpr void pop_back()
		{
			this->root_.previous       = this->root_.previous->previous;
			this->root_.previous->next = static_cast<pointer>(std::addressof(this->root_));
		}

		constexpr void push_front(pointer value)
		{
			value->next     = this->root_.next;
			value->previous = static_cast<pointer>(std::addressof(this->root_));

			this->root_.next->previous = value;
			this->root_.next           = value;
		}

		constexpr void pop_front()
		{
			this->root_.next           = this->root_.next->next;
			this->root_.next->previous = static_cast<pointer>(std::addressof(this->root_));
		}

	private:
		// Member variables
		GListNode<value_type> root_{ nullptr }; // 0
	};
	static_assert(sizeof(GList<void*>) == 0x10);
}
