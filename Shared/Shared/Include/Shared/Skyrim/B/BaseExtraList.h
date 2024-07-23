#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Relocation/PreprocessorDirectives.h"
#include "Shared/Skyrim/E/ExtraDataType.h"
#include "Shared/Skyrim/M/MemoryManager.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class BSExtraData;

	class BaseExtraList
	{
	public:
		SKYRIM_MEMORY_REDEFINE_NEW();

		struct PresenceBitField
		{
		public:
			SKYRIM_MEMORY_REDEFINE_NEW();

			// Member functions
			bool HasExtraData(Utility::Enumeration<ExtraDataType, std::uint32_t> extraDataType) const;

		private:
			// Member variables
			std::uint8_t bitField_[0x17];
		};
		static_assert(sizeof(PresenceBitField) == 0x17);

#ifdef SKYRIM_ANNIVERSARY_EDITION
		// Add
		virtual ~BaseExtraList(); // 0
#else
		~BaseExtraList();
#endif

		BaseExtraList()                     = default;
		BaseExtraList(const BaseExtraList&) = delete;
		BaseExtraList(BaseExtraList&&)      = delete;

		BaseExtraList& operator=(const BaseExtraList&) = delete;
		BaseExtraList& operator=(BaseExtraList&&)      = delete;

		// Member functions
		BSExtraData*       GetExtraData(Utility::Enumeration<ExtraDataType, std::uint32_t> extraDataType);
		const BSExtraData* GetExtraData(Utility::Enumeration<ExtraDataType, std::uint32_t> extraDataType) const;
		bool               HasExtraData(Utility::Enumeration<ExtraDataType, std::uint32_t> extraDataType) const;

		// Member variables
		BSExtraData*      extraData{ nullptr };        // 0, 8
		PresenceBitField* presenceBitField{ nullptr }; // 8, 10
	};
	static_assert(offsetof(BaseExtraList, extraData) == SKYRIM_RELOCATE(0x0, 0x8));
	static_assert(offsetof(BaseExtraList, presenceBitField) == SKYRIM_RELOCATE(0x8, 0x10));
	static_assert(sizeof(BaseExtraList) == SKYRIM_RELOCATE(0x10, 0x18));
}
