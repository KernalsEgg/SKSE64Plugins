#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Utility::TypeTraits
{
	namespace Implementation
	{
		template <class T>
		struct AddVariadicArguments
		{
		};

		template <class Result, class Class, class... Arguments>
		struct AddVariadicArguments<Result (Class::*)(Arguments...)>
		{
		public:
			using type = Result (Class::*)(Arguments..., ...);
		};

		template <class Result, class Class, class... Arguments>
		struct AddVariadicArguments<Result (Class::*)(Arguments...) const>
		{
		public:
			using type = Result (Class::*)(Arguments..., ...) const;
		};

		template <class Result, class... Arguments>
		struct AddVariadicArguments<Result (*)(Arguments...)>
		{
		public:
			using type = Result (*)(Arguments..., ...);
		};

		template <class T>
		struct MakeFunctionPointer
		{
		};

		template <class Result, class Class, class... Arguments>
		struct MakeFunctionPointer<Result (Class::*)(Arguments...)>
		{
		public:
			using type = Result (*)(Class*, Arguments...);
		};

		template <class Result, class Class, class... Arguments>
		struct MakeFunctionPointer<Result (Class::*)(Arguments..., ...)>
		{
		public:
			using type = Result (*)(Class*, Arguments..., ...);
		};

		template <class Result, class Class, class... Arguments>
		struct MakeFunctionPointer<Result (Class::*)(Arguments...) const>
		{
		public:
			using type = Result (*)(const Class*, Arguments...);
		};

		template <class Result, class Class, class... Arguments>
		struct MakeFunctionPointer<Result (Class::*)(Arguments..., ...) const>
		{
		public:
			using type = Result (*)(const Class*, Arguments..., ...);
		};
	}

	template <class T, class Enable = void>
	struct AddVariadicArguments
	{
	};

	template <class T>
	struct AddVariadicArguments<
		T,
		typename std::enable_if_t<
			std::is_member_function_pointer_v<T> || (std::is_pointer_v<T> && std::is_function_v<std::remove_pointer_t<T>>)>> :
		Implementation::AddVariadicArguments<T>
	{
	};

	template <class T, class Enable = void>
	struct MakeFunctionPointer
	{
	};

	template <class T>
	struct MakeFunctionPointer<
		T,
		typename std::enable_if_t<
			std::is_member_function_pointer_v<T>>> :
		Implementation::MakeFunctionPointer<T>
	{
	};
}
