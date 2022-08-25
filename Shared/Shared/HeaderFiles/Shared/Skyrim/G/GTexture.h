#pragma once

#include "Shared/PCH.h"

#include "Shared/Skyrim/G/GAtomic.h"
#include "Shared/Skyrim/G/GImage.h"
#include "Shared/Skyrim/G/GNewOverrideBase.h"
#include "Shared/Skyrim/G/GPoint.h"
#include "Shared/Skyrim/G/GRectangle.h"
#include "Shared/Skyrim/G/GStatistics.h"
#include "Shared/Utility/Convert.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class GImageBase;
	class GRenderer;

	class GTexture :
		public GNewOverrideBase<Utility::ToUnderlying(GStatisticRenderers::kMemory)> // 0
	{
	public:
		using Handle = void*;

		enum class ImageTextureUsage : std::uint32_t
		{
			kWrap         = 1U << 0,
			kUpdate       = 1U << 4,
			kMap          = 1U << 5,
			kRenderTarget = 1U << 6
		};
		static_assert(sizeof(ImageTextureUsage) == 0x4);

		enum class MapFlags : std::uint32_t
		{
			kNone    = 0,
			kKeepOld = 1U << 0
		};
		static_assert(sizeof(MapFlags) == 0x4);

		struct UpdateRectangle
		{
		public:
			// Member variables
			GPoint<std::int32_t>     destination; // 0
			GRectangle<std::int32_t> source;      // 8
		};
		static_assert(offsetof(UpdateRectangle, destination) == 0x0);
		static_assert(offsetof(UpdateRectangle, source) == 0x8);
		static_assert(sizeof(UpdateRectangle) == 0x18);

		struct MapRectangle
		{
		public:
			std::uint32_t width;     // 0
			std::uint32_t height;    // 4
			std::uint8_t* data;      // 8
			std::uint32_t pitch;     // 10
			std::uint32_t padding14; // 14
		};
		static_assert(offsetof(MapRectangle, width) == 0x0);
		static_assert(offsetof(MapRectangle, height) == 0x4);
		static_assert(offsetof(MapRectangle, data) == 0x8);
		static_assert(offsetof(MapRectangle, pitch) == 0x10);
		static_assert(sizeof(MapRectangle) == 0x18);

		class ChangeHandler
		{
		public:
			enum class EventType : std::uint32_t
			{
				kDataChange,
				kDataLost,
				kRendererReleased
			};
			static_assert(sizeof(EventType) == 0x4);

			// Add
			virtual ~ChangeHandler() {}                                                                              // 0
			virtual void OnChange(GRenderer* renderer, Utility::Enumeration<EventType, std::uint32_t> changeType) {} // 1
			virtual bool Recreate(GRenderer* renderer) { return false; }                                             // 2
		};
		static_assert(sizeof(ChangeHandler) == 0x8);

		// Add
		virtual ~GTexture() {}                                                                                                                                                                                                                           // 0
		virtual bool         InitializeTexture(GImageBase* image, Utility::Enumeration<ImageTextureUsage, std::uint32_t> usage = ImageTextureUsage::kWrap)                                                                                          = 0; // 1
		virtual bool         InitializeDynamicTexture(std::int32_t width, std::int32_t height, Utility::Enumeration<GImage::ImageFormat, std::uint32_t> format, std::int32_t mipMaps, Utility::Enumeration<ImageTextureUsage, std::uint32_t> usage) = 0; // 2
		virtual void         Update(std::int32_t level, std::int32_t count, const UpdateRectangle* rectangles, const GImageBase* image)                                                                                                             = 0; // 3
		virtual std::int32_t Map(std::int32_t level, std::int32_t count, MapRectangle* maps, Utility::Enumeration<MapFlags, std::uint32_t> flags = MapFlags::kNone)                                                                                 = 0; // 4
		virtual bool         Unmap(std::int32_t level, std::int32_t count, MapRectangle* maps, Utility::Enumeration<MapFlags, std::uint32_t> flags = MapFlags::kNone)                                                                               = 0; // 5
		virtual GRenderer*   GetRenderer() const                                                                                                                                                                                                    = 0; // 6
		virtual bool         IsDataValid() const                                                                                                                                                                                                    = 0; // 7
		virtual Handle       GetUserData() const                                                                                                                                                                                                    = 0; // 8
		virtual void         SetUserData(Handle data)                                                                                                                                                                                               = 0; // 9
		virtual void         AddChangeHandler(ChangeHandler* handler)                                                                                                                                                                               = 0; // A
		virtual void         RemoveChangeHandler(ChangeHandler* handler)                                                                                                                                                                            = 0; // B

		// Member functions
		void         AddReference();
		bool         AddReferenceNotZero();
		std::int32_t GetReferenceCount();
		void         Release();

	protected:
		// Member variables
		GAtomicInteger<std::int32_t> referenceCount_; // 8
		std::uint32_t                paddingC_;       // C
	};
	static_assert(sizeof(GTexture) == 0x10);
}
