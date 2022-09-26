#pragma once

#include "PrecompiledHeader.h"



namespace PrioritizeStolenItems::Patterns
{
	namespace Events
	{
		bool AddItem();
		bool DropItem();
		bool GetExtraDataListToAddItem();
		bool GetExtraDataListToDropItem();
		bool GetExtraDataListToRemoveItem();
		bool GetExtraDataListToSellItem();
		bool GetIngredient();
		bool RemoveIngredient();
		bool RemoveItem();
		bool SellItem();
	}
}
