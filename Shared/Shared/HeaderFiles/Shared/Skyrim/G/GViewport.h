#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class GViewport
	{
	public:
		enum class Flags : std::uint32_t
		{
			kNone                = 0,
			kIsRenderTexture     = 1U << 0,
			kAlphaComposite      = 1U << 1,
			kUseScissorRectangle = 1U << 2,
			kNoSetState          = 1U << 3,
			kRenderTextureAlpha  = kIsRenderTexture | kAlphaComposite
		};
		static_assert(sizeof(Flags) == 0x4);

		GViewport();
		GViewport(const GViewport& right);

		GViewport(std::int32_t bufferWidth, std::int32_t bufferHeight, std::int32_t left, std::int32_t top, std::int32_t width, std::int32_t height, std::int32_t scissorLeft, std::int32_t scissorTop, std::int32_t scissorWidth, std::int32_t scissorHeight, Utility::Enumeration<Flags, std::uint32_t> flags = Flags::kNone);
		GViewport(std::int32_t bufferWidth, std::int32_t bufferHeight, std::int32_t left, std::int32_t top, std::int32_t width, std::int32_t height, std::int32_t scissorLeft, std::int32_t scissorTop, std::int32_t scissorWidth, std::int32_t scissorHeight, float scale, float ratio, Utility::Enumeration<Flags, std::uint32_t> flags = Flags::kNone);
		GViewport(std::int32_t bufferWidth, std::int32_t bufferHeight, std::int32_t left, std::int32_t top, std::int32_t width, std::int32_t height, Utility::Enumeration<Flags, std::uint32_t> flags = Flags::kNone);

		// Member functions
		void SetViewport(std::int32_t bufferWidth, std::int32_t bufferHeight, std::int32_t left, std::int32_t top, std::int32_t width, std::int32_t height, Utility::Enumeration<Flags, std::uint32_t> flags = Flags::kNone);
		void SetScissorRectangle(std::int32_t scissorLeft, std::int32_t scissorTop, std::int32_t scissorWidth, std::int32_t scissorHeight);

		// Member variables
		std::int32_t                               bufferWidth;   // 0
		std::int32_t                               bufferHeight;  // 4
		std::int32_t                               left;          // 8
		std::int32_t                               top;           // C
		std::int32_t                               width;         // 10
		std::int32_t                               height;        // 14
		std::int32_t                               scissorLeft;   // 18
		std::int32_t                               scissorTop;    // 1C
		std::int32_t                               scissorWidth;  // 20
		std::int32_t                               scissorHeight; // 24
		float                                      scale;         // 28
		float                                      aspectRatio;   // 2C
		Utility::Enumeration<Flags, std::uint32_t> flags;         // 30
		std::uint32_t                              padding34;     // 34
	};
	static_assert(offsetof(GViewport, bufferWidth) == 0x0);
	static_assert(offsetof(GViewport, bufferHeight) == 0x4);
	static_assert(offsetof(GViewport, left) == 0x8);
	static_assert(offsetof(GViewport, top) == 0xC);
	static_assert(offsetof(GViewport, width) == 0x10);
	static_assert(offsetof(GViewport, height) == 0x14);
	static_assert(offsetof(GViewport, scissorLeft) == 0x18);
	static_assert(offsetof(GViewport, scissorTop) == 0x1C);
	static_assert(offsetof(GViewport, scissorWidth) == 0x20);
	static_assert(offsetof(GViewport, scissorHeight) == 0x24);
	static_assert(offsetof(GViewport, scale) == 0x28);
	static_assert(offsetof(GViewport, aspectRatio) == 0x2C);
	static_assert(offsetof(GViewport, flags) == 0x30);
	static_assert(sizeof(GViewport) == 0x38);
}
