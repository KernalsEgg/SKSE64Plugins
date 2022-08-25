#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BaseFormComponent.h"



namespace Skyrim
{
	class BGSPerk;

	struct PerkRank
	{
	public:
		// Member variables
		BGSPerk*      perk;        // 0
		std::uint8_t  currentRank; // 8
		std::uint8_t  padding9;    // 9
		std::uint16_t paddingA;    // A
		std::uint32_t paddingC;    // C
	};
	static_assert(offsetof(PerkRank, perk) == 0x0);
	static_assert(offsetof(PerkRank, currentRank) == 0x8);
	static_assert(sizeof(PerkRank) == 0x10);

	class BGSPerkRankArray :
		public BaseFormComponent // 0
	{
	public:
		using size_type       = std::uint32_t;
		using value_type      = PerkRank;
		using pointer         = value_type*;
		using const_pointer   = const value_type*;
		using reference       = value_type&;
		using const_reference = const value_type&;
		using iterator        = pointer;
		using const_iterator  = const_pointer;

		// Override
		virtual ~BGSPerkRankArray() override; // 0

		// Override (BaseFormComponent)
		virtual void Unknown1(BaseFormComponent*) override; // 1
		virtual void Unknown2(BaseFormComponent*) override; // 2
		virtual void Unknown3(BaseFormComponent*) override; // 3

		// Iterators
		constexpr iterator       begin() noexcept { return this->data(); }
		constexpr const_iterator begin() const noexcept { return this->data(); }
		constexpr const_iterator cbegin() const noexcept { return this->begin(); }

		constexpr iterator       end() noexcept { return this->data() + this->size(); }
		constexpr const_iterator end() const noexcept { return this->data() + this->size(); }
		constexpr const_iterator cend() const noexcept { return this->end(); }

		// Element access
		constexpr reference       operator[](size_type index) noexcept { return this->data()[index]; }
		constexpr const_reference operator[](size_type index) const noexcept { return this->data()[index]; }

		constexpr pointer       data() noexcept { return this->perkRanks; }
		constexpr const_pointer data() const noexcept { return this->perkRanks; }

		constexpr reference       front() noexcept { return this->operator[](0); }
		constexpr const_reference front() const noexcept { return this->operator[](0); }

		constexpr reference       back() noexcept { return this->operator[](this->size() - 1); }
		constexpr const_reference back() const noexcept { return this->operator[](this->size() - 1); }

		// Capacity
		constexpr bool empty() const noexcept { return this->size() == 0; }

		constexpr size_type size() const noexcept { return this->perkRankCount; }

		// Member variables
		pointer       perkRanks;     // 8
		size_type     perkRankCount; // 10
		std::uint32_t padding14;     // 14
	};
	static_assert(offsetof(BGSPerkRankArray, perkRanks) == 0x8);
	static_assert(offsetof(BGSPerkRankArray, perkRankCount) == 0x10);
	static_assert(sizeof(BGSPerkRankArray) == 0x18);
}
