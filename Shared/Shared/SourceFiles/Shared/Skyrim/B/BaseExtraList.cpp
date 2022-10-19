#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BaseExtraList.h"

#include "Shared/Skyrim/B/BSExtraData.h"



namespace Skyrim
{
	bool BaseExtraList::PresenceBitField::HasExtraData(Utility::Enumeration<ExtraDataType, std::uint32_t> type) const
	{
		std::uint32_t index = type.underlying() >> 3; // Divide by 8

		if (index < sizeof(PresenceBitField))
		{
			std::uint8_t bitMask = 1 << (type.underlying() % 8); // Modulus of 8

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

	bool BaseExtraList::HasExtraData(Utility::Enumeration<ExtraDataType, std::uint32_t> type) const
	{
		return this->presenceBitField && this->presenceBitField->HasExtraData(type);
	}

	BSExtraData* BaseExtraList::GetExtraData(Utility::Enumeration<ExtraDataType, std::uint32_t> type)
	{
		if (!this->HasExtraData(type))
		{
			return nullptr;
		}

		for (auto* extraData = this->extraData; extraData; extraData = extraData->next)
		{
			if (extraData->GetType() == type)
			{
				return extraData;
			}
		}

		return nullptr;
	}

	const BSExtraData* BaseExtraList::GetExtraData(Utility::Enumeration<ExtraDataType, std::uint32_t> type) const
	{
		if (!this->HasExtraData(type))
		{
			return nullptr;
		}

		for (auto* extraData = this->extraData; extraData; extraData = extraData->next)
		{
			if (extraData->GetType() == type)
			{
				return extraData;
			}
		}

		return nullptr;
	}
}
