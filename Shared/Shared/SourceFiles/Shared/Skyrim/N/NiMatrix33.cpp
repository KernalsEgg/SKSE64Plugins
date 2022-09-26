#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiMatrix33.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	void NiMatrix33::EulerAnglesToRotationMatrixXYZ(float x, float y, float z)
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&NiMatrix33::EulerAnglesToRotationMatrixXYZ)>::type>(Addresses::NiMatrix33::EulerAnglesToRotationMatrixXYZ) };

		function(this, x, y, z);
	}

	void NiMatrix33::EulerAnglesToRotationMatrixZXY(float z, float x, float y)
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&NiMatrix33::EulerAnglesToRotationMatrixZXY)>::type>(Addresses::NiMatrix33::EulerAnglesToRotationMatrixZXY) };

		function(this, z, x, y);
	}

	bool NiMatrix33::RotationMatrixToEulerAnglesXYZ(float& x, float& y, float& z) const
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&NiMatrix33::RotationMatrixToEulerAnglesXYZ)>::type>(Addresses::NiMatrix33::RotationMatrixToEulerAnglesXYZ) };

		return function(this, x, y, z);
	}

	bool NiMatrix33::RotationMatrixToEulerAnglesZXY(float& z, float& x, float& y) const
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&NiMatrix33::RotationMatrixToEulerAnglesZXY)>::type>(Addresses::NiMatrix33::RotationMatrixToEulerAnglesZXY) };

		return function(this, z, x, y);
	}
}
