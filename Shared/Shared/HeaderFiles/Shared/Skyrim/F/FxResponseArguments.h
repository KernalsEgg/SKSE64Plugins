#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/F/FxResponseArgumentsBase.h"
#include "Shared/Skyrim/G/GFxValue.h"



namespace Skyrim
{
	template <std::int32_t Count>
	class FxResponseArguments :
		public FxResponseArgumentsBase // 0
	{
	public:
		FxResponseArguments() :
			index_(1)
		{
		}

		// Member functions
		void Add(const GFxValue& value)
		{
			if (this->index_ > Count)
			{
				return;
			}

			this->values_[this->index_++] = value;
		}

		std::uint32_t GetValues(GFxValue** parameters)
		{
			*parameters = this->values_;

			return this->index_;
		}

	private:
		// Member variables
		GFxValue      values_[Count + 1]; // 0
		std::uint32_t index_;             // ?
	};
	static_assert(sizeof(FxResponseArguments<1>) == 0x40);
}
