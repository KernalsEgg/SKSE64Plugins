#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/T/TES.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	TES* TES::GetSingleton()
	{
		auto** singleton{ reinterpret_cast<TES**>(Addresses::TES::Singleton()) };

		return *singleton;
	}

	TESObjectCELL* TES::GetCell(const NiPoint3& position) const
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&TES::GetCell)>::type>(
			Addresses::TES::GetCell()) };

		return function(this, position);
	}

	bool TES::GetLandColor(const NiPoint3& position, NiColorA& landColor) const
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&TES::GetLandColor)>::type>(
			Addresses::TES::GetLandColor()) };

		return function(this, position, landColor);
	}

	std::uint32_t TES::GetMaterialID(const NiPoint3& position) const
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&TES::GetMaterialID)>::type>(
			Addresses::TES::GetMaterialID()) };

		return function(this, position);
	}
}
