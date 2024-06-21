#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/R/RefrInteraction.h"



namespace Skyrim
{
	class Actor;
	class BSAnimationGraphChannel;

	class MountInteraction :
		public RefrInteraction // 0
	{
	public:
		// Override
		virtual ~MountInteraction() override; // 0

		// Override (RefrInteraction)
		virtual std::uint32_t QueuedSynchronization() override;                                                                       // 1
		virtual ActorHandle   GetTargetActorHandle() const override;                                                                  // 2
		virtual std::uint32_t GetInteractMethod() const override;                                                                     // 3
		virtual bool          CanInteractionTeleport() const override;                                                                // 4
		virtual void          AssignInteractionImplementation(const BSTSmartPointer<RefrInteraction>& referenceInteraction) override; // 6
		virtual std::uint32_t SynchronizeImplementation() override;                                                                   // 8
		virtual bool          DesynchronizeImplementation(bool continueAnimation, bool desynchronize) override;                       // 9
		virtual void          FinishLoadGameImplementation() override;                                                                // C
		virtual void          UnknownD(RefrInteraction*) override;                                                                    // D
		virtual std::uint32_t BeginInteractionImplementation(TESActionData& actionData, bool finalize) override;                      // E
		virtual bool          EndInteractionImplementation(TESActionData& actionData, bool finalize) override;                        // F

		// Add
		virtual bool CanBeginInteractionImplementation(Actor* actor); // 10

		// Member variables
		BSTArray<BSTSmartPointer<BSAnimationGraphChannel>> animationGraphChannels; // 20
	};
	static_assert(offsetof(MountInteraction, animationGraphChannels) == 0x20);
	static_assert(sizeof(MountInteraction) == 0x38);
}
