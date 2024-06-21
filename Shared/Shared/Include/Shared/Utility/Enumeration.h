#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Utility
{
	// Based on std::bitset
	template <class T, class Underlying = std::underlying_type_t<T>>
		requires(std::is_enum_v<T>)
	class Enumeration
	{
	public:
		using enumeration_type = T;
		using underlying_type  = Underlying;

		constexpr Enumeration() noexcept                   = default;
		constexpr Enumeration(const Enumeration&) noexcept = default;
		constexpr Enumeration(Enumeration&&) noexcept      = default;

		constexpr ~Enumeration() noexcept = default;

		constexpr Enumeration& operator=(const Enumeration&) noexcept = default;
		constexpr Enumeration& operator=(Enumeration&&) noexcept      = default;

		template <class... Arguments>
			requires(std::same_as<Arguments, enumeration_type> && ...)
		constexpr Enumeration(Arguments... arguments) noexcept :
			enumeration_((static_cast<underlying_type>(arguments) | ...))
		{
		}

		constexpr Enumeration(underlying_type enumeration) noexcept :
			enumeration_(enumeration)
		{
		}

		constexpr Enumeration& operator=(enumeration_type enumeration) noexcept
		{
			this->enumeration_ = static_cast<underlying_type>(enumeration);

			return *this;
		}

		constexpr Enumeration& operator=(underlying_type enumeration) noexcept
		{
			this->enumeration_ = enumeration;

			return *this;
		}

		friend constexpr bool operator==(Enumeration left, Enumeration right) noexcept { return left.underlying() == right.underlying(); }
		friend constexpr bool operator==(Enumeration left, enumeration_type right) noexcept { return left.underlying() == static_cast<underlying_type>(right); }
		friend constexpr bool operator==(enumeration_type left, Enumeration right) noexcept { return static_cast<underlying_type>(left) == right.underlying(); }
		friend constexpr bool operator==(Enumeration left, underlying_type right) noexcept { return left.underlying() == right; }
		friend constexpr bool operator==(underlying_type left, Enumeration right) noexcept { return left == right.underlying(); }

		friend constexpr bool operator!=(Enumeration left, Enumeration right) noexcept { return !(left == right); }
		friend constexpr bool operator!=(Enumeration left, enumeration_type right) noexcept { return !(left == right); }
		friend constexpr bool operator!=(enumeration_type left, Enumeration right) noexcept { return !(left == right); }
		friend constexpr bool operator!=(Enumeration left, underlying_type right) noexcept { return !(left == right); }
		friend constexpr bool operator!=(underlying_type left, Enumeration right) noexcept { return !(left == right); }

		friend constexpr Enumeration operator&(Enumeration left, Enumeration right) noexcept { return left.underlying() & right.underlying(); }
		friend constexpr Enumeration operator&(Enumeration left, enumeration_type right) noexcept { return left.underlying() & static_cast<underlying_type>(right); }
		friend constexpr Enumeration operator&(enumeration_type left, Enumeration right) noexcept { return static_cast<underlying_type>(left) & right.underlying(); }
		friend constexpr Enumeration operator&(Enumeration left, underlying_type right) noexcept { return left.underlying() & right; }
		friend constexpr Enumeration operator&(underlying_type left, Enumeration right) noexcept { return left & right.underlying(); }

		friend constexpr Enumeration& operator&=(Enumeration& left, Enumeration right) noexcept { return left = left & right; }
		friend constexpr Enumeration& operator&=(Enumeration& left, enumeration_type right) noexcept { return left = left & right; }
		friend constexpr Enumeration& operator&=(Enumeration& left, underlying_type right) noexcept { return left = left & right; }

		friend constexpr Enumeration operator|(Enumeration left, Enumeration right) noexcept { return left.underlying() | right.underlying(); }
		friend constexpr Enumeration operator|(Enumeration left, enumeration_type right) noexcept { return left.underlying() | static_cast<underlying_type>(right); }
		friend constexpr Enumeration operator|(enumeration_type left, Enumeration right) noexcept { return static_cast<underlying_type>(left) | right.underlying(); }
		friend constexpr Enumeration operator|(Enumeration left, underlying_type right) noexcept { return left.underlying() | right; }
		friend constexpr Enumeration operator|(underlying_type left, Enumeration right) noexcept { return left | right.underlying(); }

		friend constexpr Enumeration& operator|=(Enumeration& left, Enumeration right) noexcept { return left = left | right; }
		friend constexpr Enumeration& operator|=(Enumeration& left, enumeration_type right) noexcept { return left = left | right; }
		friend constexpr Enumeration& operator|=(Enumeration& left, underlying_type right) noexcept { return left = left | right; }

		friend constexpr Enumeration operator^(Enumeration left, Enumeration right) noexcept { return left.underlying() ^ right.underlying(); }
		friend constexpr Enumeration operator^(Enumeration left, enumeration_type right) noexcept { return left.underlying() ^ static_cast<underlying_type>(right); }
		friend constexpr Enumeration operator^(enumeration_type left, Enumeration right) noexcept { return static_cast<underlying_type>(left) ^ right.underlying(); }
		friend constexpr Enumeration operator^(Enumeration left, underlying_type right) noexcept { return left.underlying() ^ right; }
		friend constexpr Enumeration operator^(underlying_type left, Enumeration right) noexcept { return left ^ right.underlying(); }

		friend constexpr Enumeration& operator^=(Enumeration& left, Enumeration right) noexcept { return left = left ^ right; }
		friend constexpr Enumeration& operator^=(Enumeration& left, enumeration_type right) noexcept { return left = left ^ right; }
		friend constexpr Enumeration& operator^=(Enumeration& left, underlying_type right) noexcept { return left = left ^ right; }

		friend constexpr Enumeration& operator~(Enumeration& left) noexcept { return left = ~left.underlying(); }

		friend constexpr Enumeration operator<<(Enumeration left, std::size_t right) noexcept { return left.underlying() << right; }
		friend constexpr Enumeration operator>>(Enumeration left, std::size_t right) noexcept { return left.underlying() >> right; }

		friend constexpr Enumeration& operator<<=(Enumeration& left, std::size_t right) noexcept { return left = left << right; }
		friend constexpr Enumeration& operator>>=(Enumeration& left, std::size_t right) noexcept { return left = left >> right; }

		explicit constexpr operator bool() const noexcept { return this->enumeration_ != static_cast<underlying_type>(0); }

		constexpr underlying_type*       data() noexcept { return std::addressof(this->enumeration_); }
		constexpr const underlying_type* data() const noexcept { return std::addressof(this->enumeration_); }

		constexpr enumeration_type get() const noexcept { return static_cast<enumeration_type>(this->enumeration_); }
		constexpr underlying_type  underlying() const noexcept { return this->enumeration_; }

		template <class... Arguments>
			requires(std::same_as<Arguments, enumeration_type> && ...)
		constexpr bool all(Arguments... arguments) const noexcept
		{
			return (this->enumeration_ & (static_cast<underlying_type>(arguments) | ...)) == (static_cast<underlying_type>(arguments) | ...);
		}

		template <class... Arguments>
			requires(std::same_as<Arguments, enumeration_type> && ...)
		constexpr bool any(Arguments... arguments) const noexcept
		{
			return (this->enumeration_ & (static_cast<underlying_type>(arguments) | ...)) != static_cast<underlying_type>(0);
		}

		template <class... Arguments>
			requires(std::same_as<Arguments, enumeration_type> && ...)
		constexpr bool none(Arguments... arguments) const noexcept
		{
			return (this->enumeration_ & (static_cast<underlying_type>(arguments) | ...)) == static_cast<underlying_type>(0);
		}

		template <class... Arguments>
			requires(std::same_as<Arguments, enumeration_type> && ...)
		constexpr Enumeration& reset(Arguments... arguments) noexcept
		{
			this->enumeration_ &= ~(static_cast<underlying_type>(arguments) | ...);

			return *this;
		}

		template <class... Arguments>
			requires(std::same_as<Arguments, enumeration_type> && ...)
		constexpr Enumeration& set(Arguments... arguments) noexcept
		{
			this->enumeration_ |= (static_cast<underlying_type>(arguments) | ...);

			return *this;
		}

	private:
		underlying_type enumeration_{};
	};
}
