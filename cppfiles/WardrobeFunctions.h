#ifndef WARDROBEFUNCTIONS_H
#define WARDROBEFUNCTIONS_H

#include "ClothingItem.h"
#include <vector>
#include <unordered_map>
#include <string>

// Retrieve a statement from a random version of a specific file
string retrieveStatement(const string &filename);

// Add a clothing item to both the vector and unordered_map
void addClothingItem(
    vector<ClothingItem> &wardrobe,
    unordered_map<string, ClothingItem> &wardrobeMap,
    const ClothingItem &item);

// Search for an item by name
ClothingItem searchByName(const unordered_map<string, ClothingItem> &wardrobeMap, const string &name);

// Display all items in the wardrobe
void displayWardrobe(const vector<ClothingItem> &wardrobe);

// Generate random outfit suggestions
void suggestOutfit(const vector<ClothingItem> &wardrobe);

// Save the wardrobe to a file
void saveWardrobeToFile(const vector<ClothingItem> &wardrobe, const string &filename);

// Load the wardrobe from a file
void loadWardrobeFromFile(vector<ClothingItem> &wardrobe, unordered_map<string, ClothingItem> &wardrobeMap, const string &filename);

#endif // WARDROBEFUNCTIONS_H
