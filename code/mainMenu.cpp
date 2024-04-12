#include "mainMenu.h"

MainMenu::MainMenu(float height, float width) {
    if (!font.loadFromFile("font1.ttf")) {
        cout << "Font not found" << endl;
    }

    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(Color::White);
    mainMenu[0].setCharacterSize(75);
    mainMenu[0].setPosition(400,200);
    mainMenu[0].setString("Start");

    mainMenu[1].setFont(font);
    mainMenu[1].setCharacterSize(75);
    mainMenu[1].setPosition(400, 400);
    mainMenu[1].setString("Exit");
    mainMenu[1].setFillColor(Color::White);

    mainMenuSelected = -1;

}

void MainMenu::draw(RenderWindow& window) {
    for (int i = 0; i<MAX_MAIN_MENU; ++i) {
        window.draw(mainMenu[i]);
    }
}

void MainMenu::moveUp() {
    cout << "Selected: " << mainMenuSelected << endl;
    if (mainMenuSelected >= 0) {
        mainMenu[mainMenuSelected].setFillColor(Color::White);
        mainMenuSelected --;
    }
        if (mainMenuSelected == -1) {
           
            mainMenuSelected = 1;
        }
        mainMenu[mainMenuSelected].setFillColor(Color::Blue);

}

void MainMenu::moveDown() {
    cout << "Selected: " << mainMenuSelected << endl;
    if (mainMenuSelected <= MAX_MAIN_MENU) {
        mainMenu[mainMenuSelected].setFillColor(Color::White);
        mainMenuSelected ++;
    }
    if (mainMenuSelected == 3) {
        mainMenuSelected = 1;
    }
        if (mainMenuSelected == 1) {
            mainMenuSelected = 0;
        }
        mainMenu[mainMenuSelected].setFillColor(Color::Blue);
    }
