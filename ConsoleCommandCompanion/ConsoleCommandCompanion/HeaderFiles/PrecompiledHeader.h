#pragma once

#include <algorithm>  // std::count_if, std::find_if
#include <cstdint>    // Fixed width integer types
#include <filesystem> // Filesystem library
#include <format>     // std::make_format_args, std::vformat
#include <fstream>    // std::ifstream
#include <memory>     // std::make_shared
#include <optional>   // std::optional
#include <string>     // std::string
#include <utility>    // std::move
#include <vector>     // std::vector

#include <nlohmann/json.hpp>

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_INFO

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>

#include "Shared/SKSE/SKSE.h"
#include "Shared/Skyrim/Skyrim.h"
