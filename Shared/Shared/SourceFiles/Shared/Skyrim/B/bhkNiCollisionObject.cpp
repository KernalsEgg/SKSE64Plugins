#include "Shared/PCH.h"

#include "Shared/Skyrim/B/bhkNiCollisionObject.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	bhkRigidBody* bhkNiCollisionObject::GetRigidBody() const
	{
		auto function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&bhkNiCollisionObject::GetRigidBody)>::type>(Addresses::bhkNiCollisionObject::GetRigidBody) };

		return function(this);
	}
}
