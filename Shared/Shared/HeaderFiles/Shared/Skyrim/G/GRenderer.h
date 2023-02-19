#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GColor.h"
#include "Shared/Skyrim/G/GMatrix2D.h"
#include "Shared/Skyrim/G/GPoint.h"
#include "Shared/Skyrim/G/GRectangle.h"
#include "Shared/Skyrim/G/GRefCountBase.h"
#include "Shared/Skyrim/G/GRendererEventHandler.h"
#include "Shared/Skyrim/G/GStatistics.h"
#include "Shared/Utility/Conversion.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class GFxCachedStroke;
	class GFxMesh;
	class GMatrix3D;
	class GRenderTarget;
	class GStatisticBag;
	class GTexture;
	class GViewport;

	class GRenderer :
		public GRefCountBase<GRenderer, Utility::Conversion::ToUnderlying(GStatisticRenderers::kMemory)> // 0
	{
	public:
		using Point     = GPointF;
		using Rectangle = GRectangleF;
		using Matrix    = GMatrix2D;
		using Handle    = void*;

		enum class BlendType : std::uint32_t
		{
			kNone       = 0,
			kNormal     = 1,
			kLayer      = 2,
			kMultiply   = 3,
			kScreen     = 4,
			kLighten    = 5,
			kDarken     = 6,
			kDifference = 7,
			kAdd        = 8,
			kSubtract   = 9,
			kInvert     = 10,
			kAlpha      = 11,
			kErase      = 12,
			kOverlay    = 13,
			kHardLight  = 14
		};
		static_assert(sizeof(BlendType) == 0x4);

		enum class ResizeImageType : std::uint32_t
		{
			kRGBToRGB,
			kRGBAToRGBA,
			kRGBToRGBA,
			kGray
		};
		static_assert(sizeof(ResizeImageType) == 0x4);

		enum class VertexFormat : std::uint32_t
		{
			kNone      = 0,
			kXY16i     = 1,
			kXY32f     = 2,
			kXY16iC32  = 3,
			kXY16iCF32 = 4
		};
		static_assert(sizeof(VertexFormat) == 0x4);

		enum class IndexFormat : std::uint32_t
		{
			kNone = 0,
			k16   = 1,
			k32   = 2,
		};
		static_assert(sizeof(IndexFormat) == 0x4);

		enum class RenderCapabilityBits : std::uint32_t
		{
			kCacheDataUse     = 1U << 0,
			kIndex16          = 1U << 2,
			kIndex32          = 1U << 3,
			kRenderStatistics = 1U << 4,

			kFillGouraud          = 1U << 8,
			kFillGouraudTexturing = 1U << 9,

			kCxformAdd = 1U << 12,

			kNestedMasks = 1U << 13,

			kTextureNonPower2        = 1U << 14,
			kTextureNonPower2Wrap    = 1U << 15,
			kTextureNonPower2MipMaps = 1U << 19,

			kCanLoseData = 1U << 16,

			kKeepVertexData = 1U << 17,

			kNoTextureOverwrite = 1U << 18,

			kThreadedTextureCreation = 1U << 20,

			kRenderTargets = 1U << 5,

			kRenderTargetPrePass = 1U << 6,

			kRenderTargetNonPower2 = 1U << 7,

			kRenderTargetMipMaps = 1U << 21,

			kFilterBlurs       = 1U << 22,
			kFilterColorMatrix = 1U << 23
		};
		static_assert(sizeof(RenderCapabilityBits) == 0x4);

		enum class StereoDisplay : std::uint32_t
		{
			kCenter,
			kLeft,
			kRight
		};
		static_assert(sizeof(StereoDisplay) == 0x4);

		enum class CachedDataType : std::uint32_t
		{
			kVertex     = 1,
			kIndex      = 2,
			kBitmapList = 3
		};
		static_assert(sizeof(CachedDataType) == 0x4);

		enum class UserDataPropertyFlag : std::uint32_t
		{
			kNone = 0,
			kHasString,
			kHasFloat,
			kHasMatrix
		};
		static_assert(sizeof(UserDataPropertyFlag) == 0x4);

		enum class BitmapWrapMode : std::uint32_t
		{
			kRepeat,
			kClamp
		};
		static_assert(sizeof(BitmapWrapMode) == 0x4);

		enum class BitmapSampleMode : std::uint32_t
		{
			kPoint,
			kLinear
		};
		static_assert(sizeof(BitmapSampleMode) == 0x4);

		enum class GouraudFillType : std::uint32_t
		{
			kColor,
			k1Texture,
			k1TextureColor,
			k2Texture,
			k2TextureColor,
			k3Texture
		};
		static_assert(sizeof(GouraudFillType) == 0x4);

		enum class SubmitMaskMode : std::uint32_t
		{
			kClear,
			kIncrement,
			kDecrement
		};
		static_assert(sizeof(SubmitMaskMode) == 0x4);

		enum class FilterModes : std::uint32_t
		{
			kBlur      = 1U << 0,
			kShadow    = 1U << 1,
			kHighlight = 1U << 2,

			kKnockout   = 1U << 8,
			kInner      = 1U << 9,
			kHideObject = 1U << 10,

			kUserModes    = 0xFFFF,
			kSkipLastPass = 1U << 16,
			kLastPassOnly = 1U << 17
		};
		static_assert(sizeof(FilterModes) == 0x4);

		enum class FilterSupport : std::uint32_t
		{
			kNone      = 0,
			kOk        = 1U << 0,
			kMultipass = 1U << 1,
			kSlow      = 1U << 2
		};
		static_assert(sizeof(FilterSupport) == 0x4);

		struct StereoParameters
		{
		public:
			StereoParameters();

			// Member variables
			float displayWidthCentimeters;  // 0
			float distortion;               // 4
			float displayDiagonalInches;    // 8
			float displayAspectRatio;       // C
			float eyeSeparationCentimeters; // 10
		};
		static_assert(offsetof(StereoParameters, displayWidthCentimeters) == 0x0);
		static_assert(offsetof(StereoParameters, distortion) == 0x4);
		static_assert(offsetof(StereoParameters, displayDiagonalInches) == 0x8);
		static_assert(offsetof(StereoParameters, displayAspectRatio) == 0xC);
		static_assert(offsetof(StereoParameters, eyeSeparationCentimeters) == 0x10);
		static_assert(sizeof(StereoParameters) == 0x14);

		struct RenderCapabilities
		{
		public:
			// Member variables
			std::uint32_t capabilityBits;     // 0
			std::uint32_t vertexFormats;      // 4
			std::uint32_t blendModes;         // 8
			std::uint32_t maximumTextureSize; // C
		};
		static_assert(offsetof(RenderCapabilities, capabilityBits) == 0x0);
		static_assert(offsetof(RenderCapabilities, vertexFormats) == 0x4);
		static_assert(offsetof(RenderCapabilities, blendModes) == 0x8);
		static_assert(offsetof(RenderCapabilities, maximumTextureSize) == 0xC);
		static_assert(sizeof(RenderCapabilities) == 0x10);

		struct UserData
		{
		public:
			UserData();

			// Member variables
			const char*                                              string;        // 0
			float*                                                   number;        // 8
			float*                                                   matrix;        // 10
			std::uint32_t                                            matrixSize;    // 18
			Utility::Enumeration<UserDataPropertyFlag, std::uint8_t> propertyFlags; // 1C
			std::uint8_t                                             padding1D;     // 1D
			std::uint16_t                                            padding1E;     // 1E
		};
		static_assert(offsetof(UserData, string) == 0x0);
		static_assert(offsetof(UserData, number) == 0x8);
		static_assert(offsetof(UserData, matrix) == 0x10);
		static_assert(offsetof(UserData, matrixSize) == 0x18);
		static_assert(offsetof(UserData, propertyFlags) == 0x1C);
		static_assert(sizeof(UserData) == 0x20);

		struct FillTexture
		{
		public:
			// Member variables
			GTexture*                                             texture;       // 0
			Matrix                                                textureMatrix; // 8
			Utility::Enumeration<BitmapWrapMode, std::uint32_t>   wrapMode;      // 20
			Utility::Enumeration<BitmapSampleMode, std::uint32_t> sampleMode;    // 24
		};
		static_assert(offsetof(FillTexture, texture) == 0x0);
		static_assert(offsetof(FillTexture, textureMatrix) == 0x8);
		static_assert(offsetof(FillTexture, wrapMode) == 0x20);
		static_assert(offsetof(FillTexture, sampleMode) == 0x24);
		static_assert(sizeof(FillTexture) == 0x28);

		struct VertexXY16i
		{
		public:
			// Member variables
			std::int16_t x; // 0
			std::int16_t y; // 2
		};
		static_assert(offsetof(VertexXY16i, x) == 0x0);
		static_assert(offsetof(VertexXY16i, y) == 0x2);
		static_assert(sizeof(VertexXY16i) == 0x4);

		struct VertexXY16iC32
		{
		public:
			enum
			{
				kVertexFormat = VertexFormat::kXY16iC32
			};

			// Member variables
			std::int16_t  x;     // 0
			std::int16_t  y;     // 2
			std::uint32_t color; // 4
		};
		static_assert(offsetof(VertexXY16iC32, x) == 0x0);
		static_assert(offsetof(VertexXY16iC32, y) == 0x2);
		static_assert(offsetof(VertexXY16iC32, color) == 0x4);
		static_assert(sizeof(VertexXY16iC32) == 0x8);

		struct VertexXY16iCF32
		{
		public:
			enum
			{
				kVertexFormat = VertexFormat::kXY16iCF32
			};

			// Member variables
			std::int16_t  x;       // 0
			std::int16_t  y;       // 2
			std::uint32_t color;   // 4
			std::uint32_t factors; // 8
		};
		static_assert(offsetof(VertexXY16iCF32, x) == 0x0);
		static_assert(offsetof(VertexXY16iCF32, y) == 0x2);
		static_assert(offsetof(VertexXY16iCF32, color) == 0x4);
		static_assert(offsetof(VertexXY16iCF32, factors) == 0x8);
		static_assert(sizeof(VertexXY16iCF32) == 0xC);

		struct BitmapDescriptor
		{
		public:
			// Member variables
			Rectangle coordinates;        // 0
			Rectangle textureCoordinates; // 10
			GColor    color;              // 20
		};
		static_assert(offsetof(BitmapDescriptor, coordinates) == 0x0);
		static_assert(offsetof(BitmapDescriptor, textureCoordinates) == 0x10);
		static_assert(offsetof(BitmapDescriptor, color) == 0x20);
		static_assert(sizeof(BitmapDescriptor) == 0x24);

		struct DistanceFieldParameters
		{
		public:
			// Member variables
			float   width;        // 0
			float   shadowWidth;  // 4
			GColor  shadowColor;  // 8
			GPointF shadowOffset; // C
			GColor  glowColor;    // 14
			float   glowSize[2];  // 18
		};
		static_assert(offsetof(DistanceFieldParameters, width) == 0x0);
		static_assert(offsetof(DistanceFieldParameters, shadowWidth) == 0x4);
		static_assert(offsetof(DistanceFieldParameters, shadowColor) == 0x8);
		static_assert(offsetof(DistanceFieldParameters, shadowOffset) == 0xC);
		static_assert(offsetof(DistanceFieldParameters, glowColor) == 0x14);
		static_assert(offsetof(DistanceFieldParameters, glowSize) == 0x18);
		static_assert(sizeof(DistanceFieldParameters) == 0x20);

		class Statistics
		{
		public:
			Statistics();

			// Member functions
			void Clear();

			// Member variables
			std::uint32_t triangles;  // 0
			std::uint32_t lines;      // 4
			std::uint32_t primitives; // 8
			std::uint32_t masks;      // C
			std::uint32_t filters;    // 10
		};
		static_assert(offsetof(Statistics, triangles) == 0x0);
		static_assert(offsetof(Statistics, lines) == 0x4);
		static_assert(offsetof(Statistics, primitives) == 0x8);
		static_assert(offsetof(Statistics, masks) == 0xC);
		static_assert(offsetof(Statistics, filters) == 0x10);
		static_assert(sizeof(Statistics) == 0x14);

		class CacheProvider;

		class CachedData
		{
		private:
			friend class CacheProvider;

		public:
			// Member functions
			GRenderer* GetRenderer() const;
			Handle     GetRendererData() const;
			void       SetRendererData(Handle data);

		private:
			// Member variables
			GRenderer* renderer_; // 0
			Handle     data_;     // 8
		};
		static_assert(sizeof(CachedData) == 0x10);

		class CacheProvider
		{
		private:
			friend class GFxCachedStroke;
			friend class GFxMesh;

		public:
			// Member functions
			bool CanDiscardData();

		private:
			// Member variables
			CachedData*   data_;              // 0
			bool          discardSharedData_; // 8
			std::uint8_t  padding9_;          // 9
			std::uint16_t paddingA_;          // A
			std::uint32_t paddingC_;          // C
		};
		static_assert(sizeof(CacheProvider) == 0x10);

		class Cxform
		{
		public:
			enum class Color
			{
				kRed,
				kGreen,
				kBlue,
				kAlpha,
				kTotal
			};

			enum class Operation
			{
				kMultiply,
				kAdd,
				kTotal
			};

			// Member functions
			bool operator==(const Cxform& right) const;

			// Non-member variables
			static Cxform Identity;

			// Member variables
			float elements[Utility::Conversion::ToUnderlying(Color::kTotal)][Utility::Conversion::ToUnderlying(Operation::kTotal)]{
				{ 1.0F, 1.0F },
				{ 1.0F, 1.0F },
				{ 0.0F, 0.0F },
				{ 0.0F, 0.0F }
			}; // 0, [RGBA][Multiply, Add]
		};
		static_assert(offsetof(Cxform, elements) == 0x0);
		static_assert(sizeof(Cxform) == 0x20);

		struct BlurFilterParameters
		{
		public:
			// Member functions
			bool operator==(const BlurFilterParameters& right) const;

			// Member variables
			std::uint32_t mode;     // 0
			float         blurX;    // 4
			float         blurY;    // 8
			std::uint32_t passes;   // C
			GPointF       offset;   // 10
			GColor        color;    // 18
			GColor        color2;   // 1C
			float         strength; // 20
			Cxform        cxform;   // 24
		};
		static_assert(offsetof(BlurFilterParameters, mode) == 0x0);
		static_assert(offsetof(BlurFilterParameters, blurX) == 0x4);
		static_assert(offsetof(BlurFilterParameters, blurY) == 0x8);
		static_assert(offsetof(BlurFilterParameters, passes) == 0xC);
		static_assert(offsetof(BlurFilterParameters, offset) == 0x10);
		static_assert(offsetof(BlurFilterParameters, color) == 0x18);
		static_assert(offsetof(BlurFilterParameters, color2) == 0x1C);
		static_assert(offsetof(BlurFilterParameters, strength) == 0x20);
		static_assert(offsetof(BlurFilterParameters, cxform) == 0x24);
		static_assert(sizeof(BlurFilterParameters) == 0x44);

		// Override
		virtual ~GRenderer() override; // 0

		// Add
		virtual bool           GetRenderCapabilities(RenderCapabilities* capabilities) = 0;                                                                                                                                                                                                 // 1
		virtual GTexture*      CreateTexture()                                         = 0;                                                                                                                                                                                                 // 2
		virtual GTexture*      CreateTextureYUV()                                      = 0;                                                                                                                                                                                                 // 3
		virtual void           BeginFrame() {}                                                                                                                                                                                                                                              // 4
		virtual void           EndFrame();                                                                                                                                                                                                                                                  // 5
		virtual GRenderTarget* CreateRenderTarget()                                                                                                = 0;                                                                                                                                     // 6
		virtual void           SetDisplayRenderTarget(GRenderTarget* renderTarget, bool setState = true)                                           = 0;                                                                                                                                     // 7
		virtual void           PushRenderTarget(const GRectangleF& frameRectangle, GRenderTarget* renderTarget)                                    = 0;                                                                                                                                     // 8
		virtual void           PopRenderTarget()                                                                                                   = 0;                                                                                                                                     // 9
		virtual GTexture*      PushTemporaryRenderTarget(const GRectangleF& frameRectangle, std::uint32_t targetWidth, std::uint32_t targetHeight) = 0;                                                                                                                                     // A
		virtual void           ReleaseTemporaryRenderTargets(std::uint32_t keepArea) {}                                                                                                                                                                                                     // B
		virtual void           BeginDisplay(GColor backgroundColor, const GViewport& viewport, float x0, float x1, float y0, float y1) = 0;                                                                                                                                                 // C
		virtual void           EndDisplay()                                                                                            = 0;                                                                                                                                                 // D
		virtual void           SetMatrix(const Matrix& matrix)                                                                         = 0;                                                                                                                                                 // E
		virtual void           SetUserMatrix(const Matrix& matrix)                                                                     = 0;                                                                                                                                                 // F
		virtual void           SetCxform(const Cxform& cxform)                                                                         = 0;                                                                                                                                                 // 10
		virtual void           PushBlendMode(Utility::Enumeration<BlendType, std::uint32_t> mode)                                      = 0;                                                                                                                                                 // 11
		virtual void           PopBlendMode()                                                                                          = 0;                                                                                                                                                 // 12
		virtual bool           PushUserData(UserData* data) { return false; }                                                                                                                                                                                                               // 13
		virtual void           PopUserData() {}                                                                                                                                                                                                                                             // 14
		virtual void           SetPerspective3D(const GMatrix3D& projectionMatrixInput) = 0;                                                                                                                                                                                                // 15
		virtual void           SetView3D(const GMatrix3D& viewMatrixInput)              = 0;                                                                                                                                                                                                // 16
		virtual void           SetWorld3D(const GMatrix3D* worldMatrixInput)            = 0;                                                                                                                                                                                                // 17
		virtual void           SetStereoParameters(StereoParameters parameters);                                                                                                                                                                                                            // 18
		virtual void           SetStereoDisplay(StereoDisplay display, bool setState = false) {}                                                                                                                                                                                            // 19
		virtual void           SetVertexData(const void* vertices, std::int32_t vertexCount, Utility::Enumeration<VertexFormat, std::uint32_t> vertexFormat, CacheProvider* cache = nullptr)                                        = 0;                                                    // 1A
		virtual void           SetIndexData(const void* indices, std::int32_t indexCount, Utility::Enumeration<IndexFormat, std::uint32_t> indexFormat, CacheProvider* cache = nullptr)                                             = 0;                                                    // 1B
		virtual void           ReleaseCachedData(CachedData* data, Utility::Enumeration<CachedDataType, std::uint32_t> type)                                                                                                        = 0;                                                    // 1C
		virtual void           DrawIndexedTriangleList(std::int32_t baseVertexIndex, std::int32_t minimumVertexIndex, std::int32_t vertexCount, std::int32_t startIndex, std::int32_t triangleCount)                                = 0;                                                    // 1D
		virtual void           DrawLineStrip(std::int32_t baseVertexIndex, std::int32_t lineCount)                                                                                                                                  = 0;                                                    // 1E
		virtual void           LineStyleDisable()                                                                                                                                                                                   = 0;                                                    // 1F
		virtual void           LineStyleColor(GColor color)                                                                                                                                                                         = 0;                                                    // 20
		virtual void           FillStyleDisable()                                                                                                                                                                                   = 0;                                                    // 21
		virtual void           FillStyleColor(GColor color)                                                                                                                                                                         = 0;                                                    // 22
		virtual void           FillStyleBitmap(const FillTexture* fill)                                                                                                                                                             = 0;                                                    // 23
		virtual void           FillStyleGouraud(Utility::Enumeration<GouraudFillType, std::uint32_t> fillType, const FillTexture* texture0 = nullptr, const FillTexture* texture1 = nullptr, const FillTexture* texture2 = nullptr) = 0;                                                    // 24
		virtual void           DrawBitmaps(BitmapDescriptor* bitmapList, std::int32_t listSize, std::int32_t startIndex, std::int32_t count, const GTexture* textureInput, const Matrix& matrix, CacheProvider* cache = nullptr)    = 0;                                                    // 25
		virtual void           DrawDistanceFieldBitmaps(BitmapDescriptor* bitmapList, std::int32_t listSize, std::int32_t startIndex, std::int32_t count, const GTexture* textureInput, const Matrix& matrix, const DistanceFieldParameters& parameters, CacheProvider* cache = nullptr) {} // 26
		virtual void           BeginSubmitMask(Utility::Enumeration<SubmitMaskMode, std::uint32_t> maskMode = SubmitMaskMode::kClear)                                                                  = 0;                                                                                 // 27
		virtual void           EndSubmitMask()                                                                                                                                                         = 0;                                                                                 // 28
		virtual void           DisableMask()                                                                                                                                                           = 0;                                                                                 // 29
		virtual std::uint32_t  CheckFilterSupport(const BlurFilterParameters& parameters)                                                                                                              = 0;                                                                                 // 2A
		virtual void           DrawBlurRectangle(GTexture* sourceInput, const GRectangleF& inputSourceRectangle, const GRectangleF& inputDestinationRectangle, const BlurFilterParameters& parameters) = 0;                                                                                 // 2B
		virtual void           DrawColorMatrixRectangle(GTexture* sourceInput, const GRectangleF& inputSourceRectangle, const GRectangleF& destinationRectangle, const float* matrix)                  = 0;                                                                                 // 2C
		virtual void           GetRenderStatistics(Statistics* statistics, bool resetStatistics = false)                                                                                               = 0;                                                                                 // 2D
		virtual void           GetStatistics(GStatisticBag* bag, bool reset = true)                                                                                                                    = 0;                                                                                 // 2E
		virtual void           ReleaseResources()                                                                                                                                                      = 0;                                                                                 // 2F
		virtual bool           AddEventHandler(GRendererEventHandler* handler);                                                                                                                                                                                                             // 30
		virtual void           RemoveEventHandler(GRendererEventHandler* handler);                                                                                                                                                                                                          // 31

	protected:
		// Member variables
		GList<GRendererEventHandler>                       handlers_;           // 10
		StereoParameters                                   stereo3DParameters_; // 20
		Utility::Enumeration<StereoDisplay, std::uint32_t> stereo3DDisplay_;    // 34
	};
	static_assert(sizeof(GRenderer) == 0x38);
}
