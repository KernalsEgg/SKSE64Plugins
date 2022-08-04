#include "Shared/PCH.h"

#include "Shared/Skyrim/E/ExtraDataList.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/B/BSExtraData.h"
#include "Shared/Skyrim/E/ExtraCharge.h"
#include "Shared/Skyrim/E/ExtraCount.h"
#include "Shared/Skyrim/E/ExtraHealth.h"
#include "Shared/Skyrim/E/ExtraSoul.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	bool ExtraDataList::PresenceBitField::HasType(std::uint32_t type) const
	{
		std::uint32_t index = type >> 3; // Divide by 8

		if (index < sizeof(PresenceBitField))
		{
			std::uint8_t bitMask = 1 << (type % 8); // Modulus of 8

			return (bitMask & this->bitField_[index]) != 0;
		}

		return false;
	}

	ExtraDataList::~ExtraDataList()
	{
		auto* next = this->extraData_;

		while (next)
		{
			auto* current = next;
			next          = current->next;

			delete current;
		}

		this->extraData_ = nullptr;

		delete this->presenceBitField_;

		this->presenceBitField_ = nullptr;
	}

	float ExtraDataList::GetCharge() const
	{
		const auto* extraCharge = this->GetType<ExtraCharge>(ExtraDataType::kCharge);

		return extraCharge ? extraCharge->charge : -1.0F;
	}

	std::int16_t ExtraDataList::GetCount() const
	{
		const auto* extraCount = this->GetType<ExtraCount>(ExtraDataType::kCount);

		return extraCount ? extraCount->count : 1;
	}

	float ExtraDataList::GetHealth() const
	{
		const auto* extraHealth = this->GetType<ExtraHealth>(ExtraDataType::kHealth);

		return extraHealth ? extraHealth->health : -1.0F;
	}

	BSExtraData* ExtraDataList::GetType(Utility::Enumeration<ExtraDataType, std::uint32_t> extraDataType)
	{
		BSReadLockGuard readLockGuard(this->lock_);

		if (!this->HasType(extraDataType))
		{
			return nullptr;
		}

		for (auto* extraData = this->extraData_; extraData; extraData = extraData->next)
		{
			if (extraData->GetType() == extraDataType)
			{
				return extraData;
			}
		}

		return nullptr;
	}

	const BSExtraData* ExtraDataList::GetType(Utility::Enumeration<ExtraDataType, std::uint32_t> extraDataType) const
	{
		BSReadLockGuard readLockGuard(this->lock_);

		if (!this->HasType(extraDataType))
		{
			return nullptr;
		}

		for (auto* extraData = this->extraData_; extraData; extraData = extraData->next)
		{
			if (extraData->GetType() == extraDataType)
			{
				return extraData;
			}
		}

		return nullptr;
	}

	SoulLevel ExtraDataList::GetSoulLevel() const
	{
		const auto* extraSoul = this->GetType<ExtraSoul>(ExtraDataType::kSoul);

		return extraSoul ? extraSoul->soul.get() : SoulLevel::kNone;
	}

	bool ExtraDataList::HasType(Utility::Enumeration<ExtraDataType, std::uint32_t> extraDataType) const
	{
		BSReadLockGuard readLockGuard(this->lock_);

		return this->presenceBitField_ && this->presenceBitField_->HasType(extraDataType.underlying());
	}

	bool ExtraDataList::IsQuestItem() const
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&ExtraDataList::IsQuestItem)>::type>(Addresses::ExtraDataList::IsQuestItem) };

		return function(this);
	}

	bool ExtraDataList::IsWorn(bool eitherHand, bool leftHand) const
	{
		if (eitherHand)
		{
			return this->HasType(ExtraDataType::kWorn) || this->HasType(ExtraDataType::kWornLeft);
		}
		else if (leftHand)
		{
			return this->HasType(ExtraDataType::kWornLeft);
		}
		else
		{
			return this->HasType(ExtraDataType::kWorn);
		}
	}

	bool ExtraDataList::ShouldItemStack(bool stackWorn) const
	{
		BSReadLockGuard readLockGuard(this->lock_);

		for (const auto& extraData : *this)
		{
			switch (extraData.GetType())
			{
				case ExtraDataType::kWorn:
				case ExtraDataType::kWornLeft:
				{
					if (!stackWorn)
					{
						return false;
					}
				}
				case ExtraDataType::kReferenceHandle:
				case ExtraDataType::kOriginalReference:
				case ExtraDataType::kOwnership:
				case ExtraDataType::kCount:
				case ExtraDataType::kTimeLeft:
				case ExtraDataType::kLeveledItem:
				case ExtraDataType::kScale:
				case ExtraDataType::kHotkey:
				case ExtraDataType::kAliasInstanceArray:
				case ExtraDataType::kOutfitItem:
				case ExtraDataType::kFromAlias:
				case ExtraDataType::kShouldWear:
				case ExtraDataType::kUniqueID:
				{
					break;
				}
				default:
				{
					return false;
				}
			}
		}

		return true;
	}
}
