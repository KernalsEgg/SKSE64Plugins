#pragma once

#include "PCH.h"

#include "Shared/Skyrim/A/ActorValue.h"
#include "Shared/Utility/Enumeration.h"



namespace PowerAttackNotifications
{
	class Events
	{
	public:
		static bool Register();

	private:
		static void StartStaminaMeterBlinking(Utility::Enumeration<Skyrim::ActorValue, std::uint32_t> actorValue);

		static decltype(&Events::StartStaminaMeterBlinking) startStaminaMeterBlinking_;
	};
}
