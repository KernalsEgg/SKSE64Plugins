#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSBipedObjectForm.h"
#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/S/Sex.h"
#include "Shared/Skyrim/T/TESModelTextureSwap.h"
#include "Shared/Skyrim/T/TESObject.h"
#include "Shared/Skyrim/T/TESRaceForm.h"
#include "Shared/Utility/Conversion.h"



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
		virtual void InitializeData() override;    // 4
		virtual void ClearData() override;         // 5
		virtual bool Load(TESFile* file) override; // 6
		virtual void Unknown13(TESForm*) override; // 13

		// Member variables
		std::uint8_t        priorities[Utility::Conversion::ToUnderlying(Sex::kTotal)];                        // 40
		bool                weightSlider[Utility::Conversion::ToUnderlying(Sex::kTotal)];                      // 42
		std::uint8_t        unused[Utility::Conversion::ToUnderlying(Sex::kTotal)];                            // 44
		std::uint8_t        detectionSoundValue;                                                               // 46
		std::uint8_t        padding47;                                                                         // 47
		float               weaponAdjust;                                                                      // 48
		std::uint32_t       padding4C;                                                                         // 4C
		TESModelTextureSwap bipedModelTextureSwaps[Utility::Conversion::ToUnderlying(Sex::kTotal)];            // 50
		TESModelTextureSwap firstPersonBipedModelTextureSwaps[Utility::Conversion::ToUnderlying(Sex::kTotal)]; // C0
		BGSTextureSet*      skinTextureSets[Utility::Conversion::ToUnderlying(Sex::kTotal)];                   // 130
		BGSListForm*        skinTextureSetSwapLists[Utility::Conversion::ToUnderlying(Sex::kTotal)];           // 140
		BSTArray<TESRace*>  additionalRaces;                                                                   // 150
		BGSFootstepSet*     footstepSet;                                                                       // 168
		BGSArtObject*       artObject;                                                                         // 170
	};
	static_assert(offsetof(TESObjectARMA, priorities) == 0x40);
	static_assert(offsetof(TESObjectARMA, weightSlider) == 0x42);
	static_assert(offsetof(TESObjectARMA, detectionSoundValue) == 0x46);
	static_assert(offsetof(TESObjectARMA, weaponAdjust) == 0x48);
	static_assert(offsetof(TESObjectARMA, bipedModelTextureSwaps) == 0x50);
	static_assert(offsetof(TESObjectARMA, firstPersonBipedModelTextureSwaps) == 0xC0);
	static_assert(offsetof(TESObjectARMA, skinTextureSets) == 0x130);
	static_assert(offsetof(TESObjectARMA, skinTextureSetSwapLists) == 0x140);
	static_assert(offsetof(TESObjectARMA, additionalRaces) == 0x150);
	static_assert(offsetof(TESObjectARMA, footstepSet) == 0x168);
	static_assert(offsetof(TESObjectARMA, artObject) == 0x170);
	static_assert(sizeof(TESObjectARMA) == 0x178);
}
