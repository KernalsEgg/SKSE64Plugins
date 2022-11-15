#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSSaveGameBuffer.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	void BGSSaveGameBuffer::Write(const void* source, std::uint32_t length)
	{
		auto* function{ reinterpret_cast<Utility::TypeTraits::MakeFunctionPointer<decltype(&BGSSaveGameBuffer::Write)>::type>(Addresses::BGSSaveGameBuffer::Write) };

		function(this, source, length);
	}

	void BGSSaveGameBuffer::WriteFormID(TESForm* form)
	{
		auto* function{ reinterpret_cast<Utility::TypeTraits::MakeFunctionPointer<decltype(&BGSSaveGameBuffer::WriteFormID)>::type>(Addresses::BGSSaveGameBuffer::WriteFormID) };

		function(this, form);
	}
}
