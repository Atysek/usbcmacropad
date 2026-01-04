import time
import board
import digitalio
import usb_hid

from adafruit_hid.keyboard import Keyboard
from adafruit_hid.keycode import Keycode
from adafruit_hid.consumer_control import ConsumerControl
from adafruit_hid.consumer_control_code import ConsumerControlCode

import busio
import displayio
import adafruit_displayio_ssd1306
from adafruit_display_text import label
import terminalio

# --- HID setup ---
keyboard = Keyboard(usb_hid.devices)
consumer = ConsumerControl(usb_hid.devices)

# --- Buttons ---
pins = [board.GP26, board.GP27, board.GP28, board.GP29]
buttons = []

for pin in pins:
    btn = digitalio.DigitalInOut(pin)
    btn.direction = digitalio.Direction.INPUT
    btn.pull = digitalio.Pull.UP
    buttons.append(btn)

# --- Display setup ---
displayio.release_displays()

i2c = busio.I2C(scl=board.GP7, sda=board.GP6)
display_bus = displayio.I2CDisplay(i2c, device_address=0x3C)

display = adafruit_displayio_ssd1306.SSD1306(
    display_bus, width=128, height=32
)

splash = displayio.Group()
display.root_group = splash

volume_label = label.Label(terminalio.FONT, text="VOL: 0", x=0, y=10)
uptime_label = label.Label(terminalio.FONT, text="UP: 0s", x=0, y=25)

splash.append(volume_label)
splash.append(uptime_label)

# --- State ---
volume = 0
start_time = time.monotonic()

# --- Main loop ---
while True:
    # Key 1: Discord mute (Ctrl + Shift + M)
    if not buttons[0].value:
        keyboard.send(Keycode.CONTROL, Keycode.SHIFT, Keycode.M)
        time.sleep(0.3)

    # Key 2: Discord camera (Ctrl + Shift + O)
    if not buttons[1].value:
        keyboard.send(Keycode.CONTROL, Keycode.SHIFT, Keycode.O)
        time.sleep(0.3)

    # Key 3: Volume up
    if not buttons[2].value:
        consumer.send(ConsumerControlCode.VOLUME_INCREMENT)
        volume += 1
        time.sleep(0.2)

    # Key 4: Volume down
    if not buttons[3].value:
        consumer.send(ConsumerControlCode.VOLUME_DECREMENT)
        volume -= 1
        time.sleep(0.2)

    # Update display
    volume_label.text = f"VOL: {volume}"
    uptime = int(time.monotonic() - start_time)
    uptime_label.text = f"UP: {uptime}s"

    time.sleep(0.05)
