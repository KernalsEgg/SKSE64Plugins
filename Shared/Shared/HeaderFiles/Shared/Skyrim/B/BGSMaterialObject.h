#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSMaterialObject.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Skyrim/T/TESModel.h"



namespace Skyrim
{
	class BGSMaterialObject :
		public TESForm,         // 0
		public TESModel,        // 20
		public BSMaterialObject // 48
	{
	public:
		// Override
		virtual ~BGSMaterialObject() override; // 0

		// Override (TESForm)
		virtual void Unknown5(TESForm*) override; // 5
		virtual void Unknown6(TESForm*) override; // 6

		// Override (BSMaterialObject)
		virtual void Unknown1(BSMaterialObject*) override; // 1

		// Member variables
		std::uint64_t unknownA0; // A0
		std::uint64_t unknownA8; // A8
		std::uint64_t unknownB0; // B0
	};
	static_assert(sizeof(BGSMaterialObject) == 0xB8);
}
