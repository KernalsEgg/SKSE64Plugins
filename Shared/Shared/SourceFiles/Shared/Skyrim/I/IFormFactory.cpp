#include "Shared/PCH.h"

#include "Shared/Skyrim/I/IFormFactory.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	IFormFactory* IFormFactory::GetFormFactoryFromFormType(FormType formType)
	{
		auto* function{ reinterpret_cast<decltype(&IFormFactory::GetFormFactoryFromFormType)>(Addresses::IFormFactory::GetFormFactoryFromFormType) };

		return function(formType);
	}

	TESForm* IFormFactory::Create()
	{
		return this->CreateImplementation();
	}
}
