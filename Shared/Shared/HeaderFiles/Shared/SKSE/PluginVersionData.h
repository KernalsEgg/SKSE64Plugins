#pragma once

#include "Shared/PrecompiledHeader.h"



namespace SKSE
{
#ifdef SKYRIM_ANNIVERSARY_EDITION
	struct PluginVersionData
	{
	public:
		enum
		{
			kVersion = 1
		};

		std::uint32_t dataVersion{ PluginVersionData::kVersion };             // 0
		std::uint32_t pluginVersion{ 0 };                                     // 4
		char          pluginName[256]{};                                      // 8
		char          author[256]{};                                          // 108
		char          supportEmail[252]{};                                    // 208
		std::uint32_t backwardCompatible16629                  : 1 { false }; // 304 (0, 0)
		std::uint32_t reservedVersionIndependenceExtendedFlags : 31 { 0 };    // 304 (0, 1)
		std::uint32_t addressLibrary                           : 1 { false }; // 308 (0, 0)
		std::uint32_t signatureScanning                        : 1 { false }; // 308 (0, 1)
		std::uint32_t compatible16629                          : 1 { false }; // 308 (0, 2)
		std::uint32_t reservedVersionIndependenceFlags         : 29 { 0 };    // 308 (0, 3)
		std::uint32_t compatibleVersions[16]{};                               // 30C
		std::uint32_t minimumSKSEVersion{ 0 };                                // 34C
	};
	static_assert(offsetof(PluginVersionData, dataVersion) == 0x0);
	static_assert(offsetof(PluginVersionData, pluginVersion) == 0x4);
	static_assert(offsetof(PluginVersionData, pluginName) == 0x8);
	static_assert(offsetof(PluginVersionData, author) == 0x108);
	static_assert(offsetof(PluginVersionData, supportEmail) == 0x208);
	static_assert(offsetof(PluginVersionData, compatibleVersions) == 0x30C);
	static_assert(offsetof(PluginVersionData, minimumSKSEVersion) == 0x34C);
	static_assert(sizeof(PluginVersionData) == 0x350);
#endif
}
