#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GFxPlayerStatistics.h"
#include "Shared/Skyrim/G/GRefCountBase.h"
#include "Shared/Utility/Convert.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class GFxFunctionHandler;
	class GFxMovieDef;
	class GFxValue;

	class GFxMovie :
		public GRefCountBase<GFxMovie, Utility::ToUnderlying(GFxStatisticMovieView::kOtherMemory)> // 0
	{
	public:
		enum class PlayState : std::uint32_t
		{
			kPlaying,
			kStopped
		};
		static_assert(sizeof(PlayState) == 0x4);

		enum class SetVariableType : std::uint32_t
		{
			kNormal,
			kSticky,
			kPermanent
		};
		static_assert(sizeof(SetVariableType) == 0x4);

		enum class SetArrayType : std::uint32_t
		{
			kInteger,
			kDouble,
			kFloat,
			kString,
			kStringW,
			kValue
		};
		static_assert(sizeof(SetArrayType) == 0x4);

		// Add
		virtual GFxMovieDef*  GetMovieDefinition() const                                                                                                                                                                                                                                = 0; // 1
		virtual std::uint32_t GetCurrentFrame() const                                                                                                                                                                                                                                   = 0; // 2
		virtual bool          HasLooped() const                                                                                                                                                                                                                                         = 0; // 3
		virtual void          GotoFrame(std::uint32_t frameNumber)                                                                                                                                                                                                                      = 0; // 4
		virtual bool          GotoLabeledFrame(const char* label, std::int32_t offset = 0)                                                                                                                                                                                              = 0; // 5
		virtual void          SetPlayState(Utility::Enumeration<PlayState, std::uint32_t> playState)                                                                                                                                                                                    = 0; // 6
		virtual PlayState     GetPlayState() const                                                                                                                                                                                                                                      = 0; // 7
		virtual void          SetVisible(bool visible)                                                                                                                                                                                                                                  = 0; // 8
		virtual bool          GetVisible() const                                                                                                                                                                                                                                        = 0; // 9
		virtual bool          IsAvailable(const char* pathToVariable) const                                                                                                                                                                                                             = 0; // A
		virtual void          CreateString(GFxValue* value, const char* string)                                                                                                                                                                                                         = 0; // B
		virtual void          CreateStringW(GFxValue* value, const wchar_t* stringW)                                                                                                                                                                                                    = 0; // C
		virtual void          CreateObject(GFxValue* value, const char* className = nullptr, const GFxValue* arguments = nullptr, std::uint32_t argumentCount = 0)                                                                                                                      = 0; // D
		virtual void          CreateArray(GFxValue* value)                                                                                                                                                                                                                              = 0; // E
		virtual void          CreateFunction(GFxValue* value, GFxFunctionHandler* functionHandler, void* userData = nullptr)                                                                                                                                                            = 0; // F
		virtual bool          SetVariable(const char* pathToVariable, const GFxValue& value, Utility::Enumeration<SetVariableType, std::uint32_t> setType = SetVariableType::kSticky)                                                                                                   = 0; // 10
		virtual bool          GetVariable(GFxValue* value, const char* pathToVariable) const                                                                                                                                                                                            = 0; // 11
		virtual bool          SetVariableArray(Utility::Enumeration<SetArrayType, std::uint32_t> type, const char* pathToVariable, std::uint32_t index, const void* data, std::uint32_t count, Utility::Enumeration<SetVariableType, std::uint32_t> setType = SetVariableType::kSticky) = 0; // 12
		virtual bool          SetVariableArraySize(const char* pathToVariable, std::uint32_t count, Utility::Enumeration<SetVariableType, std::uint32_t> setType = SetVariableType::kSticky)                                                                                            = 0; // 13
		virtual std::uint32_t GetVariableArraySize(const char* pathToVariable)                                                                                                                                                                                                          = 0; // 14
		virtual bool          GetVariableArray(Utility::Enumeration<SetArrayType, std::uint32_t> type, const char* pathToVariable, std::uint32_t index, void* data, std::uint32_t count)                                                                                                = 0; // 15
		virtual bool          InvokeFormat(const char* methodName, GFxValue* result, const char* argumentFormat, ...)                                                                                                                                                                   = 0; // 16
		virtual bool          Invoke(const char* methodName, GFxValue* result, const GFxValue* arguments, std::uint32_t argumentCount)                                                                                                                                                  = 0; // 17
		virtual bool          InvokeArguments(const char* methodName, GFxValue* result, const char* argumentFormat, std::va_list arguments)                                                                                                                                             = 0; // 18

		// Non-member functions
		static float GetRenderPixelScale();

		// Member functions
		bool   SetVariable(const char* pathToVariable, const char* value, Utility::Enumeration<SetVariableType, std::uint32_t> setType = SetVariableType::kSticky);
		bool   SetVariable(const char* pathToVariable, const wchar_t* value, Utility::Enumeration<SetVariableType, std::uint32_t> setType = SetVariableType::kSticky);
		bool   SetVariableDouble(const char* pathToVariable, double value, Utility::Enumeration<SetVariableType, std::uint32_t> setType = SetVariableType::kSticky);
		double GetVariableDouble(const char* pathToVariable) const;
		bool   SetVariableArray(const char* pathToVariable, std::uint32_t index, const GFxValue* data, std::uint32_t count, Utility::Enumeration<SetVariableType, std::uint32_t> setType = SetVariableType::kSticky);
		bool   GetVariableArray(const char* pathToVariable, std::uint32_t index, GFxValue* data, std::uint32_t count);
	};
	static_assert(sizeof(GFxMovie) == 0x10);
}
