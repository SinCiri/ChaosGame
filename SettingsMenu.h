#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>



using namespace sf;
using namespace std;

const int SETTING_ITEMS = 3;

class Settings {
public:
	Settings(float width, float height);
	void moveLeft();
	void moveRight();
	void up();
	void down();
	void setColor(int n);
	void setSpeed(int n);
	void draw(RenderWindow& window);
	Color getDotColor() const{ return VerColor; }
	Color getTriangleColor() const{ return triangleColor; }
	int getSpeed() const{ return speed; }

private:
	//option seleted
	int optionSelected;
	int speed;
	//for all the other points
	Color triangleColor;
	//for the first 3 points
	Color VerColor;
	Text options[SETTING_ITEMS];
	//for first 3 points
	Text colorChoice[3];
	//for the actual triangle
	Text colorChouce_2[3];
	Text speedCoice[3];
};
