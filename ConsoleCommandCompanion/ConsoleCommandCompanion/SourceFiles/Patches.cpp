#include "PrecompiledHeader.h"

#include "Patches.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Relocation/Module.h"
#include "Shared/Utility/Assembly.h"
#include "Shared/Utility/Memory.h"



namespace ConsoleCommandCompanion
{
	bool Patches::Install()
	{
		if (!Patterns::Patches::IsLoggedIn())
		{
			return false;
		}

		Utility::Memory::SafeWrite(Addresses::Patches::IsLoggedIn(), Utility::Assembly::NO_OPERATION_2);

		return true;
	}
}
