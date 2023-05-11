# Alvord2023
Notes and code for our trip to the Alvord Desert in 2023

This repository will collect notes and code in support of our visit to the Alvord Desert in 2023 May. 

* 2023 May 11 -- We had to do some futzing with the Arduino source code to make it work. Some of the required files are included in the code folder. The BMP180 library that we were using is deprecated (https://github.com/LowPowerLab/SFE_BMP180). In order to get it working in the Arduino IDE, we had to install the library (SFE_BMP180.h) AND put the source file SFE_BMP180.cpp into the Arduino library folder. (On my Mac, this library folder is ~/Documents/Arduino/libraries/SFE_BMP180.) We have also included the Arduino sketch file Waveshare_pressure_Datalogger_just-dust.ino. With that library installation process, things seem to work (except that the RTC clock date was wrong.)
