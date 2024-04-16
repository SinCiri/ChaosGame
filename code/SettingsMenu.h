#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>




using namespace sf;
using namespace std;

const int HEIGHT = 3;
const int WIDTH = 4;

class SettingsMenu {
public:
	SettingsMenu(float width, float height);
	void moveLeft();
	void moveRight();
	void up();
	void down();
	void setColor(int x, int y);
	void setSpeed(int x, int y);
	void draw(RenderWindow& window);
	Color getDotColor() const{ return VerColor; }
	Color getTriangleColor() const{ return triangleColor; }
	int getSpeed() const{ return speed; }
	int getX() const { return x; }
	int getY() const { return y; }


private:
	//option seleted
	//for traversing the 2D array of options
	int x,y;
	int speed;
	
	Font font;
	Text MenuText;
	//for all the other points
	Color triangleColor;
	//for the first 3 points
	Color VerColor;
	//2d array of options
	Text MenuChoices[HEIGHT][WIDTH];
	//background Sprite
	Sprite spriteBackGround;
	//background texture
	Texture BGtexture;
};
