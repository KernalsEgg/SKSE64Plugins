#pragma once

#include "PrecompiledHeader.h"



namespace BugFixesSSE
{
	class Settings
	{
	public:
		class Fixes
		{
		public:
			class SpeechExperience
			{
			public:
				SpeechExperience& Deserialize(const nlohmann::json& jsonSpeechExperience);
				nlohmann::json    Serialize() const;

				bool enchantedItems{ false };
				bool itemStacks{ false };
			};

			Fixes&         Deserialize(const nlohmann::json& jsonFixes);
			nlohmann::json Serialize() const;

			bool             magicEffectConditions{ false };
			bool             movementSpeed{ false };
			SpeechExperience speechExperience;
		};

		Settings()                = delete;
		Settings(const Settings&) = delete;
		Settings(Settings&&)      = delete;

		~Settings() = default;

		Settings& operator=(const Settings&) = delete;
		Settings& operator=(Settings&&)      = delete;

		explicit Settings(const std::filesystem::path& path);

		static Settings& GetSingleton();

		Settings&      Deserialize(const nlohmann::json& jsonSettings);
		nlohmann::json Serialize() const;

		Fixes fixes;
	};
}
