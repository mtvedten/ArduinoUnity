
int pushButton = 2;
int LED = 13;
bool buttonPressed = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pushButton, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(pushButton) == LOW) {
    if (!buttonPressed) {
        buttonPressed = true;
       // digitalWrite(LED, HIGH);
        Serial.write(1);
        delay(1);
        Serial.flush();
       
    }
  }
  else {
     buttonPressed = false;
     delay(20);
    // digitalWrite(LED, LOW);
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
