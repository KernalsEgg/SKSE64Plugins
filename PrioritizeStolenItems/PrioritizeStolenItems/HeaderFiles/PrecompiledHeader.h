#pragma once

#include <algorithm>  // std::min
#include <cmath>      // std::abs
#include <cstdint>    // Fixed width integer types
#include <filesystem> // Filesystem library
#include <functional> // std::function
#include <memory>     // std::addressof
#include <optional>   // std::optional
#include <queue>      // std::priority_queue
#include <utility>    // std::pair

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_INFO

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>

#include "Shared/SKSE/SKSE.h"
#include "Shared/Skyrim/Skyrim.h"
