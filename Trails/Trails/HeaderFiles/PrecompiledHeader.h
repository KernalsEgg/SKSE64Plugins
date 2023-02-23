#pragma once

#include <algorithm>  // std::max, std::min
#include <cstdint>    // Fixed width integer types
#include <exception>  // std::exception
#include <filesystem> // Filesystem library
#include <format>     // std::make_format_args, std::vformat
#include <fstream>    // std::ifstream
#include <map>        // std::map
#include <memory>     // std::addressof, std::make_shared
#include <numbers>    // Mathematical constants
#include <random>     // std::mt19937, std::random_device, std::uniform_int_distribution, std::uniform_real_distribution
#include <set>        // std::set
#include <string.h>   // _stricmp
#include <string>     // std::string, std::stoul
#include <utility>    // std::move
#include <vector>     // std::vector

#include <nlohmann/json.hpp>

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_INFO

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>

#include "Shared/SKSE/SKSE.h"
#include "Shared/Skyrim/Skyrim.h"
