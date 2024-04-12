// Include important C++ libraries here
#include "mainMenu.h"
// Make code easier to type with "using namespace"


int main()
{
    // Create a video mode object
	VideoMode vm(1920, 1080);
	// Create and open a window for the game
    RenderWindow MENU(vm, "Menu", Style::Default);
    MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);
	
    Text myText;
    Text Points;
    Font font;
	font.loadFromFile("font1.ttf");
    Points.setFont(font);
    myText.setFont(font);
    myText.setCharacterSize(45);
    myText.setString("Welcome to Chaos Game");
    Points.setString("Choose 3 points to make a Triangle");
    FloatRect textRect = myText.getLocalBounds();
	myText.setOrigin(textRect.left +
		textRect.width / 2.0f,
		textRect.top +
		textRect.height / 2.0f);
	myText.setPosition(1920 / 2.5f, 1080 / 2.5f);
    Points.setPosition(20,20);

    vector<Vector2f> vertices;
    vector<Vector2f> points;
    while(MENU.isOpen()) {
        MENU.clear();
        mainMenu.draw(MENU);
        MENU.display();
        Event aevent;
        while(MENU.pollEvent(aevent)) {
            if(aevent.type == Event::Closed) {
                MENU.close();
            }
            if(aevent.type == Event::KeyReleased) {
                if (aevent.key.code == Keyboard::Up) {
                    mainMenu.moveUp();
                    break;
                }

                
                if (aevent.key.code == Keyboard::Down) {
                    mainMenu.moveDown();
                    break;
                }
                
                if (aevent.key.code == Keyboard::Return) {
                    
                RenderWindow window(vm, "Chaos Game", Style::Default);
                while (window.isOpen())
	{
        /*
		****************************************
		Handle the players input
		****************************************
		*/
        Event event;
		while (window.pollEvent(event))
		{
            if (event.type == Event::Closed)
            {
				// Quit the game when the window is closed
				window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "the left button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;

                    if(vertices.size() < 3)
                    {
                        vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
                    }
                    else if(points.size() == 0)
                    {
                        ///fourth click
                        ///push back to points vector
                        points.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
                    }
                }
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
        /*
		****************************************
		Update
		****************************************
		*/

        if(points.size() > 0)
        {
            ///generate more point(s)
            ///select random vertex
            ///calculate midpoint between random vertex and the last point in the vector
            ///push back the newly generated coord.
            for (int i = 0; i < 50; i++) {
                double x,y;
                int lastPoint = points.size()-1;
                int randPoint = rand()%3;
                x = (vertices.at(randPoint).x + points.at(lastPoint).x)/2;
                y = (vertices.at(randPoint).y + points.at(lastPoint).y)/2;
                points.push_back(Vector2f(x,y));
            }
        }

        /*
		****************************************
		Draw
		****************************************
		*/
        window.clear();
        window.draw(myText);
        window.draw(Points);
        if(vertices.size() == 1) {
            myText.move(2000,2000);
            Points.move(2000,2000);
        }
        for(size_t i = 0; i < vertices.size(); i++)
        {
            CircleShape circ1(2,30);
            circ1.setPosition(Vector2f(vertices[i].x, vertices[i].y));
            circ1.setFillColor(Color::Green);
            window.draw(circ1);
        }
        for (size_t i = 0; i <  points.size(); i++) {
            CircleShape circ(2,30);
            circ.setPosition(Vector2f(points[i].x, points[i].y));
            circ.setFillColor(Color::Red);
            window.draw(circ);
        }
        window.display();
    }
                }

            }
            if (aevent.type == Event::KeyReleased) {
                if (aevent.key.code == Keyboard::Escape) {
                    MENU.close();
                }

            }
        }
    }

	
}