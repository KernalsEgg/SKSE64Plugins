#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/I/IFormFactory.h"



namespace Skyrim
{
	class TESObjectREFR;

	class TESObjectREFRFactory :
		public IFormFactory // 0
	{
	public:
		// Override
		virtual ~TESObjectREFRFactory() override; // 0

	protected:
		// Override (IFormFactory)
		TESForm* CreateImplementation() override; // 1

	public:
		// Override (IFormFactory)
		const char* GetFormName() const override; // 2
		FormType    GetFormType() const override; // 3

		// Non-member functions
		static TESObjectREFRFactory* GetFormFactory();

		// Member functions
		TESObjectREFR* Create();
	};
	static_assert(sizeof(TESObjectREFRFactory) == 0x8);
}
