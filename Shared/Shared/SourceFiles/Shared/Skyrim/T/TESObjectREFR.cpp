#include "Shared/PCH.h"

#include "Shared/Skyrim/T/TESObjectREFR.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/F/FormType.h"
#include "Shared/Skyrim/T/TESBoundObject.h"
#include "Shared/Skyrim/T/TESContainer.h"
#include "Shared/Skyrim/T/TESNPC.h"
#include "Shared/Skyrim/T/TESObjectCONT.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	TESObjectREFR* TESObjectREFR::GetReferenceFrom3D(NiAVObject* avObject)
	{
		auto function{ reinterpret_cast<decltype(&TESObjectREFR::GetReferenceFrom3D)>(Addresses::TESObjectREFR::GetReferenceFrom3D) };

		return function(avObject);
	}

	TESContainer* TESObjectREFR::GetContainer() const
	{
		auto baseObject = this->baseObject;

		if (baseObject)
		{
			switch (baseObject->formType.get())
			{
				case FormType::kContainer:
				{
					return static_cast<TESContainer*>(static_cast<TESObjectCONT*>(baseObject));
				}
				case FormType::kNPC:
				{
					return static_cast<TESContainer*>(static_cast<TESNPC*>(baseObject));
				}
			}
		}

		return nullptr;
	}

	InventoryChanges* TESObjectREFR::GetInventoryChanges()
	{
		auto function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&TESObjectREFR::GetInventoryChanges)>::type>(Addresses::TESObjectREFR::GetInventoryChanges) };

		return function(this);
	}

	const char* TESObjectREFR::GetReferenceName() const
	{
		auto function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&TESObjectREFR::GetReferenceName)>::type>(Addresses::TESObjectREFR::GetReferenceName) };

		return function(this);
	}

	bool TESObjectREFR::ShouldApplyDecal() const
	{
		if (this->IsWater())
		{
			return false;
		}

		if (this->baseObject->formType == FormType::kNPC || this->baseObject->formType == FormType::kProjectile)
		{
			return false;
		}

		return true;
	}
}
