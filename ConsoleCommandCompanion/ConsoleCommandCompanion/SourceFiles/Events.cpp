#include "PCH.h"

#include "Events.h"

#include "Settings.h"
#include "Shared/SKSE/Interfaces.h"
#include "Shared/Skyrim/B/ButtonEvent.h"
#include "Shared/Skyrim/S/Script.h"
#include "Shared/Utility/Log.h"



namespace ConsoleCommandCompanion::Events
{
	Skyrim::BSEventNotifyControl ButtonEventSink::ProcessEvent(Skyrim::InputEvent* const* eventArguments, Skyrim::BSTEventSource<Skyrim::InputEvent*>* eventSource)
	{
		if (!eventArguments)
		{
			return Skyrim::BSEventNotifyControl::kContinue;
		}

		for (auto inputEvent = *eventArguments; inputEvent; inputEvent = inputEvent->next)
		{
			switch (inputEvent->inputEventType.get())
			{
				case Skyrim::InputEvent::Type::kButton:
				{
					auto buttonEvent = static_cast<Skyrim::ButtonEvent*>(inputEvent);

					if (buttonEvent->IsPressed())
					{
						if (Settings::GetSingleton().log)
						{
							Utility::Log::Information("Pressed, ID Code: {}, Input Device: {}, User Event: {}", buttonEvent->idCode, buttonEvent->inputDevice.underlying(), buttonEvent->GetUserEvent());
						}

						for (const auto& pressed : Settings::GetSingleton().events.button.pressed)
						{
							if (pressed.idCode.has_value() && buttonEvent->idCode != pressed.idCode.value())
							{
								continue;
							}

							if (pressed.inputDevice.has_value() && buttonEvent->inputDevice != pressed.inputDevice.value())
							{
								continue;
							}

							if (pressed.userEvent.has_value() && static_cast<std::string_view>(buttonEvent->GetUserEvent()) != pressed.userEvent.value())
							{
								continue;
							}

							for (const auto& consoleCommand : pressed.consoleCommands)
							{
								SKSE::Cache::GetSingleton().GetTaskInterface()->AddTask(
									[consoleCommand]()
									{
										Skyrim::Script::ExecuteCommand(consoleCommand);
									});
							}
						}
					}
					else if (buttonEvent->IsReleased())
					{
						if (Settings::GetSingleton().log)
						{
							Utility::Log::Information("Released, ID Code: {}, Input Device: {}, User Event: {}", buttonEvent->idCode, buttonEvent->inputDevice.underlying(), buttonEvent->GetUserEvent());
						}

						for (const auto& released : Settings::GetSingleton().events.button.released)
						{
							if (released.idCode.has_value() && buttonEvent->idCode != released.idCode.value())
							{
								continue;
							}

							if (released.inputDevice.has_value() && buttonEvent->inputDevice != released.inputDevice.value())
							{
								continue;
							}

							if (released.userEvent.has_value() && static_cast<std::string_view>(buttonEvent->GetUserEvent()) != released.userEvent.value())
							{
								continue;
							}

							for (const auto& consoleCommand : released.consoleCommands)
							{
								SKSE::Cache::GetSingleton().GetTaskInterface()->AddTask(
									[consoleCommand]()
									{
										Skyrim::Script::ExecuteCommand(consoleCommand);
									});
							}
						}
					}

					break;
				}
			}
		}

		return Skyrim::BSEventNotifyControl::kContinue;
	}

	ButtonEventSink* ButtonEventSink::GetSingleton()
	{
		static ButtonEventSink singleton;

		return std::addressof(singleton);
	}

	Skyrim::BSEventNotifyControl LoadGameEventSink::ProcessEvent(const Skyrim::TESLoadGameEvent* eventArguments, Skyrim::BSTEventSource<Skyrim::TESLoadGameEvent>* eventSource)
	{
		for (const auto& consoleCommand : Settings::GetSingleton().events.loadGame.consoleCommands)
		{
			SKSE::Cache::GetSingleton().GetTaskInterface()->AddTask(
				[consoleCommand]()
				{
					Skyrim::Script::ExecuteCommand(consoleCommand);
				});
		}

		return Skyrim::BSEventNotifyControl::kContinue;
	}

	LoadGameEventSink* LoadGameEventSink::GetSingleton()
	{
		static LoadGameEventSink singleton;

		return std::addressof(singleton);
	}
}
