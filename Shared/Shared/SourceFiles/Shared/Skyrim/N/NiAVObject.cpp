#include "Shared/PCH.h"

#include "Shared/Skyrim/N/NiAVObject.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	NiAVObject* NiAVObject::GetBoneFromName(const BSFixedString& name, bool objects)
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&NiAVObject::GetBoneFromName)>::type>(Addresses::NiAVObject::GetBoneFromName) };

		return function(this, name, objects);
	}

	bhkCollisionObject* NiAVObject::GetCollisionObject() const
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&NiAVObject::GetCollisionObject)>::type>(Addresses::NiAVObject::GetCollisionObject) };

		return function(this);
	}
}
