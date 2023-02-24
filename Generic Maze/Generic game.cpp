#include "Generic game.h"
Generic::Generic()
{
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    m_Window.create(VideoMode(resolution.x, resolution.y),
        "Simple Game Engine",
        Style::Fullscreen);

    m_BackgroundTexture.loadFromFile("background.jpg");

    //// Связываем спрайт и текстуру
    m_BackgroundSprite.setTexture(m_BackgroundTexture);

    // Загружаем фон в текстуру
    // Подготовьте изображение под ваш размер экрана в редакторе
}

void Generic::start()
{
    // Расчет времени
    Clock clock;

    while (m_Window.isOpen())
    {
        // Перезапускаем таймер и записываем отмеренное время в dt
        Time dt = clock.restart();

        float dtAsSeconds = dt.asSeconds();

        input();
        update(dtAsSeconds);
        draw();
    }
}

void Generic::input()
{
    // Обрабатываем нажатие Escape
    while (m_Window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            m_Window.close();
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            m_Window.close();
        }
    }

    // Обрабатываем нажатие клавиш движения
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        m_Sten.moveLeft();
    }
    else
    {
        m_Sten.stopLeft();
    }

    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        m_Sten.moveRight();
    }
    else
    {
        m_Sten.stopRight();
    }

    if (Keyboard::isKeyPressed(Keyboard::W))
    {
        m_Sten.moveTop();
    }
    else
    {
        m_Sten.stopTop();
    }

    if (Keyboard::isKeyPressed(Keyboard::S))
    {
        m_Sten.moveDown();
    }
    else
    {
        m_Sten.stopDown();
    }
}

void Generic::update(float dtAsSeconds)
{
    m_Sten.update(dtAsSeconds);
}

void Generic::draw()
{
    m_Window.clear(Color::White);
    // Отрисовываем фон
    m_Window.draw(m_BackgroundSprite);
    // И Боба
    m_Window.draw(m_Sten.getSprite());

    // Отображаем все, что нарисовали
    m_Window.display();
}

void Generic::React()
{
    m_Window.clear(Color::White);



    m_Window.display();

}
