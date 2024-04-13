#include "SettingsMenu.h"
#include "mainMenu.h"

int main() {
	VideoMode vm(1920, 1080);
	RenderWindow MENU(vm, "Main Menu", Style::Default);
	MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);

	Color triangleColor = Color::Red;

	vector<Vector2f> vertices;
	vector<Vector2f> points;


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
					mainMenu.moveUp();
					break;
				}
				//if key down is pressed move down
				if (event.key.code == Keyboard::Down) {
					mainMenu.moveDown();
					break;
				}
				//if escape is pressed quit game
				if (event.key.code == Keyboard::Escape) {
					MENU.close();
				}
				//if enter is selected render play window
				if (event.key.code == Keyboard::Return) {
					//render windows when play presses enter
					RenderWindow play(vm, "Chaos Game");
					RenderWindow settings(vm, "Settings");
					//check the item selected
					int x = mainMenu.MainMenuSelected();
					//if play is selected start the game loop
					if (x == 0) {
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
									play.close();
								}

								if (aevent.type == Event::MouseButtonPressed) {
									if (aevent.mouseButton.button == Mouse::Left) {
										cout << "Left click registered at: " << endl;
										cout << "mouse x: " << aevent.mouseButton.x << endl;
										cout << "mouse y: " << aevent.mouseButton.y << endl;

										if (vertices.size() < 3) {
											vertices.push_back(Vector2f(aevent.mouseButton.x, aevent.mouseButton.y));
										}
										else if (points.size() == 0) {
											//register forth click to begin
											points.push_back(Vector2f(aevent.mouseButton.x, aevent.mouseButton.y));
										}
									}
								}
								
							}
								if (points.size() > 0) {
									for (int i = 0; i < 50; i++) {
										double x, y;
										int lastPoint = points.size() - 1;
										int randPoint = rand() % 3;
										x = (vertices.at(randPoint).x + points.at(lastPoint).x) / 2;
										y = (vertices.at(randPoint).y + points.at(lastPoint).y) / 2;
										points.push_back(Vector2f(x, y));
									}
								}
								//clear previos frame
								settings.close();
								play.clear();
								//draw 
								for (size_t i = 0; i < vertices.size(); i++)
								{
									CircleShape circ1(3, 40);
									circ1.setPosition(Vector2f(vertices[i].x, vertices[i].y));
									circ1.setFillColor(Color::Magenta);
									play.draw(circ1);
								}
								for (size_t i = 0; i < points.size(); i++) {
									CircleShape circ(2, 30);
									circ.setPosition(Vector2f(points[i].x, points[i].y));
									circ.setFillColor(Color::Red);
									play.draw(circ);
								}
								
								//display
								play.display();
							
						}
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
							}
							settings.clear();
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