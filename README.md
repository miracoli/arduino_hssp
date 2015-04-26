# arduino_hssp
PSoC® 1 Device Programming using an Arduino

This is a port of the code found at http://www.cypress.com/?rID=2906 (AN44168, Revision 2.30) to the Arduino platform.
It will write and verify ascending hex values to a PSoC® 1 Device connected to an Arduino running this code.

A desktop application for sending the Arduino a .hex file is planned as next step.

## Motivation

The aim of the project is it, to make the purchase of a separate PSoC programmer obsolete for people who already own an Arduino.

## Usage

Clone the code into a folder called 'arduino_hssp', open the project in the Arduino IDE and compile and program it. Connect your PSoC 1 device as follows (can be changed in issp_defs.h):

SDATA_PIN -> 9

SCLK_PIN -> 8

XRES_PIN -> 4

TARGET_VDD -> 11

Run the code and check serial output.

## Project status
Tested and working with Arduino Leonardo and CY8C21434.

## TODOs
Test with more Arduinos and PSoCs. Add desktop application to be able to program a hex file.

