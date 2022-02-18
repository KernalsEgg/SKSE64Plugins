#include "PCH.h"

#include "Settings.h"

#include "Shared/Relocation/Module.h"
#include "Shared/Utility/Log.h"



namespace BugFixesSSE
{
	void Settings::Fixes::SpeechExperience::Deserialize(const json& speechExperience)
	{
		if (speechExperience.contains("enchantedItems"))
		{
			speechExperience.at("enchantedItems").get_to(this->enchantedItems);
		}

		if (speechExperience.contains("itemStacks"))
		{
			speechExperience.at("itemStacks").get_to(this->itemStacks);
		}
	}

	json Settings::Fixes::SpeechExperience::Serialize() const
	{
		json speechExperience;

		speechExperience["enchantedItems"] = this->enchantedItems;
		speechExperience["itemStacks"]     = this->itemStacks;

		return speechExperience;
	}

	void Settings::Fixes::Deserialize(const json& fixes)
	{
		if (fixes.contains("magicEffectConditions"))
		{
			fixes.at("magicEffectConditions").get_to(this->magicEffectConditions);
		}

		if (fixes.contains("speechExperience"))
		{
			this->speechExperience.Deserialize(fixes.at("speechExperience"));
		}

		if (fixes.contains("speedMultUpdates"))
		{
			fixes.at("speedMultUpdates").get_to(this->speedMultUpdates);
		}
	}

	json Settings::Fixes::Serialize() const
	{
		json fixes;

		fixes["magicEffectConditions"] = this->magicEffectConditions;
		fixes["speechExperience"]      = this->speechExperience.Serialize();
		fixes["speedMultUpdates"]      = this->speedMultUpdates;

		return fixes;
	}

	Settings::Settings(const std::filesystem::path& path)
	{
		try
		{
			this->Deserialize(json::parse(std::ifstream(path), nullptr, true, true));
		}
		catch (const json::exception& exception)
		{
			Utility::Log::Error(exception.what());
		}
	}

	Settings& Settings::GetSingleton()
	{
		static Settings singleton(std::filesystem::path(Relocation::Plugin::GetSingleton().GetPath()).replace_extension("json"));

		return singleton;
	}

	void Settings::Deserialize(const json& settings)
	{
		if (settings.contains("fixes"))
		{
			this->fixes.Deserialize(settings.at("fixes"));
		}
	}

	json Settings::Serialize() const
	{
		json settings;

		settings["fixes"] = this->fixes.Serialize();

		return settings;
	}
}
