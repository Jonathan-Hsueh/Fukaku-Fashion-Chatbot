#include <iostream>
#include "ClothingItem.h"
#include "WardrobeFunctions.h"
#include "DelayPrint.h"

using namespace std;

int main() {
    vector<ClothingItem> wardrobe; // Vector to store clothing items
    unordered_map<string, ClothingItem> wardrobeMap; // Map for quick lookup

    int choice;
    do {
        delayPrintLine(retrieveStatement("prompts"));
        cin >> choice;
        cin.ignore(); // To clear the newline character

        try {
            if (choice == 1) {
                string name, color, style, description;
                delayPrintChar("Awesome! Lets design your very own thing. Enter item name: "); getline(cin, name);
                delayPrintChar("Enter item color: "); getline(cin, color);
                delayPrintChar("Enter item style: "); getline(cin, style);
                delayPrintChar("Enter item description (no commas please): "); getline(cin, description);

                addClothingItem(wardrobe, wardrobeMap, ClothingItem(name, color, style, description));

            } else if (choice == 2) {
                delayPrintChar("Sounds great, here we go!\n");
                displayWardrobe(wardrobe);

            } else if (choice == 3) {
                string name;
                delayPrintChar("Enter the name of the item to search: "); getline(cin, name);
                ClothingItem foundItem = searchByName(wardrobeMap, name);
                string statement = "Found: " + foundItem.name + " (" + foundItem.color + ", " + foundItem.style + ")\n  Description: " + foundItem.description + "\n\n";
                delayPrintChar(statement);

            } else if (choice == 4) {
                suggestOutfit(wardrobe);

            } else if (choice == 5) {
                string filename;
                delayPrintChar("Enter the filename to save the wardrobe: "); getline(cin, filename);
                saveWardrobeToFile(wardrobe, filename);

            } else if (choice == 6) {
                string filename;
                delayPrintChar("Enter the filename to load the wardrobe: "); getline(cin, filename);
                loadWardrobeFromFile(wardrobe, wardrobeMap, filename);

            } else if (choice != 7) {
                delayPrintChar("Invalid choice. Please try again.\n");
            }

        } catch (const invalid_argument &e) {
            cout << e.what() << "\n";
        }
    } while (choice != 7);

    delayPrintChar("Awe bummer, have a good one, goodbye!\n");
    return 0;
}
