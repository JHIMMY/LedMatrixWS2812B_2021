#include <FastLED.h>

FASTLED_USING_NAMESPACE

#if defined(FASTLED_VERSION) && (FASTLED_VERSION < 3001000)
#warning "Requires FastLED 3.1 or later; check github for latest code."
#endif

// animations
#include "Plasma.cpp"
#include "Snake.cpp"
#include "Twinkle.cpp"
#include "DeadChannel.cpp"
#include "Life.cpp"
#include "Sprite.cpp"

// constants for the sketch
#define WIDTH 20
#define HEIGHT 10

#define DATA_PIN 7
#define LED_TYPE    WS2812B
#define COLOR_ORDER RGB
#define NUM_LEDS    WIDTH * HEIGHT

#define BRIGHTNESS          96
#define FRAMES_PER_SECOND  120

CRGB leds[NUM_LEDS];


void setup() {
    delay(2500); // delay for recovery (library)

    Serial.begin(115200);

    FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
   
    // set master brightness control
    FastLED.setBrightness(BRIGHTNESS);

    // show whole colors on all matrix
    FastLED.clear(true);
    delay(500);
    FastLED.showColor(CRGB::Red);
    delay(1000);
    FastLED.showColor(CRGB::Lime);
    delay(1000);
    FastLED.showColor(CRGB::Blue);
    delay(1000);
    FastLED.showColor(CRGB::Yellow);
    delay(1000);
    FastLED.clear(true);
}

void loop() {
    doTwinkle();
    Serial.println("Finished Twinkle");
    doSnake();
    Serial.println("Finished Snake");
    doLife();
    Serial.println("Finished Life");
    doSprite();
    Serial.println("Finished Sprite");
    doPlasma();
    Serial.println("Finished Plasma");
    doDeadChannel();
    Serial.println("Finished dead channel");

    Serial.println("Completed All animations on the loop");
}

void doDeadChannel() {
    DeadChannel deadChannel(leds, WIDTH, HEIGHT);
    deadChannel.start();
}

void doPlasma() {
    Plasma plasma(leds, WIDTH, HEIGHT);
    plasma.start();
}

void doTwinkle() {
    Twinkle twinkle(leds, WIDTH, HEIGHT, true, true);
    twinkle.start();
}

void doSnake() {
    Snake snake(leds, WIDTH, HEIGHT);
    snake.start();
}

void doLife() {
    Life life(leds, WIDTH, HEIGHT, 56);
    life.start();
}

void doSprite() {
    Sprite sprite(leds, WIDTH, HEIGHT);
    sprite.start();
}

