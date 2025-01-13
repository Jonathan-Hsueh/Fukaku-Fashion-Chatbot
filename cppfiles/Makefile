all: Wardrobe

OBJFILES = wardrobe
MAINFILES = ClothingItem.cpp DelayPrint.cpp Main.cpp WardrobeFunctions.cpp

Wardrobe: ClothingItem.cpp DelayPrint.cpp Main.cpp WardrobeFunctions.cpp 
	g++ $(MAINFILES) -o wardrobe -std=c++17 -Wall
	@echo "Files successfully compiled."

clean: 
	rm -f $(OBJFILES)
	@echo "Object files removed."

.PHONY: all Wardrobe clean
