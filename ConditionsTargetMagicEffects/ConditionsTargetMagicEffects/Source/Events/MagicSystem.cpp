#include "PrecompiledHeader.h"

#include "Events/MagicSystem.h"

#include "Addresses.h"
#include "Shared/Utility/Format.h"
#include "Shared/Utility/Memory.h"



namespace ConditionsTargetMagicEffects::Events
{
	void MagicSystem::Register()
	{
		Utility::Memory::SafeWriteAbsoluteJump(
			Addresses::MagicSystem::GetMagicItemDescription,
			reinterpret_cast<std::uintptr_t>(std::addressof(MagicSystem::GetMagicItemDescription)));
	}

	/* Dynamically allocate memory on the heap using std::string instead of statically allocating memory on the stack using an array so that magic item descriptions can be of any length */
	void MagicSystem::GetMagicItemDescription(Skyrim::ItemCard* itemCard, Skyrim::MagicItem* magicItem, Skyrim::BSString& magicItemDescription)
	{
		magicItemDescription.clear();

		if (!magicItem)
		{
			return;
		}

		Skyrim::GetMagicItemDescriptionFunctor getMagicItemDescriptionFunctor;

		getMagicItemDescriptionFunctor.magicItemDescription = std::addressof(magicItemDescription);
		getMagicItemDescriptionFunctor.tagStart             = MagicSystem::TAG_START;
		getMagicItemDescriptionFunctor.tagEnd               = MagicSystem::TAG_END;
		getMagicItemDescriptionFunctor.magicItem            = magicItem;
		getMagicItemDescriptionFunctor.append               = false;

		magicItem->Traverse(getMagicItemDescriptionFunctor);

		if (magicItemDescription.empty())
		{
			bool        append{ false };
			std::string buffer{};

			auto* playerCharacter = Skyrim::PlayerCharacter::GetSingleton();

			for (auto* effectItem : magicItem->effectItems)
			{
				auto* effectSetting = effectItem->effectSetting;

				if (effectSetting->effectSettingFlags.all(Skyrim::EffectSetting::Flags::kHideInUI))
				{
					continue;
				}

				if (append)
				{
					buffer += " ";
				}

				auto duration  = static_cast<float>(effectItem->GetDuration());
				auto magnitude = effectItem->GetMagnitude();

				bool modifiedSpellDuration{ false };
				bool modifiedSpellMagnitude{ false };

				Skyrim::BGSEntryPoint::HandleEntryPoint(
					Skyrim::BGSEntryPoint::EntryPoint::kModifySpellDuration,
					playerCharacter,
					effectSetting,
					magicItem,
					nullptr,
					nullptr,
					std::addressof(duration),
					std::addressof(modifiedSpellDuration));

				if (!modifiedSpellDuration)
				{
					Skyrim::BGSEntryPoint::HandleEntryPoint(
						Skyrim::BGSEntryPoint::EntryPoint::kModifySpellDuration,
						playerCharacter,
						magicItem,
						nullptr,
						std::addressof(duration));
				}

				Skyrim::BGSEntryPoint::HandleEntryPoint(
					Skyrim::BGSEntryPoint::EntryPoint::kModifySpellMagnitude,
					playerCharacter,
					effectSetting,
					magicItem,
					nullptr,
					nullptr,
					std::addressof(magnitude),
					std::addressof(modifiedSpellMagnitude));

				if (!modifiedSpellMagnitude)
				{
					Skyrim::BGSEntryPoint::HandleEntryPoint(
						Skyrim::BGSEntryPoint::EntryPoint::kModifySpellMagnitude,
						playerCharacter,
						magicItem,
						nullptr,
						std::addressof(magnitude));
				}

				if (static_cast<std::int32_t>(magnitude))
				{
					buffer += Utility::Format::Print(
						"%s%s%u%s ",
						MagicSystem::TAG_START,
						"+",
						static_cast<std::int32_t>(magnitude),
						MagicSystem::TAG_END);
				}

				buffer += effectSetting->GetFullName();

				if (static_cast<std::int32_t>(duration))
				{
					auto        convertedDuration = static_cast<float>(static_cast<std::int32_t>(duration));
					const char* durationUnits{ nullptr };

					if (convertedDuration >= 60.0F * 60.0F) // Hours
					{
						convertedDuration /= 60.0F * 60.0F;

						auto hours = std::floor(convertedDuration);

						static auto* effectsListDisplayHour  = Skyrim::GameSettingCollection::InitializeSetting("sEffectsListDisplayHour");
						static auto* effectsListDisplayHours = Skyrim::GameSettingCollection::InitializeSetting("sEffectsListDisplayHours");

						durationUnits = hours == 1.0F ?
						                    effectsListDisplayHour->GetString() :
						                    effectsListDisplayHours->GetString();
					}
					else if (convertedDuration >= 60.0F) // Minutes
					{
						convertedDuration /= 60.0F;

						auto minutes = std::floor(convertedDuration);

						static auto* effectsListDisplayMinute  = Skyrim::GameSettingCollection::InitializeSetting("sEffectsListDisplayMin");
						static auto* effectsListDisplayMinutes = Skyrim::GameSettingCollection::InitializeSetting("sEffectsListDisplayMins");

						durationUnits = minutes == 1.0F ?
						                    effectsListDisplayMinute->GetString() :
						                    effectsListDisplayMinutes->GetString();
					}
					else // Seconds
					{
						auto seconds = std::floor(convertedDuration);

						static auto* effectsListDisplaySecond  = Skyrim::GameSettingCollection::InitializeSetting("sEffectsListDisplaySec");
						static auto* effectsListDisplaySeconds = Skyrim::GameSettingCollection::InitializeSetting("sEffectsListDisplaySecs");

						durationUnits = seconds == 1.0F ?
						                    effectsListDisplaySecond->GetString() :
						                    effectsListDisplaySeconds->GetString();
					}

					buffer += Utility::Format::Print(
						" %s%.0f%s %s",
						MagicSystem::TAG_START,
						convertedDuration,
						MagicSystem::TAG_END,
						durationUnits);
				}

				buffer += ".";

				append = true;
			}

			magicItemDescription = buffer.c_str();
		}
	}
}
