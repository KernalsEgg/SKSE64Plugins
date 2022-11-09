#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSPointerHandle.h"
#include "Shared/Skyrim/B/BSTSmartPointer.h"
#include "Shared/Skyrim/N/NiPointer.h"
#include "Shared/Skyrim/S/SyncQueueObj.h"



namespace Skyrim
{
	class Actor;
	class BGSLoadFormBuffer;
	class BGSSaveFormBuffer;
	class TESActionData;

	class RefrInteraction :
		public SyncQueueObj // 0
	{
	public:
		// Override
		virtual ~RefrInteraction() override; // 0

		// Add
		virtual ActorHandle   GetTargetActorHandle() const;                                                                  // 2
		virtual std::uint32_t GetInteractMethod() const      = 0;                                                            // 3
		virtual bool          CanInteractionTeleport() const = 0;                                                            // 4
		virtual std::uint32_t GetFurnitureMarkerIndex() const;                                                               // 5
		virtual void          AssignInteractionImplementation(const BSTSmartPointer<RefrInteraction>& referenceInteraction); // 6
		virtual void          Unknown7(RefrInteraction*);                                                                    // 7
		virtual std::uint32_t SynchronizeImplementation();                                                                   // 8
		virtual bool          DesynchronizeImplementation(bool continueAnimation, bool desynchronize);                       // 9
		virtual void          SaveGameImplementation(BGSSaveFormBuffer* saveFormBuffer);                                     // A
		virtual bool          LoadGameImplementation(BGSLoadFormBuffer* loadFormBuffer);                                     // B
		virtual void          FinishLoadGameImplementation();                                                                // C
		virtual void          UnknownD(RefrInteraction*)                                               = 0;                  // D
		virtual std::uint32_t BeginInteractionImplementation(TESActionData& actionData, bool finalize) = 0;                  // E
		virtual bool          EndInteractionImplementation(TESActionData& actionData, bool finalize)   = 0;                  // F

		// Member functions
		bool GetActor(NiPointer<Actor>& actor) const;
		bool GetTargetActor(NiPointer<Actor>& targetActor) const;

		// Member variables
		ObjectReferenceHandle targetHandle; // 10, Mount
		ActorHandle           actorHandle;  // 14, Rider
		bool                  synchronized; // 18
		std::uint8_t          padding19;    // 19
		std::uint16_t         padding1A;    // 1A
		std::uint32_t         padding1C;    // 1C
	};
	static_assert(offsetof(RefrInteraction, targetHandle) == 0x10);
	static_assert(offsetof(RefrInteraction, actorHandle) == 0x14);
	static_assert(offsetof(RefrInteraction, synchronized) == 0x18);
	static_assert(sizeof(RefrInteraction) == 0x20);
}
