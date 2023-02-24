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

    // ���������� ���������� ��� ������������ ����������� ��������
    bool m_LeftPressed = false;
    bool m_RightPressed = false;
    bool m_TopPressed = false;
    bool m_DownPressed = false;
    // �������� ���� � �������� � �������
    int m_Speed = 400;
public:
    Sten();
    Sprite getSprite();

    // ��� �������� ����
    void moveLeft();
    void moveRight();

    void moveTop();
    void moveDown();

    // ����������� ��������
    void stopLeft();
    void stopRight();

    void stopTop();
    void stopDown();
    // ��� ������� ����� ���������� �� ������ ����
    void update(float elapsedTime);

};