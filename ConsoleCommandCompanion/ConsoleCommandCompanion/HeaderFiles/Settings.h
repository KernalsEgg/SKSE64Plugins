#pragma once

#include "PrecompiledHeader.h"



namespace ConsoleCommandCompanion
{
	class Settings
	{
	public:
		class Button
		{
		public:
			class State
			{
			public:
				class Filter
				{
				public:
					Filter&        Deserialize(const nlohmann::json& jsonFilter);
					nlohmann::json Serialize() const;

					std::optional<std::uint32_t> inputDevice{};
					std::optional<std::uint32_t> idCode{};
					std::optional<std::string>   userEvent{};
				};

				State&         Deserialize(const nlohmann::json& jsonState);
				nlohmann::json Serialize() const;

				std::vector<std::string> consoleCommands{};
				std::vector<Filter>      filters{};
			};

			Button&        Deserialize(const nlohmann::json& jsonButton);
			nlohmann::json Serialize() const;

			bool               log{ false };
			std::vector<State> pressed{};
			std::vector<State> released{};
		};

		class Initialize
		{
		public:
			Initialize&    Deserialize(const nlohmann::json& jsonInitialize);
			nlohmann::json Serialize() const;

			std::vector<std::string> consoleCommands{};
		};

		class LoadGame
		{
		public:
			LoadGame&      Deserialize(const nlohmann::json& jsonLoadGame);
			nlohmann::json Serialize() const;

			std::vector<std::string> consoleCommands{};
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

		Initialize initialize{};
		LoadGame   loadGame{};
		Button     button{};
	};
}
