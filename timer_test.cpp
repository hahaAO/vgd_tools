#include <thread>
#include <vgd_tools/timer.hpp>

using namespace std::chrono;
int main() {
  vgd::Timer t1("main func");
  {
    vgd::Timer t_no_name;
    vgd::Timer t2("wait 2s");
    std::this_thread::sleep_for(2s);
  }

  return EXIT_SUCCESS;
}
