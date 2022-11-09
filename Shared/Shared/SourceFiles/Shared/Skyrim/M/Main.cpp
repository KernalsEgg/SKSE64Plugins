#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/M/Main.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	std::uint32_t Main::GetFrameCount()
	{
		auto* singleton{ reinterpret_cast<std::uint32_t*>(Addresses::Main::FrameCount) };

		return *singleton;
	}

	Main* Main::GetSingleton()
	{
		auto** singleton{ reinterpret_cast<Main**>(Addresses::Main::Singleton) };

		return *singleton;
	}
}
