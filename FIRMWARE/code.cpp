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

// ---------------- VARIABLES ----------------
int volume = 50;
unsigned long lastUpdate = 0;

// ---------------- FUNCTIONS ----------------
void sendDiscordKey(uint8_t key) {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(key);
  delay(40);
  Keyboard.releaseAll();
}

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

void loop() {
  if (!digitalRead(SW_MUTE)) {
    sendDiscordKey(KEY_F13);
    delay(300);
  }

  if (!digitalRead(SW_CAM)) {
    sendDiscordKey(KEY_F14);
    delay(300);
  }

  if (!digitalRead(SW_VOLU)) {
    Consumer.write(MEDIA_VOLUME_UP);
    volume = min(volume + 2, 100);
    delay(200);
  }

  if (!digitalRead(SW_VOLD)) {
    Consumer.write(MEDIA_VOLUME_DOWN);
    volume = max(volume - 2, 0);
    delay(200);
  }

  if (millis() - lastUpdate > 200) {
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
    lastUpdate = millis();
  }
}
