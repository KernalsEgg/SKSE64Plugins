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
		auto* effectItem = effectItemReplaceTagsFunctor->effectItem;

		if (effectItem)
		{
			if (::_stricmp(tag, "MAG") == 0)
			{
				auto* effectSetting = effectItem->effectSetting;

				if (effectSetting->effectSettingFlags.none(Skyrim::EffectSetting::Flags::kNoMagnitude))
				{
					auto* playerCharacter = Skyrim::PlayerCharacter::GetSingleton();
					auto* magicItem       = effectItemReplaceTagsFunctor->magicItem;
					auto  magnitude       = effectItem->GetMagnitude();

					bool modifiedSpellMagnitude{ false };

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
				auto* effectSetting = effectItem->effectSetting;

				if (effectSetting->effectSettingFlags.none(Skyrim::EffectSetting::Flags::kNoDuration))
				{
					auto* playerCharacter = Skyrim::PlayerCharacter::GetSingleton();
					auto* magicItem       = effectItemReplaceTagsFunctor->magicItem;
					auto  duration        = static_cast<float>(effectItem->GetDuration());

					bool modifiedSpellDuration{ false };

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

					effectItemReplaceTagsFunctor->tag.print(
						"%s%d%s",
						effectItemReplaceTagsFunctor->tagStart,
						static_cast<std::int32_t>(duration),
						effectItemReplaceTagsFunctor->tagEnd);
				}
			}
			else if (::_stricmp(tag, "AREA") == 0)
			{
				if (effectItem->effectSetting->effectSettingFlags.none(Skyrim::EffectSetting::Flags::kNoArea))
				{
					auto area = effectItem->GetArea();

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
