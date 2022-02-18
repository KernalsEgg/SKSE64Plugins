#include "Shared/PCH.h"

#include "Shared/Skyrim/A/Actor.h"

#include "Shared/Skyrim/A/ActorProcess.h"
#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/E/ExtraDataList.h"
#include "Shared/Skyrim/E/ExtraDataType.h"
#include "Shared/Skyrim/M/MiddleHighProcessData.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	bool Actor::AddSpell(SpellItem* spell)
	{
		auto function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Actor::AddSpell)>::type>(Addresses::Actor::AddSpell) };

		return function(this, spell);
	}

	float Actor::GetActorValueModifier(Utility::Enumeration<ActorValueModifier, std::uint32_t> actorValueModifier, Utility::Enumeration<ActorValue, std::uint32_t> actorValue) const
	{
		auto function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Actor::GetActorValueModifier)>::type>(Addresses::Actor::GetActorValueModifier) };

		return function(this, actorValueModifier, actorValue);
	}

	float Actor::GetMaximumWardPower() const
	{
		auto currentProcess = this->currentProcess;

		if (!currentProcess)
		{
			return -1.0F;
		}

		auto middleHighProcessData = currentProcess->middleHighProcessData;

		if (!middleHighProcessData)
		{
			return -1.0F;
		}

		return middleHighProcessData->maximumWardPower;
	}

	bool Actor::GetMount(NiPointer<Actor>& mount)
	{
		auto function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Actor::GetMount)>::type>(Addresses::Actor::GetMount) };

		return function(this, mount);
	}

	bool Actor::GetMovementActor(NiPointer<Actor>& movementActor)
	{
		auto function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Actor::GetMovementActor)>::type>(Addresses::Actor::GetMovementActor) };

		return function(this, movementActor);
	}

	bool Actor::IsOnMount() const
	{
		if (this->boolFlags.all(BoolFlags::kIsMount))
		{
			return false;
		}

		return this->extraDataList.HasType(ExtraDataType::kInteraction);
	}

	bool Actor::IsPlayerTeammate() const
	{
		return this->boolBits.all(BoolBits::kPlayerTeammate);
	}

	void Actor::ModifyActorValue(Utility::Enumeration<ActorValue, std::uint32_t> actorValue, float previousValue, float difference, Actor* source)
	{
		auto function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Actor::ModifyActorValue)>::type>(Addresses::Actor::ModifyActorValue) };

		function(this, actorValue, previousValue, difference, source);
	}

	void Actor::RemoveActorValueModifiers(Utility::Enumeration<ActorValue, std::uint32_t> actorValue)
	{
		auto function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Actor::RemoveActorValueModifiers)>::type>(Addresses::Actor::RemoveActorValueModifiers) };

		function(this, actorValue);
	}

	void Actor::RevertSelectedSpell(Utility::Enumeration<SlotType, std::uint32_t> slotType, MagicItem* selectedSpell)
	{
		auto function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Actor::RevertSelectedSpell)>::type>(Addresses::Actor::RevertSelectedSpell) };

		function(this, slotType, selectedSpell);
	}

	void Actor::SetMaximumWardPower(float maximumWardPower)
	{
		auto currentProcess = this->currentProcess;

		if (!currentProcess)
		{
			return;
		}

		auto middleHighProcessData = currentProcess->middleHighProcessData;

		if (!middleHighProcessData)
		{
			return;
		}

		middleHighProcessData->maximumWardPower = maximumWardPower;
	}
}
