#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/I/IFormFactory.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	IFormFactory* IFormFactory::GetFormFactory(Utility::Enumeration<FormType, std::uint8_t> formType)
	{
		auto* function{ reinterpret_cast<decltype(IFormFactory::GetFormFactory)*>(Addresses::IFormFactory::GetFormFactory) };

		return function(formType);
	}

	TESForm* IFormFactory::Create()
	{
		return this->CreateImplementation();
	}
}
