#include "WardrobeFunctions.h"
#include "DelayPrint.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random> // For random number generation

using namespace std;

// Get a statement randomly from one of three output files
string retrieveStatement(const string &filename) {
    string baseFile = filename;
    random_device rd; // Random device object
    mt19937 gen(rd()); // Mersenne Twister Random Number Generator
    uniform_int_distribution<> dis(1, 3); // Distribution object

    baseFile = baseFile + to_string(dis(gen)) + ".txt";

    ifstream inFile(baseFile);
    if(!inFile) {
        string statement = "Oh no! Error reading the file " + baseFile + " for reading.\n";
        delayPrintChar(statement);
        return "";
    }
    
    string line;    
    string statement;

    while(!inFile.eof()){
        getline(inFile, line);
        statement = statement + line + "\n";
    }

    return statement;
}

void addClothingItem(
    vector<ClothingItem> &wardrobe,
    unordered_map<string, ClothingItem> &wardrobeMap,
    const ClothingItem &item) {

    wardrobe.push_back(item); // Add to vector
    wardrobeMap[item.name] = item; // Add to map
    string statement = "Added: " + item.name + " to your wardrobe!" + "\n";
    delayPrintChar(statement);

}

ClothingItem searchByName(const unordered_map<string, ClothingItem> &wardrobeMap, const string &name) {
    if (wardrobeMap.find(name) != wardrobeMap.end()) {
        return wardrobeMap.at(name);
    } else {
        throw invalid_argument("Item not found."); // Another way to print an error statement without returning anything
    }
}

void displayWardrobe(const vector<ClothingItem> &wardrobe) {
    delayPrintChar("\nYour wardrobe contains:\n");
    if (wardrobe.empty()) {
        delayPrintChar("Hey, your wardrobe is empty! Add more things before coming back to print it out.\n\n");
        return;
    }
    for (const auto &item : wardrobe) {
        cout << "- " << item.name << " (" << item.color << ", " << item.style << ")\n  Description: " << item.description << "\n";
    }
    delayPrintChar("\nAwesome, it looks amazing! Keep adding more!\n");
}

void suggestOutfit(const vector<ClothingItem> &wardrobe) {
    if (wardrobe.size() < 3) {
        delayPrintChar("\nNot enough items in the wardrobe for a suggestion. Add more items!\n\n");
        return;
    }

    vector<ClothingItem> shuffled = wardrobe; // Copy the wardrobe
    random_device rd; // Random number generator
    mt19937 g(rd());  // Mersenne Twister random number generator
    shuffle(shuffled.begin(), shuffled.end(), g); // Shuffle the wardrobe

    delayPrintChar("\nSuggested outfit:");
    for (size_t i = 0; i < 3; ++i) {
        cout << "- " << shuffled[i].name << " (" << shuffled[i].color << ", " << shuffled[i].style << ")\n";
    }
    cout << "\n";
}

void saveWardrobeToFile(const vector<ClothingItem> &wardrobe, const string &filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error: Could not open file " << filename << " for writing.\n";
        return;
    }

    for (const auto &item : wardrobe) {
        outFile << item.name << "," << item.color << "," << item.style << "," << item.description << "\n";
    }

    outFile.close();
    string statement = "Nice! Your wardrobe saved to " + filename + "\n";
    delayPrintChar(statement);
}

void loadWardrobeFromFile(vector<ClothingItem> &wardrobe, unordered_map<string, ClothingItem> &wardrobeMap, const string &filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Could not open file " << filename << " for reading.\n";
        return;
    }

    wardrobe.clear();
    wardrobeMap.clear();

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string name, color, style, description;

        getline(ss, name, ',');
        getline(ss, color, ',');
        getline(ss, style, ',');
        getline(ss, description, ',');

        ClothingItem item(name, color, style, description);
        wardrobe.push_back(item);
        wardrobeMap[name] = item;
    }

    inFile.close();
    string statement = "Awesome! Your wardrobe loaded from " + filename + "\n";
    delayPrintChar(statement);
}
