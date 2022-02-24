#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BGSBipedObjectForm.h"
#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/S/Sex.h"
#include "Shared/Skyrim/T/TESModelTextureSwap.h"
#include "Shared/Skyrim/T/TESObject.h"
#include "Shared/Skyrim/T/TESRaceForm.h"
#include "Shared/Utility/Convert.h"



namespace Skyrim
{
	class BGSArtObject;
	class BGSFootstepSet;
	class BGSListForm;
	class BGSTextureSet;
	class TESRace;

	class TESObjectARMA :
		public TESObject,         // 0
		public TESRaceForm,       // 20
		public BGSBipedObjectForm // 30
	{
	public:
		// Override
		virtual ~TESObjectARMA() override; // 0

		// Override (TESObject)
		virtual void Unknown4(TESForm*) override;  // 4
		virtual void Unknown5(TESForm*) override;  // 5
		virtual void Unknown6(TESForm*) override;  // 6
		virtual void Unknown13(TESForm*) override; // 13

		// Member variables
		std::uint8_t        priorities[Utility::ToUnderlying(Sex::kTotal)];             // 40
		bool                weightSlider[Utility::ToUnderlying(Sex::kTotal)];           // 42
		std::uint8_t        unused[Utility::ToUnderlying(Sex::kTotal)];                 // 44
		std::uint8_t        detectionSoundValue;                                        // 46
		std::uint8_t        padding47;                                                  // 47
		float               weaponAdjust;                                               // 48
		std::uint32_t       padding4C;                                                  // 4C
		TESModelTextureSwap bipedModels[Utility::ToUnderlying(Sex::kTotal)];            // 50
		TESModelTextureSwap firstPersonBipedModels[Utility::ToUnderlying(Sex::kTotal)]; // C0
		BGSTextureSet*      skinTextures[Utility::ToUnderlying(Sex::kTotal)];           // 130
		BGSListForm*        skinTextureSwapLists[Utility::ToUnderlying(Sex::kTotal)];   // 140
		BSTArray<TESRace*>  additionalRaces;                                            // 150
		BGSFootstepSet*     footstep;                                                   // 168
		BGSArtObject*       artObject;                                                  // 170
	};
	static_assert(offsetof(TESObjectARMA, priorities) == 0x40);
	static_assert(offsetof(TESObjectARMA, weightSlider) == 0x42);
	static_assert(offsetof(TESObjectARMA, detectionSoundValue) == 0x46);
	static_assert(offsetof(TESObjectARMA, weaponAdjust) == 0x48);
	static_assert(offsetof(TESObjectARMA, bipedModels) == 0x50);
	static_assert(offsetof(TESObjectARMA, firstPersonBipedModels) == 0xC0);
	static_assert(offsetof(TESObjectARMA, skinTextures) == 0x130);
	static_assert(offsetof(TESObjectARMA, skinTextureSwapLists) == 0x140);
	static_assert(offsetof(TESObjectARMA, additionalRaces) == 0x150);
	static_assert(offsetof(TESObjectARMA, footstep) == 0x168);
	static_assert(offsetof(TESObjectARMA, artObject) == 0x170);
	static_assert(sizeof(TESObjectARMA) == 0x178);
}
