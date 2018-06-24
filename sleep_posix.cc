#include "sleep.h"

#if ( _POSIX_C_SOURCE >= 200112L ) && ( !NAN_HAS_CPLUSPLUS_11 )

#include <unistd.h>
#include <sys/time.h>

void node_sleep(unsigned seconds) {
  unsigned done = seconds;
  while (done > 0)
  {
    done = sleep(done);
  }
}

void node_usleep(unsigned usec) {
  useconds_t done;
  struct timeval start, end;

  while (usec > 0) {
    gettimeofday(&start, NULL);
    usleep(usec);
    gettimeofday(&end, NULL);

    done = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
    if (done > usec) {
      usec = 0;
    } else {
      usec -= done;
    }
  }
}

void node_nsleep(unsigned nsec) {
  // TODO: should this employ the same logic as usleep above?
  struct timespec req, rem;
  req.tv_sec = 0;
  req.tv_nsec = nsec;
  if (nanosleep(&req, &rem) < 0) {
    // TODO: throw exception here?
    printf("Nanosleep system call failed.\n");
  }
}

#endif
