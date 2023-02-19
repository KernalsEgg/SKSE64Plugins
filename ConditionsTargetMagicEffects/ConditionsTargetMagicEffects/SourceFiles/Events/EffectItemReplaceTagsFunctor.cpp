#include "PrecompiledHeader.h"

#include "Events/EffectItemReplaceTagsFunctor.h"

#include "Addresses.h"
#include "Shared/Utility/Memory.h"



namespace ConditionsTargetMagicEffects::Events
{
	void EffectItemReplaceTagsFunctor::Register()
	{
		Utility::Memory::SafeWriteAbsoluteJump(
			Addresses::EffectItemReplaceTagsFunctor::ReplaceTagsWithText,
			reinterpret_cast<std::uintptr_t>(std::addressof(EffectItemReplaceTagsFunctor::ReplaceTagsWithText)));
	}

	const char* EffectItemReplaceTagsFunctor::ReplaceTagsWithText(Skyrim::EffectItemReplaceTagsFunctor* effectItemReplaceTagsFunctor, const char* tag, const char* capitalize, const char* globalEditorID)
	{
		auto* effect = effectItemReplaceTagsFunctor->effect;

		if (effect)
		{
			if (::_stricmp(tag, "MAG") == 0)
			{
				auto* effectSetting = effect->effectSetting;

				if (effectSetting->effectSettingFlags.none(Skyrim::EffectSetting::Flags::kNoMagnitude))
				{
					auto* player    = Skyrim::PlayerCharacter::GetSingleton();
					auto* magicItem = effectItemReplaceTagsFunctor->magicItem;
					auto  magnitude = effect->GetMagnitude();

					bool modifiedSpellMagnitude{ false };

					Skyrim::BGSEntryPoint::HandleEntryPoint(
						Skyrim::BGSEntryPoint::EntryPoint::kModifySpellMagnitude,
						player,
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
							player,
							magicItem,
							nullptr,
							std::addressof(magnitude));
					}

					auto primaryActorValue = effectSetting->primaryActorValue;

					if (primaryActorValue != Skyrim::ActorValue::kNone)
					{
						auto* actorValueInformation = Skyrim::ActorValueInfo::GetSingleton(primaryActorValue);

						if (actorValueInformation && actorValueInformation->actorValueInformationFlags.all(Skyrim::ActorValueInfo::Flags::kMultiplyBy100))
						{
							magnitude *= 100.0F;
						}
					}

					effectItemReplaceTagsFunctor->tag.print(
						"%s%d%s",
						effectItemReplaceTagsFunctor->tagStart,
						static_cast<std::int32_t>(magnitude),
						effectItemReplaceTagsFunctor->tagEnd);
				}
			}
			else if (::_stricmp(tag, "DUR") == 0)
			{
				auto* effectSetting = effect->effectSetting;

				if (effectSetting->effectSettingFlags.none(Skyrim::EffectSetting::Flags::kNoDuration))
				{
					auto* player    = Skyrim::PlayerCharacter::GetSingleton();
					auto* magicItem = effectItemReplaceTagsFunctor->magicItem;
					auto  duration  = static_cast<float>(effect->GetDuration());

					bool modifiedSpellDuration{ false };

					Skyrim::BGSEntryPoint::HandleEntryPoint(
						Skyrim::BGSEntryPoint::EntryPoint::kModifySpellDuration,
						player,
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
							player,
							magicItem,
							nullptr,
							std::addressof(duration));
					}

					effectItemReplaceTagsFunctor->tag.print(
						"%s%d%s",
						effectItemReplaceTagsFunctor->tagStart,
						static_cast<std::int32_t>(duration),
						effectItemReplaceTagsFunctor->tagEnd);
				}
			}
			else if (::_stricmp(tag, "AREA") == 0)
			{
				if (effect->effectSetting->effectSettingFlags.none(Skyrim::EffectSetting::Flags::kNoArea))
				{
					auto area = effect->GetArea();

					effectItemReplaceTagsFunctor->tag.print(
						"%s%d%s",
						effectItemReplaceTagsFunctor->tagStart,
						area,
						effectItemReplaceTagsFunctor->tagEnd);
				}
			}
			else if (::_stricmp(tag, "GLOBAL") == 0)
			{
				auto* global = Skyrim::TESForm::GetFormFromEditorID(globalEditorID);

				if (global && global->formType == Skyrim::FormType::kGlobal)
				{
					effectItemReplaceTagsFunctor->tag.print(
						"%s%d%s",
						effectItemReplaceTagsFunctor->tagStart,
						static_cast<std::int32_t>(static_cast<Skyrim::TESGlobal*>(global)->value),
						effectItemReplaceTagsFunctor->tagEnd);
				}
			}
			else
			{
				effectItemReplaceTagsFunctor->tag.print(
					"%s%s%s",
					effectItemReplaceTagsFunctor->tagStart,
					tag,
					effectItemReplaceTagsFunctor->tagEnd);
			}
		}

		return effectItemReplaceTagsFunctor->tag.data();
	}
}
