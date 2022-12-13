#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/M/MemoryManager.h"



namespace Skyrim
{
	// Based on std::forward_list
	template <class T>
	class BSSimpleList
	{
	public:
		using value_type      = T;
		using reference       = value_type&;
		using const_reference = const value_type&;

		SKYRIM_MEMORY_REDEFINE_NEW();

		struct Node
		{
		public:
			SKYRIM_MEMORY_REDEFINE_NEW();

			Node()            = default;
			Node(const Node&) = default;

			Node(Node&& right) :
				value(std::move(right.value)),
				next(std::move(right.next))
			{
				right.next = nullptr;
			}

			~Node() = default;

			Node& operator=(const Node&) = default;

			Node& operator=(Node&& right)
			{
				if (this != std::addressof(right))
				{
					this->value = std::move(right.value);
					this->next  = std::move(right.next);

					right.next = nullptr;
				}

				return *this;
			}

			Node(value_type value, Node* next) :
				value(value),
				next(next)
			{
			}

			Node(const value_type& value) :
				value(value)
			{
			}

			Node(value_type&& value) :
				value(std::move(value))
			{
			}

			// Member variables
			value_type value{};         // 0
			Node*      next{ nullptr }; // ?
		};

		template <class U>
		class iterator
		{
		public:
			using value_type        = std::conditional_t<std::is_const_v<U>, const value_type, value_type>;
			using pointer           = value_type*;
			using reference         = value_type&;
			using iterator_category = std::forward_iterator_tag;

			constexpr iterator() noexcept                = default;
			constexpr iterator(const iterator&) noexcept = default;
			constexpr iterator(iterator&&) noexcept      = default;

			constexpr ~iterator() noexcept = default;

			constexpr iterator& operator=(const iterator&) noexcept = default;
			constexpr iterator& operator=(iterator&&) noexcept      = default;

			constexpr iterator(U* current) noexcept :
				current_(current)
			{
			}

			constexpr reference operator*() const noexcept { return this->current_->value; }
			constexpr pointer   operator->() const noexcept { return std::addressof(this->current_->value); }

			friend constexpr bool operator==(const iterator& left, const iterator& right) noexcept { return left.current_ == right.current_; }
			friend constexpr bool operator!=(const iterator& left, const iterator& right) noexcept { return !(left == right); }

			constexpr iterator& operator++() noexcept
			{
				this->current_ = this->current_->next;

				return *this;
			}

			constexpr iterator operator++(int) noexcept
			{
				iterator iterator(*this);

				++(*this);

				return iterator;
			}

		private:
			U* current_{ nullptr };
		};

		BSSimpleList() = default;

		BSSimpleList(const BSSimpleList& right)
		{
			this->copy(right);
		}

		BSSimpleList(BSSimpleList&&) = default;

		~BSSimpleList()
		{
			this->clear();
		}

		BSSimpleList& operator=(const BSSimpleList& right)
		{
			if (this != std::addressof(right))
			{
				this->clear();
				this->copy(right);
			}

			return *this;
		}

		BSSimpleList& operator=(BSSimpleList&& right)
		{
			if (this != std::addressof(right))
			{
				this->clear();
				this->head_ = std::move(right.head_);
			}

			return *this;
		}

		// Element access
		constexpr reference       front() noexcept { return *this->begin(); }
		constexpr const_reference front() const noexcept { return *this->begin(); }

		// Iterators
		constexpr iterator<Node>       begin() noexcept { return iterator<Node>(this->get_head()); }
		constexpr iterator<const Node> begin() const noexcept { return iterator<const Node>(this->get_head()); }
		constexpr iterator<const Node> cbegin() const noexcept { return this->begin(); }

		constexpr iterator<Node>       end() noexcept { return iterator<Node>(nullptr); }
		constexpr iterator<const Node> end() const noexcept { return iterator<const Node>(nullptr); }
		constexpr iterator<const Node> cend() const noexcept { return this->end(); }

		// Modifiers
		void clear()
		{
			auto* head = this->get_head();
			auto* next = head->next;

			std::destroy_at(std::addressof(head->value));

			head->next = nullptr;

			while (next)
			{
				head = next;
				next = next->next;

				delete head;
			}
		}

		void push_front(const value_type& value) { this->emplace_front_implementation(value); }
		void push_front(value_type&& value) { this->emplace_front_implementation(std::move(value)); }

		template <class... Arguments>
		reference emplace_front(Arguments&&... arguments)
		{
			this->emplace_front_implementation(std::forward<Arguments>(arguments)...);

			return this->front();
		}

		void pop_front()
		{
			auto* head = this->get_head();
			auto* next = head->next;

			std::destroy_at(std::addressof(head->value));

			if (next)
			{
				std::construct_at(std::addressof(head->value), std::move(next->value));

				head->next = next->next;

				delete next;
			}
		}

	private:
		void copy(const BSSimpleList& right)
		{
			auto* leftHead  = this->get_head();
			auto* rightHead = right.get_head();

			leftHead->value = rightHead->value;

			while (rightHead->next)
			{
				rightHead      = rightHead->next;
				leftHead->next = new Node(rightHead->value);
				leftHead       = leftHead->next;
			}
		}

		template <class... Arguments>
		void emplace_front_implementation(Arguments&&... arguments)
		{
			auto* head = this->get_head();

			if (static_cast<bool>(head->value))
			{
				head->next = new Node(std::move(*head));
			}

			std::destroy_at(std::addressof(head->value));
			std::construct_at(std::addressof(head->value), std::forward<Arguments>(arguments)...);
		}

		constexpr Node*       get_head() noexcept { return std::addressof(this->head_); }
		constexpr const Node* get_head() const noexcept { return std::addressof(this->head_); }

		// Member variables
		Node head_{}; // 0
	};
	static_assert(sizeof(BSSimpleList<void*>) == 0x10);
}
