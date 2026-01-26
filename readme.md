# 🎛️ USB-C Macropad

This is a 4-key USB-C macropad built around the Seeed XIAO RP2040, with a 128×32 OLED display on top.
The idea was to keep it simple and beginner-friendly — no key matrix, no drivers, no complicated firmware. Just plug it in and it works as a USB HID device.

---
# 🧩 PCB & Schematic

The PCB was designed in KiCad with direct GPIO wiring and minimal components.
![PCB](https://github.com/user-attachments/assets/a3ca02c6-11b9-46eb-af41-8a2cc5480799)

---
# ⌨️Default keymap

Key 1: Discord mute / unmute

Key 2: Discord camera on / off

Key 3: Volume up

Key 4: Volume down

---
# 💾 Firmware

Platform: Arduino (RP2040 core)
USB Mode: Composite HID
Programming
This macropad runs CircuitPython and acts as a USB HID device (keyboard + media keys).
To change behavior, just edit code.py on the CIRCUITPY drive and save — the board restarts automatically.
No compiling, no flashing tools.


# 📦 BOM – Bill of Materials

| Quantity | Name | Description |
|----------|------|-------------|
| 1× | Seeed RP2040 | Microcontroller |
| 4× | Red mechanical switches | MX compatible switches |
| 4× | Keycaps | MX keycaps |
| 1× | OLED 0.91" 128×32 | 4-pin I2C display SSD1309 |
| 1× | Custom PCB | Designed in KiCAD |
| 1× | Case | 3D-printed case through Fusion |


All the project files are included:
/pcb – KiCad PCB and schematic
/firmware – Arduino source code
/cad – Case files (optional)
Order the PCB, solder the components, flash the firmware to the XIAO, plug it in, and you’re good to go.

📸 Gallery

![WHOLE DEVICE](https://github.com/user-attachments/assets/ef13cd5d-f719-4dd9-bc52-8240453a8fed)
![BOTTOM](https://github.com/user-attachments/assets/ed747043-4215-4b27-a74c-90187678c82d)
![TOP](https://github.com/user-attachments/assets/b3c34520-6380-46e9-8a5e-9df1e8433c83)
![SCHEME](https://github.com/user-attachments/assets/9be39e64-921a-45e5-8bd8-e946ed8b6572)

