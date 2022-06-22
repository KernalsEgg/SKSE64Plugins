#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSSimpleList.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Skyrim/T/TESModel.h"
#include "Shared/Skyrim/T/TESTexture.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class TESGlobal;
	class TESWeather;

	class TESClimate :
		public TESForm // 0
	{
	public:
		enum class Moons : std::uint8_t
		{
			kNone    = 0,
			kMasser  = 1U << 6,
			kSecunda = 1U << 7,

			kPhaseLengthMask = 0x3F
		};
		static_assert(sizeof(Moons) == 0x1);

		struct WeatherType
		{
		public:
			// Member variables
			TESWeather*   weatherType; // 0
			std::uint32_t chance;      // 8
			std::uint32_t paddingC;    // C
			TESGlobal*    global;      // 10
		};
		static_assert(offsetof(WeatherType, weatherType) == 0x0);
		static_assert(offsetof(WeatherType, chance) == 0x8);
		static_assert(offsetof(WeatherType, global) == 0x10);
		static_assert(sizeof(WeatherType) == 0x18);

		// Override
		virtual ~TESClimate() override; // 0

		// Override (TESForm)
		virtual void InitializeData() override;   // 4
		virtual void Unknown6(TESForm*) override; // 6

		// Member variables
		TESModel                                  nightSky;     // 20
		BSSimpleList<WeatherType*>                weatherTypes; // 48
		TESTexture                                sun;          // 58
		TESTexture                                sunGlare;     // 68
		std::uint8_t                              sunriseBegin; // 78
		std::uint8_t                              sunriseEnd;   // 79
		std::uint8_t                              sunsetBegin;  // 7A
		std::uint8_t                              sunsetEnd;    // 7B
		std::uint8_t                              volatility;   // 7C
		Utility::Enumeration<Moons, std::uint8_t> moons;        // 7D
		std::uint8_t                              padding7E;    // 7E
		std::uint8_t                              padding7F;    // 7F
	};
	static_assert(offsetof(TESClimate, nightSky) == 0x20);
	static_assert(offsetof(TESClimate, weatherTypes) == 0x48);
	static_assert(offsetof(TESClimate, sun) == 0x58);
	static_assert(offsetof(TESClimate, sunGlare) == 0x68);
	static_assert(offsetof(TESClimate, sunriseBegin) == 0x78);
	static_assert(offsetof(TESClimate, sunriseEnd) == 0x79);
	static_assert(offsetof(TESClimate, sunsetBegin) == 0x7A);
	static_assert(offsetof(TESClimate, sunsetEnd) == 0x7B);
	static_assert(offsetof(TESClimate, volatility) == 0x7C);
	static_assert(offsetof(TESClimate, moons) == 0x7D);
	static_assert(sizeof(TESClimate) == 0x80);
}
