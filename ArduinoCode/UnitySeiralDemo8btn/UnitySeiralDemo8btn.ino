
int pushButton = 2;
int buttonPins[] = {30, 31, 32, 33, 34, 35, 36, 37};
bool  buttonPressed[] = {false, false, false, false, false, false, false, false};
int LED = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for (int i = 0; i<8; i++) {
      pinMode(buttonPins[i], INPUT_PULLUP);
  }

  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  for (int i = 0; i<8; i++) {
      if (digitalRead(buttonPins[i] ) == LOW) {
        if (!buttonPressed[i]) {
            buttonPressed[i] = true;
           // digitalWrite(LED, HIGH);
            Serial.println(i);
            delay(20);
            Serial.flush();
           
        }
      }
      else {
         buttonPressed[i] = false;
         delay(20);
        // digitalWrite(LED, LOW);
      }
  }

 // Read incoming serial data:

 if (Serial.available() > 0) {
    // read incoming serial data:
    char inChar = Serial.read();
    // Type the next ASCII value from what you received:
   // Serial.print("incomming ");
   
     
      if (inChar == 'A') {
       //  Serial.println(inChar);
        digitalWrite(LED, HIGH);
       
      }
     if (inChar == 'Z') {
      
     //   Serial.println(inChar);
        digitalWrite(LED, LOW);
        
      }
    delay(1);
  }
  
}
