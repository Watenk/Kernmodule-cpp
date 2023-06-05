
#include <iostream>

#include "FontManager.h"

FontManager::FontManager() {
    if (!oswaldRegular.loadFromFile("Fonts/oswaldRegular.ttf"))
    {
        std::cout << "Fonts/oswaldRegular.ttf missing!" << std::endl;
    }
    if (!oswaldMedium.loadFromFile("Fonts/oswaldMedium.ttf"))
    {
        std::cout << "Fonts/oswaldMedium.ttf missing!" << std::endl;
    }
}