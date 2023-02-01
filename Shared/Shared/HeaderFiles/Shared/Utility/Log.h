#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Relocation/Module.h"
#include "Shared/Utility/Message.h"



namespace Utility
{
	class Log
	{
	private:
		enum
		{
			kInformation,
			kWarning,
			kError,
			kCritical
		};

		static constexpr std::string_view LEVELS[]{
			"Information",
			"Warning",
			"Error",
			"Critical"
		};

	public:
		template <class... Arguments>
		static void Critical(Message message, const Arguments&... arguments)
		{
			Log::PrintLine(Log::kCritical, message, arguments...);
		}

		template <class... Arguments>
		static void Error(Message message, const Arguments&... arguments)
		{
			Log::PrintLine(Log::kError, message, arguments...);
		}

		template <class... Arguments>
		static void Information(Message message, const Arguments&... arguments)
		{
			Log::PrintLine(Log::kInformation, message, arguments...);
		}

		template <class... Arguments>
		static void Warning(Message message, const Arguments&... arguments)
		{
			Log::PrintLine(Log::kWarning, message, arguments...);
		}

	private:
		static std::ofstream& GetSingleton()
		{
			static std::ofstream singleton(
				std::filesystem::path(Relocation::DynamicLinkLibrary::GetSingleton().GetPath()).replace_extension("log"),
				std::ios::out | std::ios::trunc);

			return singleton;
		}

		template <class... Arguments>
		static void PrintLine(std::size_t level, Message message, const Arguments&... arguments)
		{
			std::stringstream stringStream;

			stringStream
				<< std::vformat(
					   "[{:%F %T}] [{}] {}({},{}): {}",
					   std::make_format_args(
						   std::chrono::system_clock::now(),
						   Log::LEVELS[level],
						   std::filesystem::path(message.sourceLocation.file_name()).filename().string(),
						   message.sourceLocation.line(),
						   message.sourceLocation.column(),
						   std::vformat(message.stringView, std::make_format_args(arguments...))))
				<< std::endl;

			Log::GetSingleton() << stringStream.rdbuf() << std::flush;
		}
	};
}
