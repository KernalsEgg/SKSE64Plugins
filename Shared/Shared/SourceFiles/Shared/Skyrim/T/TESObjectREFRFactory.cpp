#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/T/TESObjectREFRFactory.h"

#include "Shared/Skyrim/T/TESObjectREFR.h"



namespace Skyrim
{
	TESObjectREFRFactory* TESObjectREFRFactory::GetFormFactory()
	{
		return static_cast<TESObjectREFRFactory*>(IFormFactory::GetFormFactory(FormType::kReference));
	}

	TESObjectREFR* TESObjectREFRFactory::Create()
	{
		return static_cast<TESObjectREFR*>(this->CreateImplementation());
	}
}
