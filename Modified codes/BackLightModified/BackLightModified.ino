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
const int intensityChangeIterations = 5;
const int intensityChangeTwoIterations = 2;
const int intensityChangeThreeIterations = 5;
const int blockDropIterations = 5;
const int intensityGradualIterations = 2;
const int runnerIterations = 10;

const int defaultDelay = 2000;
const int mindelay = 100;
const int delaytoDecrement = 100;
const int delayBetweenRandom =50;
const int intensityStepDelay = 1;
const int intensityStepDelayTwo = 1;
const int intensityStepDelayThree = 1;
const int blockDropDelay = 100;

int delayBetweenBDs = 2000;

const int maxBrightness = 1023;

bool variableDelayBetweenBDs = false;

void sendState(int state[]) {
  String statevals = "";
  for (int i = 0; i < 15; i++) {
    statevals += String(state[i]) +",";
  }
  statevals += "1000,";
  Serial.println(statevals);
}

int changeDelay (int delay) {
  if (delay > mindelay) {
    delay -= delaytoDecrement;
  } else {
    delay = defaultDelay;
  }
  return delay;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
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
  // intensityChange();
  // intensityChangeTwo();
  // intensityChangeThree();
  // intensityGradualNew();
  // blockDrop();
}

void screenOpen() {
  for (int i = 0; i < screenOpenIterations; i++) {
    int state[15] = {maxBrightness,maxBrightness,maxBrightness,maxBrightness,maxBrightness,maxBrightness,maxBrightness,maxBrightness,maxBrightness,maxBrightness,0,0,0,0,0};
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
    int state[15] = {maxBrightness,maxBrightness,maxBrightness,maxBrightness,maxBrightness,maxBrightness,maxBrightness,maxBrightness,maxBrightness,maxBrightness,1,1,1,1,1};
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
    int state[15] = {maxBrightness,maxBrightness,maxBrightness,maxBrightness,maxBrightness,maxBrightness,maxBrightness,maxBrightness,maxBrightness,maxBrightness,0,0,0,0,0};
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
    int state[15] = {maxBrightness,maxBrightness,maxBrightness,maxBrightness,maxBrightness,maxBrightness,maxBrightness,maxBrightness,maxBrightness,maxBrightness,0,0,0,0,0};
    for (int i = 10; i < 15; i++) {
      state[i] = 1;
      sendState(state);
      digitalWrite(BDArr[i-10],state[i]);
      delay(delayBetweenBDs);
      if (variableDelayBetweenBDs){
        delayBetweenBDs = changeDelay(delayBetweenBDs);        
      }
      int state[15] = {maxBrightness,maxBrightness,maxBrightness,maxBrightness,maxBrightness,maxBrightness,maxBrightness,maxBrightness,maxBrightness,maxBrightness,0,0,0,0,0};
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
    int state[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
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
    int state[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for (int brightness = 0; brightness < maxBrightness+1; brightness++) {
      for (int i = 1; i < 11; i++) {
        state[i-1] = brightness;
        //sendState(state);
        ledcWrite(i, brightness);
      }
      delay(intensityStepDelay);
    }

    for (int brightness = maxBrightness; brightness >= 0; brightness--) {
      for (int i = 1; i < 11; i++) {
        state[i-1] = brightness;
        //sendState(state);
        ledcWrite(i, brightness);
      }
      delay(intensityStepDelay);
    }
  }
}

void intensityChangeTwo() {
  for (int i = 0; i < intensityChangeTwoIterations; i++) {
    int state[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for (int i = 1; i < 11; i++) {
      for (int brightness = 0; brightness < maxBrightness+1; brightness++) {
        state[i-1] = brightness;
        //sendState(state);
        ledcWrite(i, brightness);
        delay(intensityStepDelayTwo);
      }

      for (int brightness = maxBrightness; brightness >= 0; brightness--) {
        state[i-1] = brightness;
        //sendState(state);
        ledcWrite(i, brightness);
        delay(intensityStepDelayTwo);
      }
    }
  }
}

void intensityChangeThree() {
  for (int i = 0; i < intensityChangeThreeIterations; i++) {
    int state[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int val1 = random(1,11);
    int val2 = random(1,11);
    if (val1 == val2) {
      int val2 = random(1,11);
    }
    int val3 = random(1,11);
    if (val3 ==val2) {
      int val3 = random(1,11);
    }
    for (int brightness = 0; brightness < maxBrightness+1; brightness++) {
      state[val1-1] = brightness;
      state[val2-1] = brightness;
      state[val3-1] = brightness;
      //sendState(state);
      ledcWrite(val1, brightness);
      ledcWrite(val2, brightness);
      ledcWrite(val3, brightness);
      delay(intensityStepDelayThree);
    }

    for (int brightness = maxBrightness; brightness >= 0; brightness--) {
      state[val1-1] = brightness;
      state[val2-1] = brightness;
      state[val3-1] = brightness;
      //sendState(state);
      ledcWrite(val1, brightness);
      ledcWrite(val2, brightness);
      ledcWrite(val3, brightness);
      delay(intensityStepDelayThree);
    }
  }
}


void intensityGradualNew() {
  for (int i = 0; i < intensityGradualIterations; i++) {
    int state[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for (int brightness = 0; brightness < maxBrightness+1; brightness++) {
      for (int i = 1; i < 11; i++) {
        if (brightness > (i-1)*100) {
          state[i-1] = brightness;
          //sendState(state);
          ledcWrite(i, brightness-(i-1)*100);
        }
      }
      delay(intensityStepDelay);
    }

    for (int brightness = maxBrightness; brightness >= 0; brightness--) {
      for (int i = 10; i >= 0; i--) {
        state[i-1] = brightness;
        //sendState(state);
        ledcWrite(i, max(brightness-(10-i)*100,0));
        Serial.println(brightness);
      }
      delay(intensityStepDelay);
    }
  }
}

void intensityGradual() {
  for (int i = 0; i < intensityGradualIterations; i++) {
    int state[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for (int brightness = 0; brightness < maxBrightness+1; brightness++) {
      for (int i = 1; i < 11; i++) {
        if (brightness > (i-1)*100) {
          state[i-1] = brightness;
          //sendState(state);
          ledcWrite(i, brightness-(i-1)*100);
        }
        Serial.println(brightness);
      }
      delay(intensityStepDelay);
    }

    Serial.println("jhbvtfct");

    for (int brightness = maxBrightness; brightness >= 0; brightness--) {
      for (int i = 10; i >= 0; i--) {
        state[i-1] = brightness;
        //sendState(state);
        ledcWrite(i, brightness-(i-1)*100);
      }
      delay(intensityStepDelay);
    }
  }
}

void blockDrop() {
  for (int i = 0; i < blockDropIterations; i++) {
    int state[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    delay(blockDropDelay);
    for(int j = 1; j < 11; j++) {
      for (int i = 10; i > j-1; i--) {
        state[i-1] = maxBrightness;
        //sendState(state);
        ledcWrite(i,maxBrightness);
        delay(blockDropDelay);
        state[i-1] = 0;
        //sendState(state);
        ledcWrite(i,0);
      }
      state[j-1] = maxBrightness;
      //sendState(state);
      ledcWrite(j,maxBrightness);
    }
    
  }
}

