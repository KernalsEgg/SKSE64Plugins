#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	template <class Enum, class Underlying>
	class hkEnum
	{
	public:
		using enum_type       = Enum;
		using underlying_type = Underlying;

		constexpr hkEnum() noexcept
		{
		}

		constexpr hkEnum(enum_type enumeration) noexcept :
			storage(static_cast<underlying_type>(enumeration))
		{
		}

		constexpr operator enum_type() const noexcept
		{
			return static_cast<enum_type>(this->storage);
		}

		constexpr void operator=(enum_type enumeration) noexcept
		{
			this->storage = static_cast<underlying_type>(enumeration);
		}

		friend constexpr bool operator==(hkEnum left, enum_type right) noexcept
		{
			return left.storage == static_cast<underlying_type>(right);
		}

		friend constexpr bool operator!=(hkEnum left, enum_type right) noexcept
		{
			return !(left == right);
		}

	private:
		underlying_type storage;
	};
}
