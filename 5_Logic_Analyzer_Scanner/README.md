# Project: I2C Scanner devices using Arduino Uno Rev3

## The aim
When we need to use I2C modules for Arduino Uno Projects, sometimes the manufacturer didn't give the address of I2C device inside the chip. It can be a serious problem if the address is unknown or we write the wrong address. The solution is to use a method for scanning the I2C Device inside the module that connected to I2C bus in Arduino Uno (SDA, SCL). In Arduino Uno, I2C bus is connected to A4 (SDA) and A5 (SCL). The aim of this application is to show how to scan I2C-bus for devices with a very simple sketch. If a device is found, it is reported to the Arduino serial monitor. The sketch shows the 7-bit addresses of the found devices as hexadecimal values. The module used her for testing is the PCF8574 I2C module. The default I2C address of this module is HEX 0x27.

## Hardware Requirements

```
      1- Arduino Uno Rev3
      2- 24MHz 8-Channel USB Logic Analyzer Device
      3- One PCF8574 I2C module
```

## The main circuit diagram
<img src="https://github.com/user-attachments/assets/2e671438-f4ac-4933-8762-13086cd22097" width="800">
