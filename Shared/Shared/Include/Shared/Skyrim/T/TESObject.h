#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/T/TESForm.h"



namespace Skyrim
{
	class TESObject :
		public TESForm // 0
	{
	public:
		// Override
		virtual ~TESObject() override; // 0

		// Override (TESForm)
		virtual void Unknown28(TESForm*) override; // 28
		virtual void Unknown2D(TESForm*) override; // 2D

		// Add
		virtual void Unknown3B(TESObject*);             // 3B
		virtual bool IsBoundAnimObject() const;         // 3C
		virtual void Unknown3D(TESObject*);             // 3D
		virtual bool IsAutomaticallyCalculated() const; // 3E
		virtual void Unknown3F(TESObject*);             // 3F
		virtual void Unknown40(TESObject*);             // 40
		virtual void Unknown41(TESObject*);             // 41
		virtual void Unknown42(TESObject*);             // 42
		virtual void Unknown43(TESObject*);             // 43
		virtual void Unknown44(TESObject*);             // 44
		virtual void Unknown45(TESObject*);             // 45
		virtual void Unknown46(TESObject*);             // 46
		virtual void Unknown47(TESObject*);             // 47
	};
	static_assert(sizeof(TESObject) == 0x20);
}
