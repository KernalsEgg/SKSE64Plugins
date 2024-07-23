#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/H/hkpCharacterStateType.h"
#include "Shared/Skyrim/H/hkReferencedObject.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class hkpCharacterStateManager;

	class hkpCharacterContext :
		public hkReferencedObject // 0
	{
	public:
		enum class CharacterType : std::uint32_t
		{
			kProxy     = 0,
			kRigidBody = 1
		};
		static_assert(sizeof(CharacterType) == 0x4);

		// Override
		virtual ~hkpCharacterContext() override; // 0

		// Member variables
		Utility::Enumeration<CharacterType, std::uint32_t>         characterType;              // 10
		std::uint32_t                                              padding14;                  // 14
		const hkpCharacterStateManager*                            characterStateManager;      // 18
		Utility::Enumeration<hkpCharacterStateType, std::uint32_t> currentCharacterStateType;  // 20
		Utility::Enumeration<hkpCharacterStateType, std::uint32_t> previousCharacterStateType; // 24
		bool                                                       filterEnabled;              // 28
		std::uint8_t                                               padding29;                  // 29
		std::uint16_t                                              padding2A;                  // 2A
		float                                                      maximumLinearAcceleration;  // 2C
		float                                                      maximumLinearVelocity;      // 30
		float                                                      gain;                       // 34
	};
	static_assert(offsetof(hkpCharacterContext, characterType) == 0x10);
	static_assert(offsetof(hkpCharacterContext, characterStateManager) == 0x18);
	static_assert(offsetof(hkpCharacterContext, currentCharacterStateType) == 0x20);
	static_assert(offsetof(hkpCharacterContext, previousCharacterStateType) == 0x24);
	static_assert(offsetof(hkpCharacterContext, filterEnabled) == 0x28);
	static_assert(offsetof(hkpCharacterContext, maximumLinearAcceleration) == 0x2C);
	static_assert(offsetof(hkpCharacterContext, maximumLinearVelocity) == 0x30);
	static_assert(offsetof(hkpCharacterContext, gain) == 0x34);
	static_assert(sizeof(hkpCharacterContext) == 0x38);
}
