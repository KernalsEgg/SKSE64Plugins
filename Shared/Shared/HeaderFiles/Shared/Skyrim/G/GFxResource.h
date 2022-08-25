#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/G/GAtomic.h"
#include "Shared/Skyrim/G/GFxResourceKey.h"
#include "Shared/Skyrim/G/GNewOverrideBase.h"
#include "Shared/Skyrim/G/GStatistics.h"
#include "Shared/Utility/Convert.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class GFxResourceLibBase;
	class GFxResourceReport;
	class GFxResourceWeakLib;

	class GFxResource :
		public GNewOverrideBase<Utility::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory)> // 0
	{
	private:
		friend class GFxResourceWeakLib;

	public:
		enum class ResourceType : std::uint32_t
		{
			kCharacterDefinitionBit = 1U << 7,

			kNone = 0,
			kImage,
			kFont,

			kMovieDefinition,
			kSoundSample,

			kMovieDataDefinition = kCharacterDefinitionBit | 0,
			kButtonDefinition,
			kTextDefinition,
			kEditTextDefinition,
			kSpriteDefinition,
			kShapeDefinition,
			kVideoDefinition,

			kTypeCodeMask  = 0xFF00,
			kTypeCodeShift = 8
		};
		static_assert(sizeof(ResourceType) == 0x4);

		enum class ResourceUse : std::uint32_t
		{
			kNone         = 0,
			kBitmap       = 1,
			kGradient     = 2,
			kFontTexture  = 3,
			kSoundSample  = 4,
			kTypeCodeMask = 0xFF
		};
		static_assert(sizeof(ResourceUse) == 0x4);

		// Add
		virtual ~GFxResource() {}                               // 0
		virtual GFxResourceKey     GetKey();                    // 1
		virtual std::uint32_t      GetResourceTypeCode() const; // 2
		virtual GFxResourceReport* GetResourceReport();         // 3

		GFxResource();

		// Non-member functions
		static std::uint32_t MakeTypeCode(Utility::Enumeration<ResourceType, std::uint32_t> resourceType, Utility::Enumeration<ResourceUse, std::uint32_t> resourceUse = ResourceUse::kNone);

		// Member functions
		void         AddReference();
		bool         AddReferenceNotZero();
		std::int32_t GetReferenceCount() const;
		void         Release();

		void PinResource();
		void UnpinResource();

		void SetOwnerResourceLibrary(GFxResourceLibBase* library);

		ResourceType GetResourceType() const;
		ResourceUse  GetResourceUse() const;

	private:
		// Member variables
		GAtomicInteger<std::int32_t> referenceCount_; // 8
		std::uint32_t                paddingC_;       // C
		GFxResourceLibBase*          library_;        // 10
	};
	static_assert(sizeof(GFxResource) == 0x18);
}
