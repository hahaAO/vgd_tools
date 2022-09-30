#ifndef VGD_LOG_H
#define VGD_LOG_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

#define VGD_LOG(log_level, ...)                                    \
  vgd::log::log_print(log_level, __FILE__, __LINE__, __FUNCTION__, \
                      {__VA_ARGS__});
#define VGD_LOG_TRACE(...) VGD_LOG(vgd::log::trace, __VA_ARGS__)
#define VGD_LOG_DEBUG(...) VGD_LOG(vgd::log::debug, __VA_ARGS__)
#define VGD_LOG_INFO(...) VGD_LOG(vgd::log::info, __VA_ARGS__)
#define VGD_LOG_WARNING(...) VGD_LOG(vgd::log::warning, __VA_ARGS__)
#define VGD_LOG_ERROR(...) VGD_LOG(vgd::log::error, __VA_ARGS__)
#define VGD_LOG_FATAL(...) VGD_LOG(vgd::log::fatal, __VA_ARGS__)

namespace vgd {
class log {
 public:
  enum log_level {
    trace = 0,
    debug = 1,
    info = 2,
    warning = 3,
    error = 4,
    fatal = 5
  };
  static log_level global_local_log;
  static void log_print(log_level level, std::string file_name, int line,
                        std::string function_name,
                        std::vector<std::string> messages);
};

}  // namespace vgd

#endif  // VGD_LOG_H
