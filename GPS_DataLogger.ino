#include <Arduino.h>
#include <SD.h>
#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>

#include "pin_definitions.h"
#include "function_prototypes.h"
#include "GPS_struct.h"

SoftwareSerial mySerial(3,2);

char gps_filename[50];
char received_data[80];
File file_GPSdata;

Adafruit_GPS GPS(&mySerial);

void setup(){
  delay(1000); // Temporary for testing
  
  pinMode(LED1, OUTPUT); // Test LEDs
  pinMode(LED2, OUTPUT);  
  
  //Setup SD card
  if(!SD.begin(10)){ // Check if SD card can be accessed
    fail(1);
  }
  
  GPS.begin(9600);
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCONLY); // Using recommended minimum output
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ); // Receive data at 1hz
  
  delay(1000);
  
  ignore_first_commands(GPS); //Ignore responses to previous commands
}

void loop(){
  //Make a new filename everytime GPS disconnects
  create_unique_filename(gps_filename); //Create a unique filename
digitalWrite(LED1,HIGH);
  while(!GPS.newNMEAreceived()) GPS.read();
  strcpy(received_data, GPS.lastNMEA());

  if(received_data[19] == 'V');
  else if (received_data[19] == 'A')
  {  
    while(1){
      while(!GPS.newNMEAreceived()) GPS.read();
      strcpy(received_data, GPS.lastNMEA());
      
      if(received_data[19] == 'V')
        break;
digitalWrite(LED2,HIGH);
delay(80);
digitalWrite(LED2,LOW);
      file_GPSdata = SD.open(gps_filename, FILE_WRITE);
      file_GPSdata.write(received_data);
      file_GPSdata.close();
    }
  }
  else
    fail(3);
digitalWrite(LED1,LOW);
}

// Make seperate tracks later
