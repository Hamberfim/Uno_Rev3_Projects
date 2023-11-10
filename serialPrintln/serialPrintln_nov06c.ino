// Serial port analog output via println()

int analogValue = 0;  // intantiate mutable integer variable value


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  //open serial port at 9600 bps

}

void loop() {
  // put your main code here, to run repeatedly:
  analogValue = analogRead(0);  // read the analog input on pin 0 (zero)
  Serial.println("== Analog Pin Zero Value ==");
  // print the reading in several formats
  Serial.print("In Decimal Value: ");
  Serial.println(analogValue);  // default is ASCII encoded decimal. syntax as declared: Serial.println(analogValue, DEC);
  
  Serial.print("In Hexidecimal Value: ");
  Serial.println(analogValue, HEX);  // as ASCII encoded hexidecimal
  
  Serial.print("In Octal Value: ");
  Serial.println(analogValue, OCT);  // as ASCII encoded octal
  
  Serial.print("In Binary Value: ");
  Serial.println(analogValue, BIN);  // as ASCII encoded binary
  
  Serial.println();  // space in output

  // delay in milliseconds before next reading
  delay(10000);

}
