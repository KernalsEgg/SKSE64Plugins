#pragma once

#include "Shared/PrecompiledHeader.h"



namespace SKSE
{
	using PluginHandle = std::uint32_t;

	enum : PluginHandle
	{
		kInvalidPluginHandle = static_cast<PluginHandle>(-1),
	};
}
