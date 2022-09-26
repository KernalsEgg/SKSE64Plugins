#pragma once

#include "Shared/PrecompiledHeader.h"

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
		virtual const NiRTTI* GetRTTI() const override;                               // 2
		virtual BSTriShape*   AsBSTriangleShape() override;                           // 9
		virtual NiObject*     CreateClone(NiCloningProcess& cloningProcess) override; // 17
		virtual void          LoadBinary(NiStream& stream) override;                  // 18
		virtual void          LinkObject(NiStream& stream) override;                  // 19
		virtual bool          RegisterStreamables(NiStream& stream) override;         // 1A
		virtual void          SaveBinary(NiStream& stream) override;                  // 1B
		virtual bool          IsEqual(NiObject* object) override;                     // 1C

		// Member variables
		std::uint16_t triangleCount; // 158
		std::uint16_t vertexCount;   // 15A
		std::uint32_t padding15C;    // 15C
	};
	static_assert(offsetof(BSTriShape, triangleCount) == 0x158);
	static_assert(offsetof(BSTriShape, vertexCount) == 0x15A);
	static_assert(sizeof(BSTriShape) == 0x160);
}
