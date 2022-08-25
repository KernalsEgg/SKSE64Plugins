#pragma once

#include "Shared/PCH.h"

#include "Shared/Utility/Message.h"



namespace Utility::Log
{
	class Logger
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
		Logger()              = delete;
		Logger(const Logger&) = delete;
		Logger(Logger&&)      = delete;

		~Logger() = default;

		Logger& operator=(const Logger&) = delete;
		Logger& operator=(Logger&&) = delete;

		explicit Logger(const std::filesystem::path& path);

		static Logger& GetSingleton();

		template <class... Arguments>
		void Critical(Message message, const Arguments&... arguments)
		{
			this->Log(Logger::kCritical, message, arguments...);
		}

		template <class... Arguments>
		void Error(Message message, const Arguments&... arguments)
		{
			this->Log(Logger::kError, message, arguments...);
		}

		template <class... Arguments>
		void Information(Message message, const Arguments&... arguments)
		{
			this->Log(Logger::kInformation, message, arguments...);
		}

		template <class... Arguments>
		void Warning(Message message, const Arguments&... arguments)
		{
			this->Log(Logger::kWarning, message, arguments...);
		}

	private:
		template <class... Arguments>
		void Log(std::size_t level, Message message, const Arguments&... arguments)
		{
			std::stringstream stringStream;

			stringStream
				<< fmt::format("[{:%F %T}] [{}] {}({},{}): {}",
					   std::chrono::system_clock::now(),
					   Logger::LEVELS[level],
					   std::filesystem::path(message.sourceLocation.file_name()).filename().string(),
					   message.sourceLocation.line(),
					   message.sourceLocation.column(),
					   fmt::format(message.stringView, arguments...))
				<< std::endl;

			this->outputFileStream_ << stringStream.rdbuf() << std::flush;
		}

		std::ofstream outputFileStream_;
	};

	template <class... Arguments>
	void Critical(Message message, const Arguments&... arguments)
	{
		Logger::GetSingleton().Critical(message, arguments...);
	}

	template <class... Arguments>
	void Error(Message message, const Arguments&... arguments)
	{
		Logger::GetSingleton().Error(message, arguments...);
	}

	template <class... Arguments>
	void Information(Message message, const Arguments&... arguments)
	{
		Logger::GetSingleton().Information(message, arguments...);
	}

	template <class... Arguments>
	void Warning(Message message, const Arguments&... arguments)
	{
		Logger::GetSingleton().Warning(message, arguments...);
	}
}
