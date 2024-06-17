#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/M/ModelReferenceEffect.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	void ModelReferenceEffect::SwitchFirstThirdPerson()
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&ModelReferenceEffect::SwitchFirstThirdPerson)>::type>(
			Addresses::ModelReferenceEffect::SwitchFirstThirdPerson()) };

		function(this);
	}
}
