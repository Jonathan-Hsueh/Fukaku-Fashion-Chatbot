#include "ClothingItem.h"

// Default constructor
ClothingItem::ClothingItem() : name(""), color(""), style(""), description("") {}

// Constructor for convenience
ClothingItem::ClothingItem(string n, string c, string s, string d) 
    : name(n), color(c), style(s), description(d) {}
