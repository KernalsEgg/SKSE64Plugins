#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiPoint3.h"



namespace Skyrim
{
	class NiMatrix33
	{
	public:
		// Member functions
		void EulerAnglesToRotationMatrixXYZ(float x, float y, float z);
		void EulerAnglesToRotationMatrixZXY(float z, float x, float y);
		bool RotationMatrixToEulerAnglesXYZ(float& x, float& y, float& z) const;
		bool RotationMatrixToEulerAnglesZXY(float& z, float& x, float& y) const;

		// Member variables
		float elements[3][3]; // 0
	};
	static_assert(offsetof(NiMatrix33, elements) == 0x0);
	static_assert(sizeof(NiMatrix33) == 0x24);

	constexpr NiPoint3 operator*(const NiMatrix33& left, const NiPoint3& right) noexcept
	{
		return NiPoint3(
			(left.elements[0][0] * right.x) + (left.elements[0][1] * right.y) + (left.elements[0][2] * right.z),
			(left.elements[1][0] * right.x) + (left.elements[1][1] * right.y) + (left.elements[1][2] * right.z),
			(left.elements[2][0] * right.x) + (left.elements[2][1] * right.y) + (left.elements[2][2] * right.z));
	}
}
