#pragma once
#include "Sten.h"
#include "Create labirint.h"
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;

class Generic {
public:
	sf::View view;
	Generic();
	void Level(int Height_map, int Width_map, int secondGame, bool end);
	bool getLevelUp() const { return levelUp; }
	void Win();

private:
    // ��������� ������ � �������� ��� ����
	RenderWindow m_Window;
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;
	Vector2f resolution;
    Event event;

	Font font;//����� 
	Text text;//������� ������ �����. ���������� � ������ ����� ������, �����, ������ ������(� ��������);//��� ������ ����� (�� ������)
    // ��������� Stena
    Sten m_Sten;

	bool levelUp;
	bool end;
	void setEnd(bool end) { this->end = end; }

	void start(int seconds, Labirint m_Labirint);
	
	//void Level3();

	void getPositionHero(sf::Vector2f m_Position){ view.setCenter(m_Position);}
    void input(float dt, Labirint m_Labirint);
    void update(float dtAsSeconds);
    void draw(Labirint m_Labirint);
	//void Colision();
	float h = 0.15;
};