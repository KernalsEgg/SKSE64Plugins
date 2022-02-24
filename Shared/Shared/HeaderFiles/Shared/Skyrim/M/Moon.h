#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSString.h"
#include "Shared/Skyrim/N/NiPointer.h"
#include "Shared/Skyrim/S/SkyObject.h"
#include "Shared/Utility/Convert.h"



namespace Skyrim
{
	class BSTriShape;
	class NiNode;

	class Moon :
		public SkyObject // 0
	{
	public:
		enum class Phase
		{
			kFullMoon       = 0,
			kWaningGibbous  = 1,
			kThirdQuarter   = 2,
			kWaningCrescent = 3,
			kNewMoon        = 4,
			kWaxingCrescent = 5,
			kFirstQuarter   = 6,
			kWaxingGibbous  = 7,
			kTotal          = 8
		};

		// Override
		virtual ~Moon() override; // 0

		// Override (SkyObject)
		virtual void Unknown2(SkyObject*) override; // 2
		virtual void Unknown3(SkyObject*) override; // 3

		// Member variables
		NiPointer<NiNode>     moonNode;                                                // 10
		NiPointer<NiNode>     moonShadowNode;                                          // 18
		NiPointer<BSTriShape> moon;                                                    // 20
		NiPointer<BSTriShape> moonShadow;                                              // 28
		BSString              moonPhaseTextures[Utility::ToUnderlying(Phase::kTotal)]; // 30
		std::uint64_t         unknownB0;                                               // B0
		std::uint64_t         unknownB8;                                               // B8
		std::uint64_t         unknownC0;                                               // C0
		std::uint64_t         unknownC8;                                               // C8
		std::uint64_t         unknownD0;                                               // D0
	};
	static_assert(offsetof(Moon, moonNode) == 0x10);
	static_assert(offsetof(Moon, moonShadowNode) == 0x18);
	static_assert(offsetof(Moon, moon) == 0x20);
	static_assert(offsetof(Moon, moonShadow) == 0x28);
	static_assert(offsetof(Moon, moonPhaseTextures) == 0x30);
	static_assert(sizeof(Moon) == 0xD8);
}
