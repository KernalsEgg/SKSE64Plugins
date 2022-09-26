#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Skyrim/E/ExtraDataList.h"



namespace BarterLimitFix
{
	class Events
	{
	public:
		static bool Register();

	private:
		using SetCount = void (*)(Skyrim::ExtraDataList* extraDataList, std::int16_t count);

		static void SetCount1(Skyrim::ExtraDataList* extraDataList, std::int32_t count);
		static void SetCount2(Skyrim::ExtraDataList* extraDataList, std::int32_t count);
		static void SetCount3(Skyrim::ExtraDataList* extraDataList, std::int32_t count);
		static void SetCount4(Skyrim::ExtraDataList* extraDataList, std::int32_t count);
		static void SetCount5(Skyrim::ExtraDataList* extraDataList, std::int32_t count);

		static SetCount setCount1_;
		static SetCount setCount2_;
		static SetCount setCount3_;
		static SetCount setCount4_;
		static SetCount setCount5_;
	};
}
