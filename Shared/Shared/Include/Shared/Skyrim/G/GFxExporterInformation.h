#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GFxFileConstants.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	struct GFxExporterInformation
	{
	public:
		enum class ExportFlagConstants : std::uint32_t
		{
			kGlyphTexturesExported    = 1U << 0,
			kGradientTexturesExported = 1U << 1,
			kGlyphsStripped           = 1U << 4
		};
		static_assert(sizeof(ExportFlagConstants) == 0x4);

		// Member variables
		Utility::Enumeration<GFxFileConstants::FileFormatType, std::uint32_t> format;      // 0
		std::uint32_t                                                         padding4;    // 4
		const char*                                                           prefix;      // 8
		const char*                                                           swfName;     // 10
		std::uint32_t                                                         version;     // 18
		Utility::Enumeration<ExportFlagConstants, std::uint32_t>              exportFlags; // 1C
	};
	static_assert(offsetof(GFxExporterInformation, format) == 0x0);
	static_assert(offsetof(GFxExporterInformation, prefix) == 0x8);
	static_assert(offsetof(GFxExporterInformation, swfName) == 0x10);
	static_assert(offsetof(GFxExporterInformation, version) == 0x18);
	static_assert(offsetof(GFxExporterInformation, exportFlags) == 0x1C);
	static_assert(sizeof(GFxExporterInformation) == 0x20);
}
