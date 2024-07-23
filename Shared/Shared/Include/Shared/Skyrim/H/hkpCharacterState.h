#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/H/hkpCharacterStateType.h"
#include "Shared/Skyrim/H/hkReferencedObject.h"



namespace Skyrim
{
	class hkpCharacterState :
		public hkReferencedObject // 0
	{
	public:
		// Override
		virtual ~hkpCharacterState() override; // 0

		// Add
		virtual hkpCharacterStateType GetCharacterStateType() const = 0; // 3
		virtual void                  Unknown4(hkpCharacterState*);      // 4
		virtual void                  Unknown5(hkpCharacterState*);      // 5
		virtual void                  Unknown6(hkpCharacterState*) = 0;  // 6
		virtual void                  Unknown7(hkpCharacterState*) = 0;  // 7
	};
	static_assert(sizeof(hkpCharacterState) == 0x10);
}
