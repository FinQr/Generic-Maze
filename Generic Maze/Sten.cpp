#include "Sten.h"
Sten::Sten()
{
    m_Speed = 80;
    
    // —в€зываем текстуру и спрайт
    sf::Image image;
    image.loadFromFile("sten.png");
    image.createMaskFromColor(sf::Color::White);
    m_Texture.loadFromImage(image);
    m_Texture.setSmooth(true);
    m_Sprite.setTexture(m_Texture);
    m_Sprite.setTextureRect(sf::IntRect(0, 260, 160, 100));
    m_Sprite.setScale(0.12f, 0.12f);
    // ”станавливаем начальную позицию в пиксел€х
    m_Position.x = 230;
    m_Position.y = 220;
}

sf::Sprite Sten::getSprite()const
{
    return m_Sprite;
}

void Sten::moveLeft()
{
    m_LeftPressed = true;
    m_Sprite.setTextureRect(sf::IntRect(0, 140, 160, 100));
}

void Sten::moveRight()
{
    m_RightPressed = true;
    m_Sprite.setTextureRect(sf::IntRect(0, 260, 160, 100));
}

void Sten::moveTop()
{
    m_TopPressed = true;
    m_Sprite.setTextureRect(sf::IntRect(0, 360, 150, 130));
}

void Sten::moveDown()
{
    m_DownPressed = true;
    m_Sprite.setTextureRect(sf::IntRect(0, 0, 150, 130));
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

void Sten::setPosition(int x, int y)
{
    m_Position.x = x; m_Position.y = y;
    m_Sprite.setPosition(m_Position);
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

    if(m_DownPressed)
    {
        m_Position.y += m_Speed * elapsedTime;
    }
    // “еперь сдвигаем спрайт на новую позицию
    m_Sprite.setPosition(m_Position);
}
