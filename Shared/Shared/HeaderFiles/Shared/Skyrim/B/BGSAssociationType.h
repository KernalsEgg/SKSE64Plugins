#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/AssociationType.h"
#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/S/Sex.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Utility/Conversion.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BGSAssociationType :
		public TESForm // 0
	{
	public:
		enum class Flags : std::uint32_t
		{
			kNone              = 0,
			kFamilyAssociation = 1U << 0
		};
		static_assert(sizeof(Flags) == 0x4);

		// Override
		virtual ~BGSAssociationType() override; // 0

		// Override (TESForm)
		virtual void InitializeData() override;    // 4
		virtual bool Load(TESFile* file) override; // 6

		// Member variables
		BSFixedString                              associationTypeLabels[Utility::Conversion::ToUnderlying(AssociationType::kTotal)][Utility::Conversion::ToUnderlying(Sex::kTotal)]; // 20
		Utility::Enumeration<Flags, std::uint32_t> associationTypeFlags;                                                                                                              // 40
		std::uint32_t                              padding44;                                                                                                                         // 44
	};
	static_assert(offsetof(BGSAssociationType, associationTypeLabels) == 0x20);
	static_assert(offsetof(BGSAssociationType, associationTypeFlags) == 0x40);
	static_assert(sizeof(BGSAssociationType) == 0x48);
}
