#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	template <class T>
	class SimpleArray
	{
	public:
		using size_type       = std::size_t;
		using value_type      = T;
		using pointer         = value_type*;
		using const_pointer   = const value_type*;
		using reference       = value_type&;
		using const_reference = const value_type&;
		using iterator        = pointer;
		using const_iterator  = const_pointer;

		// Iterators
		constexpr iterator       begin() noexcept { return this->data(); }
		constexpr const_iterator begin() const noexcept { return this->data(); }
		constexpr const_iterator cbegin() const noexcept { return this->begin(); }

		constexpr iterator       end() noexcept { return this->data() ? this->data() + this->size() : nullptr; }
		constexpr const_iterator end() const noexcept { return this->data() ? this->data() + this->size() : nullptr; }
		constexpr const_iterator cend() const noexcept { return this->end(); }

		// Element access
		constexpr reference       operator[](size_type index) noexcept { return this->data()[index]; }
		constexpr const_reference operator[](size_type index) const noexcept { return this->data()[index]; }

		constexpr pointer       data() noexcept { return this->data_; }
		constexpr const_pointer data() const noexcept { return this->data_; }

		constexpr reference       front() noexcept { return this->operator[](0); }
		constexpr const_reference front() const noexcept { return this->operator[](0); }

		constexpr reference       back() noexcept { return this->operator[](this->size() - 1); }
		constexpr const_reference back() const noexcept { return this->operator[](this->size() - 1); }

		// Capacity
		constexpr bool empty() const noexcept { return this->size() == 0; }

		constexpr size_type size() const noexcept { return this->data() ? *static_cast<const std::size_t*>(this->GetHead()) : 0; }

	private:
		constexpr void* GetHead() noexcept
		{
			if constexpr (alignof(value_type) > alignof(std::size_t))
			{
				return this->data() - 1;
			}
			else
			{
				return reinterpret_cast<std::size_t*>(this->data()) - 1;
			}
		}

		constexpr const void* GetHead() const noexcept
		{
			if constexpr (alignof(value_type) > alignof(std::size_t))
			{
				return this->data() - 1;
			}
			else
			{
				return reinterpret_cast<const std::size_t*>(this->data()) - 1;
			}
		}

		// Member variables
		pointer data_; // 0
	};
	static_assert(sizeof(SimpleArray<void*>) == 0x8);
}
