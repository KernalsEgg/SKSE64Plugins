#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/A/Attribute.h"
#include "Shared/Skyrim/S/Skill.h"
#include "Shared/Skyrim/T/TESDescription.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Skyrim/T/TESFullName.h"
#include "Shared/Skyrim/T/TESTexture.h"
#include "Shared/Utility/Convert.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class TESClass :
		public TESForm,        // 0
		public TESFullName,    // 20
		public TESDescription, // 30
		public TESTexture      // 40
	{
	public:
		// Override
		virtual ~TESClass() override; // 0

		// Override (TESForm)
		virtual void Unknown4(TESForm*) override;  // 4
		virtual void Unknown6(TESForm*) override;  // 6
		virtual void UnknownE(TESForm*) override;  // E
		virtual void UnknownF(TESForm*) override;  // F
		virtual void Unknown12(TESForm*) override; // 12

		// Member variables
		std::uint32_t                             unknown50;                                                  // 50
		Utility::Enumeration<Skill, std::uint8_t> trainingSkill;                                              // 54
		std::uint8_t                              trainingValue;                                              // 55
		std::uint8_t                              skillWeights[Utility::ToUnderlying(Skill::kTotal)];         // 56
		float                                     bleedoutDefault;                                            // 68
		std::uint32_t                             voicePoints;                                                // 6C
		std::uint8_t                              attributeWeights[Utility::ToUnderlying(Attribute::kTotal)]; // 70
		std::uint8_t                              padding73;                                                  // 73
		std::uint32_t                             padding74;                                                  // 74
	};
	static_assert(offsetof(TESClass, trainingSkill) == 0x54);
	static_assert(offsetof(TESClass, trainingValue) == 0x55);
	static_assert(offsetof(TESClass, skillWeights) == 0x56);
	static_assert(offsetof(TESClass, bleedoutDefault) == 0x68);
	static_assert(offsetof(TESClass, voicePoints) == 0x6C);
	static_assert(offsetof(TESClass, attributeWeights) == 0x70);
	static_assert(sizeof(TESClass) == 0x78);
}
