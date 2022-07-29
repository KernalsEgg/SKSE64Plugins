#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSExtraData.h"



namespace Skyrim
{
	class ExtraHealth :
		public BSExtraData // 0
	{
	public:
		// Override
		virtual ~ExtraHealth() override; // 0

		// Override (BSExtraData)
		virtual ExtraDataType GetType() const override;                            // 1
		virtual bool          IsNotEqual(const BSExtraData* right) const override; // 2

		// Member variables
		float         health;    // 10
		std::uint32_t padding14; // 14
	};
	static_assert(offsetof(ExtraHealth, health) == 0x10);
	static_assert(sizeof(ExtraHealth) == 0x18);
}
