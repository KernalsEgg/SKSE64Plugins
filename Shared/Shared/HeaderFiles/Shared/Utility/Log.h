#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Utility/Conversion.h"



namespace Utility
{
	class Log
	{
	private:
		enum class Level : std::size_t
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

		template <Level LEVEL, class... Arguments>
		void PrintLine(std::string_view format, Arguments... arguments, std::source_location sourceLocation = std::source_location::current())
		{
			std::scoped_lock scopedLock{ this->sharedMutex_ };

			this->outputFileStream_
				<< std::vformat(
					   "[{:%F %T}] [{}] {}({},{}): {}",
					   std::make_format_args(
						   std::chrono::system_clock::now(),
						   Log::LEVELS[Utility::Conversion::ToUnderlying(LEVEL)],
						   std::filesystem::path(sourceLocation.file_name()).filename().string(),
						   sourceLocation.line(),
						   sourceLocation.column(),
						   std::vformat(format, std::make_format_args(arguments...))))
				<< std::endl;
		}

		std::ofstream     outputFileStream_;
		std::shared_mutex sharedMutex_;

	public:
		template <class... Arguments>
		struct Critical
		{
		public:
			explicit Critical(std::string_view format, Arguments... arguments, std::source_location sourceLocation = std::source_location::current())
			{
				Log::GetSingleton().PrintLine<Level::kCritical, Arguments...>(format, arguments..., sourceLocation);
			}
		};

		template <class... Arguments>
		Critical(std::string_view, Arguments...) -> Critical<Arguments...>;

		template <class... Arguments>
		struct Error
		{
		public:
			explicit Error(std::string_view format, Arguments... arguments, std::source_location sourceLocation = std::source_location::current())
			{
				Log::GetSingleton().PrintLine<Level::kError, Arguments...>(format, arguments..., sourceLocation);
			}
		};

		template <class... Arguments>
		Error(std::string_view, Arguments...) -> Error<Arguments...>;

		template <class... Arguments>
		struct Information
		{
		public:
			explicit Information(std::string_view format, Arguments... arguments, std::source_location sourceLocation = std::source_location::current())
			{
				Log::GetSingleton().PrintLine<Level::kInformation, Arguments...>(format, arguments..., sourceLocation);
			}
		};

		template <class... Arguments>
		Information(std::string_view, Arguments...) -> Information<Arguments...>;

		template <class... Arguments>
		struct Warning
		{
		public:
			explicit Warning(std::string_view format, Arguments... arguments, std::source_location sourceLocation = std::source_location::current())
			{
				Log::GetSingleton().PrintLine<Level::kWarning, Arguments...>(format, arguments..., sourceLocation);
			}
		};

		template <class... Arguments>
		Warning(std::string_view, Arguments...) -> Warning<Arguments...>;
	};
}
