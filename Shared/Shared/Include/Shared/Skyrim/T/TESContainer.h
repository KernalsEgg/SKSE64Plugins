#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BaseFormComponent.h"



namespace Skyrim
{
	struct ContainerItemExtra;

	class TESBoundObject;

	struct ContainerObject
	{
	public:
		// Member variables
		std::int32_t        count;              // 0
		std::uint32_t       padding4;           // 4
		TESBoundObject*     boundObject;        // 8
		ContainerItemExtra* containerItemExtra; // 10
	};
	static_assert(offsetof(ContainerObject, count) == 0x0);
	static_assert(offsetof(ContainerObject, boundObject) == 0x8);
	static_assert(offsetof(ContainerObject, containerItemExtra) == 0x10);
	static_assert(sizeof(ContainerObject) == 0x18);

	class TESContainer :
		public BaseFormComponent // 0
	{
	public:
		using size_type       = std::uint32_t;
		using value_type      = ContainerObject*;
		using pointer         = value_type*;
		using const_pointer   = const value_type*;
		using reference       = value_type&;
		using const_reference = const value_type&;
		using iterator        = pointer;
		using const_iterator  = const_pointer;

		// Override
		virtual ~TESContainer() override; // 0

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

		constexpr pointer       data() noexcept { return this->containerObjects_; }
		constexpr const_pointer data() const noexcept { return this->containerObjects_; }

		constexpr reference       front() noexcept { return this->operator[](0); }
		constexpr const_reference front() const noexcept { return this->operator[](0); }

		constexpr reference       back() noexcept { return this->operator[](this->size() - 1); }
		constexpr const_reference back() const noexcept { return this->operator[](this->size() - 1); }

		// Capacity
		constexpr bool empty() const noexcept { return this->size() == 0; }

		constexpr size_type size() const noexcept { return this->containerObjectCount_; }

		// Member functions
		std::int32_t GetBoundObjectCount(TESBoundObject* boundObject) const;
		bool         HasBoundObject(TESBoundObject* boundObject) const;

	private:
		// Member variables
		pointer       containerObjects_;     // 8
		size_type     containerObjectCount_; // 10
		std::uint32_t padding14_;            // 14
	};
	static_assert(sizeof(TESContainer) == 0x18);
}
