
const int LED1 = 23; // Pin number for the first LED
const int LED2 = 22; // Pin number for the second LED
const int LED3 = 12; // Pin number for the third LED
const int LED4 = 13; // Pin number for the first LED
const int LED5 = 21; // Pin number for the second LED
const int LED6 = 19; // Pin number for the third LED
const int LED7 = 18; // Pin number for the first LED
const int LED8 = 5; // Pin number for the second LED
const int LED9 = 4; // Pin number for the second LED
const int LED10 = 2; // Pin number for the first LED

int LEDArr[14] = {LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED8, LED9, LED10};

const int BD1 = 33; // Pin number for the third LED
const int BD2 = 25; // Pin number for the first LED
const int BD3 = 26; // Pin number for the first LED
const int BD4 = 27; // Pin number for the second LED
const int BD5 = 14; // Pin number for the second LED

int BDArr[5] = {BD1, BD2, BD3, BD4, BD5};

String state = "000000000000000";

const int screenOpenIterations = 600;
const int screenCloseIterations = 600;
const int screenOpenandCloseIterations = 600;
const int randomSequenceIterations = 600;
const int randomBDsIterations = 600;
const int intensityChangeIterations = 600;
const int runnerIterations = 600;
const int defaultDelay = 2000;
const int mindelay = 100;
const int delaytoDecrement = 100;

int delayBetweenBDs = 2000;
int randomNumber;

bool variableDelayBetweenBDs = false;

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 10; i++) {
    pinMode(LEDArr[i],OUTPUT);
  }
  for (int i = 0; i < 5 ; i++) {
    pinMode(BDArr[i],OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}

void screenOpen() {
  for (int i = 0; i < screenOpenIterations; i++) {
    state = "111111111100000";
    for (int i = 10; i < 15; i++) {
      state[i] = "1";
      sendState(state);
      setDigitalState(state);
      delay(delayBetweenBDs);
      if (variableDelayBetweenBDs){
        changeDelay(delayBetweenBDs);        
      }
    }    
  }
}

void screenClose() {
  for (int i = 0; i < screenCloseIterations; i++) {
    state = "111111111111111";
    for (int i = 18; i > 13; i--) {
      state[i] = "0";
      sendState(state);
      setDigitalState(state);
      delay(delayBetweenBDs);
      if (variableDelayBetweenBDs){
        changeDelay(delayBetweenBDs);        
      }
    }    
  }
}

void screenOpenandClose() {
  for (int i = 0; i < screenOpenandCloseIterations; i++) {
    state = "1111111111111100000";
    for (int i = 14; i < 19; i++) {
      state[i] = "1";
      sendState(state);
      setDigitalState(state);
      delay(delayBetweenBDs);
      if (variableDelayBetweenBDs){
        changeDelay(delayBetweenBDs);        
      }
    }    
    for (int i = 18; i > 13; i--) {
      state[i] = "0";
      sendState(state);
      setDigitalState(state);
      delay(delayBetweenBDs);
      if (variableDelayBetweenBDs){
        changeDelay(delayBetweenBDs);        
      }
    }    
  }
}

void runner() {
  for (int i = 0; i < runnerIterations; i++) {
    state = "1111111111111100000";
    for (int i = 14; i < 19; i++) {
      state[i] = "1";
      sendState(state);
      setDigitalState(state);
      delay(delayBetweenBDs);
      if (variableDelayBetweenBDs){
        changeDelay(delayBetweenBDs);        
      }
      state = "1111111111111100000";
      sendState(state);
      setDigitalState(state);
    }
  }
}

void randomSequence() {
  for (int i = 0; i < randomSequenceIterations; i++) {
    state = "0000000000000011111";
    for (int i = 0; i < 14; i++) {
      state[i] = char(random(0,2));   
      }
    sendState(state);
    setDigitalState(state);
    delay(delayBetweenBDs);
    if (variableDelayBetweenBDs){
      changeDelay(delayBetweenBDs);
    }
  }
}

void randomBDs() {
  for (int i = 0; i < randomBDsIterations; i++) {
    state = "1111111111111100000";
    for (int i = 14; i < 19; i++) {
      state[i] = char(random(0,2));   
      }
    sendState(state);
    setDigitalState(state);
    delay(delayBetweenBDs);
    if (variableDelayBetweenBDs){
      changeDelay(delayBetweenBDs);
    }
  }
}

void intensityChange() {
  for (int i = 0; i < intensityChangeIterations; i++) {
    for (int brightness = 0; i < 255; i++) {
      for (int i = 0; i < 14; i++) {
        analogWrite(LEDArr[i],brightness);
      }
    }
  }
}



void setDigitalState(String state){
  for (int i = 15; i < 20; i++) {
    if (state[i] == "1"){
      digitalWrite(LEDArr[i],"HIGH");
    } else if (state[i] == "0") {
      digitalWrite(LEDArr[i],"LOW");
    }
  }
}

void changeDelay (int delay) {
  if (delay > mindelay) {
    delay -= delaytoDecrement;
  } else {
    delay = defaultDelay;
  }
}




void sendState(String state){
  
}
