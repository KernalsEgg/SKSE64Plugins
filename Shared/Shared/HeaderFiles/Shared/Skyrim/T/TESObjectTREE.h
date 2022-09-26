#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/T/TESBoundObject.h"
#include "Shared/Skyrim/T/TESFullName.h"
#include "Shared/Skyrim/T/TESModel.h"
#include "Shared/Skyrim/T/TESProduceForm.h"



namespace Skyrim
{
	class TESObjectTREE :
		public TESBoundObject, // 0
		public TESModel,       // 30
		public TESFullName,    // 58
		public TESProduceForm  // 68
	{
	public:
		// Override
		virtual ~TESObjectTREE() override; // 0

		// Override (TESBoundObject)
		virtual void InitializeData() override;                                                                                                       // 4
		virtual bool Load(TESFile* file) override;                                                                                                    // 6
		virtual void Unknown13(TESForm*) override;                                                                                                    // 13
		virtual bool Activate(TESObjectREFR* target, TESObjectREFR* activator, bool deferred, TESBoundObject* item, std::int32_t itemCount) override; // 37
		virtual void Unknown44(TESObject*) override;                                                                                                  // 44
		virtual void Unknown4C(TESBoundObject*) override;                                                                                             // 4C
		virtual void Unknown4F(TESBoundObject*) override;                                                                                             // 4F
		virtual void Unknown50(TESBoundObject*) override;                                                                                             // 50
		virtual void Unknown51(TESBoundObject*) override;                                                                                             // 51
		virtual void Unknown52(TESBoundObject*) override;                                                                                             // 52

		// Member variables
		float         trunkFlexibility;  // 88
		float         branchFlexibility; // 8C
		std::uint64_t unknown90;         // 90
		std::uint64_t unknown98;         // 98
		std::uint64_t unknownA0;         // A0
		std::uint64_t unknownA8;         // A8
		float         leafAmplitude;     // B0
		float         leafFrequency;     // B4
		std::uint64_t unknownB8;         // B8
		std::uint64_t unknownC0;         // C0
	};
	static_assert(offsetof(TESObjectTREE, trunkFlexibility) == 0x88);
	static_assert(offsetof(TESObjectTREE, branchFlexibility) == 0x8C);
	static_assert(offsetof(TESObjectTREE, leafAmplitude) == 0xB0);
	static_assert(offsetof(TESObjectTREE, leafFrequency) == 0xB4);
	static_assert(sizeof(TESObjectTREE) == 0xC8);
}
