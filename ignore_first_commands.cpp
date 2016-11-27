#include "function_prototypes.h"
#include <Adafruit_GPS.h>

void ignore_first_commands(Adafruit_GPS GPS){
  GPS.read();
  while(!GPS.newNMEAreceived()) GPS.read();
  GPS.lastNMEA();
  while(!GPS.newNMEAreceived()) GPS.read();
  GPS.lastNMEA();
  while(!GPS.newNMEAreceived()) GPS.read();
  GPS.lastNMEA();
}
