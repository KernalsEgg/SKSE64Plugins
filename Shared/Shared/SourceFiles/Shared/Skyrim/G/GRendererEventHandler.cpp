#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GRendererEventHandler.h"



namespace Skyrim
{
	GRendererEventHandler::GRendererEventHandler()
	{
		this->next      = nullptr;
		this->previous  = nullptr;
		this->renderer_ = nullptr;
	}

	void GRendererEventHandler::BindRenderer(GRenderer* renderer)
	{
		this->renderer_ = renderer;
	}

	GRenderer* GRendererEventHandler::GetRenderer() const
	{
		return this->renderer_;
	}

	void GRendererEventHandler::RemoveAndClear()
	{
		if (this->next && this->previous)
		{
			this->Remove();
		}

		this->next      = nullptr;
		this->previous  = nullptr;
		this->renderer_ = nullptr;
	}
}
