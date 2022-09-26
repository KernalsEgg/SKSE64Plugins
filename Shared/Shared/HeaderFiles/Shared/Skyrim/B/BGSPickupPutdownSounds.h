#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BaseFormComponent.h"



namespace Skyrim
{
	class BGSSoundDescriptorForm;

	class BGSPickupPutdownSounds :
		public BaseFormComponent // 0
	{
	public:
		// Override
		virtual ~BGSPickupPutdownSounds() override; // 0

		// Override (BaseFormComponent)
		virtual void Unknown1(BaseFormComponent*) override; // 1
		virtual void Unknown2(BaseFormComponent*) override; // 2
		virtual void Unknown3(BaseFormComponent*) override; // 3

		// Member variables
		BGSSoundDescriptorForm* pickupSound;  // 8
		BGSSoundDescriptorForm* putdownSound; // 10
	};
	static_assert(offsetof(BGSPickupPutdownSounds, pickupSound) == 0x8);
	static_assert(offsetof(BGSPickupPutdownSounds, putdownSound) == 0x10);
	static_assert(sizeof(BGSPickupPutdownSounds) == 0x18);
}
