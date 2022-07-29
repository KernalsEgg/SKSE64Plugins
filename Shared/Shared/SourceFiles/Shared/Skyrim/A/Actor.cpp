#include "Shared/PCH.h"

#include "Shared/Skyrim/A/Actor.h"

#include "Shared/Skyrim/A/AIProcess.h"
#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/B/BipedAnim.h"
#include "Shared/Skyrim/E/ExtraDataList.h"
#include "Shared/Skyrim/I/InventoryEntryData.h"
#include "Shared/Skyrim/T/TESBoundObject.h"
#include "Shared/Skyrim/T/TESObjectARMO.h"
#include "Shared/Skyrim/T/TESObjectWEAP.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	bool Actor::AddSpell(SpellItem* spell)
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Actor::AddSpell)>::type>(Addresses::Actor::AddSpell) };

		return function(this, spell);
	}

	float Actor::GetActorValueModifier(Utility::Enumeration<ActorValueModifier, std::uint32_t> actorValueModifier, Utility::Enumeration<ActorValue, std::uint32_t> actorValue) const
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Actor::GetActorValueModifier)>::type>(Addresses::Actor::GetActorValueModifier) };

		return function(this, actorValueModifier, actorValue);
	}

	float Actor::GetArmorRating(InventoryEntryData* inventoryEntryData) const
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Actor::GetArmorRating)>::type>(Addresses::Actor::GetArmorRating) };

		return function(this, inventoryEntryData);
	}

	float Actor::GetWeaponDamage(InventoryEntryData* inventoryEntryData) const
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Actor::GetWeaponDamage)>::type>(Addresses::Actor::GetWeaponDamage) };

		return function(this, inventoryEntryData);
	}

	bhkCharacterController* Actor::GetCharacterController() const
	{
		auto* currentProcess = this->currentProcess;

		return currentProcess ? currentProcess->GetCharacterController() : nullptr;
	}

	InventoryEntryData* Actor::GetEquippedItem(bool leftHand) const
	{
		auto* currentProcess = this->currentProcess;

		return currentProcess ? currentProcess->GetEquippedItem(leftHand) : nullptr;
	}

	TESObjectARMO* Actor::GetEquippedShield() const
	{
		auto* thirdPersonBiped = this->GetThirdPersonBiped().get();

		if (!thirdPersonBiped)
		{
			return nullptr;
		}

		auto shieldObject = thirdPersonBiped->GetShieldObject();

		return shieldObject ? static_cast<TESObjectARMO*>(shieldObject->item) : nullptr;
	}

	TESObjectWEAP* Actor::GetEquippedWeapon(bool leftHand) const
	{
		auto* inventoryEntryData = this->GetEquippedItem(leftHand);

		if (!inventoryEntryData)
		{
			return nullptr;
		}

		auto* item = inventoryEntryData->item;

		return item && item->formType == FormType::kWeapon ? static_cast<TESObjectWEAP*>(item) : nullptr;
	}

	HitData* Actor::GetLastHitData() const
	{
		auto* currentProcess = this->currentProcess;

		return currentProcess ? currentProcess->GetLastHitData() : nullptr;
	}

	float Actor::GetMaximumWardPower() const
	{
		auto* currentProcess = this->currentProcess;

		return currentProcess ? currentProcess->GetMaximumWardPower() : -1.0F;
	}

	bool Actor::GetMount(NiPointer<Actor>& mount)
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Actor::GetMount)>::type>(Addresses::Actor::GetMount) };

		return function(this, mount);
	}

	bool Actor::GetMovementActor(NiPointer<Actor>& movementActor)
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Actor::GetMovementActor)>::type>(Addresses::Actor::GetMovementActor) };

		return function(this, movementActor);
	}

	SoulLevel Actor::GetSoulLevel() const
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Actor::GetSoulLevel)>::type>(Addresses::Actor::GetSoulLevel) };

		return function(this);
	}

	bool Actor::IsDualCasting() const
	{
		auto* currentProcess = this->currentProcess;

		return currentProcess ? currentProcess->IsDualCasting() : false;
	}

	TESObjectREFR::Height Actor::IsInViewCone(TESObjectREFR* target, float viewCone) const
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Actor::IsInViewCone)>::type>(Addresses::Actor::IsInViewCone) };

		return function(this, target, viewCone);
	}

	bool Actor::IsNPC() const
	{
		auto* currentProcess = this->currentProcess;

		if (!currentProcess)
		{
			return this->UpdateIsNPC();
		}

		auto* cachedValues = currentProcess->cachedValues;

		if (!cachedValues)
		{
			return this->UpdateIsNPC();
		}

		return cachedValues->flags.all(CachedValues::Flags::kNPC) ? cachedValues->booleanValues.all(CachedValues::BooleanValues::kNPC) : this->UpdateIsNPC();
	}

	bool Actor::IsOnMount() const
	{
		if (this->booleanFlags.all(BooleanFlags::kIsMount))
		{
			return false;
		}

		return this->extraDataList.HasType(ExtraDataType::kInteraction);
	}

	bool Actor::IsPlayerTeammate() const
	{
		return this->booleanBits.all(BooleanBits::kPlayerTeammate);
	}

	void Actor::ModifyActorValue(Utility::Enumeration<ActorValue, std::uint32_t> actorValue, float previousValue, float deltaValue, Actor* source)
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Actor::ModifyActorValue)>::type>(Addresses::Actor::ModifyActorValue) };

		function(this, actorValue, previousValue, deltaValue, source);
	}

	void Actor::RemoveActorValueModifiers(Utility::Enumeration<ActorValue, std::uint32_t> actorValue)
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Actor::RemoveActorValueModifiers)>::type>(Addresses::Actor::RemoveActorValueModifiers) };

		function(this, actorValue);
	}

	void Actor::RemoveBasePerks()
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Actor::RemoveBasePerks)>::type>(Addresses::Actor::RemoveBasePerks) };

		function(this);
	}

	void Actor::RevertSelectedSpell(Utility::Enumeration<SlotType, std::uint32_t> slotType, MagicItem* selectedSpell)
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Actor::RevertSelectedSpell)>::type>(Addresses::Actor::RevertSelectedSpell) };

		function(this, slotType, selectedSpell);
	}

	void Actor::SetMaximumWardPower(float maximumWardPower)
	{
		auto* currentProcess = this->currentProcess;

		if (!currentProcess)
		{
			return;
		}

		currentProcess->SetMaximumWardPower(maximumWardPower);
	}
}
