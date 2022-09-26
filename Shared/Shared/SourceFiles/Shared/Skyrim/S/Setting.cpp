#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/S/Setting.h"



namespace Skyrim
{
	bool Setting::IsPreferenceSetting() const
	{
		return false;
	}

	Setting::Setting(const char* name, bool value) :
		name_(name)
	{
		this->value_.b = value;
	}

	Setting::Setting(const char* name, const char* value) :
		name_(name)
	{
		this->value_.s = value;
	}

	Setting::Setting(const char* name, float value) :
		name_(name)
	{
		this->value_.f = value;
	}

	Setting::Setting(const char* name, std::int8_t value) :
		name_(name)
	{
		this->value_.c = value;
	}

	Setting::Setting(const char* name, std::int32_t value) :
		name_(name)
	{
		this->value_.i = value;
	}

	Setting::Setting(const char* name, std::uint8_t value) :
		name_(name)
	{
		this->value_.h = value;
	}

	Setting::Setting(const char* name, std::uint32_t value) :
		name_(name)
	{
		this->value_.u = value;
	}

	bool Setting::GetBool() const
	{
		return this->value_.b;
	}

	std::int8_t Setting::GetCharacter() const
	{
		return this->value_.c;
	}

	float Setting::GetFloat() const
	{
		return this->value_.f;
	}

	std::int32_t Setting::GetInteger() const
	{
		return this->value_.i;
	}

	const char* Setting::GetString() const
	{
		return this->value_.s;
	}

	std::uint8_t Setting::GetUnsignedCharacter() const
	{
		return this->value_.h;
	}

	std::uint32_t Setting::GetUnsignedInteger() const
	{
		return this->value_.u;
	}

	void Setting::SetBool(bool value)
	{
		this->value_.b = value;
	}

	void Setting::SetCharacter(std::int8_t value)
	{
		this->value_.c = value;
	}

	void Setting::SetFloat(float value)
	{
		this->value_.f = value;
	}

	void Setting::SetInteger(std::int32_t value)
	{
		this->value_.i = value;
	}

	void Setting::SetUnsignedCharacter(std::uint8_t value)
	{
		this->value_.h = value;
	}

	void Setting::SetUnsignedInteger(std::uint32_t value)
	{
		this->value_.u = value;
	}
}
