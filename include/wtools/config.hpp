#ifndef WTOOLS_CONFIG
#define WTOOLS_CONFIG

#include <map>
#include <string>

namespace wt {
class Config {
  private:
    std::map<std::string, std::map<std::string, std::string>> conf;

  public:
    Config(std::string configPath);
    std::string getValue(std::string group, std::string variable,
                         std::string type = "string");
};
} // namespace wt

#endif
