#include "PCH.h"

#include "Events.h"

#include "ImpactManager.h"
#include "Settings.h"
#include "Shared/SKSE/Interfaces.h"



namespace Trails::Events
{
	Skyrim::BSEventNotifyControl FootstepEventSink::ProcessEvent(const Skyrim::BGSFootstepEvent* eventArguments, Skyrim::BSTEventSource<Skyrim::BGSFootstepEvent>* eventSource)
	{
		if (!eventArguments)
		{
			return Skyrim::BSEventNotifyControl::kContinue;
		}

		auto        actorHandle = eventArguments->actor;
		std::string tag         = eventArguments->tag.data();

		SKSE::Cache::GetSingleton().GetTaskInterface()->AddTask(
			[actorHandle, tag]()
			{
				auto actor = actorHandle.get().get();

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

		return Skyrim::BSEventNotifyControl::kContinue;
	}

	FootstepEventSink* FootstepEventSink::GetSingleton()
	{
		static FootstepEventSink singleton;

		return std::addressof(singleton);
	}
}
