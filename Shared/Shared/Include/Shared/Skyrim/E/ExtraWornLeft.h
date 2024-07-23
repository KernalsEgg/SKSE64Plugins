#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSExtraData.h"



namespace Skyrim
{
	class ExtraWornLeft :
		public BSExtraData // 0
	{
	public:
		// Override
		virtual ~ExtraWornLeft() override; // 0

		// Override (BSExtraData)
		virtual ExtraDataType GetExtraDataType() const override; // 1
	};
	static_assert(sizeof(ExtraWornLeft) == 0x10);
}
