/*
  DigitalReadSerial

  Reads a digital input on pin 2, prints the result to the Serial Monitor

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/DigitalReadSerial
*/

// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 2;
int LED = 13;
bool buttonPressed = false;
int lastValue = 0;


const int numReadings = 10;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

int inputPin = A0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
  pinMode(LED, OUTPUT);

 
}

// the loop routine runs over and over again forever:
void loop() {
  // read the digital input pin:
  if (digitalRead(pushButton)) {
    if (!buttonPressed) {
       buttonPressed = true;
      digitalWrite(LED, HIGH);
      int buttonState = digitalRead(pushButton);
      // print out the state of the button:
      Serial.println(buttonState); 
    }
  }
  else {
       buttonPressed = false;
       digitalWrite(LED, LOW);
           delay(1); 
  }



//read anlog input pin


/*
  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = map(analogRead(inputPin), 0, 1023, 0, 50);
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;
  // send it to the computer as ASCII digits
 
  if ( lastValue != average)  {
    lastValue = average;
    Serial.println(lastValue); 
    delay(100);
  }  
  delay(1);        // delay in between reads for stability

/*
  int sensorValue = analogRead(A0);
  sensorValue = map(sensorValue, 0, 1023, 0, 50);

 
  }
  
 delay(1);
 */

 
 if (Serial.available() > 0) {
    // read incoming serial data:
    char inChar = Serial.read();
    // Type the next ASCII value from what you received:
    Serial.print("incomming ");
   
     
      if (inChar == 'A') {
          Serial.println(inChar);
        digitalWrite(LED, HIGH);
       
      }
     if (inChar == 'Z') {
        digitalWrite(LED, LOW);
      }
    delay(1);
  }
       // delay in between reads for stability
}
