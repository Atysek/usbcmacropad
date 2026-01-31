# USB-C Macropad

This is a device, that will help you with everyday tasks that needs switching tabs or using shortcuts to get to them. It is very easy to use and you can customize their use by your preferences.

---
# PCB & Schematic

The PCB was designed in KiCad.
![PCB](https://github.com/user-attachments/assets/a3ca02c6-11b9-46eb-af41-8a2cc5480799)

---
# Default keymap (My idea was to use it with Discord)
Key 1: Discord mute / unmute

Key 2: Discord camera on / off

Key 3: Volume up

Key 4: Volume down

---
# 💾 Firmware

Platform: Arduino (RP2040 core)
USB Mode: Acts as a keyboard
Programming:
This macropad runs CircuitPython and acts as a USB HID device so it can input keys like a real keyboard.
To change hotkeys, just edit the code. It uses basic drivers so you dont need to install anything.


# 📦 BOM – Bill of Materials

| Quantity | Name | Description |
|----------|------|-------------|
| 1× | Seeed RP2040 | Microcontroller |
| 4× | Red mechanical switches | MX compatible switches |
| 4× | Keycaps | MX keycaps |
| 1× | OLED 0.91" 128×32 | 4-pin I2C display SSD1309 |
| 1× | Custom PCB | Designed in KiCAD |
| 1× | Case | 3D-printed case through Fusion |


All the project files are in these repositories:
/pcb – KiCad PCB and schematic
/firmware – Arduino source code
/cad – Case files (optional)
Order the PCB, upload the code, 3D print the case and connect everything into one piece and you have a working MACROPAD.

📸 Gallery

![WHOLE DEVICE](https://github.com/user-attachments/assets/ef13cd5d-f719-4dd9-bc52-8240453a8fed)
![BOTTOM](https://github.com/user-attachments/assets/ed747043-4215-4b27-a74c-90187678c82d)
![TOP](https://github.com/user-attachments/assets/b3c34520-6380-46e9-8a5e-9df1e8433c83)
![SCHEME](https://github.com/user-attachments/assets/9be39e64-921a-45e5-8bd8-e946ed8b6572)

