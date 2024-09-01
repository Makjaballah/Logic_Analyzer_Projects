# Project: Design of a Digital to Analog converter using the STM32F103C8T6 Blue Pill Development Board

## The aim
The Analog to Digital Converters (ADC) is used to convert real world analog values into digital form so that microcontrollers can process the signals. On the other hand, the Digital to Analog Converter (DAC) is used to convert analog signals from digital values. The Digital to Analog Converter, can be used in many applications such as motor control, control brightness of the LED lights, audio amplifier, video encoders, data acquisition systems etc. The objective of this application is to design a digital to analog converter using the STM32F103C8T6 blue pill development board and the MCP4725 DAC IC. MCP4725 DAC Module, is a 12-Bit digital to analog converter module which is used to generate output analog voltages from (0 to 5V) and it is controlled by using I2C communication. It also comes with on board nonvolatile memory EEPROM. This IC has 12-Bit resolution. This means we use (0 to 4096) as input to provide the voltage output with respect to reference voltage. Maximum reference voltage is 5V. The main idea of this application is to read an analog voltage value from a potentiometer and display its ADC values on a 16x2 LCD Serial I2C interface Board Module. The ADC values are printed also on the serial monitor.

## Hardware Requirements

```
      1- STM32F103C8T6 Blue Pill
      2- MCP4725 DAC IC
      3- Digital Multimeter
      4- 16x2 LCD Serial I2C interface Board Module
      5- 24MHz 8-Channel USB Logic Analyzer Device
      6- FT232RL USB to TTL 3.3V 5V Serial Adapter Module
      7- Solderless breadboard
      8- Jumper wires
      9- 10k Potentiometer
```

## The main circuit diagram
<img src="https://github.com/user-attachments/assets/427508d7-be4b-4e7f-8821-df2c7bd82c9e" width="800">
