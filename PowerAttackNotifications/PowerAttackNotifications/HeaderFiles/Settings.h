#pragma once

#include "PrecompiledHeader.h"



namespace PowerAttackNotifications
{
	class Settings
	{
	public:
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

		std::string notification;
	};
}
