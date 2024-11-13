#include "wtools/system/filesystem.hpp"
#include <filesystem>

const char *wilt::fullPath(const char *relativePath) {
    return (const char *)std::filesystem::absolute(relativePath).c_str();
}

const char *wilt::currentPath() { return (const char *)std::filesystem::current_path().c_str(); }
