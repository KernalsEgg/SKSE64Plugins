#pragma once

#include "Shared/PrecompiledHeader.h"



namespace SKSE
{
	struct PluginInformation
	{
	public:
		enum
		{
			kVersion = 1
		};

		std::uint32_t informationVersion; // 0
		const char*   name;               // 8
		std::uint32_t version;            // 10
	};
	static_assert(offsetof(PluginInformation, informationVersion) == 0x0);
	static_assert(offsetof(PluginInformation, name) == 0x8);
	static_assert(offsetof(PluginInformation, version) == 0x10);
	static_assert(sizeof(PluginInformation) == 0x18);
}
