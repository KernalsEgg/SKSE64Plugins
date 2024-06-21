#pragma once

#include "PrecompiledHeader.h"



namespace Trails
{
	namespace CaseInsensitiveString
	{
		template <class Character>
		struct CharacterTraits;

		template <>
		struct CharacterTraits<char> :
			public std::char_traits<char>
		{
		public:
			static bool eq(char left, char right)
			{
				return ::_stricmp(std::addressof(left), std::addressof(right)) == 0;
			}

			static bool lt(char left, char right)
			{
				return ::_stricmp(std::addressof(left), std::addressof(right)) < 0;
			}

			static int compare(const char* left, const char* right, std::size_t count)
			{
				return ::_strnicmp(left, right, count);
			}

			static const char* find(const char* string, std::size_t count, char character)
			{
				while (count--)
				{
					if (::_stricmp(string, std::addressof(character)) == 0)
					{
						return string;
					}

					++string;
				}

				return nullptr;
			}
		};

		template <>
		struct CharacterTraits<wchar_t> :
			public std::char_traits<wchar_t>
		{
		public:
			static bool eq(wchar_t left, wchar_t right)
			{
				return ::_wcsicmp(std::addressof(left), std::addressof(right)) == 0;
			}

			static bool lt(wchar_t left, wchar_t right)
			{
				return ::_wcsicmp(std::addressof(left), std::addressof(right)) < 0;
			}

			static int compare(const wchar_t* left, const wchar_t* right, std::size_t count)
			{
				return ::_wcsnicmp(left, right, count);
			}

			static const wchar_t* find(const wchar_t* string, std::size_t count, wchar_t character)
			{
				while (count--)
				{
					if (::_wcsicmp(string, std::addressof(character)) == 0)
					{
						return string;
					}

					++string;
				}

				return nullptr;
			}
		};

		template <class String>
		struct Less;

		template <>
		struct Less<std::string_view>
		{
		public:
			bool operator()(std::string_view left, std::string_view right) const
			{
				return ::_stricmp(left.data(), right.data()) < 0;
			}
		};

		template <>
		struct Less<std::wstring_view>
		{
		public:
			bool operator()(std::wstring_view left, std::wstring_view right) const
			{
				return ::_wcsicmp(left.data(), right.data()) < 0;
			}
		};
	}

	using case_insensitive_string      = std::basic_string<char, CaseInsensitiveString::CharacterTraits<char>>;
	using case_insensitive_wide_string = std::basic_string<wchar_t, CaseInsensitiveString::CharacterTraits<wchar_t>>;
}
