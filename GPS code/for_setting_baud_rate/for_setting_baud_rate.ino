void setup() {
  Serial.begin( 9600 );
  Serial1.begin( 9600 );
  Serial1.print( F(" packet commands for setting baud rates ") );

}

void loop() {
  while(Serial1.available())
  {
    // use if needed
  }

}
