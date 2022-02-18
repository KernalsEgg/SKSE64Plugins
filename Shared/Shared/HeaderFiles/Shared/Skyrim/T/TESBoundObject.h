#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/T/TESObject.h"



namespace Skyrim
{
	class TESBoundObject :
		public TESObject // 0
	{
	public:
		// Override
		virtual ~TESBoundObject() override; // 0

		// Override (TESObject)
		virtual void Unknown26(TESForm*) override;   // 26
		virtual bool IsBoundObject() const override; // 27
		virtual void Unknown37(TESForm*) override;   // 37
		virtual void Unknown40(TESObject*) override; // 40
		virtual void Unknown44(TESObject*) override; // 44

		// Add
		virtual void Unknown48(TESBoundObject*); // 48
		virtual void Unknown49(TESBoundObject*); // 49
		virtual void Unknown4A(TESBoundObject*); // 4A
		virtual void Unknown4B(TESBoundObject*); // 4B
		virtual void Unknown4C(TESBoundObject*); // 4C
		virtual void Unknown4D(TESBoundObject*); // 4D
		virtual void Unknown4E(TESBoundObject*); // 4E
		virtual void Unknown4F(TESBoundObject*); // 4F
		virtual void Unknown50(TESBoundObject*); // 50
		virtual void Unknown51(TESBoundObject*); // 51
		virtual void Unknown52(TESBoundObject*); // 52

		// Member functions
		float GetWeight() const;

		// Member variables
		std::int64_t unknown20; // 20
		std::int64_t unknown28; // 28
	};
	static_assert(sizeof(TESBoundObject) == 0x30);
}
