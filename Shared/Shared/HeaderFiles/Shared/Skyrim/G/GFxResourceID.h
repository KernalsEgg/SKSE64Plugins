#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/S/ScaleformTypes.h"
#include "Shared/Utility/Convert.h"



namespace Skyrim
{
	class GFxResourceID
	{
	public:
		enum class IDTypeConstants : std::uint32_t
		{
			kIndexMask = 0x0000FFFF,
			kTypeMask  = 0x0FFF0000,

			kSWF            = 0,
			kStatic         = 1U << 16,
			kExport         = 1U << 17,
			kGenerationMask = kSWF | kStatic | kExport,

			kTypeShift = 18,

			kInvalidID = (1U << kTypeShift) | kSWF
		};
		static_assert(sizeof(IDTypeConstants) == 0x4);

		enum class IDType : std::uint32_t
		{
			kNone             = 0,
			kInternalConstant = (0U << Utility::ToUnderlying(IDTypeConstants::kTypeShift)) | Utility::ToUnderlying(IDTypeConstants::kStatic),
			kGradientImage    = (1U << Utility::ToUnderlying(IDTypeConstants::kTypeShift)) | Utility::ToUnderlying(IDTypeConstants::kStatic),
			kDynamicFontImage = (2U << Utility::ToUnderlying(IDTypeConstants::kTypeShift)) | Utility::ToUnderlying(IDTypeConstants::kStatic),
			kFontImage        = (1U << Utility::ToUnderlying(IDTypeConstants::kTypeShift)) | Utility::ToUnderlying(IDTypeConstants::kExport)
		};
		static_assert(sizeof(IDType) == 0x4);

		class HashOperation
		{
		public:
			UPInt operator()(const GFxResourceID& idReference);
		};
		static_assert(std::is_empty_v<HashOperation>);

		explicit GFxResourceID();
		GFxResourceID(const GFxResourceID& right);

		explicit GFxResourceID(std::uint32_t resourceID);

		GFxResourceID operator=(const GFxResourceID& right);

		bool operator==(const GFxResourceID& right) const;
		bool operator!=(const GFxResourceID& right) const;

		bool operator==(std::uint32_t idValue) const;
		bool operator!=(std::uint32_t idValue) const;

		GFxResourceID GenerateNextID();
		std::uint32_t GetIDIndex() const;
		IDType        GetIDType() const;
		std::uint32_t GetIDValue() const;

	private:
		// Member variables
		std::uint32_t id_; // 0
	};
	static_assert(sizeof(GFxResourceID) == 0x4);
}
