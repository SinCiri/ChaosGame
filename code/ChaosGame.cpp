#include "SettingsMenu.h"
#include "mainMenu.h"

int main() {

	VideoMode vm(1920, 1080);
	RenderWindow MENU(vm, "Main Menu", Style::Default);
	MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);
	SettingsMenu settingsMenu(MENU.getSize().x, MENU.getSize().y);

	
	
	vector<Vector2f> vertices;
	vector<Vector2f> points;


	//set up sound effects
	sf::Sound menuSound;
	sf::Sound selectionSound;
	sf::Sound waterDrop;

	sf::SoundBuffer buffer3;
	buffer3.loadFromFile("water drop.wav");
	waterDrop.setBuffer(buffer3);

	sf::SoundBuffer buffer1;
	buffer1.loadFromFile("menuSound.wav");
	menuSound.setBuffer(buffer1);

	sf::SoundBuffer buffer2;
	buffer2.loadFromFile("selectionSound.wav");
	selectionSound.setBuffer(buffer2);

	//set up music
	sf::Music menuMusic;
	if (!menuMusic.openFromFile("menuMusic.wav")) { cout << "not loading menu music"; }
	menuMusic.setVolume(45.f);
	menuMusic.setLoop(true);

	sf::Music gameMusic;
	if(!gameMusic.openFromFile("gameMusic.ogg")) { cout << "not loading game music"; }
	gameMusic.setVolume(45.f);
	gameMusic.setLoop(true);

	menuMusic.play();


	while (MENU.isOpen()) {
		Event event;
		//render mainMenu and ask for event
		while (MENU.pollEvent(event)) {
			//when menu is closed close the game
			if (event.type == Event::Closed) {
				MENU.close();
			}
			//if key up is pressed move menu option up.
			if (event.type == Event::KeyPressed) {

				if (event.key.code == Keyboard::Up) {
					menuSound.play();
					mainMenu.moveUp();
					break;
				}
				//if key down is pressed move down
				if (event.key.code == Keyboard::Down) {
					menuSound.play();
					mainMenu.moveDown();
					break;
				}
				//if escape is pressed quit game
				if (event.key.code == Keyboard::Escape) {
					menuSound.play();
					MENU.close();
				}
				//if enter is selected render play window
				if (event.key.code == Keyboard::Return) {
					selectionSound.play();													//selection sound
					//render windows when play presses enter
					RenderWindow play(vm, "Chaos Game");
					RenderWindow settings(vm, "Settings");
					//check the item selected
					int x = mainMenu.MainMenuSelected();
					//if play is selected start the game loop
					if (x == 0) {
						menuMusic.pause();
						gameMusic.play();
						///////////////////////////////////////////////////////////////////////////////
						//							main game loop									 //
						///////////////////////////////////////////////////////////////////////////////
						while (play.isOpen()) {
							
							//look for new event?
							Event aevent;
							while (play.pollEvent(aevent)) {
								if (aevent.type == Event::KeyPressed) {
									if (aevent.key.code == Keyboard::Escape) {
										play.close();
									}
								}
								if (aevent.type == Event::Closed) {
									vertices.clear();
									points.clear();
									play.close();
								}

								if (aevent.type == Event::MouseButtonPressed) {
									if (aevent.mouseButton.button == Mouse::Left) {
										cout << "Left click registered at: " << endl;
										cout << "mouse x: " << aevent.mouseButton.x << endl;
										cout << "mouse y: " << aevent.mouseButton.y << endl;
										

										if (vertices.size() < 3) {
											
											waterDrop.play();
											vertices.push_back(Vector2f(aevent.mouseButton.x, aevent.mouseButton.y));
										}
										else if (points.size() == 0) {
											
											waterDrop.play();
											//register forth click to begin
											points.push_back(Vector2f(aevent.mouseButton.x, aevent.mouseButton.y));
										}
									}
								}
								
							}
								if (points.size() > 0) {
									for (int i = 0; i < settingsMenu.getSpeed(); i++) {
										double x, y;
										int lastPoint = points.size() - 1;
										int randPoint = rand() % 3;
										x = (vertices.at(randPoint).x + points.at(lastPoint).x) / 2;
										y = (vertices.at(randPoint).y + points.at(lastPoint).y) / 2;
										points.push_back(Vector2f(x, y));
										if (!play.isOpen()) {
											break;
										}
									}
								}

								//clear previos frame
								settings.close();
								
								play.clear();
								//play.draw(prompt);
								//draw 
								for (size_t i = 0; i < vertices.size(); i++)
								{
									CircleShape circ1(3, 40);
									circ1.setPosition(Vector2f(vertices[i].x, vertices[i].y));
									circ1.setFillColor(settingsMenu.getDotColor());
									play.draw(circ1);
								}
								for (size_t i = 0; i < points.size(); i++) {
									CircleShape circ(2, 30);
									circ.setPosition(Vector2f(points[i].x, points[i].y));
									circ.setFillColor(settingsMenu.getTriangleColor());
									play.draw(circ);
								}
								
								//display
								play.display();
							
						}
						gameMusic.pause();
						menuMusic.play();
					}
					//if x == 1
					//start the settings menu
					else if (x == 1) {
						while (settings.isOpen()) {
							Event aevent;
							while (settings.pollEvent(aevent)) {
								if (aevent.type == Event::KeyPressed) {
									if (aevent.key.code == Keyboard::Escape) {
										settings.close();
									}
								}
								if (aevent.type == Event::Closed) {
									settings.close();
								}
								if (aevent.type == Event::KeyPressed) {
									if (aevent.key.code == Keyboard::Left) {
										menuSound.play();
										settingsMenu.moveLeft();
										break;
									}
									if (aevent.key.code == Keyboard::Right) {
										menuSound.play();
										settingsMenu.moveRight();
										break;
									}
									if (aevent.key.code == Keyboard::Up) {
										menuSound.play();
										settingsMenu.up();
										break;
									}
									if (aevent.key.code == Keyboard::Down) {
										menuSound.play();
										settingsMenu.down();
										break;
									}
									if (aevent.key.code == Keyboard::Return) {
										selectionSound.play();
										cout << "Added Setting" << endl;
										int x = settingsMenu.getX();
										int y = settingsMenu.getY();
										if (x == 0) {
											settingsMenu.setSpeed(x, y);
										}
										if (x == 1) {
											settingsMenu.setColor(x, y);
										}
										if (x == 2) {
											settingsMenu.setColor(x, y);
										}
									}
								}
							}
							play.close();
							settings.clear();
							settingsMenu.draw(settings);
							settings.display();
						}

					}

					//while menu is open
						//look for input
						//move up/down
						//left and right to change the option
						//enter to confirm the option
						//escape to close
						//draw the menu and clear the others and close
				


					//exit option
					else if (x == 2) {
						MENU.close();
						break;
					}
					  

				}
			}

			MENU.clear();
			mainMenu.draw(MENU);
			MENU.display();
		}
	}
	return 0;
}
