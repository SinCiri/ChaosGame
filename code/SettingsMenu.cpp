#include "SettingsMenu.h"


SettingsMenu::SettingsMenu(float height, float width) {
    speed = 25;
    VerColor = Color::Red;
    triangleColor = Color::Blue;
    if (!font.loadFromFile("font1.ttf")) {
        cout << "Font not found" << endl;
    }
    MenuText.setFillColor(Color::White);
    MenuText.setCharacterSize(75);
    MenuText.setFont(font);
    MenuText.setPosition(200, 100);
    MenuText.setString("Choose Menu Options:");

    MenuChoices[0][0].setFillColor(Color::White);
    MenuChoices[0][0].setFont(font);
    MenuChoices[0][0].setCharacterSize(50);
    MenuChoices[0][0].setPosition(200, 300);
    MenuChoices[0][0].setString("Speed: ");

    MenuChoices[1][0].setFillColor(Color::White);
    MenuChoices[1][0].setFont(font);
    MenuChoices[1][0].setCharacterSize(50);
    MenuChoices[1][0].setPosition(200, 450);
    MenuChoices[1][0].setString("Triangle Color: ");

    MenuChoices[2][0].setFillColor(Color::White);
    MenuChoices[2][0].setFont(font);
    MenuChoices[2][0].setCharacterSize(50);
    MenuChoices[2][0].setPosition(200, 600);
    MenuChoices[2][0].setString("Dot Color: ");




    //Settings Options for speed
    MenuChoices[0][1].setFillColor(Color::White);
    MenuChoices[0][1].setFont(font);
    MenuChoices[0][1].setCharacterSize(50);
    MenuChoices[0][1].setPosition(400, 300);
    MenuChoices[0][1].setString("1");

    MenuChoices[0][2].setFillColor(Color::White);
    MenuChoices[0][2].setFont(font);
    MenuChoices[0][2].setCharacterSize(50);
    MenuChoices[0][2].setPosition(500, 300);
    MenuChoices[0][2].setString("2");

    MenuChoices[0][3].setFillColor(Color::White);
    MenuChoices[0][3].setFont(font);
    MenuChoices[0][3].setCharacterSize(50);
    MenuChoices[0][3].setPosition(600, 300);
    MenuChoices[0][3].setString("3");

    //options for colors
    MenuChoices[1][1].setFillColor(Color::White);
    MenuChoices[1][1].setFont(font);
    MenuChoices[1][1].setPosition(600, 450);
    MenuChoices[1][1].setCharacterSize(50);
    MenuChoices[1][1].setString("Red");

    MenuChoices[1][2].setFillColor(Color::White);
    MenuChoices[1][2].setFont(font);
    MenuChoices[1][2].setPosition(750, 450);
    MenuChoices[1][2].setCharacterSize(50);
    MenuChoices[1][2].setString("Magenta");

    MenuChoices[1][3].setFillColor(Color::White);
    MenuChoices[1][3].setFont(font);
    MenuChoices[1][3].setPosition(1000, 450);
    MenuChoices[1][3].setCharacterSize(50);
    MenuChoices[1][3].setString("Cyan");

    MenuChoices[2][1].setFillColor(Color::White);
    MenuChoices[2][1].setFont(font);
    MenuChoices[2][1].setPosition(600, 600);
    MenuChoices[2][1].setCharacterSize(50);
    MenuChoices[2][1].setString("White");

    MenuChoices[2][2].setFillColor(Color::White);
    MenuChoices[2][2].setFont(font);
    MenuChoices[2][2].setPosition(750, 600);
    MenuChoices[2][2].setCharacterSize(50);
    MenuChoices[2][2].setString("Blue");

    MenuChoices[2][3].setFillColor(Color::White);
    MenuChoices[2][3].setFont(font);
    MenuChoices[2][3].setPosition(950, 600);
    MenuChoices[2][3].setCharacterSize(50);
    MenuChoices[2][3].setString("Yellow");
    
    x = 0;
    y = 1;

}
void SettingsMenu::moveLeft() {
    cout << "x: " << x << "y: " << y << endl;
    if (y - 1 >= -1) {
        cout << "Subtracting y" << endl;
        MenuChoices[x][y].setFillColor(Color::White);
        y--;
        if (y == 0) {
            y = 3;
        }
        
        
        MenuChoices[x][y].setFillColor(Color::Green);
    }
}
void SettingsMenu::moveRight() {
    cout << "x: " << x << "y: " << y << endl;
    if (y <= WIDTH) {
        cout << "Subtracting y" << endl;
        MenuChoices[x][y].setFillColor(Color::White);
        y++;
        
        if (y == WIDTH) {
            y = 1;
        }

        MenuChoices[x][y].setFillColor(Color::Green);
    }
}
void SettingsMenu::up() {
    if (x - 1 >= -1) {
        MenuChoices[x][y].setFillColor(Color::White);
        x--;
        if (x == -1) {
            x = 2;
        }
        MenuChoices[x][y].setFillColor(Color::Green);
    }
}
void SettingsMenu::down() {
    if (x <= HEIGHT) {
        MenuChoices[x][y].setFillColor(Color::White);
        x++;
        if (x == HEIGHT) {
            x = 0;
        }
        MenuChoices[x][y].setFillColor(Color::Green);
    }
}
void SettingsMenu::setColor(int x,int y) {
    if (x == 1) {
        if (y == 1) {
            triangleColor = Color::Red;
        }
        else if (y == 2) {
            triangleColor = Color::Magenta;
        }
        else if (y == 3) {
            triangleColor = Color::Cyan;
        }
        else {
            triangleColor = Color::Green;
        }
        MenuChoices[x][y].setFillColor(Color::Blue);
    }
    if (x == 2) {
        if (y == 1) {
            VerColor = Color::White;
        }
        else if (y == 2) {
            VerColor = Color::Blue;
        }
        else if (y == 3) {
            VerColor = Color::Yellow;
        }
        else {
            VerColor = Color::Green;
        }
        MenuChoices[x][y].setFillColor(Color::Blue);
    }
    else {
        return;
    }
        
}
void SettingsMenu::setSpeed(int x, int y) {
    if (x != 0) {
        return;
    }
    if (y == 1) {
        speed = 25;
    }
    else if (y == 2) {
        speed = 50;
    }
    else if (y == 3) {
        speed = 75;
    }
    else {
        speed = 50;
    }
    MenuChoices[x][y].setFillColor(Color::Blue);
    
}
void SettingsMenu::draw(RenderWindow& window) {
    window.draw(MenuText);
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; j++) {
            window.draw(MenuChoices[i][j]);
        }
    }
}