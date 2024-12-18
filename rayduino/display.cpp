#include "display.h"

Display::Display() {
    resX = 96;
    resY = 64;
    initializeDisplay();
}

Display::Display(int x, int y) {
    resX = x;
    resY = y;

    initializeDisplay();
}

Display::~Display() {}

void Display::initializeDisplay() {
    pinMode(clock, OUTPUT);
    pinMode(data, OUTPUT);
    pinMode(reset, OUTPUT);
    pinMode(command, OUTPUT);
    pinMode(cs, OUTPUT);


    digitalWrite(reset, LOW);
    delay(50);
    digitalWrite(reset, HIGH);
    delay(100);

    sendCommand(0xAE); // Display off

    sendCommand(0xA0); // Set remap

    sendCommand(0x72); // RGB Color

    sendCommand(0xA1); // Start line
    sendCommand(0x00);

    sendCommand(0xA2); // Display offset
    sendCommand(0x00);

    sendCommand(0xA4); // Normal display
    sendCommand(0xA8); // Set multiplex
    sendCommand(0x3F);

    sendCommand(0xAD); // Set master
    sendCommand(0x8E);

    sendCommand(0xB0); // Power mode
    sendCommand(0x0B);

    sendCommand(0xB1); // Precharge
    sendCommand(0x31);

    sendCommand(0xB3); // Clock div
    sendCommand(0xF0);

    sendCommand(0x8A); // Precharge A
    sendCommand(0x64);

    sendCommand(0x8B); // Precharge B
    sendCommand(0x78);

    sendCommand(0x8C); // Precharge C
    sendCommand(0x64);

    sendCommand(0xBB); // Precharge Level
    sendCommand(0x3A);

    sendCommand(0xBE); // VCOMH
    sendCommand(0x3E);

    // sendCommand(0x87); //Mastercurrent
    // sendCommand(0x06);

    sendCommand(0x81); // Contrast A
    sendCommand(0x91);

    sendCommand(0x82); // Contrast B
    sendCommand(0x50);

    sendCommand(0x83); // Contrast C
    sendCommand(0x7D);

    sendCommand(0xAF); // Display on
}

void Display::sendData(uint8_t din) {
    digitalWrite(command, HIGH);
    digitalWrite(cs, LOW);
    digitalWrite(clock, LOW);

    shiftOut(data, clock, MSBFIRST, din);

    digitalWrite(cs, HIGH);
}

void Display::sendCommand(uint8_t command) {
    digitalWrite(command, LOW);
    digitalWrite(cs, LOW);
    digitalWrite(clock, LOW);
    shiftOut(data, clock, MSBFIRST, command);
    digitalWrite(cs, HIGH);
}

void Display::sendColor(Color color) {
    uint16_t pixelColor = color.asBytes();
    sendData(pixelColor >> 8);
    sendData((uint8_t) pixelColor);
}
