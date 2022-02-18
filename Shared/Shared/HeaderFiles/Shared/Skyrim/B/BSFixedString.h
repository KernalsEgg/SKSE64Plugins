#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSStringPool.h"



namespace Skyrim
{
	class BSFixedString
	{
	public:
		using size_type       = std::uint32_t;
		using value_type      = char;
		using pointer         = value_type*;
		using const_pointer   = const value_type*;
		using reference       = value_type&;
		using const_reference = const value_type&;

		constexpr BSFixedString() noexcept = default;
		BSFixedString(const BSFixedString& right);
		constexpr BSFixedString(BSFixedString&&) noexcept = default;

		BSFixedString(const_pointer string);

		template <class T>
			requires(std::is_convertible_v<const T&, std::basic_string_view<value_type>> && !std::is_convertible_v<const T&, const_pointer>)
		BSFixedString(const T& string)
		{
			auto stringView = static_cast<std::basic_string_view<value_type>>(string);

			if (!stringView.empty())
			{
				this->Initialize(stringView.data());
			}
		}

		~BSFixedString() { this->Release(); }

		BSFixedString&           operator=(const BSFixedString& right);
		constexpr BSFixedString& operator=(BSFixedString&&) noexcept = default;

		BSFixedString& operator=(const_pointer string);

		template <class T>
			requires(std::is_convertible_v<const T&, std::basic_string_view<value_type>> && !std::is_convertible_v<const T&, const_pointer>)
		BSFixedString& operator=(const T& string)
		{
			auto stringView = static_cast<std::basic_string_view<value_type>>(string);
			this->Release();

			if (!stringView.empty())
			{
				this->Initialize(stringView.data());
			}

			return *this;
		}

		constexpr const_reference operator[](size_type index) const noexcept { return this->data()[index]; }

		constexpr const_reference front() const noexcept { return operator[](0); }

		constexpr const_reference back() const noexcept { return operator[](this->size() - 1); }

		constexpr const_pointer data() const noexcept
		{
			auto proxy = this->GetProxy();
			auto data  = proxy ? proxy->data() : nullptr;

			return data ? data : BSFixedString::EMPTY;
		}

		constexpr operator std::basic_string_view<value_type>() const { return { this->data(), this->size() }; }

		constexpr bool empty() const noexcept { return this->size() == 0; }

		constexpr size_type size() const noexcept
		{
			auto proxy = this->GetProxy();

			return proxy ? proxy->size() : 0;
		}

		friend constexpr bool operator==(const BSFixedString& left, const BSFixedString& right) noexcept { return left.data_ == right.data_ || left.empty() && right.empty(); }
		friend constexpr bool operator!=(const BSFixedString& left, const BSFixedString& right) noexcept { return !(left == right); }

	private:
		void Acquire();

		constexpr BSStringPool::Entry* GetProxy() noexcept
		{
			return this->data_ ? reinterpret_cast<BSStringPool::Entry*>(const_cast<pointer>(this->data_)) - 1 : nullptr;
		}

		constexpr const BSStringPool::Entry* GetProxy() const noexcept
		{
			return this->data_ ? reinterpret_cast<const BSStringPool::Entry*>(this->data_) - 1 : nullptr;
		}

		static constexpr value_type EMPTY[]{ 0 };

		// Member functions
		BSFixedString* Initialize(const_pointer string);
		void           Release() { BSStringPool::Entry::Release(this->data_); }

		// Member variables
		const_pointer data_{ nullptr }; // 0
	};
	static_assert(sizeof(BSFixedString) == 0x8);
}
