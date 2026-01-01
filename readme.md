🎛️ USB-C MACROPAD

This device is a USB-C macropad built around the XIAO RP2040, designed for media control and Discord productivity.
It features 4 mechanical keys, a 128×32 OLED display, and runs entirely over USB HID.

This project was built as a compact, beginner-friendly reference for custom macropads using modern microcontrollers.

✨ Features

⌨️ 4× Mechanical Keys (Cherry MX compatible)

🖥️ 0.91″ 128×32 SSD1306 OLED display

🔌 USB-C (XIAO RP2040)

🎧 Media control (volume up/down)

🎙️ Discord controls

Mute / unmute microphone

Camera on / off

💻 USB HID device (no drivers required)

🧠 Simple, readable firmware

🧠 What It Does
Key	Action
Key 1	Discord mute / unmute
Key 2	Discord camera toggle
Key 3	Volume up
Key 4	Volume down

The OLED display always shows:

Current volume (tracked by firmware)

Device uptime (seconds since boot)

Discord shortcuts are configured using global keybinds, so the macropad works even when Discord is not focused.

🖥 OLED Display

Resolution: 128×32

Interface: I²C

🔧 Hardware
Main Components

XIAO RP2040 DIP

4× Cherry MX switches

0.91″ SSD1306 OLED (I²C)

USB-C cable

GPIO Usage
Function	GPIO
Key 1	GPIO26
Key 2	GPIO27
Key 3	GPIO28
Key 4	GPIO29
OLED SDA	GPIO6
OLED SCL	GPIO7

Switches are wired using internal pull-ups (pressed = LOW).

🧩 PCB & Schematic

The PCB was designed in KiCad and uses:

MX switch footprints

Direct GPIO wiring (no matrix)

USB-powered only

This is a simple, low-component design meant to be easy to understand and modify.

(Add images here)


💾 Firmware

Platform: Arduino (RP2040 core)

USB Mode: Composite HID

Keyboard

Media keys

Libraries used:

HID-Project

Adafruit_SSD1306

Adafruit_GFX

Discord Keybinds Used

Configure these in Discord → Settings → Keybinds:

Action	Keybind
Mute	Ctrl + Shift + M
Camera	Ctrl + Shift + O
🚀 Getting Started

Flash firmware to the XIAO RP2040

Plug macropad into USB

Set Discord global keybinds

Done — no drivers needed 🎉

📦 BOM

1× XIAO RP2040 DIP

4× Cherry MX switches

4× Keycaps

1× SSD1306 0.91″ OLED

1× PCB

1× Case (optional / 3D printed)

🧡 Credits / Notes

This project was built as a learning exercise and reference design.
Feel free to fork, remix, or improve it.

📸 Gallery


![BOTTOM](https://github.com/user-attachments/assets/ed747043-4215-4b27-a74c-90187678c82d)
![TOP](https://github.com/user-attachments/assets/b3c34520-6380-46e9-8a5e-9df1e8433c83)
![SCHEME](https://github.com/user-attachments/assets/9be39e64-921a-45e5-8bd8-e946ed8b6572)
![PCB](https://github.com/user-attachments/assets/a3ca02c6-11b9-46eb-af41-8a2cc5480799)

