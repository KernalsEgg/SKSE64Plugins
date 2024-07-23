#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BaseExtraList.h"

#include "Shared/Skyrim/B/BSExtraData.h"



namespace Skyrim
{
	bool BaseExtraList::PresenceBitField::HasExtraData(Utility::Enumeration<ExtraDataType, std::uint32_t> extraDataType) const
	{
		std::uint32_t index = extraDataType.underlying() >> 3; // Divide by 8

		if (index < sizeof(PresenceBitField))
		{
			std::uint8_t bitMask = 1 << (extraDataType.underlying() % 8);

			return (bitMask & this->bitField_[index]) != 0;
		}

		return false;
	}

	BaseExtraList::~BaseExtraList()
	{
		auto* next = this->extraData;

		while (next)
		{
			auto* current = next;
			next          = current->next;

			delete current;
		}

		this->extraData = nullptr;

		delete this->presenceBitField;

		this->presenceBitField = nullptr;
	}

	BSExtraData* BaseExtraList::GetExtraData(Utility::Enumeration<ExtraDataType, std::uint32_t> extraDataType)
	{
		if (!this->HasExtraData(extraDataType))
		{
			return nullptr;
		}

		for (auto* extraData = this->extraData; extraData; extraData = extraData->next)
		{
			if (extraData->GetExtraDataType() == extraDataType)
			{
				return extraData;
			}
		}

		return nullptr;
	}

	const BSExtraData* BaseExtraList::GetExtraData(Utility::Enumeration<ExtraDataType, std::uint32_t> extraDataType) const
	{
		if (!this->HasExtraData(extraDataType))
		{
			return nullptr;
		}

		for (auto* extraData = this->extraData; extraData; extraData = extraData->next)
		{
			if (extraData->GetExtraDataType() == extraDataType)
			{
				return extraData;
			}
		}

		return nullptr;
	}

	bool BaseExtraList::HasExtraData(Utility::Enumeration<ExtraDataType, std::uint32_t> extraDataType) const
	{
		return this->presenceBitField && this->presenceBitField->HasExtraData(extraDataType);
	}
}
