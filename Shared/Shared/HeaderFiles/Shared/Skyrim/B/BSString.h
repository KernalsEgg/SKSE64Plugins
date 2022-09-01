#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/M/MemoryManager.h"



namespace Skyrim
{
	template <class T, std::uint32_t Count>
	class DynamicMemoryManagementPol
	{
	public:
		using value_type = T;

		constexpr DynamicMemoryManagementPol() noexcept                                  = default;
		constexpr DynamicMemoryManagementPol(const DynamicMemoryManagementPol&) noexcept = default;
		constexpr DynamicMemoryManagementPol(DynamicMemoryManagementPol&&) noexcept      = default;

		constexpr ~DynamicMemoryManagementPol() noexcept = default;

		constexpr DynamicMemoryManagementPol& operator=(const DynamicMemoryManagementPol&) noexcept = default;
		constexpr DynamicMemoryManagementPol& operator=(DynamicMemoryManagementPol&&) noexcept = default;

		value_type* allocate(std::uint32_t count)
		{
			if (count > Count)
			{
				return nullptr;
			}

			auto  size    = sizeof(value_type) * count;
			auto* pointer = Skyrim::malloc<value_type>(size);

			std::memset(pointer, 0, size);

			return pointer;
		}

		void deallocate(value_type* pointer)
		{
			Skyrim::free(pointer);
		}
	};

	template <class T, std::uint32_t Count>
	class FixedLengthMemoryManagementPol
	{
	public:
		using value_type = T;

		constexpr FixedLengthMemoryManagementPol() noexcept = default;

		FixedLengthMemoryManagementPol(const FixedLengthMemoryManagementPol& right)
		{
			this->copy(right);
		}

		FixedLengthMemoryManagementPol(FixedLengthMemoryManagementPol&& right)
		{
			this->move(std::move(right));
		}

		~FixedLengthMemoryManagementPol() = default;

		FixedLengthMemoryManagementPol& operator=(const FixedLengthMemoryManagementPol& right)
		{
			if (this != std::addressof(right))
			{
				this->copy(right);
			}

			return *this;
		}

		FixedLengthMemoryManagementPol& operator=(FixedLengthMemoryManagementPol&& right)
		{
			if (this != std::addressof(right))
			{
				this->move(right);
			}

			return *this;
		}

		value_type* allocate(std::uint32_t count)
		{
			return count > Count ? nullptr : this->buffer_;
		}

		void deallocate(value_type* pointer)
		{
		}

	private:
		void copy(const FixedLengthMemoryManagementPol& right)
		{
			std::memcpy(this->buffer_, right.buffer_, sizeof(value_type) * Count);
		}

		void move(FixedLengthMemoryManagementPol&& right)
		{
			std::memmove(this->buffer_, right.buffer_, sizeof(value_type) * Count);
			std::memset(right.buffer_, 0, sizeof(value_type) * Count);
		}

		// Member variables
		value_type buffer_[Count]{ 0 }; // 0
	};

	template <class Character, std::uint32_t Count, template <class, std::uint32_t> class Allocator>
	class BSStringT
	{
	public:
		using value_type      = Character;
		using traits_type     = std::char_traits<value_type>;
		using allocator_type  = Allocator<value_type, Count>;
		using size_type       = std::uint16_t;
		using reference       = value_type&;
		using const_reference = const value_type&;
		using pointer         = value_type*;
		using const_pointer   = const value_type*;

		TES_MEMORY_REDEFINE_NEW();

		BSStringT()
		{
			this->clear();
		}

		BSStringT(const BSStringT& right) :
			allocator_type(right)
		{
			this->set_data(right.data());
		}

		BSStringT(BSStringT&& right) :
			allocator_type(std::move(right)),
			data_(right.data_),
			size_(right.size_),
			capacity_(right.capacity_)
		{
			right.data_     = nullptr;
			right.size_     = 0;
			right.capacity_ = 0;
		}

		~BSStringT()
		{
			this->deallocate(this->data_);

			this->data_     = nullptr;
			this->size_     = 0;
			this->capacity_ = 0;
		}

		BSStringT& operator=(const BSStringT& right)
		{
			if (this != std::addressof(right))
			{
				static_cast<allocator_type&>(*this) = right;

				this->set_data(right.data_);
			}

			return *this;
		}

		BSStringT& operator=(BSStringT&& right)
		{
			if (this != std::addressof(right))
			{
				static_cast<allocator_type&>(*this) = std::move(right);

				this->data_     = right.data_;
				this->size_     = right.size_;
				this->capacity_ = right.capacity_;

				right.data_     = nullptr;
				right.size_     = 0;
				right.capacity_ = 0;
			}

			return *this;
		}

		BSStringT(const_pointer right)
		{
			this->set_data(right);
		}

		BSStringT& operator=(const_pointer right)
		{
			this->set_data(right);

			return *this;
		}

		// Element access
		constexpr const_reference operator[](size_type index) const noexcept { return this->data()[index]; }

		constexpr const_reference front() const noexcept { return this->operator[](0); }

		constexpr const_reference back() const noexcept { return this->operator[](this->size() - 1); }

		constexpr const_pointer data() const noexcept { return this->data_ ? this->data_ : BSStringT::EMPTY; }

		constexpr operator std::basic_string_view<value_type>() const noexcept { return { this->data(), this->size() }; }

		// Capacity
		constexpr bool empty() const noexcept { return this->size() == 0; }

		constexpr size_type size() const noexcept { return this->size_ != BSStringT::MAXIMUM ? this->size_ : static_cast<size_type>(traits_type::length(this->data())); }

		// Operations
		void clear() { this->set_data(BSStringT::EMPTY); }

		// Non-member functions
		friend bool operator==(const BSStringT& left, const_pointer right) { return (left.data_ == right) || (BSStringT::compare(left.data_, right) == 0); }
		friend bool operator!=(const BSStringT& left, const_pointer right) { return !(left == right); }
		friend bool operator==(const_pointer left, const BSStringT& right) { return right == left; }
		friend bool operator!=(const_pointer left, const BSStringT& right) { return !(left == right); }
		friend bool operator==(const BSStringT& left, const BSStringT& right) { return left == right.data(); }
		friend bool operator!=(const BSStringT& left, const BSStringT& right) { return !(left == right); }

	private:
		static constexpr value_type EMPTY[]{ 0 };
		static constexpr size_type  MAXIMUM = static_cast<size_type>(Count);

		static int compare(const char* left, const char* right)
		{
			return _stricmp(left, right);
		}

		static int compare(const wchar_t* left, const wchar_t* right)
		{
			return _wcsicmp(left, right);
		}

		pointer allocate(std::uint32_t count)
		{
			return allocator_type::allocate(count);
		}

		void deallocate(pointer pointer)
		{
			allocator_type::deallocate(pointer);
		}

		bool set_data(const_pointer string, std::uint32_t length = 0)
		{
			if (this->data_ == string)
			{
				return true;
			}

			auto newLength = (length == 0) ? static_cast<size_type>(traits_type::length(string)) : static_cast<size_type>(length);
			auto newSize   = newLength > BSStringT::MAXIMUM ? BSStringT::MAXIMUM : newLength;

			++newLength;

			if (newLength <= this->capacity_)
			{
				traits_type::copy(this->data_, string, newLength);

				this->size_ = newSize;

				return true;
			}

			auto* newData = this->allocate(newLength);

			if (newData)
			{
				traits_type::copy(newData, string, newLength);

				if (this->data_)
				{
					this->deallocate(this->data_);
				}

				auto newCapacity = newLength > BSStringT::MAXIMUM ? BSStringT::MAXIMUM : newLength;

				this->data_     = newData;
				this->size_     = newSize;
				this->capacity_ = newCapacity;

				return true;
			}

			return false;
		}

		// Member variables
		pointer   data_{ nullptr }; // 0
		size_type size_{ 0 };       // 8
		size_type capacity_{ 0 };   // A
	};

	using BSString = BSStringT<char, static_cast<std::uint32_t>(-1), DynamicMemoryManagementPol>;
	static_assert(sizeof(BSString) == 0x10);
}
