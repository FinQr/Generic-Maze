#pragma once
#include "Sten.h"
#include "Create labirint.h"
#include <SFML/Graphics.hpp>
#include <sstream>
#define Height 30
#define Width 30
using namespace sf;

class Generic {
public:
	sf::View view;
	Generic();

    void start();
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
	Labirint m_Labirint;

	void getPositionHero(sf::Vector2f m_Position)
	{
		view.setCenter(m_Position);
	}
    void input(float dt);
    void update(float dtAsSeconds);
    void draw();
	//void Colision();
	float h = 0.15;
};