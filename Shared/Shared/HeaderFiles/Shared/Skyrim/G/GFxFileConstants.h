#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	class GFxFileConstants
	{
	public:
		enum class FileFormatType : std::uint32_t
		{
			kUnopened,
			kUnknown,

			kSWF,
			kGFX,

			kJPEG = 10,
			kPNG  = 11,
			kGIF  = 12,

			kTGA  = 13,
			kDDS  = 14,
			kHDR  = 15,
			kBMP  = 16,
			kDIB  = 17,
			kPFM  = 18,
			kTIFF = 19,

			kWAVE = 20,

			kNextAvailable,
			kOriginal = 65535
		};
		static_assert(sizeof(FileFormatType) == 0x4);
	};
	static_assert(std::is_empty_v<GFxFileConstants>);
}
