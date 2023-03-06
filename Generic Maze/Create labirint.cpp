#include "Create labirint.h"

Labirint::Labirint()
{
}

sf::String Labirint::getTeilMap(const int Height_map, const int Width_map)
{
	for (int i = 0; i < Height_map; ++i) {
		for (int j = 0; j < Width_map; ++j) {
			if (i == 0 || i == Height_map - 1 || j == 0 || j == Width_map - 1)
				TeileMap[i][j] = '1';
			else {
				TeileMap[i][j] = '0';
			}
		}
	}
	return TeileMap[Height_map][Width_map];
}

//sf::Sprite Labirint::createMap(const int Height_map, const int Width_map)
//{
//	
//	for (int i = 0; i < Height_map; ++i) {
//		for (int j = 0; j < Width_map; ++j) {
//			s_window.clear();
//			if (TileMap[i][j] == '1') {
//				s_map.setTextureRect(IntRect(0, 0, 32, 32));
//			}
//			if (TileMap[i][j] == '0') {
//				s_map.setTextureRect(IntRect(32, 0, 32, 32));
//			}
//			s_map.setPosition(j * 32, i * 32);
//			s_window.draw(s_map);
//			s_window.display();
//		}
//		
//	}
//}

