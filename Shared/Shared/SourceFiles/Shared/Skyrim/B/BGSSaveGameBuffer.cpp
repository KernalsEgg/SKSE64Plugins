#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSSaveGameBuffer.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	void BGSSaveGameBuffer::SaveData(const void* source, std::uint32_t length, std::uint32_t position)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&BGSSaveGameBuffer::SaveData)>::type>(
			Addresses::BGSSaveGameBuffer::SaveData()) };

		function(this, source, length, position);
	}

	void BGSSaveGameBuffer::SaveFormID(TESForm* form, std::uint32_t position)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&BGSSaveGameBuffer::SaveFormID)>::type>(
			Addresses::BGSSaveGameBuffer::SaveFormID()) };

		function(this, form, position);
	}
}
