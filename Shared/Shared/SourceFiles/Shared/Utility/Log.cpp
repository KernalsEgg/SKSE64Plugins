#include "Shared/PCH.h"

#include "Shared/Utility/Log.h"

#include "Shared/Relocation/Module.h"



namespace Utility::Log
{
	Logger& Logger::GetSingleton()
	{
		static Logger singleton(std::filesystem::path(Relocation::Plugin::GetSingleton().GetPath()).replace_extension("log"));

		return singleton;
	}

	Logger::Logger(const std::filesystem::path& path) :
		outputFileStream_(std::ofstream(path, std::ios::out | std::ios::trunc))
	{
	}
}
