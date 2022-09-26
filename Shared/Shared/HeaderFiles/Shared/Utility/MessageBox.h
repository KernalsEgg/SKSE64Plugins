#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Relocation/Module.h"
#include "Shared/Utility/Message.h"



namespace Utility::MessageBox
{
	template <class... Arguments>
	void Error(Message message, const Arguments&... arguments)
	{
		::MessageBoxA(
			nullptr,
			std::vformat(
				"{}({},{}): {}",
				std::make_format_args(
					std::filesystem::path(message.sourceLocation.file_name()).filename().string(),
					message.sourceLocation.line(),
					message.sourceLocation.column(),
					std::vformat(message.stringView, std::make_format_args(arguments...))))
				.c_str(),
			Relocation::DynamicLinkLibrary::GetSingleton().GetPath().filename().string().c_str(),
			MB_OK | MB_ICONERROR);

		std::terminate();
	}
}
