#include "mainMenu.h"

MainMenu::MainMenu(float height, float width) {
    if (!font.loadFromFile("font1.ttf")) {
        cout << "Font not found" << endl;
    }
    if (!MMtexture.loadFromFile("MMtexture.png")) {
        cout << "Background texture not found" << endl;
    }
    
    spriteBackGround.setTexture(MMtexture);
    spriteBackGround.setPosition(0, 0);

    mainMenu[0].setString("Welcome to chaos Game");
    mainMenu[0].setFillColor(Color::White);
    mainMenu[0].setCharacterSize(75);
    mainMenu[0].setPosition(650, 200);
    mainMenu[0].setFont(font);
    

    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(Color::White);
    mainMenu[1].setCharacterSize(75);
    mainMenu[1].setPosition(900,300);
    mainMenu[1].setString("Start");

    mainMenu[2].setFont(font);
    mainMenu[2].setCharacterSize(75);
    mainMenu[2].setPosition(900, 400);
    mainMenu[2].setString("Settings");
    mainMenu[2].setFillColor(Color::White);

    mainMenu[3].setFont(font);
    mainMenu[3].setCharacterSize(75);
    mainMenu[3].setPosition(900, 500);
    mainMenu[3].setString("Exit");
    mainMenu[3].setFillColor(Color::White);



    mainMenuSelected = 0;

}

void MainMenu::draw(RenderWindow& window) {
    window.draw(spriteBackGround);
    for (int i = 0; i<MAX_MAIN_MENU; ++i) {
        window.draw(mainMenu[i]);
    }
}

void MainMenu::moveUp() {
    cout << "Selected: " << mainMenuSelected << endl;
    if (mainMenuSelected >= 0) {
        mainMenu[mainMenuSelected].setFillColor(Color::White);
        mainMenuSelected--;

        if (mainMenuSelected == 0) {

            mainMenuSelected = 3;
        }
        mainMenu[mainMenuSelected].setFillColor(Color::Green);
    }
}

void MainMenu::moveDown() {
    cout << "Selected: " << mainMenuSelected << endl;
    if (mainMenuSelected <= MAX_MAIN_MENU) {
        mainMenu[mainMenuSelected].setFillColor(Color::White);
        mainMenuSelected++;

        if (mainMenuSelected == 4) {
            mainMenuSelected = 1;
        }
    }
    mainMenu[mainMenuSelected].setFillColor(Color::Green);
   
    }
