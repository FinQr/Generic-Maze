#pragma once
#include <SFML/Graphics.hpp>

class Sten {
public:
    Sten();

    sf::Sprite getSprite()const;
    sf::Vector2f getPositon()const { return m_Position; };

    int getPosX()const { return m_Position.x; };
    int getPosY()const { return m_Position.y; };

    void setPosition(int x, int y);
    //обновления состояния персонажа на основе прошедшего времени.
    void update(float elapsedtime);
    //методы для получения состояния направления движения персонажа.
    bool getTop()const { return m_TopPressed; };
    bool getDown()const { return m_DownPressed; };
    bool getLeft()const { return m_LeftPressed; };
    bool getRight()const { return m_RightPressed; };

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

private:
    sf::Vector2f m_Position;

    // Объявляем объект Sprite
    sf::Sprite m_Sprite;

    // Добавляем текстуру
    sf::Texture m_Texture;

    //Логические переменные для отслеживания направления движения
    bool m_LeftPressed = false;
    bool m_RightPressed = false;
    bool m_TopPressed = false;
    bool m_DownPressed = false;
    // Скорость в пикселях в секунду
    int m_Speed;
};