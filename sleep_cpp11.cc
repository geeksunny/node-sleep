#include "sleep.h"

#if NAN_HAS_CPLUSPLUS_11

#include <thread>
#include <chrono>

void node_sleep(unsigned seconds) {
  std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void node_usleep(unsigned usec) {
  std::this_thread::sleep_for(std::chrono::microseconds(usec));
}

void node_nsleep(unsigned nsec) {
  std::this_thread::sleep_for(std::chrono::nanoseconds(nsec));
}

#endif
