#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GArray.h"
#include "Shared/Skyrim/G/GColor.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class GImageBase
	{
	public:
		enum class ImageFormat : std::uint32_t
		{
			kNone     = 0,
			kARGB8888 = 1,
			kRGB888   = 2,
			kL8       = 8,
			kA8       = 9,
			kDXT1     = 10,
			kDXT3     = 11,
			kDXT5     = 12,

			kP8 = 100,

			kYUV822   = 200,
			kYUVA8228 = 201
		};
		static_assert(sizeof(ImageFormat) == 0x4);

		// Member variables
		Utility::Enumeration<ImageFormat, std::uint32_t> format;      // 0
		std::uint32_t                                    width;       // 4
		std::uint32_t                                    height;      // 8
		std::uint32_t                                    pitch;       // C
		std::uint8_t*                                    data;        // 10
		std::uint32_t                                    dataSize;    // 18
		std::uint32_t                                    mipMapCount; // 1C
		GArray<GColor>                                   colorMap;    // 20
	};
	static_assert(offsetof(GImageBase, format) == 0x0);
	static_assert(offsetof(GImageBase, width) == 0x4);
	static_assert(offsetof(GImageBase, height) == 0x8);
	static_assert(offsetof(GImageBase, pitch) == 0xC);
	static_assert(offsetof(GImageBase, data) == 0x10);
	static_assert(offsetof(GImageBase, dataSize) == 0x18);
	static_assert(offsetof(GImageBase, mipMapCount) == 0x1C);
	static_assert(offsetof(GImageBase, colorMap) == 0x20);
	static_assert(sizeof(GImageBase) == 0x38);
}
