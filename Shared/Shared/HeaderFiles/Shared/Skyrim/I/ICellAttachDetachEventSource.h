#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/B/BSTEventSource.h"
#include "Shared/Skyrim/B/BSTSingleton.h"



namespace Skyrim
{
	class CellAttachDetachEvent;

	class ICellAttachDetachEventSource :
		public BSTSingletonExplicit<ICellAttachDetachEventSource>, // 0
		public BSTEventSource<CellAttachDetachEvent>               // 8
	{
	public:
		// Add
		virtual ~ICellAttachDetachEventSource(); // 0
	};
	static_assert(sizeof(ICellAttachDetachEventSource) == 0x60);
}
