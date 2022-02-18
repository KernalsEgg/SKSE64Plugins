#include "Shared/PCH.h"

#include "Shared/Skyrim/E/EffectSetting.h"



namespace Skyrim
{
	bool EffectSetting::IsHostile()
	{
		return this->effectSettingFlags.all(Flags::kHostile);
	}
}
