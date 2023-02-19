#include "PrecompiledHeader.h"

#include "Events.h"

#include "ImpactManager.h"
#include "Settings.h"



namespace Trails::Events
{
	Skyrim::EventNotifyControl FootstepEventSink::ProcessEvent(const Skyrim::BGSFootstepEvent* eventArguments, Skyrim::BSTEventSource<Skyrim::BGSFootstepEvent>* eventSource)
	{
		if (!eventArguments)
		{
			return Skyrim::EventNotifyControl::kContinue;
		}

		auto        actorHandle = eventArguments->actor;
		std::string tag         = eventArguments->tag.data();

		SKSE::Storage::GetSingleton().GetTaskInterface()->AddTask(
			[actorHandle, tag]()
			{
				auto* actor = actorHandle.get().get();

				if (!actor)
				{
					return;
				}

				for (const auto& footsteps : Settings::GetSingleton().footsteps)
				{
					if (!footsteps.first)
					{
						continue;
					}

					if (!footsteps.first->matchConditions.IsTrue(actor, nullptr))
					{
						continue;
					}

					for (const auto& footstep : footsteps.second)
					{
						if (!footstep.tags.contains(tag))
						{
							continue;
						}

						for (const auto& arguments : footstep.arguments)
						{
							ImpactManager::PlayImpactEffect(actor, arguments);
						}
					}
				}
			});

		return Skyrim::EventNotifyControl::kContinue;
	}

	FootstepEventSink& FootstepEventSink::GetSingleton()
	{
		static FootstepEventSink singleton;

		return singleton;
	}
}
