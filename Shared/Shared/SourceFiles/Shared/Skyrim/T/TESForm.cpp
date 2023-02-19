#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/T/TESForm.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/T/TESDataHandler.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	TESForm* TESForm::GetFormFromEditorID(const char* editorID)
	{
		auto* function{ reinterpret_cast<decltype(TESForm::GetFormFromEditorID)*>(Addresses::TESForm::GetFormFromEditorID) };

		return function(editorID);
	}

	EnchantmentItem* TESForm::GetEnchantment(ExtraDataList* extraDataList)
	{
		auto* function{ reinterpret_cast<Utility::TypeTraits::MakeFunctionPointer<decltype(&TESForm::GetEnchantment)>::type>(Addresses::TESForm::GetEnchantment) };

		return function(this, extraDataList);
	}

	TESFile* TESForm::GetFile(std::int32_t index) const
	{
		auto* fileArray = this->sourceFiles.fileArray;

		if (!fileArray || fileArray->empty())
		{
			return nullptr;
		}

		return index < 0 || static_cast<std::uint32_t>(index) >= fileArray->size() ? fileArray->back() : (*fileArray)[index];
	}

	const char* TESForm::GetFormName() const
	{
		auto* function{ reinterpret_cast<Utility::TypeTraits::MakeFunctionPointer<decltype(&TESForm::GetFormName)>::type>(Addresses::TESForm::GetFormName) };

		return function(this);
	}

	std::uint16_t TESForm::GetMaximumCharge(ExtraDataList* extraDataList) const
	{
		auto* function{ reinterpret_cast<Utility::TypeTraits::MakeFunctionPointer<decltype(&TESForm::GetMaximumCharge)>::type>(Addresses::TESForm::GetMaximumCharge) };

		return function(this, extraDataList);
	}

	bool TESForm::IsCreated() const
	{
		return TESDataHandler::GetSingleton()->IsFormIDCreated(this->formID);
	}

	void TESForm::SetTemporary()
	{
		auto* function{ reinterpret_cast<Utility::TypeTraits::MakeFunctionPointer<decltype(&TESForm::SetTemporary)>::type>(Addresses::TESForm::SetTemporary) };

		function(this);
	}
}
