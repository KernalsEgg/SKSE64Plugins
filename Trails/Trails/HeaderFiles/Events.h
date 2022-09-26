#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSFootstepEvent.h"
#include "Shared/Skyrim/B/BSTEventSink.h"
#include "Shared/Skyrim/B/BSTEventSource.h"



namespace Trails::Events
{
	class FootstepEventSink :
		public Skyrim::BSTEventSink<Skyrim::BGSFootstepEvent> // 0
	{
	public:
		FootstepEventSink()                         = default;
		FootstepEventSink(const FootstepEventSink&) = delete;
		FootstepEventSink(FootstepEventSink&&)      = delete;

		FootstepEventSink& operator=(const FootstepEventSink&) = delete;
		FootstepEventSink& operator=(FootstepEventSink&&)      = delete;

		// Override
		virtual ~FootstepEventSink() override = default; // 0

		// Override (BSTEventSink<BGSFootstepEvent>)
		virtual Skyrim::BSEventNotifyControl ProcessEvent(const Skyrim::BGSFootstepEvent* eventArguments, Skyrim::BSTEventSource<Skyrim::BGSFootstepEvent>* eventSource) override; // 1

		// Non-member functions
		static FootstepEventSink& GetSingleton();
	};
}
