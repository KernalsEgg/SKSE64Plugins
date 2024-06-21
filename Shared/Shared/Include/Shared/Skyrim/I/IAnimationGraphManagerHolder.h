#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	class BSFixedString;

	class IAnimationGraphManagerHolder
	{
	public:
		// Add
		virtual ~IAnimationGraphManagerHolder();                                                                // 0
		virtual void Unknown1(IAnimationGraphManagerHolder*);                                                   // 1
		virtual void Unknown2(IAnimationGraphManagerHolder*) = 0;                                               // 2
		virtual void Unknown3(IAnimationGraphManagerHolder*) = 0;                                               // 3
		virtual void Unknown4(IAnimationGraphManagerHolder*);                                                   // 4
		virtual void Unknown5(IAnimationGraphManagerHolder*) = 0;                                               // 5
		virtual void Unknown6(IAnimationGraphManagerHolder*);                                                   // 6
		virtual void Unknown7(IAnimationGraphManagerHolder*);                                                   // 7
		virtual void Unknown8(IAnimationGraphManagerHolder*);                                                   // 8
		virtual void Unknown9(IAnimationGraphManagerHolder*);                                                   // 9
		virtual void UnknownA(IAnimationGraphManagerHolder*);                                                   // A
		virtual void UnknownB(IAnimationGraphManagerHolder*);                                                   // B
		virtual void UnknownC(IAnimationGraphManagerHolder*);                                                   // C
		virtual void UnknownD(IAnimationGraphManagerHolder*);                                                   // D
		virtual void UnknownE(IAnimationGraphManagerHolder*);                                                   // E
		virtual void UnknownF(IAnimationGraphManagerHolder*);                                                   // F
		virtual bool GetAnimationVariableFloat(const BSFixedString& variableName, float& value) const;          // 10
		virtual bool GetAnimationVariableInteger(const BSFixedString& variableName, std::int32_t& value) const; // 11
		virtual bool GetAnimationVariableBool(const BSFixedString& variableName, bool& value) const;            // 12
	};
	static_assert(sizeof(IAnimationGraphManagerHolder) == 0x8);
}
