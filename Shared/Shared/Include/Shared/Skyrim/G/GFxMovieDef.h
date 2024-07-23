#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GFxResource.h"
#include "Shared/Skyrim/G/GFxResourceID.h"
#include "Shared/Skyrim/G/GFxStateBag.h"
#include "Shared/Skyrim/G/GMemoryHeap.h"
#include "Shared/Skyrim/G/GRectangle.h"
#include "Shared/Skyrim/G/GRefCountBase.h"
#include "Shared/Skyrim/G/GStatistics.h"
#include "Shared/Skyrim/S/ScaleformTypes.h"
#include "Shared/Utility/Conversion.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	struct GFxExporterInformation;

	class GFxMovieView;

	class GFxMovieDef :
		public GFxResource, // 0
		public GFxStateBag  // 18
	{
	public:
		enum class FileAttributeFlags : std::uint32_t
		{
			kUseNetwork  = 1U << 0,
			kHasMetadata = 1U << 4
		};
		static_assert(sizeof(FileAttributeFlags) == 0x4);

		enum class VisitResourceMask : std::uint32_t
		{
			kNestedMovies = 1U << 15,

			kFonts          = 1U << 0,
			kBitmaps        = 1U << 1,
			kGradientImages = 1U << 2,
			kEditTextFields = 1U << 3,
			kSounds         = 1U << 4,
			kSprite         = 1U << 5,

			kAllLocalImages = kBitmaps | kGradientImages,
			kAllImages      = kBitmaps | kGradientImages | kNestedMovies
		};
		static_assert(sizeof(VisitResourceMask) == 0x4);

		struct MemoryParameters
		{
		public:
			MemoryParameters(UPInt memoryArena = 0);

			// Member variables
			GMemoryHeap::HeapDescriptor heapDescriptor;           // 0
			float                       heapLimitMultiplier;      // 40
			std::uint32_t               maximumCollectionRoots;   // 44
			std::uint32_t               framesBetweenCollections; // 48
			std::uint32_t               padding4C;                // 4C
		};
		static_assert(offsetof(MemoryParameters, heapDescriptor) == 0x0);
		static_assert(offsetof(MemoryParameters, heapLimitMultiplier) == 0x40);
		static_assert(offsetof(MemoryParameters, maximumCollectionRoots) == 0x44);
		static_assert(offsetof(MemoryParameters, framesBetweenCollections) == 0x48);
		static_assert(sizeof(MemoryParameters) == 0x50);

		struct ImportVisitor
		{
		public:
			// Add
			virtual ~ImportVisitor() {}                                                                                              // 0
			virtual void Visit(GFxMovieDef* parentDefinition, GFxMovieDef* importDefinition, const char* importedMovieFilename) = 0; // 1
		};
		static_assert(sizeof(ImportVisitor) == 0x8);

		struct ResourceVisitor :
			public GFxFileConstants // 0
		{
		public:
			// Add
			virtual ~ResourceVisitor() {}                                                                                                  // 0
			virtual void Visit(GFxMovieDef* movieDefinition, GFxResource* resource, GFxResourceID resourceID, const char* exportName) = 0; // 1
		};
		static_assert(sizeof(ResourceVisitor) == 0x8);

		class MemoryContext :
			public GRefCountBase<MemoryContext, Utility::Conversion::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory)> // 0
		{
		public:
			// Override
			virtual ~MemoryContext() override {} // 0

		protected:
			MemoryContext() {}
		};
		static_assert(sizeof(MemoryContext) == 0x10);

		// Add
		virtual std::uint32_t                 GetVersion() const                                                                                                                                         = 0; // 4
		virtual std::uint32_t                 GetLoadingFrame() const                                                                                                                                    = 0; // 5
		virtual float                         GetWidth() const                                                                                                                                           = 0; // 6
		virtual float                         GetHeight() const                                                                                                                                          = 0; // 7
		virtual std::uint32_t                 GetFrameCount() const                                                                                                                                      = 0; // 8
		virtual float                         GetFrameRate() const                                                                                                                                       = 0; // 9
		virtual GRectangleF                   GetFrameRectangle() const                                                                                                                                  = 0; // A
		virtual std::uint32_t                 GetSWFFlags() const                                                                                                                                        = 0; // B
		virtual const char*                   GetFileURL() const                                                                                                                                         = 0; // C
		virtual void                          WaitForLoadFinish(bool cancel = false) const                                                                                                               = 0; // D
		virtual void                          WaitForFrame(std::uint32_t frame) const                                                                                                                    = 0; // E
		virtual std::uint32_t                 GetFileAttributes() const                                                                                                                                  = 0; // F
		virtual std::uint32_t                 GetMetadata(char* buffer, std::uint32_t bufferSize) const                                                                                                  = 0; // 10
		virtual GMemoryHeap*                  GetLoadDataHeap() const                                                                                                                                    = 0; // 11
		virtual GMemoryHeap*                  GetBindDataHeap() const                                                                                                                                    = 0; // 12
		virtual GMemoryHeap*                  GetImageHeap() const                                                                                                                                       = 0; // 13
		virtual GFxResource*                  GetMovieDataResource() const                                                                                                                               = 0; // 14
		virtual const GFxExporterInformation* GetExporterInformation() const                                                                                                                             = 0; // 15
		virtual MemoryContext*                CreateMemoryContext(const char* heapName, const MemoryParameters& memoryParameters, bool debugHeap)                                                        = 0; // 16
		virtual GFxMovieView*                 CreateInstance(const MemoryParameters& memoryParameters, bool initializeFirstFrame = true)                                                                 = 0; // 17
		virtual GFxMovieView*                 CreateInstance(MemoryContext* memoryContext, bool initializeFirstFrame = true)                                                                             = 0; // 18
		virtual void                          VisitImportedMovies(ImportVisitor* importVisitor)                                                                                                          = 0; // 19
		virtual void                          VisitResources(ResourceVisitor* resourceVisitor, Utility::Enumeration<VisitResourceMask, std::uint32_t> visitResourceMask = VisitResourceMask::kAllImages) = 0; // 1A
		virtual GFxResource*                  GetResource(const char* exportName) const                                                                                                                  = 0; // 1B

		// Member functions
		GFxMovieView* CreateInstance(bool initializeFirstFrame = true, UPInt memoryArena = 0);
	};
	static_assert(sizeof(GFxMovieDef) == 0x20);
}
