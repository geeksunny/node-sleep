#ifndef SLEEP_H
#define SLEEP_H

#include <nan.h>

void node_sleep(unsigned seconds);
void node_usleep(unsigned usec);
void node_msleep(unsigned msec);
void node_nsleep(unsigned nsec);

#endif // SLEEP_H
