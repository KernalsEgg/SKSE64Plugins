#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSExtraData.h"



namespace Skyrim
{
	class TESForm;

	class ExtraLockList :
		public BSExtraData // 0
	{
	public:
		// Override
		virtual ~ExtraLockList() override; // 0

		// Override (BSExtraData)
		virtual ExtraDataType GetType() const override;                            // 1
		virtual bool          IsNotEqual(const BSExtraData* right) const override; // 2

		// Member variables
		TESForm* lockList; // 10
	};
	static_assert(offsetof(ExtraLockList, lockList) == 0x10);
	static_assert(sizeof(ExtraLockList) == 0x18);
}
