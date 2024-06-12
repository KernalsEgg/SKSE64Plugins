#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSAudioManager.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	BSAudioManager* BSAudioManager::GetSingleton()
	{
		auto* function{ reinterpret_cast<decltype(BSAudioManager::GetSingleton)*>(
			Addresses::BSAudioManager::GetSingleton()) };

		return function();
	}

	void BSAudioManager::GetSoundHandleFromName(BSSoundHandle& soundHandle, const char* editorID, std::uint32_t flags)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&BSAudioManager::GetSoundHandleFromName)>::type>(
			Addresses::BSAudioManager::GetSoundHandleFromName()) };

		function(this, soundHandle, editorID, flags);
	}
}
