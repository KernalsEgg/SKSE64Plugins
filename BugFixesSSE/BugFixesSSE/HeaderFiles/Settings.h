#pragma once

#include "PCH.h"

#include <nlohmann/json.hpp>



namespace BugFixesSSE
{
	using json = nlohmann::json;

	class Settings
	{
	public:
		class Fixes
		{
		public:
			class SpeechExperience
			{
			public:
				void Deserialize(const json& speechExperience);
				json Serialize() const;

				bool enchantedItems{ false };
				bool itemStacks{ false };
			};

			void Deserialize(const json& fixes);
			json Serialize() const;

			bool             magicEffectConditions{ false };
			bool             movementSpeed{ false };
			SpeechExperience speechExperience;
		};

		Settings()                = delete;
		Settings(const Settings&) = delete;
		Settings(Settings&&)      = delete;

		~Settings() = default;

		Settings& operator=(const Settings&) = delete;
		Settings& operator=(Settings&&) = delete;

		explicit Settings(const std::filesystem::path& path);

		static Settings& GetSingleton();

		void Deserialize(const json& settings);
		json Serialize() const;

		Fixes fixes;
	};
}
