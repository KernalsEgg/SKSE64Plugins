#include "PrecompiledHeader.h"

#include "Settings.h"

#include "Shared/Relocation/Module.h"
#include "Shared/Utility/Log.h"



namespace ConsoleCommandCompanion
{
	Settings::Events::Button::State::Filter& Settings::Events::Button::State::Filter::Deserialize(const nlohmann::json& jsonFilter)
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

	nlohmann::json Settings::Events::Button::State::Filter::Serialize() const
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

	Settings::Events::Button::State& Settings::Events::Button::State::Deserialize(const nlohmann::json& jsonState)
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

	nlohmann::json Settings::Events::Button::State::Serialize() const
	{
		nlohmann::json jsonState;

		jsonState["consoleCommands"] = nlohmann::json(this->consoleCommands);

		for (const auto& filter : this->filters)
		{
			jsonState["filters"].push_back(filter.Serialize());
		}

		return jsonState;
	}

	Settings::Events::Button& Settings::Events::Button::Deserialize(const nlohmann::json& jsonButton)
	{
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

	nlohmann::json Settings::Events::Button::Serialize() const
	{
		nlohmann::json jsonButton;

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

	Settings::Events::Initialize& Settings::Events::Initialize::Deserialize(const nlohmann::json& jsonInitialize)
	{
		this->consoleCommands = jsonInitialize.at("consoleCommands").get<std::vector<std::string>>();

		return *this;
	}

	nlohmann::json Settings::Events::Initialize::Serialize() const
	{
		nlohmann::json jsonInitialize;

		jsonInitialize["consoleCommands"] = nlohmann::json(this->consoleCommands);

		return jsonInitialize;
	}

	Settings::Events::LoadGame& Settings::Events::LoadGame::Deserialize(const nlohmann::json& jsonLoadGame)
	{
		this->consoleCommands = jsonLoadGame.at("consoleCommands").get<std::vector<std::string>>();

		return *this;
	}

	nlohmann::json Settings::Events::LoadGame::Serialize() const
	{
		nlohmann::json jsonLoadGame;

		jsonLoadGame["consoleCommands"] = nlohmann::json(this->consoleCommands);

		return jsonLoadGame;
	}

	Settings::Events& Settings::Events::Deserialize(const nlohmann::json& jsonEvents)
	{
		if (jsonEvents.contains("initialize"))
		{
			this->initialize.Deserialize(jsonEvents.at("initialize"));
		}

		if (jsonEvents.contains("loadGame"))
		{
			this->loadGame.Deserialize(jsonEvents.at("loadGame"));
		}

		if (jsonEvents.contains("button"))
		{
			this->button.Deserialize(jsonEvents.at("button"));
		}

		return *this;
	}

	nlohmann::json Settings::Events::Serialize() const
	{
		nlohmann::json jsonEvents;

		jsonEvents["initialize"] = this->initialize.Serialize();
		jsonEvents["loadGame"]   = this->loadGame.Serialize();
		jsonEvents["button"]     = this->button.Serialize();

		return jsonEvents;
	}

	Settings::Settings(const std::filesystem::path& path)
	{
		try
		{
			this->Deserialize(nlohmann::json::parse(std::ifstream(path), nullptr, true, true));
		}
		catch (const nlohmann::json::exception& jsonException)
		{
			Utility::Log::Critical("{}", jsonException.what());

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
		if (jsonSettings.contains("log"))
		{
			this->log = jsonSettings.at("log").get<bool>();
		}

		if (jsonSettings.contains("events"))
		{
			this->events.Deserialize(jsonSettings.at("events"));
		}

		return *this;
	}

	nlohmann::json Settings::Serialize() const
	{
		nlohmann::json jsonSettings;

		jsonSettings["log"]    = this->log;
		jsonSettings["events"] = this->events.Serialize();

		return jsonSettings;
	}
}
