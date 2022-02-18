#pragma once

#include "Shared/PCH.h"



namespace Utility
{
	namespace Implementation
	{
		template <class T>
		struct MemberFunctionPointer : std::false_type
		{
		};

		template <class Result, class Class, class... Arguments>
		struct MemberFunctionPointer<Result (Class::*)(Arguments...)>
		{
		public:
			using type = Result (*)(Class*, Arguments...);
		};

		template <class Result, class Class, class... Arguments>
		struct MemberFunctionPointer<Result (Class::*)(Arguments...) const>
		{
		public:
			using type = Result (*)(const Class*, Arguments...);
		};
	}

	template <class T, class Enable = void>
	struct MemberFunctionPointer
	{
	};

	template <class T>
	struct MemberFunctionPointer<
		T,
		typename std::enable_if_t<
			std::is_member_function_pointer_v<T>>> :
		Implementation::MemberFunctionPointer<T>
	{
	};
}
