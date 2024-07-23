#pragma once

#include <algorithm>   // std::max, std::min
#include <cstddef>     // std::size_t
#include <cstdint>     // Fixed width integer types
#include <filesystem>  // Filesystem library
#include <fstream>     // std::ifstream
#include <map>         // std::map, std::multimap
#include <memory>      // std::addressof, std::make_shared
#include <numbers>     // Mathematical constants
#include <random>      // std::mersenne_twister_engine, std::random_device, std::uniform_int_distribution, std::uniform_real_distribution
#include <string.h>    // _stricmp, _strnicmp, _wcsicmp, _wcsnicmp
#include <string>      // std::basic_string, std::char_traits, std::string
#include <string_view> // std::string_view, std::wstring_view
#include <utility>     // std::move

#include <nlohmann/json.hpp>

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_INFO

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>

#include "Shared/SKSE/SKSE.h"
#include "Shared/Skyrim/Skyrim.h"
