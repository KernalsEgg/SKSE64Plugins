#pragma once

#include "Shared/PCH.h"

#include "Shared/Relocation/Module.h"
#include "Shared/Utility/Message.h"



namespace Utility::MessageBox
{
	template <class... Arguments>
	void Error(Message message, const Arguments&... arguments)
	{
		::MessageBoxA(
			nullptr,
			fmt::format("{}({},{}): {}",
				std::filesystem::path(message.sourceLocation.file_name()).filename().string(),
				message.sourceLocation.line(),
				message.sourceLocation.column(),
				fmt::format(message.stringView, arguments...))
				.c_str(),
			Relocation::Plugin::GetSingleton().GetPath().filename().string().c_str(),
			MB_OK | MB_ICONERROR);

		std::terminate();
	}
}
