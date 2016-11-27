#include "function_prototypes.h"
#include <SD.h>

//Takes the number of files, n, on the SD card and makes a cstring which is just "n".
//Will end up with file names "0", "1", "2" on the SD card
//But this function just creates the name, not the actual file.
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
