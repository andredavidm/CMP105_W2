#include "Level.h"
using namespace std;
#include <Windows.h>
//#include "Input.h"

sf::Vector2i position;

sf::Vector2i a;
sf::Vector2i b;

bool isfirst = true;
bool release = false;


Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects



	
	rect.setSize(sf::Vector2f(5,5));
	rect.setFillColor(sf::Color::Red);


}



Level::~Level()
{




	input = nullptr;
}

// handle user input
void Level::handleInput()
{
	if (input->isKeyDown(sf::Keyboard::K))
	{
		
		
		cout << "K" << endl;
		
	}
	
	if (input->isKeyDown(sf::Keyboard::J) && input->isKeyDown(sf::Keyboard::K) && input->isKeyDown(sf::Keyboard::L))
	{
		
			

		cout << "muitas letras" << endl;

	}

	input->setKeyUp(sf::Keyboard::K);
	//input->isKeyDown(sf::Keyboard::J) && input->isKeyDown(sf::Keyboard::K) && input->isKeyDown(sf::Keyboard::L);


	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && isfirst)

	{


		rect.setPosition(position.x, position.y);
		
	/*	sf::Vector2i vetorrapido;
		vetorrapido.x = sf::VideoMode::getDesktopMode().width;
		vetorrapido.y = sf::VideoMode::getDesktopMode().height;
		
		sf::Window x = sf::RenderWindow window;
		
		*/
		//get first point
		a = sf::Mouse::getPosition();

		cout << a.x << endl;
		cout << a.y << endl;

		isfirst = false;
		release = false;

	}

	else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)&& !release)
	{
		isfirst = true;
		release = true;
		cout << "larguei" << endl;
		b = sf::Mouse::getPosition();
		
		
		
		double result = sqrt(((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * (b.y - a.y)));


		cout << "Distance is " << result << endl;
	
	
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !release)
	{
		rect.setPosition(position.x, position.y);


	}

	//position = sf::Mouse::getPosition(*window);

}

// Update game objects	
void Level::update()
{
	
	//sf::Text mouse_p{ position.x };
	//mouse_p.setPosition({ 5, 5 });

	position = sf::Mouse::getPosition(*window);

}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(rect);


	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	//window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}