#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/N/NiColor.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSImpactDataSet;

	class BGSMaterialType :
		public TESForm // 0
	{
	public:
		enum class Flags : std::uint32_t
		{
			kNone          = 0,
			kStairMaterial = 1U << 0,
			kArrowsStick   = 1U << 1
		};
		static_assert(sizeof(Flags) == 0x4);

		// Override
		virtual ~BGSMaterialType() override; // 0

		// Override (TESForm)
		virtual void Unknown4(TESForm*) override;  // 4
		virtual void Unknown6(TESForm*) override;  // 6
		virtual void Unknown13(TESForm*) override; // 13

		// Non-member functions
		static BGSMaterialType* GetMaterialTypeFromMaterialID(std::uint32_t materialID);

		// Member variables
		BGSMaterialType*                           parentMaterial;     // 20
		BSFixedString                              materialName;       // 28
		std::uint32_t                              materialID;         // 30
		NiColor                                    havokDisplayColor;  // 34
		float                                      buoyancy;           // 40
		Utility::Enumeration<Flags, std::uint32_t> materialTypeFlags;  // 44
		BGSImpactDataSet*                          havokImpactDataSet; // 48
	};
	static_assert(offsetof(BGSMaterialType, parentMaterial) == 0x20);
	static_assert(offsetof(BGSMaterialType, materialName) == 0x28);
	static_assert(offsetof(BGSMaterialType, materialID) == 0x30);
	static_assert(offsetof(BGSMaterialType, havokDisplayColor) == 0x34);
	static_assert(offsetof(BGSMaterialType, buoyancy) == 0x40);
	static_assert(offsetof(BGSMaterialType, materialTypeFlags) == 0x44);
	static_assert(offsetof(BGSMaterialType, havokImpactDataSet) == 0x48);
	static_assert(sizeof(BGSMaterialType) == 0x50);
}
