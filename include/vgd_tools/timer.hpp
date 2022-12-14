#ifndef VGD_TIMER_H
#define VGD_TIMER_H

#include <chrono>
#include <iostream>
#include <string>

namespace vgd {
class Timer {
 private:
  decltype(std::chrono::high_resolution_clock::now()) start_time_;
  std::string task_name_;

 public:
  Timer() : start_time_(std::chrono::high_resolution_clock::now()) {}

  template <typename T>
  Timer(T&& task_name)
      : start_time_(std::chrono::high_resolution_clock::now()),
        task_name_(std::forward<T>(task_name)) {}

  ~Timer() {
    auto end_time = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(
        end_time - start_time_);
    std::cout << task_name_ << "花费了"
              << double(duration.count()) *
                     std::chrono::microseconds::period::num /
                     std::chrono::microseconds::period::den
              << "秒" << std::endl;
  }
};
}  // namespace vgd
#endif  // VGD_TIMER_H