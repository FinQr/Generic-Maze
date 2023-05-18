#pragma once
#include <SFML/Graphics.hpp>
#include "Sten.h"
#include "vector"
#include "cstdlib"
#include "ctime"

class Labirint {
public:
	Labirint(Sten& cp_Sten, sf::RenderWindow &window);
	void createMap(sf::RenderWindow& window, Sten& m_Sten);
	void getTeilMap();
	void setUpHero(Sten& cp_Sten);
	bool setUpPortal(sf::RenderWindow &window, Sten &cp_Sten);

	int Randint(int min, int max);
	sf::Sprite GetSpriteLab() const{ return cl_Labirint; };
	sf::Sprite getSpriteWall()const { return Wall; };
	//sf::RenderWindow& GetRenderWindow() { return cl_Window; };

	void Colision(Sten& cp_Sten);

	//void Colision(Sten& cp_Sten)
	//{
	//	
	//	sf::Vector2f pos = cp_Sten.getSprite().getScale();
	//	int h = cp_Sten.getSprite().getTextureRect().height*0.1;
	//	int w = cp_Sten.getSprite().getTextureRect().width*0.1;
	//	int x = cp_Sten.getPosx();
	//	int y = cp_Sten.getPosy();
	//	for (auto i = y / 32; i < (y + h) / 32; i++)//���������� �� ��������, �������������� � �������, �� ���� �� ���� ����������� ������� 32*32, ������� �� ���������� � 9 �����. ��� ������� ������� ����.
	//		for (auto j = x / 32; j < (x + w) / 32; j++)//��� ����� �� 32, ��� ����� �������� ����� ���������, � ������� �������� �������������. (�� ���� ������ ������� 32*32, ������� ����� ������������ ������ �� ���������� ���������). � j<(x + w) / 32 - ������� ����������� ��������� �� ����. �� ���� ���������� ������ ������� ��������, ������� ������������� � ����������. ����� ������� ���� � ����� ����� ������� �� ����, ������� �� �� ������ �������� (���������������� � ������), �� ������� �������� (���������������� � ������)
	//		{
	//			if (TeileMap[i][j] == 0)//���� ��� ��������� ������������� ������� 0 (�����), �� ��������� "����������� ��������" ���������:
	//			{
	//				if (cp_Sten.getDown())//���� �� ��� ����,
	//				{
	//					cp_Sten.setPositon(x, 32*i - h);//�� �������� ���������� ����� ���������. ������� �������� ���������� ������ ���������� �� �����(�����) � ����� �������� �� ������ ������� ���������.
	//				}
	//				if (cp_Sten.getTop())
	//				{
	//					cp_Sten.setPositon(x, 32*i + 32);//���������� � ������� �����. dy<0, ������ �� ���� ����� (���������� ���������� ������)
	//				}
	//				if (cp_Sten.getRight())
	//				{
	//					cp_Sten.setPositon(32*j - w, y);//���� ���� ������, �� ���������� � ����� ����� (������ 0) ����� ������ ���������
	//				}
	//				if (cp_Sten.getLeft())
	//				{
	//					cp_Sten.setPositon(32*j + 32, y);//���������� ���� �����
	//				}
	//			}
	//			//else cp_Sten.update(h);
	//		}
	//	//cp_Sten.getSprite().setPosition(cp_Sten.getPositon());
	//}


private:
	sf::Sprite cl_Labirint;

	sf::Sprite Wall;
	//sf::RenderWindow cl_Window;
	sf::Texture cl_Texture;

	sf::Texture walltexture;
	sf::Vector2f cl_Position;

	std::vector <sf::RectangleShape> Wallab;
	std::vector <sf::RectangleShape> Tropalab;
	static const int Height_map = 25;
	static const int Width_map = 25;
	int TeileMap[Width_map][Height_map] = {};
	//std::vector <std::vector<int> > TeileMap{ Width_map, std::vector <int>(Height_map) };
};
