#pragma once
#include <SFML/Graphics.hpp>
#include "Sten.h"
#include "vector"
#include "cstdlib"
#include "ctime"

class Labirint {
public:
	Labirint(int Height, int Width, Sten& cp_Sten, sf::RenderWindow &window);
	void outputMap( sf::RenderWindow& window, Sten& m_Sten);
	void createTeilMap();

	void setUpHero(Sten& cp_Sten);
	bool setUpPortal(sf::RenderWindow &window, Sten &cp_Sten);

	void setHeight(int Height) { this->Height_map = Height; };
	void setWidth(int Width) { this->Width_map = Width; };

	
	sf::Sprite GetSpriteLab() const{ return sprite_Labirint; };
	sf::Sprite getSpriteWall()const { return Wall; };

	void Colision(Sten& cp_Sten);
private:
	sf::Sprite sprite_Labirint;

	sf::Sprite Wall;
	//sf::RenderWindow cl_Window;
	sf::Texture cl_Texture;

	sf::Texture walltexture;
	sf::Vector2f cl_Position;

	std::vector <sf::RectangleShape> Wallab;
	std::vector <sf::RectangleShape> Tropalab;

	int Randint(int min, int max);

	int Height_map;
	int Width_map;
	std::vector <std::vector<int> > TeileMap;
};
