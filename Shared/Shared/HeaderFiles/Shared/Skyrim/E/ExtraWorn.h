#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSExtraData.h"



namespace Skyrim
{
	class ExtraWorn :
		public BSExtraData // 0
	{
	public:
		// Override
		virtual ~ExtraWorn() override; // 0

		// Override (BSExtraData)
		virtual ExtraDataType GetType() const override; // 1
	};
	static_assert(sizeof(ExtraWorn) == 0x10);
}
