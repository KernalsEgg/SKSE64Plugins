#include "Shared/PCH.h"

#include "Shared/Skyrim/G/GViewport.h"



namespace Skyrim
{
	GViewport::GViewport() :
		bufferWidth(0),
		bufferHeight(0),
		left(0),
		top(0),
		width(1),
		height(1),
		scissorLeft(0),
		scissorTop(0),
		scissorWidth(0),
		scissorHeight(0),
		scale(1.0F),
		aspectRatio(1.0F),
		flags(Flags::kNone)
	{
	}

	GViewport::GViewport(const GViewport& right) :
		bufferWidth(right.bufferWidth),
		bufferHeight(right.bufferHeight),
		left(right.left),
		top(right.top),
		width(right.width),
		height(right.height),
		scissorLeft(right.scissorLeft),
		scissorTop(right.scissorTop),
		scissorWidth(right.scissorWidth),
		scissorHeight(right.scissorHeight),
		scale(right.scale),
		aspectRatio(right.aspectRatio),
		flags(right.flags)
	{
	}

	GViewport::GViewport(std::int32_t bufferWidth, std::int32_t bufferHeight, std::int32_t left, std::int32_t top, std::int32_t width, std::int32_t height, std::int32_t scissorLeft, std::int32_t scissorTop, std::int32_t scissorWidth, std::int32_t scissorHeight, Utility::Enumeration<Flags, std::uint32_t> flags) :
		bufferWidth(bufferWidth),
		bufferHeight(bufferHeight),
		left(left),
		top(top),
		width(width),
		height(height),
		scale(1.0F),
		aspectRatio(1.0F),
		flags(flags | Flags::kUseScissorRectangle)
	{
		this->SetScissorRectangle(scissorLeft, scissorTop, scissorWidth, scissorHeight);
	}

	GViewport::GViewport(std::int32_t bufferWidth, std::int32_t bufferHeight, std::int32_t left, std::int32_t top, std::int32_t width, std::int32_t height, std::int32_t scissorLeft, std::int32_t scissorTop, std::int32_t scissorWidth, std::int32_t scissorHeight, float scale, float ratio, Utility::Enumeration<Flags, std::uint32_t> flags) :
		bufferWidth(bufferWidth),
		bufferHeight(bufferHeight),
		left(left),
		top(top),
		width(width),
		height(height),
		scale(scale),
		aspectRatio(aspectRatio),
		flags(flags | Flags::kUseScissorRectangle)
	{
		this->SetScissorRectangle(scissorLeft, scissorTop, scissorWidth, scissorHeight);
	}

	GViewport::GViewport(std::int32_t bufferWidth, std::int32_t bufferHeight, std::int32_t left, std::int32_t top, std::int32_t width, std::int32_t height, Utility::Enumeration<Flags, std::uint32_t> flags) :
		bufferWidth(bufferWidth),
		bufferHeight(bufferHeight),
		left(left),
		top(top),
		width(width),
		height(height),
		scissorLeft(0),
		scissorTop(0),
		scissorWidth(0),
		scissorHeight(0),
		scale(1.0F),
		aspectRatio(1.0F),
		flags(flags)
	{
	}

	void GViewport::SetViewport(std::int32_t bufferWidth, std::int32_t bufferHeight, std::int32_t left, std::int32_t top, std::int32_t width, std::int32_t height, Utility::Enumeration<Flags, std::uint32_t> flags)
	{
		this->bufferWidth   = bufferWidth;
		this->bufferHeight  = bufferHeight;
		this->left          = left;
		this->top           = top;
		this->width         = width;
		this->height        = height;
		this->scissorLeft   = 0;
		this->scissorTop    = 0;
		this->scissorWidth  = 0;
		this->scissorHeight = 0;
		this->scale         = 1.0F;
		this->aspectRatio   = 1.0F;
	}

	void GViewport::SetScissorRectangle(std::int32_t scissorLeft, std::int32_t scissorTop, std::int32_t scissorWidth, std::int32_t scissorHeight)
	{
		this->scissorLeft   = scissorLeft;
		this->scissorTop    = scissorTop;
		this->scissorWidth  = scissorWidth;
		this->scissorHeight = scissorHeight;

		this->flags.set(Flags::kUseScissorRectangle);
	}
}
