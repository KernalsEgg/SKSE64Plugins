#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/M/MemoryManager.h"
#include "Shared/Skyrim/S/ScrapHeap.h"



// Based on std::vector
namespace Skyrim
{
	class BSTArrayBase
	{
	public:
		using size_type = std::uint32_t;

		constexpr BSTArrayBase() noexcept                    = default;
		constexpr BSTArrayBase(const BSTArrayBase&) noexcept = default;

		constexpr BSTArrayBase(BSTArrayBase&& right) noexcept :
			size_(right.size())
		{
			right.size_ = 0;
		}

		constexpr ~BSTArrayBase() noexcept
		{
			this->size_ = 0;
		}

		constexpr BSTArrayBase& operator=(const BSTArrayBase&) noexcept = default;

		constexpr BSTArrayBase& operator=(BSTArrayBase&& right) noexcept
		{
			if (this != std::addressof(right))
			{
				this->size_ = right.size();

				right.size_ = 0;
			}

			return *this;
		}

		constexpr bool empty() const noexcept { return this->size() == 0; }

		constexpr size_type size() const noexcept { return this->size_; }

	protected:
		constexpr void set_size(size_type size) noexcept
		{
			this->size_ = size;
		}

	private:
		// Member variables
		size_type size_{ 0 }; // 0
	};
	static_assert(sizeof(BSTArrayBase) == 0x4);

	/* CommonLibSSE incorrectly implements the allocator classes by not considering the size of the type when calling Skyrim::malloc, std::memcpy, std::memmove, and std::memset */
	template <class T>
	class BSTArrayHeapAllocator
	{
	public:
		using size_type     = std::uint32_t;
		using value_type    = T;
		using pointer       = value_type*;
		using const_pointer = const value_type*;

		SKYRIM_MEMORY_REDEFINE_NEW();

		constexpr BSTArrayHeapAllocator() noexcept = default;

		BSTArrayHeapAllocator(const BSTArrayHeapAllocator& right) :
			capacity_(right.capacity())
		{
			if (this->capacity() > 0)
			{
				this->data_ = this->allocate(this->capacity());

				std::memcpy(this->data(), right.data(), sizeof(value_type) * this->capacity());
			}
		}

		constexpr BSTArrayHeapAllocator(BSTArrayHeapAllocator&& right) noexcept :
			data_(right.data()),
			capacity_(right.capacity())
		{
			right.data_     = nullptr;
			right.capacity_ = 0;
		}

		~BSTArrayHeapAllocator()
		{
			this->deallocate(this->data());

			this->data_     = nullptr;
			this->capacity_ = 0;
		}

		BSTArrayHeapAllocator& operator=(const BSTArrayHeapAllocator& right)
		{
			if (this != std::addressof(right))
			{
				this->deallocate(this->data());

				this->data_     = nullptr;
				this->capacity_ = right.capacity();

				if (this->capacity() > 0)
				{
					this->data_ = this->allocate(this->capacity());

					std::memcpy(this->data(), right.data(), sizeof(value_type) * this->capacity());
				}
			}

			return *this;
		}

		BSTArrayHeapAllocator& operator=(BSTArrayHeapAllocator&& right)
		{
			if (this != std::addressof(right))
			{
				this->deallocate(this->data());

				this->data_     = right.data();
				this->capacity_ = right.capacity();

				right.data_     = nullptr;
				right.capacity_ = 0;
			}

			return *this;
		}

		constexpr pointer       data() noexcept { return this->data_; }
		constexpr const_pointer data() const noexcept { return this->data_; }

		constexpr size_type capacity() const noexcept { return this->capacity_; }

	protected:
		pointer allocate(size_type count)
		{
			auto* data = static_cast<pointer>(Skyrim::malloc(sizeof(value_type) * count));

			if (!data)
			{
				throw std::bad_alloc{};
			}

			std::memset(data, 0, sizeof(value_type) * count);

			return data;
		}

		void deallocate(pointer data)
		{
			Skyrim::free(data);
		}

		constexpr void set_allocator_traits(pointer data, size_type capacity) noexcept
		{
			this->data_     = data;
			this->capacity_ = capacity;
		}

	private:
		// Member variables
		pointer   data_{ nullptr }; // 0
		size_type capacity_{ 0 };   // 8
	};
	static_assert(sizeof(BSTArrayHeapAllocator<void*>) == 0x10);

	/* CommonLibSSE incorrectly implements move, release, and setting allocator traits */
	template <class T, std::uint32_t COUNT>
	class BSTSmallArrayHeapAllocator
	{
	public:
		using size_type     = std::uint32_t;
		using value_type    = T;
		using pointer       = value_type*;
		using const_pointer = const value_type*;

		SKYRIM_MEMORY_REDEFINE_NEW();

		constexpr BSTSmallArrayHeapAllocator() noexcept = default;

		BSTSmallArrayHeapAllocator(const BSTSmallArrayHeapAllocator& right)
		{
			this->copy(right);
		}

		BSTSmallArrayHeapAllocator(BSTSmallArrayHeapAllocator&& right)
		{
			this->move(std::move(right));
		}

		~BSTSmallArrayHeapAllocator()
		{
			this->release();
		}

		BSTSmallArrayHeapAllocator& operator=(const BSTSmallArrayHeapAllocator& right)
		{
			if (this != std::addressof(right))
			{
				this->release();
				this->copy(right);
			}

			return *this;
		}

		BSTSmallArrayHeapAllocator& operator=(BSTSmallArrayHeapAllocator&& right)
		{
			if (this != std::addressof(right))
			{
				this->release();
				this->move(std::move(right));
			}

			return *this;
		}

		constexpr pointer       data() noexcept { return this->local() ? this->data_.local : this->data_.heap; }
		constexpr const_pointer data() const noexcept { return this->local() ? this->data_.local : this->data_.heap; }

		constexpr size_type capacity() const noexcept { return this->capacity_; }

	protected:
		pointer allocate(size_type count)
		{
			if (count > COUNT)
			{
				auto* data = static_cast<pointer>(Skyrim::malloc(sizeof(value_type) * count));

				if (!data)
				{
					throw std::bad_alloc{};
				}

				std::memset(data, 0, sizeof(value_type) * count);

				return data;
			}
			else
			{
				return this->data_.local;
			}
		}

		void deallocate(pointer data)
		{
			if (data != this->data_.local)
			{
				Skyrim::free(data);
			}
		}

		constexpr void set_allocator_traits(pointer data, size_type capacity) noexcept
		{
			this->capacity_ = capacity;

			if (data != this->data_.local)
			{
				this->local_     = 0;
				this->data_.heap = data;
			}
			else
			{
				this->local_ = 1;
			}
		}

	private:
		void copy(const BSTSmallArrayHeapAllocator& right)
		{
			this->capacity_ = right.capacity_;
			this->local_    = right.local_;

			if (!this->local())
			{
				auto* data = static_cast<pointer>(Skyrim::malloc(sizeof(value_type) * this->capacity()));

				if (!data)
				{
					throw std::bad_alloc{};
				}

				this->data_.heap = data;
			}

			std::memcpy(this->data(), right.data(), sizeof(value_type) * this->capacity());
		}

		constexpr bool local() const noexcept
		{
			return this->local_ != 0;
		}

		void move(BSTSmallArrayHeapAllocator&& right)
		{
			this->capacity_ = right.capacity_;
			this->local_    = right.local_;

			if (!this->local())
			{
				this->data_.heap = right.data_.heap;
			}
			else
			{
				std::memmove(this->data(), right.data(), sizeof(value_type) * this->capacity());
			}

			right.capacity_ = COUNT;
			right.local_    = 1;

			std::memset(right.data(), 0, sizeof(value_type) * right.capacity());
		}

		void release()
		{
			if (!this->local())
			{
				Skyrim::free(this->data_.heap);
			}

			this->capacity_ = COUNT;
			this->local_    = 1;

			std::memset(this->data(), 0, sizeof(value_type) * this->capacity());
		}

		// Member variables
		size_type capacity_ : 31 { 0 }; // 0
		size_type local_    : 1 { 1 };  // 0
		union
		{
		public:
			// Member variables
			pointer    heap;
			value_type local[COUNT]{ 0 };
		} data_{}; // 8
	};
	static_assert(sizeof(BSTSmallArrayHeapAllocator<void*, 1>) == 0x10);

	template <class T>
	class BSScrapArrayAllocator
	{
	public:
		using size_type     = std::uint32_t;
		using value_type    = T;
		using pointer       = value_type*;
		using const_pointer = const value_type*;

		SKYRIM_MEMORY_REDEFINE_NEW();

		constexpr BSScrapArrayAllocator() noexcept = default;

		BSScrapArrayAllocator(const BSScrapArrayAllocator& right) :
			capacity_(right.capacity_)
		{
			if (this->capacity() > 0)
			{
				this->data_ = this->allocate(this->capacity());

				std::memcpy(this->data(), right.data(), sizeof(value_type) * this->capacity());
			}
		}

		constexpr BSScrapArrayAllocator(BSScrapArrayAllocator&& right) noexcept :
			allocator_(right.allocator_),
			data_(right.data_),
			capacity_(right.capacity_)
		{
			right.allocator_ = nullptr;
			right.data_      = nullptr;
			right.capacity_  = 0;
		}

		~BSScrapArrayAllocator()
		{
			if (this->data())
			{
				this->deallocate(this->data());
			}

			this->allocator_ = nullptr;
			this->data_      = nullptr;
			this->capacity_  = 0;
		}

		BSScrapArrayAllocator& operator=(const BSScrapArrayAllocator& right)
		{
			if (this != std::addressof(right))
			{
				if (this->data())
				{
					this->deallocate(this->data());

					this->data_ = nullptr;
				}

				this->capacity_ = right.capacity();

				if (this->capacity() > 0)
				{
					this->data_ = this->allocate(this->capacity());

					std::memcpy(this->data(), right.data(), sizeof(value_type) * this->capacity());
				}
			}

			return *this;
		}

		BSScrapArrayAllocator& operator=(BSScrapArrayAllocator&& right)
		{
			if (this != std::addressof(right))
			{
				if (this->data())
				{
					this->deallocate(this->data());
				}

				this->allocator_ = right.allocator_;
				this->data_      = right.data_;
				this->capacity_  = right.capacity_;

				right.allocator_ = nullptr;
				right.data_      = nullptr;
				right.capacity_  = 0;
			}

			return *this;
		}

		constexpr pointer       data() noexcept { return this->data_; }
		constexpr const_pointer data() const noexcept { return this->data_; }

		constexpr size_type capacity() const noexcept { return this->capacity_; }

	protected:
		pointer allocate(size_type count)
		{
			if (!this->allocator_)
			{
				auto* memoryManager = MemoryManager::GetSingleton();
				this->allocator_    = memoryManager ? memoryManager->GetThreadScrapHeap() : nullptr;
			}

			auto* data = static_cast<pointer>(this->allocator_->Allocate(sizeof(value_type) * count, alignof(pointer)));

			if (!data)
			{
				throw std::bad_alloc{};
			}

			std::memset(data, 0, sizeof(value_type) * count);

			return data;
		}

		void deallocate(pointer data)
		{
			if (this->allocator_)
			{
				this->allocator_->Deallocate(data);
			}
		}

		constexpr void set_allocator_traits(pointer data, size_type capacity) noexcept
		{
			this->data_     = data;
			this->capacity_ = capacity;
		}

	private:
		// Member variables
		ScrapHeap* allocator_{ nullptr }; // 0
		pointer    data_{ nullptr };      // 8
		size_type  capacity_{ 0 };        // 10
	};
	static_assert(sizeof(BSScrapArrayAllocator<void*>) == 0x18);

	/* CommonLibSSE incorrectly implements the move constructor */
	template <class T, class Allocator = BSTArrayHeapAllocator<T>>
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

		SKYRIM_MEMORY_REDEFINE_NEW();

		BSTArray() = default;

		BSTArray(const BSTArray& right)
		{
			auto newCapacity = right.capacity();

			if (newCapacity > 0)
			{
				auto  newSize = right.size();
				auto* newData = this->allocate(newCapacity);

				for (size_type index = 0; index < newSize; ++index)
				{
					std::construct_at(newData + index, right[index]);
				}

				this->set_allocator_traits(newData, newCapacity);
				this->set_size(newSize);
			}
		}

		BSTArray(BSTArray&&) = default;

		~BSTArray()
		{
			this->release();
		}

		BSTArray& operator=(const BSTArray& right)
		{
			if (this != std::addressof(right))
			{
				this->clear();

				auto newCapacity = right.capacity();
				this->change_capacity(newCapacity);

				auto newSize = right.size();
				this->set_size(newSize);

				auto* newData = this->data();

				for (size_type index = 0; index < newSize; ++index)
				{
					std::construct_at(newData + index, right[index]);
				}
			}

			return *this;
		}

		BSTArray& operator=(BSTArray&&) = default;

		explicit BSTArray(size_type count)
		{
			if (count > 0)
			{
				auto  newCapacity = count;
				auto  newSize     = count;
				auto* newData     = this->allocate(newCapacity);

				for (size_type index = 0; index < newSize; ++index)
				{
					std::construct_at(newData + index);
				}

				this->set_allocator_traits(newData, newCapacity);
				this->set_size(newSize);
			}
		}

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

		constexpr pointer       data() noexcept { return allocator_type::data(); }
		constexpr const_pointer data() const noexcept { return allocator_type::data(); }

		constexpr reference       front() noexcept { return this->operator[](0); }
		constexpr const_reference front() const noexcept { return this->operator[](0); }

		constexpr reference       back() noexcept { return this->operator[](this->size() - 1); }
		constexpr const_reference back() const noexcept { return this->operator[](this->size() - 1); }

		// Capacity
		constexpr bool empty() const noexcept { return BSTArrayBase::empty(); }

		constexpr size_type size() const noexcept { return BSTArrayBase::size(); }

		void reserve(size_type newCapacity)
		{
			if (newCapacity > this->capacity())
			{
				this->change_capacity(newCapacity);
			}
		}

		constexpr size_type capacity() const noexcept { return allocator_type::capacity(); }

		void shrink_to_fit()
		{
			auto newCapacity = this->size();

			if (newCapacity != this->capacity())
			{
				this->change_capacity(newCapacity);
			}
		}

		// Modifiers
		void clear()
		{
			if (!this->empty())
			{
				this->change_size(0);
			}
		}

		iterator erase(const_iterator position)
		{
			auto* currentPosition = const_cast<iterator>(position);
			auto* result          = currentPosition;

			for (auto* previousPosition = currentPosition++; currentPosition != this->end(); previousPosition = currentPosition++)
			{
				*previousPosition = std::move(*currentPosition);
			}

			this->pop_back();

			return result;
		}

		void push_back(const value_type& value)
		{
			this->emplace_back(value);
		}

		void push_back(value_type&& value)
		{
			this->emplace_back(std::move(value));
		}

		template <class... Arguments>
		reference emplace_back(Arguments&&... arguments)
		{
			if (this->size() == this->capacity())
			{
				this->grow_capacity();
			}

			this->set_size(this->size() + 1);

			auto& back = this->back();

			std::construct_at(std::addressof(back), std::forward<Arguments>(arguments)...);

			return back;
		}

		void pop_back()
		{
			std::destroy_at(std::addressof(this->back()));

			this->set_size(this->size() - 1);
		}

		void resize(size_type count)
		{
			if (count != this->size())
			{
				this->change_size(count);
			}
		}

		void resize(size_type count, const value_type& value)
		{
			if (count != this->size())
			{
				this->change_size(count, value);
			}
		}

	private:
		static constexpr size_type DEFAULT_CAPACITY{ 4 };
		static constexpr size_type GROWTH_FACTOR{ 2 };

		pointer allocate(size_type count)
		{
			return allocator_type::allocate(count);
		}

		void deallocate(pointer data)
		{
			allocator_type::deallocate(data);
		}

		constexpr void set_allocator_traits(pointer data, size_type capacity) noexcept
		{
			allocator_type::set_allocator_traits(data, capacity);
		}

		constexpr void set_size(size_type size) noexcept
		{
			BSTArrayBase::set_size(size);
		}

		void change_capacity(size_type newCapacity)
		{
			auto* oldData = this->data();
			auto* newData = newCapacity > 0 ? this->allocate(newCapacity) : nullptr;

			if (oldData)
			{
				if (newData)
				{
					auto oldCapacity = this->capacity();
					auto size        = sizeof(value_type) * std::min(oldCapacity, newCapacity);

					std::memcpy(newData, oldData, size);
				}

				this->deallocate(oldData);
			}

			this->set_allocator_traits(newData, newCapacity);
		}

		template <class... Arguments>
		void change_size(size_type newSize, Arguments&&... arguments)
		{
			if (newSize > this->capacity())
			{
				this->grow_capacity(newSize);
			}

			auto oldSize = this->size();

			if (newSize > oldSize)
			{
				for (size_type index = oldSize; index < newSize; ++index)
				{
					std::construct_at(this->data() + index, std::forward<Arguments>(arguments)...);
				}
			}
			else
			{
				for (size_type index = newSize; index < oldSize; ++index)
				{
					std::destroy_at(this->data() + index);
				}
			}

			this->set_size(newSize);
		}

		void grow_capacity()
		{
			this->grow_capacity(this->capacity());
		}

		void grow_capacity(size_type hint)
		{
			auto capacity = hint > 0 ? BSTArray::GROWTH_FACTOR * hint : BSTArray::DEFAULT_CAPACITY;

			this->change_capacity(capacity);
		}

		void release()
		{
			this->clear();
			this->change_capacity(0);
		}
	};
	static_assert(sizeof(BSTArray<void*>) == 0x18);

	template <class T, std::uint32_t COUNT>
	using BSTSmallArray = BSTArray<T, BSTSmallArrayHeapAllocator<T, COUNT>>;
	static_assert(sizeof(BSTSmallArray<void*, 1>) == 0x18);

	template <class T>
	using BSScrapArray = BSTArray<T, BSScrapArrayAllocator<T>>;
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

		constexpr reference       front() noexcept { return this->operator[](0); }
		constexpr const_reference front() const noexcept { return this->operator[](0); }

		constexpr reference       back() noexcept { return this->operator[](this->size() - 1); }
		constexpr const_reference back() const noexcept { return this->operator[](this->size() - 1); }

		// Capacity
		constexpr bool empty() const noexcept { return this->size() == 0; }

		constexpr size_type size() const noexcept { return this->size_; }

	private:
		// Member variables
		pointer   data_; // 0
		size_type size_; // 8
	};
	static_assert(sizeof(BSStaticArray<void*>) == 0x10);

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
		constexpr iterator       begin() noexcept { return this->data(); }
		constexpr const_iterator begin() const noexcept { return this->data(); }
		constexpr const_iterator cbegin() const noexcept { return this->begin(); }

		constexpr iterator       end() noexcept { return this->data() + this->size(); }
		constexpr const_iterator end() const noexcept { return this->data() + this->size(); }
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
