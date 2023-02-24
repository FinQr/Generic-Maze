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

    // Логические переменные для отслеживания направления движения
    bool m_LeftPressed = false;
    bool m_RightPressed = false;
    bool m_TopPressed = false;
    bool m_DownPressed = false;
    // Скорость Боба в пикселях в секунду
    int m_Speed = 400;
public:
    Sten();
    Sprite getSprite();

    // Для движения Боба
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

};