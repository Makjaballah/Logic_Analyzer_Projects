# Project: Interfacing of DAC IC to the STM32F103C8T6 Blue Pill Development Board to generate Triangular Wave 

## The aim
The MCP4725 IC Digital to Analog Converter (DAC) is easy to program and understand. It has the following features:
```
-> 12-bit resolution
-> On-board nonvolatile memory (EEPROM)
-> External A0 address pin
-> Normal or power-down mode
-> Single-supply operation: 2.7 V to 5.5 V
-> Standard (100 kbit/sec), fast (400 kbit/sec), and high (3.4 Mbit/sec) speeds
```
The MCP4725 IC can respond to one of the following I2C addresses: 0x60/0x61, 0x62/0x63, 0x64/0x65, or 0x66/0x67. There are two I2C operations of interest: writing a 12-bit digital value to the DAC and reading the current DAC output and EEPROM values from the chip. The main purpose of this application is to generate a continuous triangle wave by continuously incrementing the DAC output from 0x0 to 0xFFF (12 bits) and then decrementing from 0xFFF back to 0x0. The Logic Analyzer Device is used to analyze the I2C data stream. As such, it displays the address byte and R/W command and each data byte passing on the bus. On the other hand, the display also marks the start and stop conditions on the data waveforms.

## Hardware Requirements

```
      1- STM32F103C8T6 Blue Pill
      2- MCP4725 DAC IC
      3- Oscilloscope
      4- 24MHz 8-Channel USB Logic Analyzer Device
      5- FT232RL USB to TTL 3.3V 5V Serial Adapter Module
      6- Solderless breadboard
      7- Jumper wires
```

## The main circuit diagram
<img src="https://github.com/user-attachments/assets/5ff397bf-c4be-418b-8c60-e60a537adcd7" width="800">
