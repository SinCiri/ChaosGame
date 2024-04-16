#ifndef MAIN_MENU_H
#define MAIN_MENU_H
// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>


using namespace sf;
using namespace std;

const int MAX_MAIN_MENU = 4;

class MainMenu {
public:
    MainMenu(float height, float width);

    void draw(RenderWindow& window);

    //moving around menu options
    void moveUp();
    void moveDown();

    int MainMenuSelected() {
        return mainMenuSelected;
    }

    Font getFont() {
        return font;
    }

 
private:
    int mainMenuSelected;
    Font font;
    Text mainMenu[MAX_MAIN_MENU];
    Texture MMtexture;
    Sprite spriteBackGround;
    
};





#endif