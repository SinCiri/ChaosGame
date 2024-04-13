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

    MMtext.setFont(font);
    MMtext.setColor(Color::White);
    MMtext.setPosition(600, 100);
    MMtext.setCharacterSize(100);
    MMtext.setString("Welcome to Chaos Game");

    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(Color::White);
    mainMenu[0].setCharacterSize(75);
    mainMenu[0].setPosition(900,300);
    mainMenu[0].setString("Start");

    mainMenu[1].setFont(font);
    mainMenu[1].setCharacterSize(75);
    mainMenu[1].setPosition(900, 400);
    mainMenu[1].setString("Settings");
    mainMenu[1].setFillColor(Color::White);

    mainMenu[2].setFont(font);
    mainMenu[2].setCharacterSize(75);
    mainMenu[2].setPosition(900, 500);
    mainMenu[2].setString("Exit");
    mainMenu[2].setFillColor(Color::White);



    mainMenuSelected = -1;

}

void MainMenu::draw(RenderWindow& window) {
    window.draw(spriteBackGround);
    for (int i = 0; i<MAX_MAIN_MENU; ++i) {
        window.draw(mainMenu[i]);
    }
    window.draw(MMtext);
}

void MainMenu::moveUp() {
    cout << "Selected: " << mainMenuSelected << endl;
    if (mainMenuSelected - 1 >= 0) {
        mainMenu[mainMenuSelected].setFillColor(Color::White);
        mainMenuSelected--;

        if (mainMenuSelected == -1) {

            mainMenuSelected = 3;
        }
        mainMenu[mainMenuSelected].setFillColor(Color::Green);
    }
}

void MainMenu::moveDown() {
    cout << "Selected: " << mainMenuSelected << endl;
    if (mainMenuSelected + 1 <= MAX_MAIN_MENU) {
        mainMenu[mainMenuSelected].setFillColor(Color::White);
        mainMenuSelected++;

        if (mainMenuSelected == 3) {
            mainMenuSelected = 0;
        }
    }
    mainMenu[mainMenuSelected].setFillColor(Color::Green);
   
    }
