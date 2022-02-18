#include "PCH.h"

#include "Settings.h"

#include "Shared/Relocation/Module.h"
#include "Shared/Utility/Log.h"



namespace ActorLimitFix
{
	void Settings::Fixes::Deserialize(const json& fixes)
	{
		if (fixes.contains("morphLimit"))
		{
			fixes.at("morphLimit").get_to(this->morphLimit);
		}

		if (fixes.contains("moverLimit"))
		{
			fixes.at("moverLimit").get_to(this->moverLimit);
		}

		if (fixes.contains("replaceStaticArray"))
		{
			fixes.at("replaceStaticArray").get_to(this->replaceStaticArray);
		}
	}

	json Settings::Fixes::Serialize() const
	{
		json fixes;

		fixes["morphLimit"]         = this->morphLimit;
		fixes["moverLimit"]         = this->moverLimit;
		fixes["replaceStaticArray"] = this->replaceStaticArray;

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
