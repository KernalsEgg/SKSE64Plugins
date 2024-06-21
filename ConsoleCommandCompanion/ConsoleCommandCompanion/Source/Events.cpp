#include "PrecompiledHeader.h"

#include "Events.h"



namespace ConsoleCommandCompanion
{
	void Events::InitializeEventSink::RegisterSink()
	{
		Skyrim::Events::InitializeThread::GetSingleton().After().RegisterSink(InitializeEventSink::ProcessEvent);
	}

	void Events::InitializeEventSink::ProcessEvent()
	{
		/* Create the Console menu to allow batch files to be run */
		if (!Skyrim::UI::GetSingleton()->IsMenuOpen(Skyrim::InterfaceStrings::GetSingleton()->console))
		{
			Skyrim::Console::ExecuteCommand(std::format("ShowMenu {}", Skyrim::InterfaceStrings::GetSingleton()->console.data()).c_str());
			Skyrim::Console::ExecuteCommand(std::format("HideMenu {}", Skyrim::InterfaceStrings::GetSingleton()->console.data()).c_str());
		}

		Events::ExecuteConsoleCommands(Settings::GetSingleton().initialize.consoleCommands);

		LoadGameEventSink::GetSingleton().RegisterSink();
		ButtonEventSink::GetSingleton().RegisterSink();
	}

	Skyrim::EventNotifyControl Events::LoadGameEventSink::ProcessEvent(const Skyrim::TESLoadGameEvent* eventArguments, Skyrim::BSTEventSource<Skyrim::TESLoadGameEvent>* eventSource)
	{
		Events::ExecuteConsoleCommands(Settings::GetSingleton().loadGame.consoleCommands);

		return Skyrim::EventNotifyControl::kContinue;
	}

	Events::LoadGameEventSink& Events::LoadGameEventSink::GetSingleton()
	{
		static LoadGameEventSink singleton;

		return singleton;
	}

	void Events::LoadGameEventSink::RegisterSink()
	{
		Skyrim::ScriptEventSourceHolder::GetSingleton()->GetEventSource<Skyrim::TESLoadGameEvent>()->RegisterSink(this);
	}

	Skyrim::EventNotifyControl Events::ButtonEventSink::ProcessEvent(Skyrim::InputEvent* const* eventArguments, Skyrim::BSTEventSource<Skyrim::InputEvent*>* eventSource)
	{
		if (!eventArguments)
		{
			return Skyrim::EventNotifyControl::kContinue;
		}

		const auto& settings = Settings::GetSingleton();

		if (settings.button.log)
		{
			ButtonEventSink::Log(*eventArguments);
		}

		for (const auto& pressed : settings.button.pressed)
		{
			auto iterator = std::find_if(
				pressed.filters.begin(),
				pressed.filters.end(),
				[eventArguments](const Settings::Button::State::Filter& filter)
				{
					return ButtonEventSink::IsPressed(*eventArguments, filter);
				});

			if (iterator != pressed.filters.end())
			{
				auto count = std::count_if(
					pressed.filters.begin(),
					pressed.filters.end(),
					[eventArguments](const Settings::Button::State::Filter& filter)
					{
						return ButtonEventSink::IsPressing(*eventArguments, filter);
					});

				if (count == pressed.filters.size())
				{
					Events::ExecuteConsoleCommands(pressed.consoleCommands);
				}
			}
		}

		for (const auto& released : settings.button.released)
		{
			auto iterator = std::find_if(
				released.filters.begin(),
				released.filters.end(),
				[eventArguments](const Settings::Button::State::Filter& filter)
				{
					return ButtonEventSink::IsReleased(*eventArguments, filter);
				});

			if (iterator != released.filters.end())
			{
				auto count = std::count_if(
					released.filters.begin(),
					released.filters.end(),
					[eventArguments](const Settings::Button::State::Filter& filter)
					{
						return ButtonEventSink::IsPressing(*eventArguments, filter) || ButtonEventSink::IsReleased(*eventArguments, filter);
					});

				if (count == released.filters.size())
				{
					Events::ExecuteConsoleCommands(released.consoleCommands);
				}
			}
		}

		return Skyrim::EventNotifyControl::kContinue;
	}

	Events::ButtonEventSink& Events::ButtonEventSink::GetSingleton()
	{
		static ButtonEventSink singleton;

		return singleton;
	}

	void Events::ButtonEventSink::RegisterSink()
	{
		Skyrim::BSInputDeviceManager::GetSingleton()->RegisterSink(this);
	}

	bool Events::ButtonEventSink::IsPressed(Skyrim::InputEvent* inputEvents, const Settings::Button::State::Filter& filter)
	{
		if (inputEvents)
		{
			for (const auto& inputEvent : *inputEvents)
			{
				switch (inputEvent.inputEventType.get())
				{
					case Skyrim::InputEvent::Type::kButton:
					{
						const auto& buttonEvent = static_cast<const Skyrim::ButtonEvent&>(inputEvent);

						if (buttonEvent.IsPressed())
						{
							if (filter.inputDevice.has_value() && filter.inputDevice.value() != buttonEvent.inputDevice)
							{
								continue;
							}

							if (filter.idCode.has_value() && filter.idCode.value() != buttonEvent.idCode)
							{
								continue;
							}

							if (filter.userEvent.has_value() && filter.userEvent.value() != buttonEvent.GetUserEvent())
							{
								continue;
							}

							return true;
						}

						break;
					}
				}
			}
		}

		return false;
	}

	bool Events::ButtonEventSink::IsPressing(Skyrim::InputEvent* inputEvents, const Settings::Button::State::Filter& filter)
	{
		if (inputEvents)
		{
			for (const auto& inputEvent : *inputEvents)
			{
				switch (inputEvent.inputEventType.get())
				{
					case Skyrim::InputEvent::Type::kButton:
					{
						const auto& buttonEvent = static_cast<const Skyrim::ButtonEvent&>(inputEvent);

						if (buttonEvent.IsPressing())
						{
							if (filter.inputDevice.has_value() && filter.inputDevice.value() != buttonEvent.inputDevice)
							{
								continue;
							}

							if (filter.idCode.has_value() && filter.idCode.value() != buttonEvent.idCode)
							{
								continue;
							}

							if (filter.userEvent.has_value() && filter.userEvent.value() != buttonEvent.GetUserEvent())
							{
								continue;
							}

							return true;
						}

						break;
					}
				}
			}
		}

		return false;
	}

	bool Events::ButtonEventSink::IsReleased(Skyrim::InputEvent* inputEvents, const Settings::Button::State::Filter& filter)
	{
		if (inputEvents)
		{
			for (const auto& inputEvent : *inputEvents)
			{
				switch (inputEvent.inputEventType.get())
				{
					case Skyrim::InputEvent::Type::kButton:
					{
						const auto& buttonEvent = static_cast<const Skyrim::ButtonEvent&>(inputEvent);

						if (buttonEvent.IsReleased())
						{
							if (filter.inputDevice.has_value() && filter.inputDevice.value() != buttonEvent.inputDevice)
							{
								continue;
							}

							if (filter.idCode.has_value() && filter.idCode.value() != buttonEvent.idCode)
							{
								continue;
							}

							if (filter.userEvent.has_value() && filter.userEvent.value() != buttonEvent.GetUserEvent())
							{
								continue;
							}

							return true;
						}

						break;
					}
				}
			}
		}

		return false;
	}

	void Events::ButtonEventSink::Log(Skyrim::InputEvent* inputEvents)
	{
		if (inputEvents)
		{
			for (const auto& inputEvent : *inputEvents)
			{
				switch (inputEvent.inputEventType.get())
				{
					case Skyrim::InputEvent::Type::kButton:
					{
						const auto& buttonEvent = static_cast<const Skyrim::ButtonEvent&>(inputEvent);

						if (buttonEvent.IsPressed())
						{
							SPDLOG_INFO("Pressed, Input Device: {}, ID Code: {}, User Event: \"{}\"", buttonEvent.inputDevice.underlying(), buttonEvent.idCode, buttonEvent.GetUserEvent().data());
						}
						else if (buttonEvent.IsReleased())
						{
							SPDLOG_INFO("Released, Input Device: {}, ID Code: {}, User Event: \"{}\"", buttonEvent.inputDevice.underlying(), buttonEvent.idCode, buttonEvent.GetUserEvent().data());
						}

						break;
					}
				}
			}
		}
	}

	void Events::ExecuteConsoleCommands(const std::vector<std::string>& consoleCommands)
	{
		for (const auto& consoleCommand : consoleCommands)
		{
			SKSE::Storage::GetSingleton().GetTaskInterface()->AddTask(
				[consoleCommand]()
				{
					Skyrim::Console::ExecuteCommand(consoleCommand.c_str());
				});
		}
	}
}
