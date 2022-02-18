#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/N/NiColor.h"
#include "Shared/Skyrim/N/NiPoint3.h"
#include "Shared/Skyrim/N/NiPointer.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class NiProperty;

	class BSMaterialObject
	{
	public:
		enum class Flags : std::uint32_t
		{
			kNone = 0,
			kSnow = 1U << 0
		};
		static_assert(sizeof(Flags) == 0x4);

		struct DirectionalMaterialData
		{
		public:
			// Member variables
			float                                      falloffScale;                // 0
			float                                      falloffBias;                 // 4
			float                                      noiseUVScale;                // 8
			float                                      materialUVScale;             // C
			NiPoint3                                   directionalProjectionVector; // 10
			float                                      normalDampner;               // 1C
			NiColor                                    singlePassColor;             // 20
			std::int32_t                               singlePass;                  // 2C
			Utility::Enumeration<Flags, std::uint32_t> materialObjectFlags;         // 30
			std::int32_t                               padding34;                   // 34
		};
		static_assert(offsetof(DirectionalMaterialData, falloffScale) == 0x0);
		static_assert(offsetof(DirectionalMaterialData, falloffBias) == 0x4);
		static_assert(offsetof(DirectionalMaterialData, noiseUVScale) == 0x8);
		static_assert(offsetof(DirectionalMaterialData, materialUVScale) == 0xC);
		static_assert(offsetof(DirectionalMaterialData, directionalProjectionVector) == 0x10);
		static_assert(offsetof(DirectionalMaterialData, normalDampner) == 0x1C);
		static_assert(offsetof(DirectionalMaterialData, singlePassColor) == 0x20);
		static_assert(offsetof(DirectionalMaterialData, singlePass) == 0x2C);
		static_assert(offsetof(DirectionalMaterialData, materialObjectFlags) == 0x30);
		static_assert(sizeof(DirectionalMaterialData) == 0x38);

		// Add
		virtual ~BSMaterialObject();              // 0
		virtual void Unknown1(BSMaterialObject*); // 1

		// Member variables
		DirectionalMaterialData         directionalMaterialData; // 8
		BSTArray<NiPointer<NiProperty>> properties;              // 40
	};
	static_assert(offsetof(BSMaterialObject, directionalMaterialData) == 0x8);
	static_assert(offsetof(BSMaterialObject, properties) == 0x40);
	static_assert(sizeof(BSMaterialObject) == 0x58);
}
