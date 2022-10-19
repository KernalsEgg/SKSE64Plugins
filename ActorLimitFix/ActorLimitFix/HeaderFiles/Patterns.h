#pragma once

#include "PrecompiledHeader.h"



namespace ActorLimitFix::Patterns
{
	namespace MoverLimit
	{
		bool GetMoverLimit();
		bool CompareMoverLimit();
	}

	namespace ReplaceStaticArray
	{
		bool GetArrayCapacityAdd();
		bool GetArrayCapacityCommentOnPlayerAction();
		bool GetArrayCapacityFind();
		bool GetArrayCapacityFindInline();
		bool GetArrayCapacityGetActors();

		bool GetArrayAdd();
		bool GetArrayCommentOnPlayerAction();
		bool GetArrayFind();
		bool GetArrayFindInline();
		bool GetArrayGetActors();

		bool HasCapacityAdd();
	}
}
