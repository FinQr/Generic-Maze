#pragma once
#include <SFML/Graphics.hpp>

class Labirint {
public:
	Labirint();
	sf::String getTeilMap(const int Height_map, const int Width_map);
	sf::Sprite createMap(const int Height_map, const int Width_map);
	static const int Height_map = 23;
	static const int Width_map = 36;
private:
	

	sf::String TeileMap[Height_map][Width_map] = {};

	/*sf::String TileMap[Height_map] = {
		"1111111111",
		"1000000001",
		"1000000001",
		"1000000001",
		"1000000001",
		"1000000001",
		"1000000001",
		"1000000001",
		"1000000001",
		"1000000001",
		"1000000001",
		"1000000001",
		"1000000001",
		"1000000001",
		"1111111111",
	};*/
};
