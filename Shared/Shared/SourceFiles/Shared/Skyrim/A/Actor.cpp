#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/Actor.h"

#include "Shared/Skyrim/A/AIProcess.h"
#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/B/BipedAnim.h"
#include "Shared/Skyrim/E/ExtraDataList.h"
#include "Shared/Skyrim/I/InventoryEntryData.h"
#include "Shared/Skyrim/T/TESAmmo.h"
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

	bhkCharacterController* Actor::GetCharacterController() const
	{
		auto* currentProcess = this->currentProcess;

		return currentProcess ? currentProcess->GetCharacterController() : nullptr;
	}

	bool Actor::GetControllingActor(NiPointer<Actor>& controllingActor)
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Actor::GetControllingActor)>::type>(Addresses::Actor::GetControllingActor) };

		return function(this, controllingActor);
	}

	InventoryEntryData* Actor::GetEquippedAmmunitionInventoryEntryData() const
	{
		auto* currentProcess = this->currentProcess;

		if (!currentProcess)
		{
			return nullptr;
		}

		auto* inventoryEntryData = currentProcess->GetAmmunitionInventoryEntryData();

		if (!inventoryEntryData)
		{
			return nullptr;
		}

		auto* item = inventoryEntryData->item;

		return (item && item->formType == FormType::kAmmunition) ? inventoryEntryData : nullptr;
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
		auto* inventoryEntryData = this->GetEquippedWeaponInventoryEntryData(leftHand);

		return inventoryEntryData ? static_cast<TESObjectWEAP*>(inventoryEntryData->item) : nullptr;
	}

	InventoryEntryData* Actor::GetEquippedWeaponInventoryEntryData(bool leftHand) const
	{
		auto* currentProcess = this->currentProcess;

		if (!currentProcess)
		{
			return nullptr;
		}

		auto* inventoryEntryData = leftHand ? currentProcess->GetLeftHandInventoryEntryData() : currentProcess->GetRightHandInventoryEntryData();

		if (!inventoryEntryData)
		{
			return nullptr;
		}

		auto* item = inventoryEntryData->item;

		return (item && item->formType == FormType::kWeapon) ? inventoryEntryData : nullptr;
	}

	NiAVObject* Actor::GetHeadNode() const
	{
		auto* currentProcess = this->currentProcess;

		return currentProcess ? currentProcess->GetHeadNode() : nullptr;
	}

	HitData* Actor::GetLastHitData() const
	{
		auto* currentProcess = this->currentProcess;

		return currentProcess ? currentProcess->GetLastHitData() : nullptr;
	}

	NiPoint3& Actor::GetLineOfSightLocation(NiPoint3& result, Utility::Enumeration<LineOfSightLocation, std::uint32_t> lineOfSightLocation) const
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Actor::GetLineOfSightLocation)>::type>(Addresses::Actor::GetLineOfSightLocation) };

		return function(this, result, lineOfSightLocation);
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

	SoulLevel Actor::GetSoulLevel() const
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Actor::GetSoulLevel)>::type>(Addresses::Actor::GetSoulLevel) };

		return function(this);
	}

	NiAVObject* Actor::GetTorsoNode() const
	{
		auto* currentProcess = this->currentProcess;

		return currentProcess ? currentProcess->GetTorsoNode() : nullptr;
	}

	float Actor::GetWeaponDamage(InventoryEntryData* inventoryEntryData) const
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Actor::GetWeaponDamage)>::type>(Addresses::Actor::GetWeaponDamage) };

		return function(this, inventoryEntryData);
	}

	Actor::LineOfSightLocation Actor::IsActorInLineOfSight(Actor* target, float viewCone) const
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Actor::IsActorInLineOfSight)>::type>(Addresses::Actor::IsActorInLineOfSight) };

		return function(this, target, viewCone);
	}

	bool Actor::IsDualCasting() const
	{
		auto* currentProcess = this->currentProcess;

		return currentProcess ? currentProcess->IsDualCasting() : false;
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

		return this->extraDataList.HasExtraData(ExtraDataType::kInteraction);
	}

	bool Actor::IsPlayerTeammate() const
	{
		return this->booleanBits.all(BooleanBits::kPlayerTeammate);
	}

	NiAVObject* Actor::IsPositionInLineOfSight(const NiPoint3& target, NiPoint3& result, float viewCone) const
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Actor::IsPositionInLineOfSight)>::type>(Addresses::Actor::IsPositionInLineOfSight) };

		return function(this, target, result, viewCone);
	}

	bool Actor::IsReferenceInLineOfSight(TESObjectREFR* target, float viewCone) const
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Actor::IsReferenceInLineOfSight)>::type>(Addresses::Actor::IsReferenceInLineOfSight) };

		return function(this, target, viewCone);
	}

	bool Actor::IsSneaking() const
	{
		return this->ActorState::IsSneaking() && !this->ActorState::IsSwimming() && !this->IsOnMount();
	}

	void Actor::ModifyActorValue(Utility::Enumeration<ActorValue, std::uint32_t> actorValue, float oldValue, float deltaValue, Actor* source)
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Actor::ModifyActorValue)>::type>(Addresses::Actor::ModifyActorValue) };

		function(this, actorValue, oldValue, deltaValue, source);
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

	void Actor::SetMaximumWardPower(float maximumWardPower)
	{
		auto* currentProcess = this->currentProcess;

		if (!currentProcess)
		{
			return;
		}

		currentProcess->SetMaximumWardPower(maximumWardPower);
	}

	void Actor::SetSelectedSpell(Utility::Enumeration<MagicSystem::CastingSource, std::uint32_t> castingSource, MagicItem* selectedSpell)
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Actor::SetSelectedSpell)>::type>(Addresses::Actor::SetSelectedSpell) };

		function(this, castingSource, selectedSpell);
	}
}
