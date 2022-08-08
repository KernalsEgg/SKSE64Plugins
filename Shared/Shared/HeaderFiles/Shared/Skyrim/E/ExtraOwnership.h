#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSExtraData.h"



namespace Skyrim
{
	class TESForm;

	class ExtraOwnership :
		public BSExtraData // 0
	{
	public:
		// Override
		virtual ~ExtraOwnership() override; // 0

		// Override (BSExtraData)
		virtual ExtraDataType GetType() const override;                            // 1
		virtual bool          IsNotEqual(const BSExtraData* right) const override; // 2

		// Member variables
		TESForm* owner; // 10
	};
	static_assert(offsetof(ExtraOwnership, owner) == 0x10);
	static_assert(sizeof(ExtraOwnership) == 0x18);
}
