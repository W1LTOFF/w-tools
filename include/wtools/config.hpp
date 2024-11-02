#ifndef WTOOLS_CONFIG
#define WTOOLS_CONFIG

#include <map>
#include <string>

namespace wilt {
class Config {
  private:
    std::map<std::string, std::map<std::string, std::string>> cfg;
    std::string configSrc;

    void read();
    void writeGroup(std::map<std::string, std::string> values,
                    std::string groupName = "config");

  public:
    Config(std::string configPath);

    std::string getValue(std::string group, std::string variable,
                         std::string type = "string");
};
} // namespace wilt

#endif
