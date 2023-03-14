#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/E/EffectArchetypes.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	namespace EffectArchetypes
	{
		Archetype* GetArchetype(Utility::Enumeration<ArchetypeID, std::uint32_t> effectArchetype)
		{
			return std::addressof(EffectArchetypes::GetArchetypes()[effectArchetype.underlying()]);
		}

		Archetype* GetArchetypes()
		{
			auto* singleton{ reinterpret_cast<Archetype*>(Addresses::EffectArchetypes::Archetypes) };

			return singleton;
		}
	}
}
