#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	class NiPoint3
	{
	public:
		constexpr NiPoint3() noexcept                = default;
		constexpr NiPoint3(const NiPoint3&) noexcept = default;
		constexpr NiPoint3(NiPoint3&&) noexcept      = default;

		constexpr ~NiPoint3() noexcept = default;

		constexpr NiPoint3& operator=(const NiPoint3&) noexcept = default;
		constexpr NiPoint3& operator=(NiPoint3&&) noexcept      = default;

		constexpr NiPoint3(float x, float y, float z) noexcept :
			x(x), y(y), z(z)
		{
		}

		constexpr NiPoint3& operator+=(const NiPoint3& right) noexcept
		{
			this->x += right.x;
			this->y += right.y;
			this->z += right.z;

			return *this;
		}

		constexpr NiPoint3& operator+=(float right) noexcept
		{
			this->x += right;
			this->y += right;
			this->z += right;

			return *this;
		}

		constexpr NiPoint3& operator-=(const NiPoint3& right) noexcept
		{
			this->x -= right.x;
			this->y -= right.y;
			this->z -= right.z;

			return *this;
		}

		constexpr NiPoint3& operator-=(float right) noexcept
		{
			this->x -= right;
			this->y -= right;
			this->z -= right;

			return *this;
		}

		constexpr NiPoint3& operator*=(float right) noexcept
		{
			this->x *= right;
			this->y *= right;
			this->z *= right;

			return *this;
		}

		constexpr NiPoint3& operator/=(float right) noexcept
		{
			this->x /= right;
			this->y /= right;
			this->z /= right;

			return *this;
		}

		// Member functions
		float Magnitude() const;
		void  Normalize();

		// Member variables
		float x{ 0.0F }; // 0
		float y{ 0.0F }; // 4
		float z{ 0.0F }; // 8
	};
	static_assert(offsetof(NiPoint3, x) == 0x0);
	static_assert(offsetof(NiPoint3, y) == 0x4);
	static_assert(offsetof(NiPoint3, z) == 0x8);
	static_assert(sizeof(NiPoint3) == 0xC);

	constexpr bool operator==(const NiPoint3& left, const NiPoint3& right) noexcept { return (left.x == right.x) && (left.y == right.y) && (left.z == right.z); }
	constexpr bool operator!=(const NiPoint3& left, const NiPoint3& right) noexcept { return !(left == right); }

	constexpr NiPoint3 operator-(const NiPoint3& left) noexcept { return NiPoint3(-left.x, -left.y, -left.z); }

	constexpr NiPoint3 operator+(const NiPoint3& left, const NiPoint3& right) noexcept { return NiPoint3(left.x + right.x, left.y + right.y, left.z + right.z); }
	constexpr NiPoint3 operator+(const NiPoint3& left, float right) noexcept { return NiPoint3(left.x + right, left.y + right, left.z + right); }
	constexpr NiPoint3 operator+(float left, const NiPoint3& right) noexcept { return NiPoint3(left + right.x, left + right.y, left + right.z); }

	constexpr NiPoint3 operator-(const NiPoint3& left, const NiPoint3& right) noexcept { return NiPoint3(left.x - right.x, left.y - right.y, left.z - right.z); }
	constexpr NiPoint3 operator-(const NiPoint3& left, float right) noexcept { return NiPoint3(left.x - right, left.y - right, left.z - right); }
	constexpr NiPoint3 operator-(float left, const NiPoint3& right) noexcept { return NiPoint3(left - right.x, left - right.y, left - right.z); }

	constexpr float    operator*(const NiPoint3& left, const NiPoint3& right) noexcept { return left.x * right.x + left.y * right.y + left.z * right.z; }
	constexpr NiPoint3 operator*(const NiPoint3& left, float right) noexcept { return NiPoint3(left.x * right, left.y * right, left.z * right); }
	constexpr NiPoint3 operator*(float left, const NiPoint3& right) noexcept { return NiPoint3(left * right.x, left * right.y, left * right.z); }

	constexpr NiPoint3 operator/(const NiPoint3& left, float right) noexcept { return NiPoint3(left.x / right, left.y / right, left.z / right); }
	constexpr NiPoint3 operator/(float left, const NiPoint3& right) noexcept { return NiPoint3(left / right.x, left / right.y, left / right.z); }
}
