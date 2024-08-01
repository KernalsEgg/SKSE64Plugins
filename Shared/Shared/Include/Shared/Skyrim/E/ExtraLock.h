#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSExtraData.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class TESKey;

	enum class LockLevel : std::uint32_t
	{
		kUnlocked    = static_cast<std::underlying_type_t<LockLevel>>(-1),
		kNovice      = 0,
		kApprentice  = 1,
		kAdept       = 2,
		kExpert      = 3,
		kMaster      = 4,
		kRequiresKey = 5
	};
	static_assert(sizeof(LockLevel) == 0x4);

	struct ReferenceLock
	{
	public:
		enum class Flags : std::uint8_t
		{
			kNone                = 0,
			kLocked              = 1U << 0,
			kLockEffectArchetype = 1U << 1,
			kLeveled             = 1U << 2
		};
		static_assert(sizeof(Flags) == 0x1);

		// Member variables
		std::int8_t                               lockLevel;          // 0
		std::uint8_t                              padding1;           // 1
		std::uint16_t                             padding2;           // 2
		std::uint32_t                             padding4;           // 4
		TESKey*                                   key;                // 8
		Utility::Enumeration<Flags, std::uint8_t> referenceLockFlags; // 10
		std::uint8_t                              padding11;          // 11
		std::uint16_t                             padding12;          // 12
		std::uint32_t                             tries;              // 14
		std::uint32_t                             opens;              // 18
		std::uint32_t                             padding1C;          // 1C
	};
	static_assert(offsetof(ReferenceLock, lockLevel) == 0x0);
	static_assert(offsetof(ReferenceLock, key) == 0x8);
	static_assert(offsetof(ReferenceLock, referenceLockFlags) == 0x10);
	static_assert(offsetof(ReferenceLock, tries) == 0x14);
	static_assert(offsetof(ReferenceLock, opens) == 0x18);
	static_assert(sizeof(ReferenceLock) == 0x20);

	class ExtraLock :
		public BSExtraData // 0
	{
	public:
		// Override
		virtual ~ExtraLock() override; // 0

		// Override (BSExtraData)
		virtual ExtraDataType GetExtraDataType() const override;                   // 1
		virtual bool          IsNotEqual(const BSExtraData* right) const override; // 2

		// Member variables
		ReferenceLock* referenceLock; // 10
	};
	static_assert(sizeof(ExtraLock) == 0x18);
}
