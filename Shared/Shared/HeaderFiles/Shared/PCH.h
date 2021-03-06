#pragma once

#ifndef NOMINMAX
#	define NOMINMAX
#endif

#ifndef WIN32_LEAN_AND_MEAN
#	define WIN32_LEAN_AND_MEAN
#endif

#include <Windows.h>

#include <DirectXMath.h>
#include <Psapi.h>
#include <d3d9types.h>
#include <memoryapi.h>

#include <algorithm>       // std::lower_bound, std::sort
#include <atomic>          // std::atomic_ref, std::atomic_size_t
#include <chrono>          // std::chrono
#include <cmath>           // std::abs, std::pow, std::sqrt
#include <compare>         // std::strong_ordering
#include <concepts>        // std::same_as
#include <cstddef>         // offsetof, std::nullptr_t, std::ptrdiff_t, std::size_t
#include <cstdint>         // Fixed width integer types
#include <exception>       // std::terminate
#include <filesystem>      // std::filesystem::path
#include <fstream>         // std::ifstream, std::ofstream
#include <functional>      // std::equal_to, std::function
#include <ios>             // std::ios
#include <iterator>        // std::forward_iterator_tag
#include <limits>          // std::numeric_limits
#include <memory>          // std::addressof
#include <new>             // Dynamic memory management
#include <optional>        // std::optional
#include <ostream>         // std::endl, std::flush
#include <source_location> // std::source_location
#include <span>            // std::span
#include <sstream>         // std::stringstream, std::wistringstream
#include <string>          // _stricmp, std::char_traits, std::getline, std::stoi, std::string, std::wstring
#include <string_view>     // std::basic_string_view, std::string_view
#include <type_traits>     // Type traits
#include <utility>         // std::forward, std::move
#include <vector>          // std::vector

using namespace std::literals;

#include <fmt/chrono.h> // std::chrono::time_point
#include <fmt/format.h> // fmt::format
