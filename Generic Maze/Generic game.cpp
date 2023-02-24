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

    //// ��������� ������ � ��������
    m_BackgroundSprite.setTexture(m_BackgroundTexture);

    // ��������� ��� � ��������
    // ����������� ����������� ��� ��� ������ ������ � ���������
}

void Generic::start()
{
    // ������ �������
    Clock clock;

    while (m_Window.isOpen())
    {
        // ������������� ������ � ���������� ���������� ����� � dt
        Time dt = clock.restart();

        float dtAsSeconds = dt.asSeconds();

        input();
        update(dtAsSeconds);
        draw();
    }
}

void Generic::input()
{
    // ������������ ������� Escape
    while (m_Window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            m_Window.close();
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            m_Window.close();
        }
    }

    // ������������ ������� ������ ��������
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
    // ������������ ���
    m_Window.draw(m_BackgroundSprite);
    // � ����
    m_Window.draw(m_Sten.getSprite());

    // ���������� ���, ��� ����������
    m_Window.display();
}

void Generic::React()
{
    m_Window.clear(Color::White);



    m_Window.display();

}
