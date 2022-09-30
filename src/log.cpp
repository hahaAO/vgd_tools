#include "log.h"

#include <chrono>
#include <ctime>
#include <sstream>

namespace vgd {

log::log_level log::global_local_log = log::trace;

static const std::map<log::log_level, const char*> log_level_map = {
    {log::trace, "trace"},     {log::debug, "debug"}, {log::info, "info"},
    {log::warning, "warning"}, {log::error, "error"}, {log::fatal, "fatal"}};

void log::log_print(log_level level, std::string file_name, int line,
                    std::string function_name,
                    std::vector<std::string> messages) {
  if (level < log::global_local_log) {
    return;
  }

  auto now = std::chrono::system_clock::now();
  auto in_time_t = std::chrono::system_clock::to_time_t(now);

  std::string time_str(32, '\0');
  std::strftime(&time_str[0], time_str.size(), "%Y-%m-%d %H:%M:%S",
                std::localtime(&in_time_t));

  std::string message;

  for (auto& s : messages) {
    message += s;
  }

  fprintf(stdout, "%s [%s] %s %d %s message:%s\n", time_str.c_str(),
          log_level_map.at(level), file_name.c_str(), line,
          function_name.c_str(), message.c_str());
}

}  // namespace vgd