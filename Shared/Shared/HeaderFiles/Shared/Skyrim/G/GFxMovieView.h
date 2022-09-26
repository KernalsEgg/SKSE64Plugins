#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GColor.h"
#include "Shared/Skyrim/G/GFxMovie.h"
#include "Shared/Skyrim/G/GFxMovieDef.h"
#include "Shared/Skyrim/G/GFxStateBag.h"
#include "Shared/Skyrim/G/GPoint.h"
#include "Shared/Skyrim/G/GPoint3.h"
#include "Shared/Skyrim/G/GRectangle.h"
#include "Shared/Skyrim/G/GRenderer.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class GFxEvent;
	class GMatrix3D;
	class GMemoryHeap;
	class GStatisticBag;
	class GViewport;

	class GFxMovieView :
		public GFxMovie,   // 0
		public GFxStateBag // 10
	{
	public:
		enum class ScaleModeType : std::uint32_t
		{
			kNoScale,
			kShowAll,
			kExactFit,
			kNoBorder
		};
		static_assert(sizeof(ScaleModeType) == 0x4);

		enum class AlignType : std::uint32_t
		{
			kCenter,
			kTopCenter,
			kBottomCenter,
			kCenterLeft,
			kCenterRight,
			kTopLeft,
			kTopRight,
			kBottomLeft,
			kBottomRight
		};
		static_assert(sizeof(AlignType) == 0x4);

		enum class HandleEventReturnValueType : std::uint32_t
		{
			kNotHandled      = 0,
			kHandled         = 1U << 0,
			kNoDefaultAction = 1U << 1,
			kCompleted       = kHandled | kNoDefaultAction
		};
		static_assert(sizeof(HandleEventReturnValueType) == 0x4);

		enum class HitTestType : std::uint32_t
		{
			kBounds            = 0,
			kShapes            = 1,
			kButtonEvents      = 2,
			kShapesNoInvisible = 3
		};
		static_assert(sizeof(HitTestType) == 0x4);

		// Add
		virtual void                        SetViewport(const GViewport& viewDescription)                                                                                                               = 0; // 19
		virtual void                        GetViewport(GViewport* viewDescription) const                                                                                                               = 0; // 1A
		virtual void                        SetViewScaleMode(Utility::Enumeration<ScaleModeType, std::uint32_t> type)                                                                                   = 0; // 1B
		virtual ScaleModeType               GetViewScaleMode() const                                                                                                                                    = 0; // 1C
		virtual void                        SetViewAlignment(Utility::Enumeration<AlignType, std::uint32_t> type)                                                                                       = 0; // 1D
		virtual AlignType                   GetViewAlignment() const                                                                                                                                    = 0; // 1E
		virtual GRectangleF                 GetVisibleFrameRectangle() const                                                                                                                            = 0; // 1F
		virtual void                        SetPerspective3D(const GMatrix3D& projectionMatrixInput)                                                                                                    = 0; // 20
		virtual void                        SetView3D(const GMatrix3D& viewMatrixInput)                                                                                                                 = 0; // 21
		virtual GRectangleF                 GetSafeRectangle() const                                                                                                                                    = 0; // 22
		virtual void                        SetSafeRectangle(const GRectangleF& rectangle)                                                                                                              = 0; // 23
		virtual void                        Restart()                                                                                                                                                   = 0; // 24
		virtual float                       Advance(float deltaTime, std::uint32_t frameCatchUpCount = 2)                                                                                               = 0; // 25
		virtual void                        Display()                                                                                                                                                   = 0; // 26
		virtual void                        DisplayPrePass()                                                                                                                                            = 0; // 27
		virtual void                        SetPause(bool pause)                                                                                                                                        = 0; // 28
		virtual bool                        IsPaused() const                                                                                                                                            = 0; // 29
		virtual void                        SetBackgroundColor(const GColor backgroundColor)                                                                                                            = 0; // 2A
		virtual void                        SetBackgroundAlpha(float alpha)                                                                                                                             = 0; // 2B
		virtual float                       GetBackgroundAlpha() const                                                                                                                                  = 0; // 2C
		virtual std::uint32_t               HandleEvent(const GFxEvent& event)                                                                                                                          = 0; // 2D
		virtual void                        GetMouseState(std::uint32_t mouseIndex, float* x, float* y, std::uint32_t* buttons)                                                                         = 0; // 2E
		virtual void                        NotifyMouseState(float x, float y, std::uint32_t buttons, std::uint32_t mouseIndex = 0)                                                                     = 0; // 2F
		virtual bool                        HitTest(float x, float y, Utility::Enumeration<HitTestType, std::uint32_t> testCondition = HitTestType::kShapes, std::uint32_t controllerIndex = 0)         = 0; // 30
		virtual bool                        HitTest3D(GPoint3F* out, float x, float y, std::uint32_t controllerIndex = 0)                                                                               = 0; // 31
		virtual void                        SetExternalInterfaceReturnValue(const GFxValue& returnValue)                                                                                                = 0; // 32
		virtual void*                       GetUserData() const                                                                                                                                         = 0; // 33
		virtual void                        SetUserData(void* userData)                                                                                                                                 = 0; // 34
		virtual bool                        AttachDisplayCallback(const char* pathToObject, void (*callback)(void* user), void* user)                                                                   = 0; // 35
		virtual bool                        IsMovieFocused() const                                                                                                                                      = 0; // 36
		virtual bool                        GetDirtyFlag(bool doReset = true)                                                                                                                           = 0; // 37
		virtual void                        SetMouseCursorCount(std::uint32_t count)                                                                                                                    = 0; // 38
		virtual std::uint32_t               GetMouseCursorCount() const                                                                                                                                 = 0; // 39
		virtual void                        SetControllerCount(std::uint32_t count)                                                                                                                     = 0; // 3A
		virtual std::uint32_t               GetControllerCount() const                                                                                                                                  = 0; // 3B
		virtual void                        GetStatistics(GStatisticBag* bag, bool reset = true)                                                                                                        = 0; // 3C
		virtual GMemoryHeap*                GetHeap() const                                                                                                                                             = 0; // 3D
		virtual void                        ForceCollectGarbage()                                                                                                                                       = 0; // 3E
		virtual GPointF                     TranslateToScreen(const GPointF& point, GRenderer::Matrix userMatrix = GRenderer::Matrix::Identity)                                                         = 0; // 3F
		virtual GRectangleF                 TranslateToScreen(const GRectangleF& point, GRenderer::Matrix userMatrix = GRenderer::Matrix::Identity)                                                     = 0; // 40
		virtual bool                        TranslateLocalToScreen(const char* pathToCharacter, const GPointF& point, GPointF* resultPoint, GRenderer::Matrix userMatrix = GRenderer::Matrix::Identity) = 0; // 41
		virtual bool                        SetControllerFocusGroup(std::uint32_t controllerIndex, std::uint32_t focusGroupIndex)                                                                       = 0; // 42
		virtual std::uint32_t               GetControllerFocusGroup(std::uint32_t controllerIndex) const                                                                                                = 0; // 43
		virtual GFxMovieDef::MemoryContext* GetMemoryContext() const                                                                                                                                    = 0; // 44
		virtual void                        Release()                                                                                                                                                   = 0; // 45
	};
	static_assert(sizeof(GFxMovieView) == 0x18);
}
