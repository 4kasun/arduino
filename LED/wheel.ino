#include <FastLED.h>

#define DATA_PIN    13

#define NUM_LEDS    100

#define NUM_PER_ROW 6

#define NUM_LINES   16

CRGB leds[NUM_LEDS];

#define START   4

void setup() {
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
  //Serial.begin(9600);
}

void loop() {


  for (int a = 0; a < 5; a++) {
    circlieIncreaseSingle(a);
    delay(30);
  }

  delay(1000);
  for (int b = 0; b < 5; b++) {
    lineFlow();
  }

  delay(1000);
  for (int c = 0; c < 5; c++) {
    circleIncrease();
  }

  delay(1000);
  for (int d = 0; d < 5; d++) {
    lineFlowReverse();
  }

  delay(1000);

  for (int e = 0; e < 5; e++) {
    darkLineMove(e);
  }

}

/**
 *******************************circle design start*********************************
*/

/**
   circle increase decrease multiple with color
*/
void circleIncrease() {
  for (int circle = 0; circle <= NUM_LINES; circle++) {
    onCircleOneByOne(circle - 1, circle % 5);
  }

  for (int circle = 0; circle <= NUM_LINES; circle++) {
    onCircleOneByOne(circle - 1, 5);
  }
}

/**
   ciecle incease decreas with single color
*/
void circlieIncreaseSingle(int color) {
  for (int circle = 0; circle <= NUM_LINES; circle++) {
    onCircleOneByOne(circle - 1, circle % 5);
  }

  for (int circle = 0; circle <= NUM_LINES; circle++) {
    onCircleOneByOne(circle - 1, color);
  }

  for (int circle = 0; circle <= NUM_LINES; circle++) {
    onCircleOneByOne(circle - 1,  circle % 5);
  }
}

/**
   light on line with given color and given line no
*/
void onCircleOneByOne(int circleNo, int color) {
  int start = circleNo + START;
  for (int i = start; i < NUM_LEDS; i += (NUM_PER_ROW * 2)) {
    leds[i] = getColor(color);
    FastLED.show();
  }
}

/**
*******************************circle design end*********************************
*/

/**
 * ********************************line design start*********************************
*/

/**
   continusly line on with flag color order
*/
void lineFlow() {
  for (int line = 0; line <= NUM_LINES; line++) {
    onLine(line - 1, line % 5);
  }

  for (int line = 0; line <= NUM_LINES; line++) {
    onLine(line - 1, 5);
  }
}

/**
   line on and reverse off
*/
void lineFlowReverse() {
  for (int line = 0; line <= NUM_LINES; line++) {
    onLine(line - 1, line % 5);
  }

  for (int line = NUM_LINES; line >= 0; line--) {
    onLine(line - 1, 5);
  }
}

/**
   move dark line
*/
void darkLineMove(int color) {
  for (int i = START; i < NUM_LEDS; i++) {
    leds[i] = getColor(color);
    FastLED.show();
  }

  for (int line = 1; line <= NUM_LINES; line++) {
    onLine(line - 1, 3);
  }

  for (int i = START; i < NUM_LEDS; i++) {
    leds[i] = getColor(color);
    FastLED.show();
  }

}

/**
   light on line with given color and given line no
*/
void onLine(int lineNo, int color) {
  int start = (lineNo * NUM_PER_ROW) + START;
  for (int i = start; i < start + NUM_PER_ROW; i++) {
    leds[i] = getColor(color);
    FastLED.show();
  }
}

/**
 * ********************************line design end*********************************
*/


/**
   get buddish flag colors by code
   0 for orange
   1 for blue
   2 for yellow
   3 for Red
   4 for white
   5 for black/off
*/
CRGB getColor(int colorId) {
  switch (colorId) {
    case 0:
      return CRGB::OrangeRed;
      break;
    case 1:
      return CRGB::Blue;
      break;
    case 2:
      return CRGB::Yellow;
      break;
    case 3:
      return CRGB::Red;
      break;
    case 4:
      return CRGB::White;
      break;
    case 5:
      return CRGB::Black;
      break;
  }
}
