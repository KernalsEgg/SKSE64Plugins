#pragma once

#include "PCH.h"



namespace ActorLimitFix::Patterns
{
	namespace MoverLimit
	{
		bool GetMoverLimit();
		bool CompareMoverLimit();
	}

	namespace ReplaceStaticArray
	{
		bool GetStaticArrayCapacityCommentOnPlayerAction();
		bool GetStaticArrayCapacityContains();
		bool GetStaticArrayCapacityCopy();
		bool GetStaticArrayCapacityErase();
		bool GetStaticArrayCapacityInsert();
		bool GetStaticArrayCommentOnPlayerAction();
		bool GetStaticArrayContains();
		bool GetStaticArrayCopy();
		bool GetStaticArrayErase();
		bool GetStaticArrayInsert();
		bool HasCapacityInsert();
	}
}
