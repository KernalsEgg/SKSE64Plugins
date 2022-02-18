#include "Shared/PCH.h"

#include "Shared/Skyrim/E/ExtraDataList.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/B/BSExtraData.h"
#include "Shared/Skyrim/E/ExtraCharge.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	bool ExtraDataList::PresenceBitField::HasType(std::uint32_t type) const
	{
		std::uint32_t index = type >> 3;

		if (index < sizeof(PresenceBitField))
		{
			std::uint8_t bitMask = 1 << (type & 7);

			return (bitMask & this->bitField_[index]) != 0;
		}

		return false;
	}

	float ExtraDataList::GetCharge() const
	{
		auto extraCharge = this->GetType<ExtraCharge>(ExtraDataType::kCharge);

		return extraCharge != nullptr ? extraCharge->charge : -1.0F;
	}

	BSExtraData* ExtraDataList::GetType(Utility::Enumeration<ExtraDataType, std::uint32_t> extraDataType)
	{
		BSReadLockGuard readLockGuard(this->lock_);

		if (!this->HasType(extraDataType))
		{
			return nullptr;
		}

		for (auto extraData = this->extraData_; extraData != nullptr; extraData = extraData->next)
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

		for (auto extraData = this->extraData_; extraData != nullptr; extraData = extraData->next)
		{
			if (extraData->GetType() == extraDataType)
			{
				return extraData;
			}
		}

		return nullptr;
	}

	bool ExtraDataList::HasType(Utility::Enumeration<ExtraDataType, std::uint32_t> extraDataType) const
	{
		BSReadLockGuard readLockGuard(this->lock_);

		return this->presenceBitField_ != nullptr && this->presenceBitField_->HasType(extraDataType.underlying());
	}

	bool ExtraDataList::IsQuestItem() const
	{
		auto function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&ExtraDataList::IsQuestItem)>::type>(Addresses::ExtraDataList::IsQuestItem) };

		return function(this);
	}

	bool ExtraDataList::IsWorn() const
	{
		return this->HasType(ExtraDataType::kWorn) || this->HasType(ExtraDataType::kWornLeft);
	}
}
