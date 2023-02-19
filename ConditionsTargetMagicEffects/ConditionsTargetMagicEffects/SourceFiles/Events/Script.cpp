#include "PrecompiledHeader.h"

#include "Events/Script.h"

#include "Addresses.h"
#include "Shared/Utility/Enumeration.h"



namespace ConditionsTargetMagicEffects::Events
{
	void Script::Register()
	{
		*reinterpret_cast<decltype(Script::EntryPointMagicSpellHasKeywordConditionFunction)**>(Addresses::Script::EntryPointMagicSpellHasKeywordConditionFunction) =
			std::addressof(Script::EntryPointMagicSpellHasKeywordConditionFunction);
		*reinterpret_cast<decltype(Script::EntryPointMagicSpellHasSkillConditionFunction)**>(Addresses::Script::EntryPointMagicSpellHasSkillConditionFunction) =
			std::addressof(Script::EntryPointMagicSpellHasSkillConditionFunction);
	}

	bool Script::EntryPointMagicSpellHasKeywordConditionFunction(Skyrim::TESObjectREFR* object, void* parameter1, void* parameter2, double& result)
	{
		result = 0.0;

		if (object && parameter1)
		{
			auto* lockList = object->extraDataList.GetLockList();

			if (lockList && lockList->formType == Skyrim::FormType::kMagicEffect)
			{
				auto* effectSetting = static_cast<Skyrim::EffectSetting*>(lockList);

				if (effectSetting && effectSetting->HasKeyword(static_cast<Skyrim::BGSKeyword*>(parameter1)))
				{
					result = 1.0;
				}
			}
			else
			{
				auto* magicItem = static_cast<Skyrim::MagicItem*>(object->baseObject);

				if (magicItem->HasKeyword(static_cast<Skyrim::BGSKeyword*>(parameter1)))
				{
					result = 1.0;
				}
			}
		}

		return true;
	}

	/* Do not compare parameter1 to a null pointer because it is cast to an actor value */
	bool Script::EntryPointMagicSpellHasSkillConditionFunction(Skyrim::TESObjectREFR* object, void* parameter1, void* parameter2, double& result)
	{
		result = 0.0;

		if (object)
		{
			auto* lockList = object->extraDataList.GetLockList();

			if (lockList && lockList->formType == Skyrim::FormType::kMagicEffect)
			{
				auto* effectSetting = static_cast<Skyrim::EffectSetting*>(lockList);

				Utility::Enumeration<Skyrim::ActorValue, std::uint32_t> magicSkill = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(parameter1));

				if (effectSetting->magicSkill == magicSkill)
				{
					result = 1.0;
				}
			}
			else
			{
				auto* magicItem       = static_cast<Skyrim::MagicItem*>(object->baseObject);
				auto* costliestEffect = magicItem->GetCostliestEffect(Skyrim::MagicSystem::Delivery::kAny, false);

				Utility::Enumeration<Skyrim::ActorValue, std::uint32_t> magicSkill = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(parameter1));

				if (costliestEffect->effectSetting->magicSkill == magicSkill)
				{
					result = 1.0;
				}
			}
		}

		return true;
	}
}
