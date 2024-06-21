#include "Shared/PrecompiledHeader.h"

#include "Shared/Utility/Log.h"

#include "Shared/Relocation/Module.h"



namespace Utility
{
	Log::Log(std::ofstream&& outputFileStream) :
		outputFileStream_(std::move(outputFileStream))
	{
	}

	Log& Log::GetSingleton()
	{
		static Log singleton(
			std::ofstream(
				std::filesystem::path(Relocation::DynamicLinkLibrary::GetSingleton().GetPath()).replace_extension("log"),
				std::ios::out | std::ios::trunc));

		return singleton;
	}
}
