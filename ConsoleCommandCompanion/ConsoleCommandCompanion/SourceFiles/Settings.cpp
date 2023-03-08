#include "PrecompiledHeader.h"

#include "Settings.h"

#include "Shared/Relocation/Module.h"



namespace ConsoleCommandCompanion
{
	Settings::Button::State::Filter& Settings::Button::State::Filter::Deserialize(const nlohmann::json& jsonFilter)
	{
		if (jsonFilter.contains("inputDevice"))
		{
			this->inputDevice = jsonFilter.at("inputDevice").get<std::uint32_t>();
		}

		if (jsonFilter.contains("idCode"))
		{
			this->idCode = jsonFilter.at("idCode").get<std::uint32_t>();
		}

		if (jsonFilter.contains("userEvent"))
		{
			this->userEvent = jsonFilter.at("userEvent").get<std::string>();
		}

		return *this;
	}

	nlohmann::json Settings::Button::State::Filter::Serialize() const
	{
		nlohmann::json jsonFilter;

		if (this->inputDevice.has_value())
		{
			jsonFilter["inputDevice"] = this->inputDevice.value();
		}

		if (this->idCode.has_value())
		{
			jsonFilter["idCode"] = this->idCode.value();
		}

		if (this->userEvent.has_value())
		{
			jsonFilter["userEvent"] = this->userEvent.value();
		}

		return jsonFilter;
	}

	Settings::Button::State& Settings::Button::State::Deserialize(const nlohmann::json& jsonState)
	{
		this->consoleCommands = jsonState.at("consoleCommands").get<std::vector<std::string>>();

		std::vector<Filter> filters;

		for (const auto& jsonFilter : jsonState.at("filters"))
		{
			filters.push_back(Filter().Deserialize(jsonFilter));
		}

		this->filters = filters;

		return *this;
	}

	nlohmann::json Settings::Button::State::Serialize() const
	{
		nlohmann::json jsonState;

		jsonState["consoleCommands"] = this->consoleCommands;

		for (const auto& filter : this->filters)
		{
			jsonState["filters"].push_back(filter.Serialize());
		}

		return jsonState;
	}

	Settings::Button& Settings::Button::Deserialize(const nlohmann::json& jsonButton)
	{
		if (jsonButton.contains("log"))
		{
			this->log = jsonButton.at("log").get<bool>();
		}

		if (jsonButton.contains("pressed"))
		{
			std::vector<State> pressed;

			for (const auto& jsonPressed : jsonButton.at("pressed"))
			{
				pressed.push_back(State().Deserialize(jsonPressed));
			}

			this->pressed = pressed;
		}

		if (jsonButton.contains("released"))
		{
			std::vector<State> released;

			for (const auto& jsonReleased : jsonButton.at("released"))
			{
				released.push_back(State().Deserialize(jsonReleased));
			}

			this->released = released;
		}

		return *this;
	}

	nlohmann::json Settings::Button::Serialize() const
	{
		nlohmann::json jsonButton;

		jsonButton["log"] = this->log;

		for (const auto& pressed : this->pressed)
		{
			jsonButton["pressed"].push_back(pressed.Serialize());
		}

		for (const auto& released : this->released)
		{
			jsonButton["released"].push_back(released.Serialize());
		}

		return jsonButton;
	}

	Settings::Initialize& Settings::Initialize::Deserialize(const nlohmann::json& jsonInitialize)
	{
		this->consoleCommands = jsonInitialize.at("consoleCommands").get<std::vector<std::string>>();

		return *this;
	}

	nlohmann::json Settings::Initialize::Serialize() const
	{
		nlohmann::json jsonInitialize;

		jsonInitialize["consoleCommands"] = this->consoleCommands;

		return jsonInitialize;
	}

	Settings::LoadGame& Settings::LoadGame::Deserialize(const nlohmann::json& jsonLoadGame)
	{
		this->consoleCommands = jsonLoadGame.at("consoleCommands").get<std::vector<std::string>>();

		return *this;
	}

	nlohmann::json Settings::LoadGame::Serialize() const
	{
		nlohmann::json jsonLoadGame;

		jsonLoadGame["consoleCommands"] = this->consoleCommands;

		return jsonLoadGame;
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
		if (jsonSettings.contains("initialize"))
		{
			this->initialize.Deserialize(jsonSettings.at("initialize"));
		}

		if (jsonSettings.contains("loadGame"))
		{
			this->loadGame.Deserialize(jsonSettings.at("loadGame"));
		}

		if (jsonSettings.contains("button"))
		{
			this->button.Deserialize(jsonSettings.at("button"));
		}

		return *this;
	}

	nlohmann::json Settings::Serialize() const
	{
		nlohmann::json jsonSettings;

		jsonSettings["initialize"] = this->initialize.Serialize();
		jsonSettings["loadGame"]   = this->loadGame.Serialize();
		jsonSettings["button"]     = this->button.Serialize();

		return jsonSettings;
	}
}
