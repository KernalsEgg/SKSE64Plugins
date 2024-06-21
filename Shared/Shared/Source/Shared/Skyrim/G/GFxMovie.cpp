#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GFxMovie.h"

#include "Shared/Skyrim/G/GFxValue.h"



namespace Skyrim
{
	float GFxMovie::GetRenderPixelScale()
	{
		return 20.0F;
	}

	bool GFxMovie::SetVariable(const char* pathToVariable, const char* value, Utility::Enumeration<SetVariableType, std::uint32_t> setType)
	{
		return this->SetVariable(pathToVariable, GFxValue(value), setType);
	}

	bool GFxMovie::SetVariable(const char* pathToVariable, const wchar_t* value, Utility::Enumeration<SetVariableType, std::uint32_t> setType)
	{
		return this->SetVariable(pathToVariable, GFxValue(value), setType);
	}

	bool GFxMovie::SetVariableDouble(const char* pathToVariable, double value, Utility::Enumeration<SetVariableType, std::uint32_t> setType)
	{
		return this->SetVariable(pathToVariable, GFxValue(value), setType);
	}

	double GFxMovie::GetVariableDouble(const char* pathToVariable) const
	{
		GFxValue result(GFxValue::ValueType::kNumber);

		this->GetVariable(std::addressof(result), pathToVariable);

		return result.IsNumber() ? result.GetNumber() : 0.0;
	}

	bool GFxMovie::SetVariableArray(const char* pathToVariable, std::uint32_t index, const GFxValue* data, std::uint32_t count, Utility::Enumeration<SetVariableType, std::uint32_t> setType)
	{
		return this->SetVariableArray(SetArrayType::kValue, pathToVariable, index, data, count, setType);
	}

	bool GFxMovie::GetVariableArray(const char* pathToVariable, std::uint32_t index, GFxValue* data, std::uint32_t count)
	{
		return this->GetVariableArray(SetArrayType::kValue, pathToVariable, index, data, count);
	}
}
