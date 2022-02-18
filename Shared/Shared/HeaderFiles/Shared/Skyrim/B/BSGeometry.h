#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/N/NiAVObject.h"
#include "Shared/Skyrim/N/NiPointer.h"
#include "Shared/Utility/Convert.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class NiProperty;
	class NiSkinInstance;

	class BSGeometry :
		public NiAVObject // 0
	{
	public:
		enum class State
		{
			kProperty = 0,
			kEffect   = 1,
			kTotal    = 2
		};

		enum class Type : std::uint8_t
		{
			kGeometry = 0,
			kTriShape = 3
		};
		static_assert(sizeof(Type) == 0x1);

		// Override
		virtual ~BSGeometry() override; // 0

		// Override (NiAVObject)
		virtual const NiRTTI* GetRTTI() const override;        // 2
		virtual void          Unknown7(NiObject*) override;    // 7
		virtual void          Unknown18(NiObject*) override;   // 18
		virtual void          Unknown19(NiObject*) override;   // 19
		virtual void          Unknown1A(NiObject*) override;   // 1A
		virtual void          Unknown1B(NiObject*) override;   // 1B
		virtual void          Unknown1C(NiObject*) override;   // 1C
		virtual void          Unknown1D(NiObject*) override;   // 1D
		virtual void          Unknown1E(NiObject*) override;   // 1E
		virtual void          Unknown27(NiAVObject*) override; // 27
		virtual void          Unknown2B(NiAVObject*) override; // 2B
		virtual void          Unknown2C(NiAVObject*) override; // 2C
		virtual void          Unknown2D(NiAVObject*) override; // 2D
		virtual void          Unknown2E(NiAVObject*) override; // 2E
		virtual void          Unknown2F(NiAVObject*) override; // 2F
		virtual void          Unknown34(NiAVObject*) override; // 34

		// Add
		virtual void Unknown35(BSGeometry*); // 35
		virtual void Unknown36(BSGeometry*); // 36
		virtual void Unknown37(BSGeometry*); // 37

		// Member variables
		std::int64_t                             unknown110;                                   // 110
		std::int64_t                             unknown118;                                   // 118
		NiPointer<NiProperty>                    states[Utility::ToUnderlying(State::kTotal)]; // 120
		NiPointer<NiSkinInstance>                skinInstance;                                 // 130
		std::int64_t                             unknown138;                                   // 138
		std::int64_t                             unknown140;                                   // 140
		std::int64_t                             unknown148;                                   // 148
		Utility::Enumeration<Type, std::uint8_t> type;                                         // 150
		std::int8_t                              padding151;                                   // 151
		std::int16_t                             padding152;                                   // 152
		std::int32_t                             padding154;                                   // 154
	};
	static_assert(offsetof(BSGeometry, states) == 0x120);
	static_assert(offsetof(BSGeometry, skinInstance) == 0x130);
	static_assert(offsetof(BSGeometry, type) == 0x150);
	static_assert(sizeof(BSGeometry) == 0x158);
}
