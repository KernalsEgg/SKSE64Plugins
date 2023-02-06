#include "PrecompiledHeader.h"

#include "Settings.h"

#include "Fixes/MagicEffectConditions.h"
#include "Fixes/MovementSpeed.h"
#include "Fixes/SpeechExperience/EnchantedItems.h"
#include "Fixes/SpeechExperience/ItemStacks.h"
#include "Shared/Relocation/Module.h"
#include "Shared/Utility/Log.h"



namespace BugFixesSSE
{
	Settings::Fixes::SpeechExperience& Settings::Fixes::SpeechExperience::Deserialize(const nlohmann::json& jsonSpeechExperience)
	{
		if (jsonSpeechExperience.contains("enchantedItems"))
		{
			jsonSpeechExperience.at("enchantedItems").get_to(this->enchantedItems);
		}

		if (jsonSpeechExperience.contains("itemStacks"))
		{
			jsonSpeechExperience.at("itemStacks").get_to(this->itemStacks);
		}

		return *this;
	}

	nlohmann::json Settings::Fixes::SpeechExperience::Serialize() const
	{
		nlohmann::json jsonSpeechExperience;

		jsonSpeechExperience["enchantedItems"] = this->enchantedItems;
		jsonSpeechExperience["itemStacks"]     = this->itemStacks;

		return jsonSpeechExperience;
	}

	Settings::Fixes& Settings::Fixes::Deserialize(const nlohmann::json& jsonFixes)
	{
		if (jsonFixes.contains("magicEffectConditions"))
		{
			jsonFixes.at("magicEffectConditions").get_to(this->magicEffectConditions);
		}

		if (jsonFixes.contains("movementSpeed"))
		{
			jsonFixes.at("movementSpeed").get_to(this->movementSpeed);
		}

		if (jsonFixes.contains("speechExperience"))
		{
			this->speechExperience.Deserialize(jsonFixes.at("speechExperience"));
		}

		return *this;
	}

	nlohmann::json Settings::Fixes::Serialize() const
	{
		nlohmann::json jsonFixes;

		jsonFixes["magicEffectConditions"] = this->magicEffectConditions;
		jsonFixes["movementSpeed"]         = this->movementSpeed;
		jsonFixes["speechExperience"]      = this->speechExperience.Serialize();

		return jsonFixes;
	}

	Settings::Settings(const std::filesystem::path& path)
	{
		try
		{
			this->Deserialize(nlohmann::json::parse(std::ifstream(path), nullptr, true, true));
		}
		catch (const nlohmann::json::exception& jsonException)
		{
			Utility::Log::Critical()("{}", jsonException.what());

			throw;
		}
	}

	Settings& Settings::GetSingleton()
	{
		static Settings singleton(std::filesystem::path(Relocation::DynamicLinkLibrary::GetSingleton().GetPath()).replace_extension("json"));

		return singleton;
	}

	Settings& Settings::Deserialize(const nlohmann::json& jsonSettings)
	{
		if (jsonSettings.contains("fixes"))
		{
			this->fixes.Deserialize(jsonSettings.at("fixes"));
		}

		return *this;
	}

	void Settings::Initialize()
	{
		Utility::Log::Information()("Initializing...\n{}", this->Serialize().dump(1, '\t'));

		if (this->fixes.magicEffectConditions)
		{
			BugFixesSSE::Fixes::MagicEffectConditions::Fix(this->fixes.magicEffectConditions);
		}

		if (this->fixes.movementSpeed)
		{
			BugFixesSSE::Fixes::MovementSpeed::Fix(this->fixes.movementSpeed);
		}

		if (this->fixes.speechExperience.enchantedItems)
		{
			BugFixesSSE::Fixes::SpeechExperience::EnchantedItems::Fix(this->fixes.speechExperience.enchantedItems);
		}

		// Must be installed after BugFixesSSE::Fixes::Speechcraft::EnchantedItems
		if (this->fixes.speechExperience.itemStacks)
		{
			BugFixesSSE::Fixes::SpeechExperience::ItemStacks::Fix(this->fixes.speechExperience.itemStacks);
		}

		Utility::Log::Information()("Initialized.\n{}", this->Serialize().dump(1, '\t'));
	}

	nlohmann::json Settings::Serialize() const
	{
		nlohmann::json jsonSettings;

		jsonSettings["fixes"] = this->fixes.Serialize();

		return jsonSettings;
	}
}
