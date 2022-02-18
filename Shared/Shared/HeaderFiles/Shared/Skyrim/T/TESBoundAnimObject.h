#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/T/TESBoundObject.h"



namespace Skyrim
{
	class TESBoundAnimObject :
		public TESBoundObject // 0
	{
	public:
		// Override
		virtual ~TESBoundAnimObject() override; // 0

		// Override (TESBoundObject)
		virtual bool IsBoundAnimObject() const override;  // 3C
		virtual void Unknown4B(TESBoundObject*) override; // 4B
	};
	static_assert(sizeof(TESBoundAnimObject) == 0x30);
}
