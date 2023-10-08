const int LED1 = 23; // Pin number for the first LED
const int LED2 = 22; // Pin number for the second LED
const int LED3 = 21; // Pin number for the third LED
const int LED4 = 19; // Pin number for the first LED
const int LED5 = 18; // Pin number for the second LED
const int LED6 = 5; // Pin number for the third LED
const int LED7 = 17; // Pin number for the first LED
const int LED8 = 14; // Pin number for the second LED
const int LED9 = 4; // Pin number for the third LED
const int LED10 = 0; // Pin number for the first LED

int LEDArr[15] = {LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED8, LED9, LED10};

const int BD1 = 2; // Pin number for the third LED
const int BD2 = 15; // Pin number for the first LED
const int BD3 = 27; // Pin number for the first LED
const int BD4 = 27; // Pin number for the second LED
const int BD5 = 14; // Pin number for the second LED

int BDArr[15] = {BD1, BD2, BD3, BD4, BD5};

//int state[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

const int screenOpenIterations = 10;
const int screenCloseIterations = 10;
const int screenOpenandCloseIterations = 10;
const int randomSequenceIterations = 600;
const int randomBDsIterations = 10;
const int intensityChangeIterations = 500;
const int runnerIterations = 10;
const int defaultDelay = 2000;
const int mindelay = 100;
const int delaytoDecrement = 100;

int delayBetweenBDs = 2000;
int delayBetweenRandom =50;
int randomNumber;

bool variableDelayBetweenBDs = false;

void setup() {
  // put your setup code here, to run once:
  
  for (int i = 1; i < 11; i++) {
    ledcSetup(i, 5000, 10);
    ledcAttachPin(LEDArr[i-1],i);
  }
  

  // for (int i = 0; i < 10; i++) {
  //   pinMode(LEDArr[i],OUTPUT);
  // }
  // for (int i = 0; i < 55; i++) {
  //   pinMode(BDArr[i],OUTPUT);
  // }
}

void loop() {
  // put your main code here, to run repeatedly:
  //ledcWrite(23,1024);
  intensityChange();
}

void screenOpen() {
  for (int i = 0; i < screenOpenIterations; i++) {
    int state[15] = {255,255,255,255,255,255,255,255,255,255,0,0,0,0,0};
    for (int i = 10; i < 15; i++) {
      state[i] = 1;
      sendState(state);
      digitalWrite(BDArr[i-10],state[i]);
      delay(delayBetweenBDs);
      if (variableDelayBetweenBDs){
        delayBetweenBDs = changeDelay(delayBetweenBDs);        
      }
    }    
  }
}

void screenClose() {
  for (int i = 0; i < screenCloseIterations; i++) {
    int state[15] = {255,255,255,255,255,255,255,255,255,255,1,1,1,1,1};
    for (int i = 14; i > 9; i--) {
      state[i] = 0;
      sendState(state);
      digitalWrite(BDArr[i-10],state[i]);
      delay(delayBetweenBDs);
      if (variableDelayBetweenBDs){
        delayBetweenBDs = changeDelay(delayBetweenBDs);        
      }
    }    
  }
}

void screenOpenandClose() {
  for (int i = 0; i < screenOpenandCloseIterations; i++) {
    int state[15] = {255,255,255,255,255,255,255,255,255,255,0,0,0,0,0};
    for (int i = 10; i < 15; i++) {
      state[i] = 1;
      sendState(state);
      digitalWrite(BDArr[i-10],state[i]);
      delay(delayBetweenBDs);
      if (variableDelayBetweenBDs){
        delayBetweenBDs = changeDelay(delayBetweenBDs);        
      }
    }    
    for (int i = 14; i > 9; i--) {
      state[i] = 0;
      sendState(state);
      digitalWrite(BDArr[i-10],state[i]);
      delay(delayBetweenBDs);
      if (variableDelayBetweenBDs){
        delayBetweenBDs = changeDelay(delayBetweenBDs);        
      }
    }    
  }
}

void runner() {
  for (int i = 0; i < runnerIterations; i++) {
    int state[15] = {255,255,255,255,255,255,255,255,255,255,0,0,0,0,0};
    for (int i = 10; i < 15; i++) {
      state[i] = 1;
      sendState(state);
      digitalWrite(BDArr[i-10],state[i]);
      delay(delayBetweenBDs);
      if (variableDelayBetweenBDs){
        delayBetweenBDs = changeDelay(delayBetweenBDs);        
      }
      int state[15] = {255,255,255,255,255,255,255,255,255,255,0,0,0,0,0};
      sendState(state);
      digitalWrite(BDArr[i-10],state[i]);
    }
  }
}

void randomSequence() {
  for (int i = 0; i < randomSequenceIterations; i++) {
    int state[15] = {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1};
    for (int i = 0; i < 10; i++) {
      int randomNumber = random(10,20);
      if (randomNumber <= 14) {
        state[i] = 0;
      } else {
        state[i] = 1024;
      }
    }
    sendState(state);
    for (int i = 1; i < 11; i++){
      ledcWrite(i, state[i-1]);
    }
    delay(delayBetweenBDs);
    if (variableDelayBetweenBDs){
      delayBetweenBDs = changeDelay(delayBetweenBDs);
    }
  }
}

void randomOne() {
  for (int i = 0; i < randomSequenceIterations; i++) {
    int state[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int randomNumber = random(0,10);
    state[randomNumber] = 1024;
    int randomval = random(10,15);
    state[randomval] = 1;
    sendState(state);
    for (int i = 1; i < 11; i++){
      ledcWrite(i, state[i-1]);
    }
    digitalWrite(BDArr[randomNumber],state[randomNumber]);
    delay(delayBetweenRandom);
    if (variableDelayBetweenBDs){
      delayBetweenBDs = changeDelay(delayBetweenBDs);
    }
  }
}

void randomBDs() {
  for (int i = 0; i < randomBDsIterations; i++) {
    int state[15] = {255,255,255,255,255,255,255,255,255,255,0,0,0,0,0};
    for (int i = 10; i < 15; i++) {
      int randomNumber = random(10,20);
      if (randomNumber <= 14) {
        state[i] = 0;
      } else {
        state[i] = 1;
      }
    }
    sendState(state);
    digitalWrite(BDArr[i-10],state[i]);
    delay(delayBetweenBDs);
    if (variableDelayBetweenBDs){
      delayBetweenBDs = changeDelay(delayBetweenBDs);
    }
  }
}

void intensityChange() {
  for (int i = 0; i < intensityChangeIterations; i++) {
    for (int brightness = 0; brightness < 1024; brightness++) {
      for (int i = 0; i < 15; i++) {
        ledcWrite(i, brightness);
        delay(5);
      }
    }
    for (int brightness = 1023; brightness >= 0; brightness--) {
      for (int i = 0; i < 15; i++) {
        ledcWrite(i, brightness);
        delay(5);
      }
    }
  }
}

int changeDelay (int delay) {
  if (delay > mindelay) {
    delay -= delaytoDecrement;
  } else {
    delay = defaultDelay;
  }
  return delay;
}




void sendState(int state[]){
  
}
