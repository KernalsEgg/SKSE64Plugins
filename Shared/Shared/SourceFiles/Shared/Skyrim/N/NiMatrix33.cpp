#include "Shared/PCH.h"

#include "Shared/Skyrim/N/NiMatrix33.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	void NiMatrix33::EulerAnglesToRotationMatrix(float x, float y, float z)
	{
		auto function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&NiMatrix33::EulerAnglesToRotationMatrix)>::type>(Addresses::NiMatrix33::EulerAnglesToRotationMatrix) };

		function(this, x, y, z);
	}

	bool NiMatrix33::RotationMatrixToEulerAngles(float& x, float& y, float& z) const
	{
		auto function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&NiMatrix33::RotationMatrixToEulerAngles)>::type>(Addresses::NiMatrix33::RotationMatrixToEulerAngles) };

		return function(this, x, y, z);
	}
}
