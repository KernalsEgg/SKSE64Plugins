#include "Shared/PCH.h"

#include "Shared/Skyrim/S/SpellItem.h"

#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/M/MagicCaster.h"



namespace Skyrim
{
	void SpellItem::Apply(Actor* target, Actor* caster)
	{
		if (this->ShouldAddSpell())
		{
			target->AddSpell(this);
		}
		else
		{
			caster->GetMagicCaster(MagicSystem::CastingSource::kInstant)->Cast(this, false, target, 1.0F, false, 0.0F, nullptr);
		}
	}
}
