#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Utility
{
	class Log
	{
	private:
		enum : std::size_t
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

		Log()           = delete;
		Log(const Log&) = delete;
		Log(Log&&)      = delete;

		~Log() = default;

		Log& operator=(const Log&) = delete;
		Log& operator=(Log&&)      = delete;

		explicit Log(std::ofstream&& outputFileStream);

		static Log& GetSingleton();

		template <std::size_t LEVEL>
		struct Level
		{
		public:
			Level(std::source_location sourceLocation = std::source_location::current()) :
				sourceLocation_(sourceLocation) {}

			template <class... Arguments>
			void operator()(std::string_view format, Arguments... arguments)
			{
				std::stringstream stringStream;

				stringStream
					<< std::vformat(
						   "[{:%F %T}] [{}] {}({},{}): {}",
						   std::make_format_args(
							   std::chrono::system_clock::now(),
							   Log::LEVELS[LEVEL],
							   std::filesystem::path(this->sourceLocation_.file_name()).filename().string(),
							   this->sourceLocation_.line(),
							   this->sourceLocation_.column(),
							   std::vformat(format, std::make_format_args(arguments...))))
					<< std::endl;

				Log::GetSingleton().outputFileStream_ << stringStream.rdbuf() << std::flush;
			}

		private:
			std::source_location sourceLocation_;
		};

		std::ofstream outputFileStream_;

	public:
		using Information = Level<Log::kInformation>;
		using Warning     = Level<Log::kWarning>;
		using Error       = Level<Log::kError>;
		using Critical    = Level<Log::kCritical>;
	};
}
