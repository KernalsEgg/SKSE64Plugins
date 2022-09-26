#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/ButtonEvent.h"



namespace Skyrim
{
	bool ButtonEvent::IsPressed() const
	{
		return this->value != 0.0F && this->holdDuration == 0.0F;
	}

	bool ButtonEvent::IsReleased() const
	{
		return this->value == 0.0F && this->holdDuration != 0.0F;
	}
}
