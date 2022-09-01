#pragma once

#include "Shared/PCH.h"



namespace Skyrim
{
	template <class T, class Underlying>
	class hkEnumeration
	{
	public:
		using enumeration_type = T;
		using underlying_type  = Underlying;

		constexpr hkEnumeration() noexcept
		{
		}

		constexpr hkEnumeration(enumeration_type enumeration) noexcept :
			storage_(static_cast<underlying_type>(enumeration))
		{
		}

		constexpr operator enumeration_type() const noexcept
		{
			return static_cast<enumeration_type>(this->storage_);
		}

		constexpr void operator=(enumeration_type enumeration) noexcept
		{
			this->storage_ = static_cast<underlying_type>(enumeration);
		}

		friend constexpr bool operator==(hkEnumeration left, enumeration_type right) noexcept
		{
			return left.storage_ == static_cast<underlying_type>(right);
		}

		friend constexpr bool operator!=(hkEnumeration left, enumeration_type right) noexcept
		{
			return !(left == right);
		}

	private:
		// Member variables
		underlying_type storage_;
	};
}
