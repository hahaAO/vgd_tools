#include <vgd_tools/log.h>

int main() {
  VGD_LOG_DEBUG("Hello, from vgd_tools log DEBUG!");
  VGD_LOG_FATAL("Hello, from vgd_tools log FATAL!");
  VGD_LOG(vgd::log::error, "i m", " ", "vgd_tools\n");
  return EXIT_SUCCESS;
}
