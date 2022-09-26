#pragma once

#include "PrecompiledHeader.h"



namespace ConsoleCommandCompanion
{
	class Settings
	{
	public:
		class Events
		{
		public:
			class Button
			{
			public:
				class State
				{
				public:
					State&         Deserialize(const nlohmann::json& jsonState);
					nlohmann::json Serialize() const;

					std::vector<std::string>     consoleCommands;
					std::optional<std::uint32_t> idCode;
					std::optional<std::uint32_t> inputDevice;
					std::optional<std::string>   userEvent;
				};

				Button&        Deserialize(const nlohmann::json& jsonButton);
				nlohmann::json Serialize() const;

				std::vector<State> pressed;
				std::vector<State> released;
			};

			class Initialize
			{
			public:
				Initialize&    Deserialize(const nlohmann::json& jsonInitialize);
				nlohmann::json Serialize() const;

				std::vector<std::string> consoleCommands;
			};

			class LoadGame
			{
			public:
				LoadGame&      Deserialize(const nlohmann::json& jsonLoadGame);
				nlohmann::json Serialize() const;

				std::vector<std::string> consoleCommands;
			};

			Events&        Deserialize(const nlohmann::json& jsonEvents);
			nlohmann::json Serialize() const;

			Button     button;
			Initialize initialize;
			LoadGame   loadGame;
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

		Events events;
		bool   log;
	};
}
