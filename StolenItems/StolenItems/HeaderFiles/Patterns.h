#pragma once

#include "PCH.h"



namespace StolenItems::Patterns
{
	namespace Events
	{
		namespace Add
		{
			bool GetExtraDataList();
			bool RemoveItem();
		}

		namespace Drop
		{
			bool GetExtraDataList();
			bool DropItem();
		}

		namespace Remove
		{
			bool GetExtraDataList();
			bool RemoveItem();
		}

		namespace RequestItemCardInformation
		{
			bool IsOwnedBy();
		}

		namespace Sell
		{
			bool GetExtraDataList();
			bool RemoveItem();
		}
	}
}
