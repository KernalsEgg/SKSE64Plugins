#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/T/TESForm.h"



namespace Skyrim
{
	class TESWeather;
	class TESWorldSpace;

	class TESRegion :
		public TESForm // 0
	{
	public:
		// Override
		virtual ~TESRegion() override; // 0

		// Override (TESForm)
		virtual void ClearData() override;         // 5
		virtual void Unknown6(TESForm*) override;  // 6
		virtual void Unknown13(TESForm*) override; // 13

		// Add
		virtual void Unknown3B(TESRegion*); // 3B

		// Member variables
		std::uint64_t  unknown20;      // 20
		std::uint64_t  unknown28;      // 28
		TESWorldSpace* worldSpace;     // 30
		TESWeather*    currentWeather; // 38
		std::uint64_t  unknown40;      // 40
		std::uint64_t  unknown48;      // 48
	};
	static_assert(offsetof(TESRegion, worldSpace) == 0x30);
	static_assert(offsetof(TESRegion, currentWeather) == 0x38);
	static_assert(sizeof(TESRegion) == 0x50);
}
