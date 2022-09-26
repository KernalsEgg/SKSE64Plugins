#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BaseFormComponent.h"



namespace Skyrim
{
	class TESAttackDamageForm :
		public BaseFormComponent // 0
	{
	public:
		// Override
		virtual ~TESAttackDamageForm() override; // 0

		// Override (BaseFormComponent)
		virtual void Unknown1(BaseFormComponent*) override; // 1
		virtual void Unknown2(BaseFormComponent*) override; // 2
		virtual void Unknown3(BaseFormComponent*) override; // 3

		// Add
		virtual std::uint16_t GetAttackDamage() const; // 4

		// Member variables
		std::uint16_t attackDamage; // 8
		std::uint16_t paddingA;     // A
		std::uint32_t paddingC;     // C
	};
	static_assert(offsetof(TESAttackDamageForm, attackDamage) == 0x8);
	static_assert(sizeof(TESAttackDamageForm) == 0x10);
}
