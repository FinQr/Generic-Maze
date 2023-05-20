#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Sten {
private:
    Vector2f m_Position;

    // ��������� ������ Sprite
    Sprite m_Sprite;

    // ��������� ��������
    Texture m_Texture;
    sf::View view;

     //���������� ���������� ��� ������������ ����������� ��������
    bool m_LeftPressed = false;
    bool m_RightPressed = false;
    bool m_TopPressed = false;
    bool m_DownPressed = false;
    // �������� � �������� � �������
    int m_Speed;
public:
    Sten();
    Sprite getSprite()const;
    sf::Vector2f getPositon()const { return m_Position; };
    int getPosX()const { return m_Position.x; };
    int getPosY()const { return m_Position.y; };

    void setPosition(int x, int y);

    sf::View getView()const{ return view; };
    void update(float elapsedtime);

    bool getTop()const { return m_TopPressed; };
    bool getDown()const { return m_DownPressed; };
    bool getLeft()const { return m_LeftPressed; };
    bool getRight()const { return m_RightPressed; };

    // ��� ��������
    void moveLeft();
    void moveRight();

    void moveTop();
    void moveDown();

    // ����������� ��������
    void stopLeft();
    void stopRight();

    void stopTop();
    void stopDown();

    void setPositionCenterHero(Vector2f positon);
};