#pragma once
#include "Sten.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Generic {
public:
    Generic();
    void start();
private:
    RenderWindow m_Window;

    // Объявляем спрайт и текстуру для фона
    Sprite m_BackgroundSprite;
    Texture m_BackgroundTexture;
    Event event;
    // Экземпляр Боба
    Sten m_Sten;

    void input();
    void update(float dtAsSeconds);
    void draw();
    void React();
};