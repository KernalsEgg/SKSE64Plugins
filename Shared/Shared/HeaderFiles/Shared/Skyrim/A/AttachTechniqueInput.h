#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/N/NiPointer.h"



namespace Skyrim
{
	class NiNode;

	namespace BSAttachTechniques
	{
		struct AttachTechniqueInput
		{
		public:
			// Add
			virtual ~AttachTechniqueInput();              // 0
			virtual void Unknown1(AttachTechniqueInput*); // 1

			// Member functions
			void SetArtObjectRoot(NiNode* artObjectRoot);
			void SetAttachRoot(NiNode* attachRoot);

			// Member variables
			NiPointer<NiNode> attachRoot;    // 8
			NiPointer<NiNode> artObjectRoot; // 10
			std::uint64_t     unknown18;     // 18
		};
		static_assert(offsetof(AttachTechniqueInput, attachRoot) == 0x8);
		static_assert(offsetof(AttachTechniqueInput, artObjectRoot) == 0x10);
		static_assert(sizeof(AttachTechniqueInput) == 0x20);
	}
}
