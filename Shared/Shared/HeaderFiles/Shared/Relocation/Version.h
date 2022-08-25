#pragma once

#include "Shared/PCH.h"



namespace Relocation
{
	struct Version
	{
	public:
		constexpr Version() noexcept               = default;
		constexpr Version(const Version&) noexcept = default;
		constexpr Version(Version&&) noexcept      = default;

		constexpr ~Version() noexcept = default;

		constexpr Version& operator=(const Version&) noexcept = default;
		constexpr Version& operator=(Version&&) noexcept = default;

		explicit constexpr Version(std::int32_t major, std::int32_t minor, std::int32_t revision, std::int32_t build) :
			major(major), minor(minor), revision(revision), build(build)
		{
		}

		std::int32_t major{};
		std::int32_t minor{};
		std::int32_t revision{};
		std::int32_t build{};
	};

	constexpr bool operator==(const Version& left, const Version& right) noexcept
	{
		return (left.major == right.major) &&
		       (left.minor == right.minor) &&
		       (left.revision == right.revision) &&
		       (left.build == right.build);
	}

	constexpr std::strong_ordering operator<=>(const Version& left, const Version& right) noexcept
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
}
