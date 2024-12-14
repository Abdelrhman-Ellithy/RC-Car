# 🚗 RC Car Project with ATmega32

This repository contains the implementation of a remote-controlled (RC) car using the **ATmega32 microcontroller**. The project utilizes various peripherals and drivers to control the car's motion, handle inputs, and provide feedback using sensors and actuators.

---

## 📂 Project Structure

```
RC Car
├── .vs
│   ├── testttt
│   │   ├── v14
│   │   │   └── .atsuo
├── testttt
│   ├── ATMEGA32
│   │   └── main.asm
│   │   └── main.c
│   ├── Debug
 
│   │   └── makedep.mk
│   │   └── testttt.eep
│   │   └── testttt.elf
│   │   └── testttt.hex
│   │   └── testttt.lss
│   │   └── testttt.map
│   │   └── testttt.srec
│   ├── HAL
│   │   ├── DC Motor
│   │   │   └── DCMOTOR_Interface.h
│   │   │   └── DCMOTOR_program.c
│   │   │   └── DC_Motor_Config.h
│   │   │   └── DC_Motor_Private.h
│   ├── LIB
│   │   └── BIT_OPERATIONS.h
│   │   └── Types.h
│   │   └── register.h
│   ├── MCAL
│   │   ├── DIO Driver
│   │   │   └── BIT_OPERATIONS.h
│   │   │   └── DIO_Config.h
│   │   │   └── DIO_Interface.h
│   │   │   └── DIO_Private.h
│   │   │   └── DIO_Program.c
│   │   ├── EX_INT Driver
│   │   │   └── EX_INTERRUPT_Config.h
│   │   │   └── EX_INTERRUPT_Interface.h
│   │   │   └── EX_INTERRUPT_Private.h
│   │   │   └── EX_INTERRUPT_Progrm.c
│   │   ├── PORT Driver
│   │   │   └── PORT_config.h
│   │   │   └── PORT_interface.h
│   │   │   └── PORT_private.h
│   │   │   └── PORT_program.c
 
│   │   ├── Timers
│   │   │   └── Timers_Config.h
│   │   │   └── Timers_Interface.h
│   │   │   └── Timers_Private.h
│   │   │   └── Timers_Program.c
│   │   ├── UART Driver
│   │   │   └── UART_Config.h
│   │   │   └── UART_Interface.h
│   │   │   └── UART_Private.h
│   │   │   └── UART_Program.c
│   │   └── Timers.c
│   │   └── Timers.h
│   ├── Project Backups
│   │   └── rc [Proteus 8.0].pdsprj
│   └── testttt.componentinfo.xml
│   └── Backup Of rc.pdsbak
│   └── main.c
│   └── rc.pdsprj
│   └── rc.pdsprj.ABDELRHMAN-LAPT.lenovo.workspace
│   └── testttt.cproj
└── testttt.atsln
```

---

## 🛠️ Features

- **DC Motor Control**:  
  Control the car's motion (forward, backward, left, right) using the DC Motor driver.

- **Button Control**:  
  Manage inputs via buttons for different control actions.

- **Buzzer Feedback**:  
  Alert or notify using the buzzer for specific events.

- **LED Indicators**:  
  Visual feedback for different car states (e.g., motion direction).

- **Temperature Monitoring**:  
  Integrated **LM35 sensor** to monitor and display temperature.

- **Keypad Input**:  
  Use a keypad for manual control or entering commands.

- **EEPROM Storage**:  
  Persistent storage using the EEPROM driver for saving settings.

- **Timers and Interrupts**:  
  Timer-based control and external interrupts for responsive behavior.

- **UART Communication**:  
  Serial communication for debugging or additional controls.

---

## ⚙️ Setup Instructions

1. **Hardware Requirements**:
   - ATmega32 Microcontroller
   - DC Motors and Motor Driver
   - Buttons and Keypad
   - LEDs
   - Buzzer
   - LM35 Temperature Sensor
   - Power Supply
   - Breadboard and Jumper Wires

2. **Software Requirements**:
   - **AVR Studio** / **Microchip Studio**
   - **Proteus 8.0** for simulation
   - **AVR Toolchain** (GCC, AVRDUDE)

3. **Build and Flash**:
   - Compile `main.c` and generate the hex file.
   - Flash the hex file to the ATmega32 microcontroller using a USBasp programmer.

---

## 📝 Notes

- The project uses **assembly (`main.asm`)** and **C language (`main.c`)** for firmware development.
- The Proteus simulation files are located in `Project Backups/`.

---

## 📜 License

This project is licensed under the MIT License.

---

## 📧 Contact

For questions or suggestions, reach out via [abdelarhmanellithy@gmail.com] or visit my GitHub profile at [Abdelrhman-Ellithy](https://github.com/Abdelrhman-Ellithy).