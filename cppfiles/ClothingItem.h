#ifndef CLOTHINGITEM_H
#define CLOTHINGITEM_H

#include <string>

using namespace std;

struct ClothingItem {
    string name;
    string color;
    string style;
    string description;

    // Default constructor
    ClothingItem();
    // Constructor for convenience
    ClothingItem(string n, string c, string s, string d);
};

#endif // CLOTHINGITEM_H
