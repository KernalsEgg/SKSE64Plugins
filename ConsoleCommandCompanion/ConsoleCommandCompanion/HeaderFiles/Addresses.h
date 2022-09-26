#pragma once

#include "PrecompiledHeader.h"



namespace ConsoleCommandCompanion::Addresses
{
	namespace Patches
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x8A4930</summary>
		std::uintptr_t IsLoggedIn();
	}
}
