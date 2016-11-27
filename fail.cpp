#include "pin_definitions.h"
#include <Arduino.h>
#include "function_prototypes.h"

/*
 * Fail Code definitions:
 *   1 - Unable to connect to SD card
 *   2 - Unable to open file on SD card
 *   3 - Incorrect valid-character received from GPS
 */
void fail(unsigned short int fail_code){
  while(1){
    for(short int i = 0; i < 4; i++){ // 4 quick flashes, indicating failure
      digitalWrite(LED1, HIGH);
      delay(200);
      digitalWrite(LED1, LOW);
      delay(200);
    }
    for(short int i = 0; i < fail_code; i++){ // # of flashes indicates cause of failure
      digitalWrite(LED2, HIGH);
      delay(400);
      digitalWrite(LED2, LOW);
      delay(400);
    } 
  } 
}
