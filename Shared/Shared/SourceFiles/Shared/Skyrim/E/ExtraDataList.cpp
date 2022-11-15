#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/E/ExtraDataList.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/E/ExtraCharge.h"
#include "Shared/Skyrim/E/ExtraCount.h"
#include "Shared/Skyrim/E/ExtraHealth.h"
#include "Shared/Skyrim/E/ExtraInteraction.h"
#include "Shared/Skyrim/E/ExtraOwnership.h"
#include "Shared/Skyrim/E/ExtraPoison.h"
#include "Shared/Skyrim/E/ExtraSoul.h"
#include "Shared/Skyrim/R/RefrInteraction.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	float ExtraDataList::GetCharge() const
	{
		const auto* extraCharge = this->GetExtraData<ExtraCharge>(ExtraDataType::kCharge);

		return extraCharge ? extraCharge->charge : -1.0F;
	}

	std::int16_t ExtraDataList::GetCount() const
	{
		const auto* extraCount = this->GetExtraData<ExtraCount>(ExtraDataType::kCount);

		return extraCount ? extraCount->count : 1;
	}

	float ExtraDataList::GetHealth() const
	{
		const auto* extraHealth = this->GetExtraData<ExtraHealth>(ExtraDataType::kHealth);

		return extraHealth ? extraHealth->health : -1.0F;
	}

	bool ExtraDataList::GetInteraction(BSTSmartPointer<RefrInteraction>& referenceInteraction) const
	{
		const auto* extraInteraction = this->GetExtraData<ExtraInteraction>(ExtraDataType::kInteraction);

		if (extraInteraction)
		{
			referenceInteraction = extraInteraction->interaction;
		}
		else
		{
			referenceInteraction.reset();
		}

		return static_cast<bool>(referenceInteraction);
	}

	TESForm* ExtraDataList::GetOwner() const
	{
		const auto* extraOwnership = this->GetExtraData<ExtraOwnership>(ExtraDataType::kOwnership);

		return extraOwnership ? extraOwnership->owner : nullptr;
	}

	AlchemyItem* ExtraDataList::GetPoison() const
	{
		const auto* extraPoison = this->GetExtraData<ExtraPoison>(ExtraDataType::kPoison);

		return extraPoison ? extraPoison->poison : nullptr;
	}

	SoulLevel ExtraDataList::GetSoulLevel() const
	{
		const auto* extraSoul = this->GetExtraData<ExtraSoul>(ExtraDataType::kSoul);

		return extraSoul ? extraSoul->soul.get() : SoulLevel::kNone;
	}

	bool ExtraDataList::IsQuestItem() const
	{
		auto* function{ reinterpret_cast<Utility::TypeTraits::MakeFunctionPointer<decltype(&ExtraDataList::IsQuestItem)>::type>(Addresses::ExtraDataList::IsQuestItem) };

		return function(this);
	}

	bool ExtraDataList::IsWorn(bool eitherHand, bool leftHand) const
	{
		if (eitherHand)
		{
			return this->HasExtraData(ExtraDataType::kWorn) || this->HasExtraData(ExtraDataType::kWornLeft);
		}
		else if (leftHand)
		{
			return this->HasExtraData(ExtraDataType::kWornLeft);
		}
		else
		{
			return this->HasExtraData(ExtraDataType::kWorn);
		}
	}

	BSExtraData* ExtraDataList::GetExtraData(Utility::Enumeration<ExtraDataType, std::uint32_t> type)
	{
		BSReadLockGuard readLockGuard(this->lock_);

		return this->baseExtraList_.GetExtraData(type);
	}

	const BSExtraData* ExtraDataList::GetExtraData(Utility::Enumeration<ExtraDataType, std::uint32_t> type) const
	{
		BSReadLockGuard readLockGuard(this->lock_);

		return this->baseExtraList_.GetExtraData(type);
	}

	bool ExtraDataList::HasExtraData(Utility::Enumeration<ExtraDataType, std::uint32_t> type) const
	{
		BSReadLockGuard readLockGuard(this->lock_);

		return this->baseExtraList_.HasExtraData(type);
	}
}
