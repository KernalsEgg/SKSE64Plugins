#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Relocation/Module.h"



namespace Utility::InformationBox
{
	struct Error
	{
	public:
		Error(std::source_location sourceLocation = std::source_location::current()) :
			sourceLocation_(sourceLocation) {}

		template <class... Arguments>
		void operator()(std::string_view format, Arguments... arguments)
		{
			::MessageBoxA(
				nullptr,
				std::vformat(
					"{}({},{}): {}",
					std::make_format_args(
						std::filesystem::path(this->sourceLocation_.file_name()).filename().string(),
						this->sourceLocation_.line(),
						this->sourceLocation_.column(),
						std::vformat(format, std::make_format_args(arguments...))))
					.c_str(),
				Relocation::DynamicLinkLibrary::GetSingleton().GetPath().filename().string().c_str(),
				MB_OK | MB_ICONERROR);

			std::terminate();
		}

	private:
		std::source_location sourceLocation_;
	};
}
