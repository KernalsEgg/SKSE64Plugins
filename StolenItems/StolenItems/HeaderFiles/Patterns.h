#pragma once

#include "PCH.h"



namespace StolenItems::Patterns
{
	namespace Events
	{
		bool AddItem();
		bool DisenchantItem();
		bool DropItem();
		bool GetExtraDataLists();
		bool GetExtraDataListToAddItem();
		bool GetExtraDataListToDropItem();
		bool GetExtraDataListToRemoveItem();
		bool GetExtraDataListToRemoveSoul();
		bool GetExtraDataListToRemoveSoulGem();
		bool GetExtraDataListToSellItem();
		bool GetIngredientToRemove();
		bool GetItemToDisenchant();
		bool IsOwnedBy();
		bool RemoveIngredient();
		bool RemoveItem();
		bool RemoveSoul();
		bool RemoveSoulGem();
		bool SellItem();
	}
}
