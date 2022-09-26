#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Relocation
{
	template <class T>
	class Version
	{
	public:
		constexpr Version() noexcept               = default;
		constexpr Version(const Version&) noexcept = default;
		constexpr Version(Version&&) noexcept      = default;

		constexpr ~Version() noexcept = default;

		constexpr Version& operator=(const Version&) noexcept = default;
		constexpr Version& operator=(Version&&) noexcept      = default;

		explicit constexpr Version(T major, T minor, T revision, T build) :
			major(major), minor(minor), revision(revision), build(build)
		{
		}

		friend constexpr std::strong_ordering operator<=>(const Version& left, const Version& right) noexcept
		{
			if (left.major != right.major)
			{
				return left.major < right.major ? std::strong_ordering::less : std::strong_ordering::greater;
			}

			if (left.minor != right.minor)
			{
				return left.minor < right.minor ? std::strong_ordering::less : std::strong_ordering::greater;
			}

			if (left.revision != right.revision)
			{
				return left.revision < right.revision ? std::strong_ordering::less : std::strong_ordering::greater;
			}

			if (left.build != right.build)
			{
				return left.build < right.build ? std::strong_ordering::less : std::strong_ordering::greater;
			}

			return std::strong_ordering::equal;
		}

		friend constexpr bool operator==(const Version& left, const Version& right) noexcept
		{
			return operator<=>(left, right) == std::strong_ordering::equal;
		}

		T major{};
		T minor{};
		T revision{};
		T build{};
	};
}
