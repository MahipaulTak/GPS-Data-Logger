
#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std


void write_data_to_SD(string DATA)
{
   File dataFile = SD.open("datalog.txt", FILE_WRITE);
   if (dataFile) {
    dataFile.println(DATA);
    dataFile.close();
    Serial.println(dataString);//write to Serial
  }

  else {
    Serial.println("error opening datalog.txt");//error
  }
}
