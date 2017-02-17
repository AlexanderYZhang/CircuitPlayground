#include <Adafruit_CircuitPlayground.h>

uint8_t pixeln = 0;
int start = 0;
int wait = 500;
int leftpixels[] = {0,0,0,0};
int rightpixels[] = {0,0,0,0};
void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(wait);
  if(CircuitPlayground.leftButton() || CircuitPlayground.rightButton()) {
    start = 1;
  }
  if (start == 1) {
    for (int i = 0; i < 3; i++) {
      leftpixels[i] = leftpixels[i+1];
      rightpixels[i] = rightpixels[i+1];
    }
    if (random(0,10) < random(0,10)) { 
      leftpixels[3] = random(0,10)*25;
    } else {
      leftpixels[3] = 0;
    }
    if (random(0,10) < random(0,10)) { 
      rightpixels[3] = random(0,10)*25;
    } else {
      rightpixels[3] = 0;
    }
    CircuitPlayground.clearPixels();
    for (int i = 0; i < 4; i++) {
      if (rightpixels[i] != 0) {
        CircuitPlayground.setPixelColor(1+i, CircuitPlayground.colorWheel(leftpixels[i]));
      }
      if (leftpixels[i] != 0) {
        CircuitPlayground.setPixelColor(8-i,CircuitPlayground.colorWheel(rightpixels[i]));
      }
    }
    if (CircuitPlayground.leftButton() && rightpixels[0] != 0) {
      CircuitPlayground.setPixelColor(0, CircuitPlayground.colorWheel(100));
    }
    if (CircuitPlayground.rightButton() && leftpixels[0] != 0) {
      CircuitPlayground.setPixelColor(9, CircuitPlayground.colorWheel(100));
    }
  }
}
