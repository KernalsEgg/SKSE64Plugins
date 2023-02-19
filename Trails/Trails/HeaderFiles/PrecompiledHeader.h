#pragma once

#include <algorithm>  // std::max, std::min
#include <cstdint>    // Fixed width integer types
#include <exception>  // std::exception
#include <filesystem> // Filesystem
#include <format>     // std::make_format_args, std::vformat
#include <fstream>    // std::ifstream
#include <map>        // std::map
#include <memory>     // std::addressof
#include <numbers>    // Mathematical constants
#include <random>     // std::mt19937, std::random_device, std::uniform_int_distribution, std::uniform_real_distribution
#include <set>        // std::set
#include <string.h>   // _stricmp
#include <string>     // std::string, std::stoul
#include <vector>     // std::vector

#include <nlohmann/json.hpp>

#include "Shared/SKSE/SKSE.h"
#include "Shared/Skyrim/Skyrim.h"
