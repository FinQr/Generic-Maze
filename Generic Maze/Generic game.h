#pragma once
#include "Sten.h"
#include "Create labirint.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Generic {
public:
	sf::View view;
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

	void getPositionHero(sf::Vector2f m_Position)
	{
		view.setCenter(m_Position);
	}
    void input();
    void update(float dtAsSeconds);
    void draw();
	void Colision();
	float h = 0.5;

	static const int Height_map = 25;
	static const int Width_map = 25;
	int TeileMap[Width_map][Height_map] = {};
};