#include "function_prototypes.h"
#include <Adafruit_GPS.h>

//This function ignores the first three data results from the GPS, because they end up being responses
//  to the commands that we give it, and aren't useful to us
void ignore_first_commands(Adafruit_GPS GPS){
  GPS.read();
  while(!GPS.newNMEAreceived()) GPS.read();
  GPS.lastNMEA();
  while(!GPS.newNMEAreceived()) GPS.read();
  GPS.lastNMEA();
  while(!GPS.newNMEAreceived()) GPS.read();
  GPS.lastNMEA();
}
