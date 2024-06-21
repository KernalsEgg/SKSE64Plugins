#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Relocation/Module.h"



namespace Utility::InformationBox
{
	template <class... Arguments>
	struct Error
	{
	public:
		explicit Error(std::string_view format, Arguments... arguments, std::source_location sourceLocation = std::source_location::current())
		{
			::MessageBoxA(
				nullptr,
				std::format(
					"{}({},{}): {}",
					std::filesystem::path(sourceLocation.file_name()).filename().string(),
					sourceLocation.line(),
					sourceLocation.column(),
					std::vformat(format, std::make_format_args(arguments...)))
					.c_str(),
				Relocation::DynamicLinkLibrary::GetSingleton().GetPath().filename().string().c_str(),
				MB_OK | MB_ICONERROR);

			std::terminate();
		}
	};

	template <class... Arguments>
	Error(std::string_view, Arguments...) -> Error<Arguments...>;
}
