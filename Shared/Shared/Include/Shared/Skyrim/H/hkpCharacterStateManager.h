#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/H/hkpCharacterStateType.h"
#include "Shared/Skyrim/H/hkReferencedObject.h"
#include "Shared/Utility/Conversion.h"



namespace Skyrim
{
	class hkpCharacterState;

	class hkpCharacterStateManager :
		public hkReferencedObject // 0
	{
	public:
		// Override
		virtual ~hkpCharacterStateManager() override; // 0

		// Member variables
		hkpCharacterState* registeredCharacterStates[Utility::Conversion::ToUnderlying(hkpCharacterStateType::kTotal)]; // 10
	};
	static_assert(offsetof(hkpCharacterStateManager, registeredCharacterStates) == 0x10);
	static_assert(sizeof(hkpCharacterStateManager) == 0x68);
}
