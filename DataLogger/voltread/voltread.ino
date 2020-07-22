/*
  ReadAnalogVoltage

  Reads an analog input on pin 0, converts it to voltage, and prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/ReadAnalogVoltage
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int SV1 = analogRead(A0);
  int SV2 = analogRead(A1);
  int SV3 = analogRead(A2);


  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
float   V1 = SV1 * (5.0 / 1023.0);
float   V2 = SV2 * (5.0 / 1023.0);
float   V3 = SV3 * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(String(V1) + "ab" + String(V2) + "cd" + String(V3) );
  delay(20000);

}
