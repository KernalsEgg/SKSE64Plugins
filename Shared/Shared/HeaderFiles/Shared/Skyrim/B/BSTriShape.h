#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSGeometry.h"



namespace Skyrim
{
	class BSTriShape :
		public BSGeometry // 0
	{
	public:
		// Override
		virtual ~BSTriShape() override; // 0

		// Override (BSGeometry)
		virtual const NiRTTI* GetRTTI() const override;      // 2
		virtual void          Unknown9(NiObject*) override;  // 9
		virtual void          Unknown17(NiObject*) override; // 17
		virtual void          Unknown18(NiObject*) override; // 18
		virtual void          Unknown19(NiObject*) override; // 19
		virtual void          Unknown1A(NiObject*) override; // 1A
		virtual void          Unknown1B(NiObject*) override; // 1B
		virtual void          Unknown1C(NiObject*) override; // 1C

		// Member variables
		std::uint16_t triangleCount; // 158
		std::uint16_t vertexCount;   // 15A
		std::int32_t  padding15C;    // 15C
	};
	static_assert(offsetof(BSTriShape, triangleCount) == 0x158);
	static_assert(offsetof(BSTriShape, vertexCount) == 0x15A);
	static_assert(sizeof(BSTriShape) == 0x160);
}
