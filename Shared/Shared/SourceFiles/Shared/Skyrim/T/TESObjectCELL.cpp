#include "Shared/PCH.h"

#include "Shared/Skyrim/T/TESObjectCELL.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	BSTempEffectParticle* TESObjectCELL::CreateTemporaryEffectParticle(float duration, const char* model, const NiPoint3& normal, const NiPoint3& position, float scale, std::uint32_t flags, NiAVObject* target3D)
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&TESObjectCELL::CreateTemporaryEffectParticle)>::type>(Addresses::TESObjectCELL::CreateTemporaryEffectParticle) };

		return function(this, duration, model, normal, position, scale, flags, target3D);
	}

	bhkWorld* TESObjectCELL::GetHavokWorld() const
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&TESObjectCELL::GetHavokWorld)>::type>(Addresses::TESObjectCELL::GetHavokWorld) };

		return function(this);
	}

	bool TESObjectCELL::IsAttached() const
	{
		return this->cellState == TESObjectCELL::State::kAttached;
	}
}
