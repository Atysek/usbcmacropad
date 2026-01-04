🎛️ USB-C Macropad

What is this

Basically, I wanted a small macropad for Discord controls and media volume, with a little screen for feedback. It’s a 4-key USB-C macropad built around the Seeed XIAO RP2040, with a 128×32 OLED display on top.

The idea was to keep it simple and beginner-friendly — no key matrix, no drivers, no complicated firmware. Just plug it in and it works as a USB HID device.

✨ Features

⌨️ 4× Mechanical Keys (Cherry MX compatible)

🖥️ 0.91″ 128×32 SSD1306 OLED display

🔌 USB-C connectivity (XIAO RP2040)

🎧 Media controls

Volume up

Volume down

🎙️ Discord controls

Mute / unmute microphone

Camera on / off

💻 USB HID device (works on Windows, macOS, Linux)

🧠 Simple, readable firmware

⚡ USB-powered only (no battery)

🔧Hardware

MCU: Seeed XIAO RP2040 (DIP)

Switches: 4× Cherry MX compatible switches

Display: 0.91″ 128×32 SSD1306 OLED (I²C)

Interface: USB-C (USB HID)

Power: USB only

🧩 PCB & Schematic

The PCB was designed in KiCad with simplicity in mind:

MX switch footprints

Direct GPIO wiring (no switch matrix)

The PCB was designed in KiCad with direct GPIO wiring and minimal components.
![PCB](https://github.com/user-attachments/assets/a3ca02c6-11b9-46eb-af41-8a2cc5480799)
⌨️Default keymap

Key 1: Discord mute / unmute

Key 2: Discord camera on / off

Key 3: Volume up

Key 4: Volume down

Discord actions use global keybinds, so they work even when Discord isn’t focused.

🖥 OLED Display

The OLED provides basic real-time feedback:

Current system volume (tracked by firmware)

Device uptime (seconds since boot)

Display details:

Resolution: 128×32

Controller: SSD1306

Interface: I²C

GPIO layout

Key 1: GPIO26

Key 2: GPIO27

Key 3: GPIO28

Key 4: GPIO29

OLED SDA: GPIO6

OLED SCL: GPIO7

Switches use internal pull-ups (pressed = LOW).

💾 Firmware

Platform: Arduino (RP2040 core)

USB Mode: Composite HID

Programming

This macropad runs CircuitPython and acts as a USB HID device (keyboard + media keys).

To change behavior, just edit code.py on the CIRCUITPY drive and save — the board restarts automatically.

No compiling, no flashing tools.

Libraries used:

HID-Project

Adafruit_SSD1306

Adafruit_GFX

🎮Discord keybinds

Configure these in Discord → Settings → Keybinds:

Mute / Unmute: Ctrl + Shift + M

Camera Toggle: Ctrl + Shift + O

📦 Bill of Materials (BOM)

1× Seeed XIAO RP2040 DIP

4× Cherry MX switches

4× Keycaps

1× 0.91″ SSD1306 OLED

1× Custom PCB

1× Case (optional / 3D printed)


Building one

All the project files are included:

/pcb – KiCad PCB and schematic

/firmware – Arduino source code

/cad – Case files (optional)

Order the PCB, solder the components, flash the firmware to the XIAO, plug it in, and you’re good to go.

🧡 Final Thoughts

This project was built as a learning exercise and reference design for anyone interested in custom macropads. It’s intentionally simple, easy to assemble, and easy to modify.
📸 Gallery


![BOTTOM](https://github.com/user-attachments/assets/ed747043-4215-4b27-a74c-90187678c82d)
![TOP](https://github.com/user-attachments/assets/b3c34520-6380-46e9-8a5e-9df1e8433c83)
![SCHEME](https://github.com/user-attachments/assets/9be39e64-921a-45e5-8bd8-e946ed8b6572)

