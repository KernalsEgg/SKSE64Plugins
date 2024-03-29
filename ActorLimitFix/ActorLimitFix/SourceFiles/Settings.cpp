#include "PrecompiledHeader.h"

#include "Settings.h"

#include "Fixes/MorphLimit.h"
#include "Fixes/MoverLimit.h"
#include "Fixes/ReplaceStaticArray.h"
#include "Shared/Relocation/Module.h"



namespace ActorLimitFix
{
	Settings::Fixes& Settings::Fixes::Deserialize(const nlohmann::json& jsonFixes)
	{
		jsonFixes.at("morphLimit").get_to(this->morphLimit);
		jsonFixes.at("moverLimit").get_to(this->moverLimit);
		jsonFixes.at("replaceStaticArray").get_to(this->replaceStaticArray);

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
			SPDLOG_CRITICAL("{}", jsonException.what());

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
		this->fixes.Deserialize(jsonSettings.at("fixes"));

		return *this;
	}

	void Settings::Load()
	{
		SPDLOG_INFO("Loading...\n{}", this->Serialize().dump(1, '\t'));

		if (this->fixes.replaceStaticArray)
		{
			ActorLimitFix::Fixes::ReplaceStaticArray::Fix(this->fixes.replaceStaticArray);
		}

		/* Must be installed after ActorLimitFix::Fixes::ReplaceStaticArray */
		ActorLimitFix::Fixes::MorphLimit::Fix(this->fixes.morphLimit, this->fixes.replaceStaticArray);
		ActorLimitFix::Fixes::MoverLimit::Fix(this->fixes.moverLimit);

		SPDLOG_INFO("Loaded.\n{}", this->Serialize().dump(1, '\t'));
	}

	nlohmann::json Settings::Serialize() const
	{
		nlohmann::json jsonSettings;

		jsonSettings["fixes"] = this->fixes.Serialize();

		return jsonSettings;
	}
}
