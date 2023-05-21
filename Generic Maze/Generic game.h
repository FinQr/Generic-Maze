#pragma once
#include "Sten.h"
#include "Create labirint.h"
#include <SFML/Graphics.hpp>
#include <sstream>

class Generic {
public:
	Generic();
	void Level(int Height_map, int Width_map, int secondGame, bool end);
	bool getLevelUp() const { return levelUp; }
	void Win();

private:
    // ��������� ������ � �������� ��� ����
	sf::RenderWindow m_Window;
	sf::Sprite m_BackgroundSprite;
	sf::Texture m_BackgroundTexture;
    sf::Event event;
	sf::View view;

	sf::Font font;//����� 
	sf::Text text;//������� ������ �����. ���������� � ������ ����� ������, �����, ������ ������(� ��������);
    // ��������� ���������
    Sten m_Sten;

	bool levelUp; // ��� ���� ����� ����� ������� �� �������
	bool end; // �������� ��������� �������
	void setEnd(bool end) { this->end = end; }

	void start(int seconds, Labirint m_Labirint);

	void setPositionCenterView(sf::Vector2f m_Position){ view.setCenter(m_Position);}
    void input(float dt, Labirint m_Labirint);
    void update(float dtAsSeconds);
    void draw(Labirint m_Labirint);
};