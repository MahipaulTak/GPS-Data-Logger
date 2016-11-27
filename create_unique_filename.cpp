#include "function_prototypes.h"
#include <SD.h>

void create_unique_filename(char *buffer){
  unsigned int file_count = 0;
  File root = SD.open("/", FILE_READ);
  File entry;

  root.rewindDirectory();
  while(1){
    entry = root.openNextFile();
    if(!entry) break; //Last file on card
    entry.close();
    
    file_count++;
  }  
  
  sprintf(buffer, "%d", file_count);
  
  root.close();
  
  return;
}
