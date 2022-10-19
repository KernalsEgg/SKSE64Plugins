#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/bhkSerializable.h"



namespace Skyrim
{
	struct bhkPickData;

	class bhkWorld :
		public bhkSerializable // 0
	{
	public:
		// Override
		virtual ~bhkWorld() override; // 0

		// Override (bhkSerializable)
		virtual const NiRTTI* GetRTTI() const override;             // 2
		virtual void          Unknown25(bhkRefObject*) override;    // 25
		virtual void          Unknown26(bhkRefObject*) override;    // 26
		virtual hkpWorld*     GetWorld() override;                  // 27
		virtual void          Unknown28(bhkSerializable*) override; // 28
		virtual void          Unknown2B(bhkSerializable*) override; // 2B
		virtual void          Unknown2C(bhkSerializable*) override; // 2C
		virtual void          Unknown2E(bhkSerializable*) override; // 2E
		virtual void          Unknown2F(bhkSerializable*) override; // 2F

		// Add
		virtual void Unknown32(bhkWorld*);        // 32
		virtual bool Pick(bhkPickData& pickData); // 33
		virtual void Unknown34(bhkWorld*);        // 34
		virtual void Unknown35(bhkWorld*);        // 35
		virtual void Unknown36(bhkWorld*);        // 36

		// Non-member functions
		static float GetScale();
		static float GetScaleInverse();

		// Member variables
		std::uint8_t unknown20[0xC600 - 0x20]; // 20
	};
	static_assert(sizeof(bhkWorld) == 0xC600);
}
