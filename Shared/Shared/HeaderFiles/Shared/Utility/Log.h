#pragma once

#include "Shared/PCH.h"

#include "Shared/Utility/Convert.h"
#include "Shared/Utility/Message.h"



namespace Utility::Log
{
	enum class Level
	{
		kInformation,
		kWarning,
		kError,
		kCritical
	};

	constexpr std::string_view Levels[]{
		"Information",
		"Warning",
		"Error",
		"Critical"
	};

	class Logger
	{
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
			this->Log(Level::kCritical, message, arguments...);
		}

		template <class... Arguments>
		void Error(Message message, const Arguments&... arguments)
		{
			this->Log(Level::kError, message, arguments...);
		}

		template <class... Arguments>
		void Information(Message message, const Arguments&... arguments)
		{
			this->Log(Level::kInformation, message, arguments...);
		}

		template <class... Arguments>
		void Warning(Message message, const Arguments&... arguments)
		{
			this->Log(Level::kWarning, message, arguments...);
		}

	private:
		template <class... Arguments>
		void Log(Level level, Message message, const Arguments&... arguments)
		{
			this->outputFileStream_
				<< fmt::format("[{:%F %T}] [{}] {}({},{}): {}",
					   std::chrono::system_clock::now(),
					   Levels[Utility::ToUnderlying(level)],
					   std::filesystem::path(message.sourceLocation.file_name()).filename().string(),
					   message.sourceLocation.line(),
					   message.sourceLocation.column(),
					   fmt::format(message.stringView, arguments...))
				<< std::endl;
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
