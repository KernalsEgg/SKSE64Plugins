#include "Shared/PCH.h"

#include "Shared/Skyrim/A/ActorProcess.h"

#include "Shared/Skyrim/M/MiddleHighProcessData.h"



namespace Skyrim
{
	ObjectReferenceHandle ActorProcess::GetCurrentFurniture() const
	{
		auto middleHighProcessData = this->middleHighProcessData;

		if (middleHighProcessData)
		{
			return middleHighProcessData->currentFurniture;
		}
		else
		{
			return {};
		}
	}
}
