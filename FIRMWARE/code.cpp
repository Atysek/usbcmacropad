#include <HID-Project.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ---------------- OLED ----------------
#define OLED_RESET -1
Adafruit_SSD1306 display(128, 32, &Wire, OLED_RESET);

// ---------------- PINS ----------------
#define SW_MUTE 26
#define SW_CAM  27
#define SW_VOLU 28
#define SW_VOLD 29

// ---------------- SETTINGS ----------------
#define DEBOUNCE_DELAY 200

// ---------------- STATE ----------------
int volume = 50;
unsigned long lastOLED = 0;
unsigned long lastPress[4] = {0, 0, 0, 0};

// ---------------- FUNCTIONS ----------------
void sendDiscordKey(uint8_t key) {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(key);
  delay(40);
  Keyboard.releaseAll();
}

bool pressed(uint8_t pin, uint8_t index) {
  if (!digitalRead(pin)) {
    if (millis() - lastPress[index] > DEBOUNCE_DELAY) {
      lastPress[index] = millis();
      return true;
    }
  }
  return false;
}

// ---------------- SETUP ----------------
void setup() {
  pinMode(SW_MUTE, INPUT_PULLUP);
  pinMode(SW_CAM, INPUT_PULLUP);
  pinMode(SW_VOLU, INPUT_PULLUP);
  pinMode(SW_VOLD, INPUT_PULLUP);

  Keyboard.begin();
  Consumer.begin();

  Wire.begin(6, 7); // SDA, SCL

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
}

// ---------------- LOOP ----------------
void loop() {

  // Discord mute (CTRL + SHIFT + M)
  if (pressed(SW_MUTE, 0)) {
    sendDiscordKey(KEY_M);
  }

  // Discord video (CTRL + SHIFT + V)
  if (pressed(SW_CAM, 1)) {
    sendDiscordKey(KEY_V);
  }

  // Volume up
  if (pressed(SW_VOLU, 2)) {
    Consumer.write(MEDIA_VOLUME_UP);
    volume = min(volume + 2, 100);
  }

  // Volume down
  if (pressed(SW_VOLD, 3)) {
    Consumer.write(MEDIA_VOLUME_DOWN);
    volume = max(volume - 2, 0);
  }

  // OLED refresh
  if (millis() - lastOLED > 200) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(0, 0);
    display.print("USB-C MACROPAD");

    display.setCursor(0, 12);
    display.print("VOL: ");
    display.print(volume);
    display.print("%");

    display.setCursor(0, 22);
    display.print("TIME: ");
    display.print(millis() / 1000);
    display.print("s");

    display.display();
    lastOLED = millis();
  }
}
