#pragma once
#include "Sten.h"
#include "Create labirint.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Generic {
public:
	Generic();
    void start();
	void createMap(const int Height_map, const int Width_map);
	void getTeilMap(const int Height_map, const int Width_map);

private:
    // Объявляем спрайт и текстуру для фона
	RenderWindow m_Window;
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;
	Vector2f resolution;
    Event event;
    // Экземпляр Stena
    Sten m_Sten;

    void input();
    void update(float dtAsSeconds);
    void draw();
    void React();

	static const int Height_map = 23;
	static const int Width_map = 36;
	sf::String TeileMap[Height_map][Width_map] = {};
};