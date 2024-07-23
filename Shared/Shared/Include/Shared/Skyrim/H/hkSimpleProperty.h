#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/H/hkBaseTypes.h"



namespace Skyrim
{
	struct hkSimplePropertyValue
	{
	public:
		hkSimplePropertyValue() {}
		hkSimplePropertyValue(const float real);
		hkSimplePropertyValue(const std::int32_t integer);
		hkSimplePropertyValue(const std::uint32_t unsignedInteger);
		hkSimplePropertyValue(std::uint64_t unsignedInteger64);
		hkSimplePropertyValue(void* pointer);

		void SetInteger(const std::int32_t integer);
		void SetPointer(void* pointer);
		void SetReal(const float real);
		void SetUnsignedInteger64(std::uint64_t unsignedInteger64);

		std::int32_t  GetInteger() const;
		void*         GetPointer() const;
		float         GetReal() const;
		std::uint64_t GetUnsignedInteger64() const;

		// Member variables
		std::uint64_t data; // 0
	};
	static_assert(offsetof(hkSimplePropertyValue, data) == 0x0);
	static_assert(sizeof(hkSimplePropertyValue) == 0x8);

	class hkSimpleProperty
	{
	public:
		hkSimpleProperty() {}
		hkSimpleProperty(std::uint32_t key, std::int32_t value);
		hkSimpleProperty(std::uint32_t key, hkSimplePropertyValue value);
		hkSimpleProperty(hkFinishLoadedObjectFlag finishLoadedObjectFlag) {}

		// Member variables
		std::uint32_t         key;      // 0
		std::uint32_t         padding4; // 4
		hkSimplePropertyValue value;    // 8
	};
	static_assert(offsetof(hkSimpleProperty, key) == 0x0);
	static_assert(offsetof(hkSimpleProperty, value) == 0x8);
	static_assert(sizeof(hkSimpleProperty) == 0x10);
}
