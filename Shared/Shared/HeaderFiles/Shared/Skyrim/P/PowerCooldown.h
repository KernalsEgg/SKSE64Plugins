#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	class SpellItem;

	struct PowerCooldown
	{
	public:
		template <class T>
		class iterator
		{
		public:
			using value_type        = T;
			using pointer           = value_type*;
			using reference         = value_type&;
			using iterator_category = std::forward_iterator_tag;

			constexpr iterator() noexcept                = default;
			constexpr iterator(const iterator&) noexcept = default;
			constexpr iterator(iterator&&) noexcept      = default;

			constexpr ~iterator() noexcept = default;

			constexpr iterator& operator=(const iterator&) noexcept = default;
			constexpr iterator& operator=(iterator&&) noexcept = default;

			constexpr iterator(T* powerCooldown) noexcept :
				node_(powerCooldown)
			{
			}

			const reference operator*() const noexcept { return *this->node_; }
			const pointer   operator->() const noexcept { return this->node_; }

			friend constexpr bool operator==(const iterator& left, const iterator& right) noexcept { return left.node_ == right.node_; }
			friend constexpr bool operator!=(const iterator& left, const iterator& right) noexcept { return !(left == right); }

			constexpr iterator& operator++() noexcept
			{
				this->node_ = this->node_->next;

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
			pointer node_{ nullptr };
		};

		constexpr iterator<PowerCooldown>       begin() noexcept { return iterator<PowerCooldown>(this); }
		constexpr iterator<const PowerCooldown> begin() const noexcept { return iterator<const PowerCooldown>(this); }
		constexpr iterator<const PowerCooldown> cbegin() const noexcept { return this->begin(); }

		constexpr iterator<PowerCooldown>       end() noexcept { return iterator<PowerCooldown>(nullptr); }
		constexpr iterator<const PowerCooldown> end() const noexcept { return iterator<const PowerCooldown>(nullptr); }
		constexpr iterator<const PowerCooldown> cend() const noexcept { return this->end(); }

		// Member variables
		SpellItem*     power;    // 0
		float          cooldown; // 8
		std::uint32_t  paddingC; // C
		PowerCooldown* next;     // 10
	};
	static_assert(offsetof(PowerCooldown, power) == 0x0);
	static_assert(offsetof(PowerCooldown, cooldown) == 0x8);
	static_assert(offsetof(PowerCooldown, next) == 0x10);
	static_assert(sizeof(PowerCooldown) == 0x18);
}
