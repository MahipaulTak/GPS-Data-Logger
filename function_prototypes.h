#ifndef FUNC_PROTO
#define FUNC_PROTO

#include <SD.h>
#include <Adafruit_GPS.h>
#include "GPS_struct.h"

void fail(unsigned short int fail_code);
void create_unique_filename(char *buffer);
void ignore_first_commands(Adafruit_GPS GPS);

#endif
