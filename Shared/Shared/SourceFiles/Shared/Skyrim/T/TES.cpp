#include "Shared/PCH.h"

#include "Shared/Skyrim/T/TES.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	TES* TES::GetSingleton()
	{
		auto singleton{ reinterpret_cast<TES**>(Addresses::TES::Singleton) };

		return *singleton;
	}

	TESObjectCELL* TES::GetCell(const NiPoint3& position) const
	{
		auto function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&TES::GetCell)>::type>(Addresses::TES::GetCell) };

		return function(this, position);
	}

	std::uint32_t TES::GetMaterialID(const NiPoint3& position) const
	{
		auto function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&TES::GetMaterialID)>::type>(Addresses::TES::GetMaterialID) };

		return function(this, position);
	}
}
