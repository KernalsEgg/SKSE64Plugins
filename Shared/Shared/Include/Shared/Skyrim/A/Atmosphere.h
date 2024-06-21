#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiPointer.h"
#include "Shared/Skyrim/S/SkyObject.h"



namespace Skyrim
{
	class BSFogProperty;
	class BSTriShape;

	class Atmosphere :
		public SkyObject // 0
	{
	public:
		// Override
		virtual ~Atmosphere() override; // 0

		// Override (SkyObject)
		virtual void Unknown3(SkyObject*) override; // 3

		// Add
		virtual void Unknown4(Atmosphere*); // 4

		// Member variables
		NiPointer<BSTriShape>    atmosphere; // 10
		NiPointer<BSFogProperty> fog;        // 18
		std::uint64_t            unknown20;  // 20
		std::uint64_t            unknown28;  // 28
		std::uint64_t            unknown30;  // 30
	};
	static_assert(offsetof(Atmosphere, atmosphere) == 0x10);
	static_assert(offsetof(Atmosphere, fog) == 0x18);
	static_assert(sizeof(Atmosphere) == 0x38);
}
