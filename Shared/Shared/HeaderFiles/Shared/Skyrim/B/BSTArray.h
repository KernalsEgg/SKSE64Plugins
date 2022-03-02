#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



// Based on std::vector
namespace Skyrim
{
	struct Effect;

	class ScrapHeap;

	class BSTArrayBase
	{
	public:
		using size_type = std::uint32_t;

		constexpr bool      empty() const noexcept { return this->size_ == 0; }
		constexpr size_type size() const noexcept { return this->size_; }

	private:
		// Member variables
		size_type size_; // 0
	};
	static_assert(sizeof(BSTArrayBase) == 0x4);

	class BSTArrayHeapAllocator
	{
	public:
		using size_type = std::uint32_t;

		constexpr void*       data() noexcept { return this->data_; }
		constexpr const void* data() const noexcept { return this->data_; }
		constexpr size_type   capacity() const noexcept { return this->capacity_; }

	private:
		// Member variables
		void*     data_;     // 0
		size_type capacity_; // 8
	};
	static_assert(sizeof(BSTArrayHeapAllocator) == 0x10);

	template <std::uint32_t N>
	class BSTSmallArrayHeapAllocator
	{
	public:
		using size_type = std::uint32_t;

		constexpr void*       data() noexcept { return this->local() ? this->data_.local : this->data_.heap; }
		constexpr const void* data() const noexcept { return this->local() ? this->data_.local : this->data_.heap; }

		constexpr size_type capacity() const noexcept { return this->capacity_; }

	private:
		constexpr bool local() const noexcept { return this->local_ != 0; }

		// Member variables
		size_type capacity_: 31; // 0
		size_type local_   : 1;  // 0
		union
		{
		public:
			// Member variables
			void* heap;
			char  local[N];
		} data_; // 8
	};
	static_assert(sizeof(BSTSmallArrayHeapAllocator<sizeof(void*)>) == 0x10);

	class BSScrapArrayAllocator
	{
	public:
		using size_type = std::uint32_t;

		constexpr void*       data() noexcept { return this->data_; }
		constexpr const void* data() const noexcept { return this->data_; }

		constexpr size_type capacity() const noexcept { return this->capacity_; }

	private:
		// Member variables
		ScrapHeap* allocator_; // 0
		void*      data_;      // 8
		size_type  capacity_;  // 10
	};
	static_assert(sizeof(BSScrapArrayAllocator) == 0x18);

	template <class T, class Allocator = BSTArrayHeapAllocator>
	class BSTArray :
		public Allocator,   // 0
		public BSTArrayBase // 10
	{
	public:
		using allocator_type  = Allocator;
		using size_type       = typename BSTArrayBase::size_type;
		using value_type      = T;
		using pointer         = value_type*;
		using const_pointer   = const value_type*;
		using reference       = value_type&;
		using const_reference = const value_type&;
		using iterator        = pointer;
		using const_iterator  = const_pointer;

		// Iterators
		constexpr iterator       begin() noexcept { return this->empty() ? nullptr : this->data(); }
		constexpr const_iterator begin() const noexcept { return this->empty() ? nullptr : this->data(); }
		constexpr const_iterator cbegin() const noexcept { return this->begin(); }

		constexpr iterator       end() noexcept { return this->empty() ? nullptr : this->data() + this->size(); }
		constexpr const_iterator end() const noexcept { return this->empty() ? nullptr : this->data() + this->size(); }
		constexpr const_iterator cend() const noexcept { return this->end(); }

		// Element access
		constexpr reference       operator[](size_type index) noexcept { return this->data()[index]; }
		constexpr const_reference operator[](size_type index) const noexcept { return this->data()[index]; }

		constexpr pointer       data() noexcept { return static_cast<pointer>(allocator_type::data()); }
		constexpr const_pointer data() const noexcept { return static_cast<const_pointer>(allocator_type::data()); }

		constexpr reference       front() noexcept { return operator[](0); }
		constexpr const_reference front() const noexcept { return operator[](0); }

		constexpr reference       back() noexcept { return operator[](this->size() - 1); }
		constexpr const_reference back() const noexcept { return operator[](this->size() - 1); }

		// Capacity
		constexpr bool empty() const noexcept { return BSTArrayBase::empty(); }

		constexpr size_type size() const noexcept { return BSTArrayBase::size(); }

		constexpr size_type capacity() const noexcept { return allocator_type::capacity(); }

		// Member functions
		size_type AddEffect(Effect* effect)
		{
			auto function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&BSTArray::AddEffect)>::type>(Addresses::BSTArray::AddEffect) };

			return function(this, effect);
		}
	};
	static_assert(sizeof(BSTArray<void*>) == 0x18);

	template <class T, std::uint32_t N = 1>
	using BSTSmallArray = BSTArray<T, BSTSmallArrayHeapAllocator<sizeof(T) * N>>;
	static_assert(sizeof(BSTSmallArray<void*>) == 0x18);

	template <class T>
	using BSScrapArray = BSTArray<T, BSScrapArrayAllocator>;
	static_assert(sizeof(BSScrapArray<void*>) == 0x20);

	template <class T>
	class BSStaticArray
	{
	public:
		using size_type       = std::uint32_t;
		using value_type      = T;
		using pointer         = value_type*;
		using const_pointer   = const value_type*;
		using reference       = value_type&;
		using const_reference = const value_type&;
		using iterator        = pointer;
		using const_iterator  = const_pointer;

		// Iterators
		constexpr iterator       begin() noexcept { return this->empty() ? nullptr : this->data(); }
		constexpr const_iterator begin() const noexcept { return this->empty() ? nullptr : this->data(); }
		constexpr const_iterator cbegin() const noexcept { return this->begin(); }

		constexpr iterator       end() noexcept { return this->empty() ? nullptr : this->data() + this->size(); }
		constexpr const_iterator end() const noexcept { return this->empty() ? nullptr : this->data() + this->size(); }
		constexpr const_iterator cend() const noexcept { return this->end(); }

		// Element access
		constexpr reference       operator[](size_type index) noexcept { return this->data()[index]; }
		constexpr const_reference operator[](size_type index) const noexcept { return this->data()[index]; }

		constexpr pointer       data() noexcept { return this->data_; }
		constexpr const_pointer data() const noexcept { return this->data_; }

		constexpr reference       front() noexcept { return operator[](0); }
		constexpr const_reference front() const noexcept { return operator[](0); }

		constexpr reference       back() noexcept { return operator[](this->size() - 1); }
		constexpr const_reference back() const noexcept { return operator[](this->size() - 1); }

		// Capacity
		constexpr bool empty() const noexcept { return this->size() == 0; }

		constexpr size_type size() const noexcept { return this->size_; }

	private:
		// Member variables
		pointer   data_; // 0
		size_type size_; // 8
	};
	static_assert(sizeof(BSStaticArray<void*>) == 0x10);

	// CommonLibSSE does not check whether the array is empty while iterating
	template <class T>
	class BSTSmallSharedArray
	{
	public:
		using size_type       = std::uint32_t;
		using value_type      = T;
		using pointer         = value_type*;
		using const_pointer   = const value_type*;
		using reference       = value_type&;
		using const_reference = const value_type&;
		using iterator        = pointer;
		using const_iterator  = const_pointer;

		// Iterators
		constexpr iterator       begin() noexcept { return this->empty() ? nullptr : this->data(); }
		constexpr const_iterator begin() const noexcept { return this->empty() ? nullptr : this->data(); }
		constexpr const_iterator cbegin() const noexcept { return this->begin(); }

		constexpr iterator       end() noexcept { return this->empty() ? nullptr : this->data() + this->size(); }
		constexpr const_iterator end() const noexcept { return this->empty() ? nullptr : this->data() + this->size(); }
		constexpr const_iterator cend() const noexcept { return this->end(); }

		// Element access
		constexpr reference       operator[](size_type index) noexcept { return this->data()[index]; }
		constexpr const_reference operator[](size_type index) const noexcept { return this->data()[index]; }

		constexpr pointer       data() noexcept { return this->size() > 1 ? this->data_.heap : std::addressof(this->data_.local); }
		constexpr const_pointer data() const noexcept { return this->size() > 1 ? this->data_.heap : std::addressof(this->data_.local); }

		// Capacity
		constexpr bool empty() const noexcept { return this->size() == 0; }

		constexpr size_type size() const noexcept { return this->size_; }

	private:
		// Member variables
		size_type size_; // 0
		union
		{
		public:
			// Member variables
			pointer    heap;
			value_type local;
		} data_; // 8
	};
	static_assert(sizeof(BSTSmallSharedArray<void*>) == 0x10);
}
