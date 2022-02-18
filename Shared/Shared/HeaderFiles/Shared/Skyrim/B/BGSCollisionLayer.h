#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/C/Color.h"
#include "Shared/Skyrim/T/TESDescription.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSCollisionLayer :
		public TESForm,       // 0
		public TESDescription // 20
	{
	public:
		enum class Flags : std::uint32_t
		{
			kNone                   = 0,
			kTriggerVolume          = 1U << 0,
			kSensor                 = 1U << 1,
			kNavigationMeshObstacle = 1U << 2
		};
		static_assert(sizeof(Flags) == 0x4);

		// Override
		virtual ~BGSCollisionLayer() override; // 0

		// Override (TESForm)
		virtual void Unknown5(TESForm*) override;  // 5
		virtual void Unknown6(TESForm*) override;  // 6
		virtual void Unknown13(TESForm*) override; // 13
		virtual void Unknown23(TESForm*) override; // 23

		// Member variables
		std::uint32_t                              index;               // 30
		Color                                      debugColor;          // 34
		Utility::Enumeration<Flags, std::uint32_t> collisionLayerFlags; // 38
		std::int32_t                               padding3C;           // 3C
		BSFixedString                              name;                // 40
		BSTArray<BGSCollisionLayer*>               collidesWith;        // 48
	};
	static_assert(offsetof(BGSCollisionLayer, index) == 0x30);
	static_assert(offsetof(BGSCollisionLayer, debugColor) == 0x34);
	static_assert(offsetof(BGSCollisionLayer, collisionLayerFlags) == 0x38);
	static_assert(offsetof(BGSCollisionLayer, name) == 0x40);
	static_assert(offsetof(BGSCollisionLayer, collidesWith) == 0x48);
	static_assert(sizeof(BGSCollisionLayer) == 0x60);
}
