#include "Sten.h"
Sten::Sten()
{
    m_Speed = 3;

    // Связываем текстуру и спрайт
    Image image;
    image.loadFromFile("sten.png");
    image.createMaskFromColor(Color::White);
    m_Texture.loadFromImage(image);
    m_Sprite.setTexture(m_Texture);
    m_Sprite.setTextureRect(IntRect(0, 260, 160, 100));
    m_Sprite.setScale(0.2f, 0.2f);
    // Устанавливаем начальную позицию Боба в пикселях
    /*m_Position.x = 250;
    m_Position.y = 250;*/
}

Sprite Sten::getSprite()const
{
    return m_Sprite;
}

void Sten::moveLeft()
{
    m_LeftPressed = true;
    m_Sprite.setTextureRect(IntRect(0, 140, 160, 100));
}

void Sten::moveRight()
{
    m_RightPressed = true;
    m_Sprite.setTextureRect(IntRect(0, 260, 160, 100));
}

void Sten::moveTop()
{
    m_TopPressed = true;
    m_Sprite.setTextureRect(IntRect(0, 360, 150, 130));
}

void Sten::moveDown()
{
    m_DownPressed = true;
    m_Sprite.setTextureRect(IntRect(0, 0, 150, 130));
}

void Sten::stopLeft()
{
    m_LeftPressed = false;
}

void Sten::stopRight()
{
    m_RightPressed = false;
}

void Sten::stopTop()
{
    m_TopPressed = false;
}

void Sten::stopDown()
{
    m_DownPressed = false;
}

void Sten::update(float elapsedTime)
{
    if (m_RightPressed)
    {
        m_Position.x += m_Speed * elapsedTime;
    }

    if (m_LeftPressed)
    {
        m_Position.x -= m_Speed * elapsedTime;
    }

    if (m_TopPressed)
    {
        m_Position.y -= m_Speed * elapsedTime;
    }

    if (m_DownPressed)
    {
        m_Position.y += m_Speed * elapsedTime;
    }
    // Теперь сдвигаем спрайт на новую позицию
    m_Sprite.setPosition(m_Position);
}

void Sten::getPositionHero(sf::Vector2f m_Position)
{
    view.setCenter(m_Position);
}
