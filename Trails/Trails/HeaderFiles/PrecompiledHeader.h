#pragma once

#include <algorithm>  // std::max, std::min
#include <cstdint>    // Fixed width integer types
#include <exception>  // std::exception
#include <filesystem> // std::filesystem::directory_entry, std::filesystem::directory_iterator, std::filesystem::is_directory, std::filesystem::path
#include <format>     // std::make_format_args, std::vformat
#include <fstream>    // std::ifstream
#include <map>        // std::map
#include <memory>     // std::addressof
#include <numbers>    // Mathematical constants
#include <random>     // std::mt19937, std::random_device, std::uniform_int_distribution, std::uniform_real_distribution
#include <set>        // std::set
#include <string>     // _stricmp, std::string, std::stoul
#include <vector>     // std::vector

#include <nlohmann/json.hpp>

using namespace std::literals;
