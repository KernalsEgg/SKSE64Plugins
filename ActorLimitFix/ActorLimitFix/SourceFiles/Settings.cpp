#include "PCH.h"

#include "Settings.h"

#include "Shared/Relocation/Module.h"
#include "Shared/Utility/Log.h"



namespace ActorLimitFix
{
	Settings::Fixes& Settings::Fixes::Deserialize(const nlohmann::json& jsonFixes)
	{
		if (jsonFixes.contains("morphLimit"))
		{
			jsonFixes.at("morphLimit").get_to(this->morphLimit);
		}

		if (jsonFixes.contains("moverLimit"))
		{
			jsonFixes.at("moverLimit").get_to(this->moverLimit);
		}

		if (jsonFixes.contains("replaceStaticArray"))
		{
			jsonFixes.at("replaceStaticArray").get_to(this->replaceStaticArray);
		}

		return *this;
	}

	nlohmann::json Settings::Fixes::Serialize() const
	{
		nlohmann::json jsonFixes;

		jsonFixes["morphLimit"]         = this->morphLimit;
		jsonFixes["moverLimit"]         = this->moverLimit;
		jsonFixes["replaceStaticArray"] = this->replaceStaticArray;

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
			Utility::Log::Error("{}", jsonException.what());
		}
	}

	Settings& Settings::GetSingleton()
	{
		static Settings singleton(std::filesystem::path(Relocation::Plugin::GetSingleton().GetPath()).replace_extension("json"));

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

	nlohmann::json Settings::Serialize() const
	{
		nlohmann::json jsonSettings;

		jsonSettings["fixes"] = this->fixes.Serialize();

		return jsonSettings;
	}
}
