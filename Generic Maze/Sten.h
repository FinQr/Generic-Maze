#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Sten {
private:
    Vector2f m_Position;

    // Объявляем объект Sprite
    Sprite m_Sprite;

    // Добавляем текстуру
    Texture m_Texture;
    sf::View view;

    // Логические переменные для отслеживания направления движения
    bool m_LeftPressed = false;
    bool m_RightPressed = false;
    bool m_TopPressed = false;
    bool m_DownPressed = false;
    // Скорость в пикселях в секунду
    int m_Speed = 250;
public:
    Sten();
    Sprite getSprite()const;
    sf::Vector2f getPositon()const { return m_Position; };
    int getPosx()const { return m_Position.x; };
    int getPosy()const { return m_Position.y; };
    void setPositon(int x, int y) { m_Position.x = x; m_Position.y = y; };
    sf::View getView()const{ return view; };

    // Для движения
    void moveLeft();
    void moveRight();

    void moveTop();
    void moveDown();

    // Прекращение движения
    void stopLeft();
    void stopRight();

    void stopTop();
    void stopDown();
    // Эта функция будет вызываться на каждый кадр
    void update(float elapsedTime);

    void getPositionHero(Vector2f positon);
};