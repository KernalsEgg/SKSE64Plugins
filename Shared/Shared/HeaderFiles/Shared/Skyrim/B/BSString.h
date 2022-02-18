#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	template <class T, std::uint32_t N>
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
	};

	template <class CharT, std::uint32_t N, template <class, std::uint32_t> class Allocator>
	class BSStringT
	{
	public:
		using value_type      = CharT;
		using traits_type     = std::char_traits<value_type>;
		using allocator_type  = Allocator<value_type, N>;
		using size_type       = std::uint16_t;
		using reference       = value_type&;
		using const_reference = const value_type&;
		using pointer         = value_type*;
		using const_pointer   = const value_type*;

	public:
		constexpr operator std::basic_string_view<value_type>() const noexcept { return { this->data(), this->size() }; }

		// Element access
		constexpr const_reference operator[](size_type index) const noexcept { return this->data()[index]; }

		constexpr const_pointer data() const noexcept { return this->data_ ? this->data_ : BSStringT::EMPTY; }

		constexpr const_reference front() const noexcept { return operator[](0); }

		constexpr const_reference back() const noexcept { return operator[](this->size() - 1); }

		// Capacity
		constexpr bool empty() const noexcept { return this->size() == 0; }

		constexpr size_type size() const noexcept { return this->size_ != BSStringT::MAXIMUM ? this->size_ : static_cast<size_type>(traits_type::length(this->data())); }

	private:
		static constexpr value_type EMPTY[]{ 0 };
		static constexpr auto       MAXIMUM = static_cast<size_type>(N);

		// Member variables
		pointer      data_;     // 0
		size_type    size_;     // 8
		size_type    capacity_; // A
		std::int32_t paddingC;  // C
	};

	using BSString = BSStringT<char, static_cast<std::uint32_t>(-1), DynamicMemoryManagementPol>;
	static_assert(sizeof(BSString) == 0x10);
}
