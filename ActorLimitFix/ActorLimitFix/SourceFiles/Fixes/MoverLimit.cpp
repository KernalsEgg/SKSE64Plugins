#include "PCH.h"

#include "Fixes/MoverLimit.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Memory.h"



namespace ActorLimitFix::Fixes
{
	void MoverLimit::Fix(std::uint32_t& moverLimit)
	{
		if (!Patterns::MoverLimit::CompareMoverLimit() ||
			!Patterns::MoverLimit::GetMoverLimit())
		{
			return;
		}

		Utility::Memory::SafeWrite(Addresses::MoverLimit::GetMoverLimit, std::optional<std::uint8_t>{}, moverLimit);
		Utility::Memory::SafeWrite(Addresses::MoverLimit::CompareMoverLimit, std::optional<std::uint8_t>{}, moverLimit);
	}
}
