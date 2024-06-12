#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSSoundHandle.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	bool BSSoundHandle::Play()
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&BSSoundHandle::Play)>::type>(
			Addresses::BSSoundHandle::Play()) };

		return function(this);
	}
}
