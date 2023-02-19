#pragma once

#include "PrecompiledHeader.h"

#include "Settings.h"



namespace ConsoleCommandCompanion
{
	class Events
	{
	public:
		class InitializeEventSink
		{
		public:
			static void RegisterSink();
			static void ProcessEvent();
		};

		class LoadGameEventSink :
			public Skyrim::BSTEventSink<Skyrim::TESLoadGameEvent>
		{
		public:
			virtual ~LoadGameEventSink() override = default;
			virtual Skyrim::EventNotifyControl ProcessEvent(const Skyrim::TESLoadGameEvent* eventArguments, Skyrim::BSTEventSource<Skyrim::TESLoadGameEvent>* eventSource) override;

			static LoadGameEventSink& GetSingleton();

			void RegisterSink();
		};

		class ButtonEventSink :
			public Skyrim::BSTEventSink<Skyrim::InputEvent*>
		{
		public:
			virtual ~ButtonEventSink() override = default;
			virtual Skyrim::EventNotifyControl ProcessEvent(Skyrim::InputEvent* const* eventArguments, Skyrim::BSTEventSource<Skyrim::InputEvent*>* eventSource) override;

			static ButtonEventSink& GetSingleton();

			void RegisterSink();

		private:
			static bool IsPressed(Skyrim::InputEvent* inputEvents, const Settings::Events::Button::State::Filter& filter);
			static bool IsPressing(Skyrim::InputEvent* inputEvents, const Settings::Events::Button::State::Filter& filter);
			static bool IsReleased(Skyrim::InputEvent* inputEvents, const Settings::Events::Button::State::Filter& filter);
			static void Log(Skyrim::InputEvent* inputEvents);
		};

		static void ExecuteConsoleCommands(const std::vector<std::string>& consoleCommands);
	};
}
