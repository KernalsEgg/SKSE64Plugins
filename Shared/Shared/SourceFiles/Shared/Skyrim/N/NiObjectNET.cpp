#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiObjectNET.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	bool NiObjectNET::AddExtraData(NiExtraData* extraData)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&NiObjectNET::AddExtraData)>::type>(
			Addresses::NiObjectNET::AddExtraData()) };

		return function(this, extraData);
	}

	bool NiObjectNET::AddNamedExtraData(const BSFixedString& name, NiExtraData* extraData)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&NiObjectNET::AddNamedExtraData)>::type>(
			Addresses::NiObjectNET::AddNamedExtraData()) };

		return function(this, name, extraData);
	}

	void NiObjectNET::DeleteExtraDataAt(std::uint16_t index)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&NiObjectNET::DeleteExtraDataAt)>::type>(
			Addresses::NiObjectNET::DeleteExtraDataAt()) };

		function(this, index);
	}

	NiExtraData* NiObjectNET::GetExtraData(const BSFixedString& name) const
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&NiObjectNET::GetExtraData)>::type>(
			Addresses::NiObjectNET::GetExtraData()) };

		return function(this, name);
	}

	bool NiObjectNET::InsertExtraData(NiExtraData* extraData)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&NiObjectNET::InsertExtraData)>::type>(
			Addresses::NiObjectNET::InsertExtraData()) };

		return function(this, extraData);
	}

	void NiObjectNET::RemoveAllExtraData()
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&NiObjectNET::RemoveAllExtraData)>::type>(
			Addresses::NiObjectNET::RemoveAllExtraData()) };

		function(this);
	}

	bool NiObjectNET::RemoveExtraData(const BSFixedString& name)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&NiObjectNET::RemoveExtraData)>::type>(
			Addresses::NiObjectNET::RemoveExtraData()) };

		return function(this, name);
	}

	bool NiObjectNET::RemoveExtraDataAt(std::uint16_t index)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&NiObjectNET::RemoveExtraDataAt)>::type>(
			Addresses::NiObjectNET::RemoveExtraDataAt()) };

		return function(this, index);
	}
}
