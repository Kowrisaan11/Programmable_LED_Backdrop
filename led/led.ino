const int ledPin1 = 23; // Pin number for the first LED
const int ledPin2 = 22; // Pin number for the second LED
const int ledPin3 = 1; // Pin number for the third LED
const int ledPin4 = 3; // Pin number for the first LED
const int ledPin5 = 21; // Pin number for the second LED
const int ledPin6 = 19; // Pin number for the third LED
const int ledPin7 = 18; // Pin number for the first LED
const int ledPin8 = 5; // Pin number for the second LED
const int ledPin9 = 17; // Pin number for the third LED
const int ledPin10 = 16; // Pin number for the first LED
const int ledPin11 = 4; // Pin number for the second LED
const int ledPin12 = 0; // Pin number for the third LED
const int ledPin13 = 2; // Pin number for the first LED
const int ledPin14 = 15; // Pin number for the second LED
const int ledPin20 = 32; // Pin number for the second LED
const int ledPin21 = 33; // Pin number for the third LED
const int ledPin22 = 25; // Pin number for the first LED
const int ledPin27 = 26; // Pin number for the first LED
const int ledPin23 = 27; // Pin number for the second LED
const int ledPin24 = 14; // Pin number for the second LED
const int ledPin25 = 12; // Pin number for the third LED
const int ledPin26 = 13; // Pin number for the first LED

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);
  pinMode(ledPin8, OUTPUT);
  pinMode(ledPin9, OUTPUT);
  pinMode(ledPin10, OUTPUT);
  pinMode(ledPin11, OUTPUT);
  pinMode(ledPin12, OUTPUT);
  pinMode(ledPin13, OUTPUT);
  pinMode(ledPin14, OUTPUT);

  pinMode(ledPin20, OUTPUT);
  pinMode(ledPin21, OUTPUT);
  pinMode(ledPin22, OUTPUT);
  pinMode(ledPin23, OUTPUT);
  pinMode(ledPin24, OUTPUT);
  pinMode(ledPin25, OUTPUT);
  pinMode(ledPin26, OUTPUT);
  pinMode(ledPin27, OUTPUT);
  
  // digitalWrite(ledPin1,LOW);
  // digitalWrite(ledPin2, LOW);
  // digitalWrite(ledPin3, LOW);
  // digitalWrite(ledPin4, LOW);
  // digitalWrite(ledPin5, LOW);
  // digitalWrite(ledPin6, HIGH);
  // digitalWrite(ledPin7, HIGH);
  // digitalWrite(ledPin8, HIGH);
  // digitalWrite(ledPin9, HIGH);
  // digitalWrite(ledPin10, HIGH);
  // digitalWrite(ledPin11, HIGH);
  // digitalWrite(ledPin12, HIGH);
  // digitalWrite(ledPin13, HIGH);
  // digitalWrite(ledPin14, HIGH);

  // digitalWrite(ledPin20, HIGH);
  // digitalWrite(ledPin21, HIGH);
  // digitalWrite(ledPin22, HIGH);
  // digitalWrite(ledPin23, HIGH);
  // digitalWrite(ledPin24, HIGH);
  // digitalWrite(ledPin25, HIGH);
  // digitalWrite(ledPin26, HIGH);
  // digitalWrite(ledPin27, HIGH);
}

void loop() {
  
    // Fade in
        for(int ledVal = 0; ledVal <= 255; ledVal +=1) {
        analogWrite(ledPin21, ledVal);
        delay(5);
     }  
 
     // Fade out
     for(int ledVal = 255; ledVal >= 0; ledVal -=1) {
        analogWrite(ledPin21, ledVal);
         delay(5);
     } 

        // Fade in
        for(int ledVal = 0; ledVal <= 255; ledVal +=1) {
        analogWrite(ledPin22, ledVal);
        delay(5);
     }  
 
     // Fade out
     for(int ledVal = 255; ledVal >= 0; ledVal -=1) {
        analogWrite(ledPin22, ledVal);
         delay(5);
     } 

        // Fade in
        for(int ledVal = 0; ledVal <= 255; ledVal +=1) {
        analogWrite(ledPin23, ledVal);
        delay(5);
     }  
 
     // Fade out
     for(int ledVal = 255; ledVal >= 0; ledVal -=1) {
        analogWrite(ledPin23, ledVal);
         delay(5);
     } 
    

        // Fade in
        for(int ledVal = 0; ledVal <= 255; ledVal +=1) {
        analogWrite(ledPin24, ledVal);
        delay(5);
     }  
 
     // Fade out
     for(int ledVal = 255; ledVal >= 0; ledVal -=1) {
        analogWrite(ledPin24, ledVal);
         delay(5);
     } 

        // Fade in
        for(int ledVal = 0; ledVal <= 255; ledVal +=1) {
        analogWrite(ledPin25, ledVal);
        delay(5);
     }  
 
     // Fade out
     for(int ledVal = 255; ledVal >= 0; ledVal -=1) {
        analogWrite(ledPin25, ledVal);
         delay(5);
     } 
    
    // Pause for 1 second (1000 milliseconds)
    delay(1000);
 
}