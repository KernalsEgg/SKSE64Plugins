#pragma once

#include "Shared/PCH.h"



// Based on std::vector
namespace Skyrim
{
	template <class T>
	class NiTNewInterface;

	template <class T>
	class NiTMallocInterface;

	// Sparse array with potentially null elements that should be skipped
	// CommonLibSSE checks capacity instead of size to see whether it is empty, and iterates from 0 to size - 1 instead of from 0 to free index - 1
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
		using iterator        = pointer;
		using const_iterator  = const_pointer;

		// Add
		virtual ~NiTArray(); // 0

		// Iterators
		constexpr iterator       begin() noexcept { return this->data(); }
		constexpr const_iterator begin() const noexcept { return this->data(); }
		constexpr const_iterator cbegin() const noexcept { return this->begin(); }

		constexpr iterator       end() noexcept { return this->empty() ? nullptr : this->data() + this->freeIndex_; }
		constexpr const_iterator end() const noexcept { return this->empty() ? nullptr : this->data() + this->freeIndex_; }
		constexpr const_iterator cend() const noexcept { return this->end(); }

		// Element access
		constexpr reference       operator[](size_type index) noexcept { return this->data()[index]; }
		constexpr const_reference operator[](size_type index) const noexcept { return this->data()[index]; }

		constexpr pointer       data() noexcept { return this->data_; }
		constexpr const_pointer data() const noexcept { return this->data_; }

		constexpr reference       front() noexcept { return operator[](0); }
		constexpr const_reference front() const noexcept { return operator[](0); }

		constexpr reference       back() noexcept { return operator[](this->freeIndex_ - 1); }
		constexpr const_reference back() const noexcept { return operator[](this->freeIndex_ - 1); }

		// Capacity
		constexpr bool empty() const noexcept { return this->size() == 0; }

		constexpr size_type size() const noexcept { return this->size_; }

		constexpr size_type capacity() const noexcept { return this->capacity_; }

	private:
		// Member variables
		value_type* data_;       // 8
		size_type   capacity_;   // 10
		size_type   freeIndex_;  // 12
		size_type   size_;       // 14
		size_type   growthSize_; // 16
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
