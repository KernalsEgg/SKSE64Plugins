#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/AttachTechniqueInput.h"

#include "Shared/Skyrim/N/NiNode.h"



namespace Skyrim
{
	namespace BSAttachTechniques
	{
		void AttachTechniqueInput::SetArtObjectRoot(NiNode* artObjectRoot)
		{
			this->artObjectRoot.reset(artObjectRoot);
		}

		void AttachTechniqueInput::SetAttachRoot(NiNode* attachRoot)
		{
			this->attachRoot.reset(attachRoot);
		}
	}
}
