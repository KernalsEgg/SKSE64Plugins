#pragma once

#include "PCH.h"

#include "Shared/Skyrim/B/BSTEventSink.h"
#include "Shared/Skyrim/B/BSTEventSource.h"
#include "Shared/Skyrim/I/InputEvent.h"
#include "Shared/Skyrim/T/TESLoadGameEvent.h"



namespace ConsoleCommandCompanion::Events
{
	class ButtonEventSink :
		public Skyrim::BSTEventSink<Skyrim::InputEvent*>
	{
	public:
		virtual ~ButtonEventSink() override = default;
		virtual Skyrim::BSEventNotifyControl ProcessEvent(Skyrim::InputEvent* const* eventArguments, Skyrim::BSTEventSource<Skyrim::InputEvent*>* eventSource) override;

		static ButtonEventSink* GetSingleton();
	};

	class LoadGameEventSink :
		public Skyrim::BSTEventSink<Skyrim::TESLoadGameEvent>
	{
	public:
		virtual ~LoadGameEventSink() override = default;
		virtual Skyrim::BSEventNotifyControl ProcessEvent(const Skyrim::TESLoadGameEvent* eventArguments, Skyrim::BSTEventSource<Skyrim::TESLoadGameEvent>* eventSource) override;

		static LoadGameEventSink* GetSingleton();
	};
}
