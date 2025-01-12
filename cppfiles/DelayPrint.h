// DelayPrint.h

#ifndef DELAYPRINT_H
#define DELAYPRINT_H

#include <string>  // For string type
#include <chrono>  // For time delays
#include <thread>  // For time delay functionality

// Function to print each character slowly (one character at a time)
void delayPrintChar(const std::string& text, int delay_ms = 30); // Super cool, if you include this, that means it defaults 

// Function to print each line slowly (one line at a time)
void delayPrintLine(const std::string& text, int delay_ms = 50); 

#endif
