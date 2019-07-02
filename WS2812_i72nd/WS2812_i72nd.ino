#define CHANGE_FORWARD 10
#define CHANGE_BACKWARD 11

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define LED_PIN    9

#define LED_COUNT 4

#define DELAY_DEBOUNCE 20000

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(255); // Set BRIGHTNESS to about 1/5 (max = 255)
  pinMode(CHANGE_FORWARD, INPUT_PULLUP);
  pinMode(CHANGE_BACKWARD, INPUT_PULLUP);
}

// R G B
void loop() {
  static uint8_t color_state = 18;


  while (digitalRead(CHANGE_FORWARD) == LOW) {
    for (int i = 0; i < DELAY_DEBOUNCE; i++);
    while (digitalRead(CHANGE_FORWARD) == LOW);
    if (color_state == 18) {
      color_state = 1;
      break;
    }
    else {
      color_state++;
      break;
    }
  }

  while (digitalRead(CHANGE_BACKWARD) == LOW) {
    for (int i = 0; i < DELAY_DEBOUNCE; i++);
    while (digitalRead(CHANGE_BACKWARD) == LOW);
    if (color_state == 1) {
      color_state = 18;
      break;
    }
    else {
      color_state--;
      break;
    }

  }



  switch (color_state) {
      strip.clear();
    case 1:
      setAllColor(strip.Color(  0,   0, 255)); //1
      break;
    case 2:
      setAllColor(strip.Color(  30,   210, 0)); //2
      break;
    case 3:
      setAllColor(strip.Color(  255,   80, 0)); //3
      break;
    case 4:
      setAllColor(strip.Color(  0,   247, 255)); //4
      break;
    case 5:
      setAllColor(strip.Color(  140,   0, 255)); //5
      break;
    case 6:
      setAllColor(strip.Color(  255,   230, 0)); //6
      break;
    case 7:
      setAllColor(strip.Color(  255,   0, 0)); //7
      break;
    case 8:
      setAllColor(strip.Color(  190,   190, 255)); //8
      break;
    case 9:
      setAllColor(strip.Color(  255,   86, 140)); //9
      break;
    case 10:
      setAllColor(strip.Color(  0,   80, 255)); //10
      break;
    case 11:
      setAllColor(strip.Color(  255,   0, 50)); //100
      break;
    case 12:
      setAllColor(strip.Color(  0,   255, 5)); //1000
      break;
    case 13:
      setAllColor(strip.Color(  255,   100, 200)); //Z 棗
      break;
    case 14:
      setAllColor(strip.Color(  70,   255, 170));    //O 亥
      break;
    case 15:
      setAllColor(strip.Color(  255,   60, 70)); //O 狗丸
      break;
    case 16:
      setAllColor(strip.Color(  255,   130, 150)); //L 御堂
      break;
    case 17 :
      setAllColor(strip.Color(  255,   255, 255)); //WHITE
    case 18 :
      setAllColor(strip.Color(  0,   0, 0)); //OFF
      break;
      strip.show();
  }

}

void setAllColor(uint32_t color) {
  for (int i = 0; i < strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
  }
  strip.show();                          //  Update strip to match
}
