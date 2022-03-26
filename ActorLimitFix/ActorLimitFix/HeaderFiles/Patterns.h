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
		bool GetStaticArrayCapacityContainsInline();
		bool GetStaticArrayCapacityCopy();
		bool GetStaticArrayCapacityInsert();
		bool GetStaticArrayCommentOnPlayerAction();
		bool GetStaticArrayContains();
		bool GetStaticArrayContainsInline();
		bool GetStaticArrayCopy();
		bool GetStaticArrayInsert();
		bool HasCapacityInsert();
	}
}
