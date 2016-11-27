# GPS-Data-Logger
ENEL 400 Project

PLEASE READ IN RAW DATA FORM, BECAUSE GITHUB HAS BAD FORMATTING

GPS data logger code for fleet tracking
Project for ENEL 400 - 2016

Group Members: Mahipaul, Kevin, Brendon, Aakash, Luke

These links have some pretty damn useful libraries/examples:
https://github.com/adafruit/Adafruit_GPS
http://www.studiopieters.nl/arduino-datalogger/

Link to Thread on using the GPS protocols
https://forum.arduino.cc/index.php?topic=408311.0

How the GPS->SD card storing code currently works:
  1) Sets up each of them
    a) connects GPS on software serial pins, sets update rate, tells it to only send GPRMC data
    b) connects SD card
  2) Goes into a loop
  3) Creates a new filename for the SD card
  4) Waits until a successful signal is received (GPRMC valid character == 'A')
  5) Goes into another loop
  6) Writes the GPRMC data to the SD card
  7) Waits for a new GPRMC signal
  8) Checks the valid character, breaks if invalid
  9) loops back
  10) loops back
  
Ends up with a file like:
$GPRMC,045604.000,A,5102.2956,N,11409.7111,W,0.23,93.35,171116,,,A*46^M
$GPRMC,045605.000,A,5102.2956,N,11409.7111,W,0.07,259.64,171116,,,A*71^M
$GPRMC,045606.000,A,5102.2955,N,11409.7109,W,0.07,301.65,171116,,,A*75^M
$GPRMC,045607.000,A,5102.2954,N,11409.7108,W,0.06,227.65,171116,,,A*70^M
$GPRMC,045608.000,A,5102.2952,N,11409.7105,W,0.20,127.32,171116,,,A*71^M
$GPRMC,045609.000,A,5102.2951,N,11409.7104,W,0.20,129.07,171116,,,A*7A^M
$GPRMC,045610.000,A,5102.2950,N,11409.7105,W,0.17,175.49,171116,,,A*75^M
$GPRMC,045611.000,A,5102.2951,N,11409.7108,W,0.09,227.26,171116,,,A*7A^M
$GPRMC,045612.000,A,5102.2952,N,11409.7110,W,0.02,25.51,171116,,,A*48^M
$GPRMC,045613.000,A,5102.2952,N,11409.7112,W,0.04,108.64,171116,,,A*75^M         

Which has all the information needed.
It creates a new file every time it loses a fix/power, otherwise will write to a single file.
