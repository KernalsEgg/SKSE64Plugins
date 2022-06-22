#include "PCH.h"

#include "Patches.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Relocation/Module.h"
#include "Shared/Utility/Assembly.h"
#include "Shared/Utility/Memory.h"



namespace ConsoleCommandCompanion
{
	std::optional<bool> Patches::Install()
	{
		if (!Relocation::Executable::GetSingleton().IsSpecialEdition())
		{
			return {};
		}

		if (!Patterns::Patches::IsLoggedIn())
		{
			return false;
		}

		Utility::Memory::SafeWrite(Addresses::Patches::IsLoggedIn, Utility::Assembly::NoOperation2);

		return true;
	}
}
