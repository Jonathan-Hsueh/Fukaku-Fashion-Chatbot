// DelayPrint.cpp

#include "DelayPrint.h"
#include <iostream>  // For printing to the console
#include <sstream>   // For stringstream to split text by lines 

// Function to print each character slowly (one character at a time)
void delayPrintChar(const std::string& text, int delay_ms) {
    for (char c : text) {
        std::cout << c << std::flush;  // Print the character immediately
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));  // Wait for the specified delay
    }
    //std::cout << std::endl;  // Ensure a newline after the text is fully printed
}

// Function to print each line slowly (one line at a time)
void delayPrintLine(const std::string& text, int delay_ms) {
    std::stringstream ss(text); // Create a single stream object on text using ss
    std::string line;
    
    while (std::getline(ss, line)) { // ss is single string, gets each string automatically
        std::cout << line << std::endl; // print out each line
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));  // Delay between lines (optional)
    }
}
