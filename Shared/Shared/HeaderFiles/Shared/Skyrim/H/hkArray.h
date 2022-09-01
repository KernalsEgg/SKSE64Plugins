#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	template <class T>
	class hkArrayBase
	{
	public:
		using size_type       = std::int32_t;
		using value_type      = T;
		using pointer         = value_type*;
		using const_pointer   = const value_type*;
		using reference       = value_type&;
		using const_reference = const value_type&;
		using iterator        = pointer;
		using const_iterator  = const_pointer;

		enum
		{
			kCapacityMask = 0x3FFFFFFF,
			kFlagMask     = 0xC0000000
		};

		// Iterators
		constexpr iterator       begin() noexcept { return this->data(); }
		constexpr const_iterator begin() const noexcept { return this->data(); }
		constexpr const_iterator cbegin() const noexcept { return this->begin(); }

		constexpr iterator       end() noexcept { return this->data() + this->size(); }
		constexpr const_iterator end() const noexcept { return this->data() + this->size(); }
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

		constexpr size_type size() const noexcept { return this->size_; }

		constexpr size_type capacity() const noexcept { return this->capacityAndFlags_ & hkArrayBase::kCapacityMask; }

	private:
		// Member variables
		T*           data_;             // 0
		std::int32_t size_;             // 8
		std::int32_t capacityAndFlags_; // C
	};
	static_assert(sizeof(hkArrayBase<void*>) == 0x10);

	template <class T, class Allocator = void>
	class hkArray :
		public hkArrayBase<T> // 0
	{
	};
	static_assert(sizeof(hkArray<void*>) == 0x10);

	template <class T, std::size_t Count, class Allocator = void>
	class hkInplaceArray :
		public hkArray<T, Allocator> // 0
	{
	public:
		T storage[Count]; // 10
	};
}
