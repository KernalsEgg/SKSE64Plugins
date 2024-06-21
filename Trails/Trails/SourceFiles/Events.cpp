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

				for (const auto& [conditions, footprints] : Settings::GetSingleton().footsteps)
				{
					if (!conditions)
					{
						continue;
					}

					if (!conditions->matchConditions.IsTrue(actor, actor))
					{
						continue;
					}

					auto footprintsRange = footprints.equal_range(tag);

					for (auto footprintsIterator = footprintsRange.first; footprintsIterator != footprintsRange.second; ++footprintsIterator)
					{
						ImpactManager::PlayImpactEffect(actor, footprintsIterator->second);
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
