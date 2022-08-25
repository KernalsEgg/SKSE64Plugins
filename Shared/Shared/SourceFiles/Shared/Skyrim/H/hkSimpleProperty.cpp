#include "Shared/PCH.h"

#include "Shared/Skyrim/H/hkSimpleProperty.h"



namespace Skyrim
{
	hkSimplePropertyValue::hkSimplePropertyValue(const float real)
	{
		this->SetReal(real);
	}

	hkSimplePropertyValue::hkSimplePropertyValue(const std::int32_t integer)
	{
		this->SetInteger(integer);
	}

	hkSimplePropertyValue::hkSimplePropertyValue(const std::uint32_t unsignedInteger)
	{
		this->SetInteger(unsignedInteger);
	}

	hkSimplePropertyValue::hkSimplePropertyValue(std::uint64_t unsignedInteger64)
	{
		this->SetUnsignedInteger64(unsignedInteger64);
	}

	hkSimplePropertyValue::hkSimplePropertyValue(void* pointer)
	{
		this->SetPointer(pointer);
	}

	void hkSimplePropertyValue::SetInteger(const std::int32_t integer)
	{
		this->data = integer;
	}

	void hkSimplePropertyValue::SetPointer(void* pointer)
	{
		this->data = reinterpret_cast<std::uint64_t>(pointer);
	}

	void hkSimplePropertyValue::SetReal(const float real)
	{
		union
		{
		public:
			float         real;
			std::uint32_t unsignedInteger32;
		} cast{
			.real = real
		};

		this->data = cast.unsignedInteger32;
	}

	void hkSimplePropertyValue::SetUnsignedInteger64(std::uint64_t unsignedInteger64)
	{
		this->data = unsignedInteger64;
	}

	std::int32_t hkSimplePropertyValue::GetInteger() const
	{
		return static_cast<std::int32_t>(this->data);
	}

	void* hkSimplePropertyValue::GetPointer() const
	{
		return reinterpret_cast<void*>(this->data);
	}

	float hkSimplePropertyValue::GetReal() const
	{
		union
		{
		public:
			float         real;
			std::uint32_t unsignedInteger32;
		} cast{
			.unsignedInteger32 = static_cast<std::uint32_t>(this->data)
		};

		return cast.real;
	}

	std::uint64_t hkSimplePropertyValue::GetUnsignedInteger64() const
	{
		return this->data;
	}

	hkSimpleProperty::hkSimpleProperty(std::uint32_t key, std::int32_t value) :
		key(key), value(value)
	{
	}

	hkSimpleProperty::hkSimpleProperty(std::uint32_t key, hkSimplePropertyValue value) :
		key(key), value(value)
	{
	}
}
