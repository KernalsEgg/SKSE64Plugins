#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSCRC32.h"
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

		constexpr BSFixedString(BSFixedString&& right) noexcept :
			data_(right.data_)
		{
			right.data_ = nullptr;
		}

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

		~BSFixedString();

		BSFixedString& operator=(const BSFixedString& right);
		BSFixedString& operator=(BSFixedString&& right);

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

		// Element access
		constexpr const_reference operator[](size_type index) const noexcept { return this->data()[index]; }

		constexpr const_reference front() const noexcept { return this->operator[](0); }

		constexpr const_reference back() const noexcept { return this->operator[](this->size() - 1); }

		constexpr const_pointer data() const noexcept
		{
			const auto* proxy = this->GetProxy();

			if (proxy)
			{
				const auto* data = proxy->data();

				if (data)
				{
					return data;
				}
			}

			return BSFixedString::EMPTY;
		}

		constexpr operator std::basic_string_view<value_type>() const { return { this->data(), this->size() }; }

		// Capacity
		constexpr bool empty() const noexcept { return this->size() == 0; }

		constexpr size_type size() const noexcept
		{
			const auto* proxy = this->GetProxy();

			return proxy ? proxy->size() : 0;
		}

		// Non-member functions
		friend constexpr bool operator==(const BSFixedString& left, const BSFixedString& right) noexcept { return left.data_ == right.data_; }
		friend constexpr bool operator!=(const BSFixedString& left, const BSFixedString& right) noexcept { return !(left == right); }

		friend bool operator==(const BSFixedString& left, const_pointer right)
		{
			if (!left.data_)
			{
				return !right;
			}

			return right ? ::_stricmp(left.data_, right) == 0 : false;
		}

		friend bool operator!=(const BSFixedString& left, const_pointer right) { return !(left == right); }
		friend bool operator==(const_pointer left, const BSFixedString& right) { return right == left; }
		friend bool operator!=(const_pointer left, const BSFixedString& right) { return !(left == right); }

		template <class T>
			requires(std::is_convertible_v<const T&, std::basic_string_view<value_type>> && !std::is_convertible_v<const T&, const_pointer>)
		friend bool operator==(const BSFixedString& left, const T& right)
		{
			return left == static_cast<std::basic_string_view<value_type>>(right).data();
		}

		template <class T>
			requires(std::is_convertible_v<const T&, std::basic_string_view<value_type>> && !std::is_convertible_v<const T&, const_pointer>)
		friend bool operator!=(const BSFixedString& left, const T& right)
		{
			return !(left == right);
		}

		template <class T>
			requires(std::is_convertible_v<const T&, std::basic_string_view<value_type>> && !std::is_convertible_v<const T&, const_pointer>)
		friend bool operator==(const T& left, const BSFixedString& right)
		{
			return right == left;
		}

		template <class T>
			requires(std::is_convertible_v<const T&, std::basic_string_view<value_type>> && !std::is_convertible_v<const T&, const_pointer>)
		friend bool operator!=(const T& left, const BSFixedString& right)
		{
			return !(left == right);
		}

	private:
		static constexpr value_type EMPTY[]{ 0 };

		void Acquire();

		constexpr BSStringPool::Entry* GetProxy() noexcept
		{
			return this->data_ ? reinterpret_cast<BSStringPool::Entry*>(const_cast<pointer>(this->data_)) - 1 : nullptr;
		}

		constexpr const BSStringPool::Entry* GetProxy() const noexcept
		{
			return this->data_ ? reinterpret_cast<const BSStringPool::Entry*>(this->data_) - 1 : nullptr;
		}

		// Member functions
		BSFixedString* Initialize(const_pointer string);
		void           Release();

		// Member variables
		const_pointer data_{ nullptr }; // 0
	};
	static_assert(sizeof(BSFixedString) == 0x8);

	namespace Implementation
	{
		template <>
		struct BSCRC32<BSFixedString>
		{
		public:
			inline std::uint32_t operator()(const BSFixedString& key) const noexcept
			{
				return BSCRC32<BSFixedString::const_pointer>()(key.data());
			}
		};
	}
}
