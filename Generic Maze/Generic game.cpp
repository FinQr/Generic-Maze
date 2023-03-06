#include "Generic game.h"
Generic::Generic()
{
    
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    m_Window.create(VideoMode(resolution.x - Width_map, resolution.y - Height_map),
        "Maze generation",
        Style::Default);

    Image m_image;
    m_image.loadFromFile("blok.png");//загружаем файл для карты
    m_BackgroundTexture.loadFromImage(m_image);//заряжаем текстуру картинкой
    m_BackgroundSprite.setTexture(m_BackgroundTexture);
    //m_Window.setFramerateLimit(256);

    //m_BackgroundTexture.loadFromFile("background.jpg");

    // Связываем спрайт и текстуру
    //m_BackgroundSprite.setTexture(m_BackgroundTexture);

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

void Generic::createMap(const int Height_map, const int Width_map)
{
    for (int i = 0; i < Height_map; ++i) {
        for (int j = 0; j < Width_map; ++j) {
            if (TeileMap[i][j] == '1') {
                m_BackgroundSprite.setTextureRect(IntRect(64, 0, 32, 32));
            }
            if (TeileMap[i][j] == '0') {
                m_BackgroundSprite.setTextureRect(IntRect(0, 0, 32, 32));
            }
            m_BackgroundSprite.setPosition(j * 32, i * 32);
            m_Window.draw(m_BackgroundSprite);
        }
    }
}
void Generic::getTeilMap(const int Height_map, const int Width_map)
{
    for (int i = 0; i < Height_map; ++i) {
        for (int j = 0; j < Width_map; ++j) {
            if (i == 0 || i == Height_map-1 || j == 0 || j == Width_map - 1)
                TeileMap[i][j] = '1';
            else {
                TeileMap[i][j] = '0';
            }
        }
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
    if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
    {
        m_Sten.moveLeft();
    }
    else
    {
        m_Sten.stopLeft();
    }

    if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
    {
        m_Sten.moveRight();
    }
    else
    {
        m_Sten.stopRight();
    }

    if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up))
    {
        m_Sten.moveTop();
    }
    else
    {
        m_Sten.stopTop();
    }

    if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down))
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
    // Отрисовываем карту
    getTeilMap(Height_map, Width_map);
    
    createMap(Height_map, Width_map);

    // И Stena
    m_Window.draw(m_Sten.getSprite());
    // Отображаем все, что нарисовали
    m_Window.display();
}

void Generic::React()
{
    m_Window.clear(Color::White);

    m_Window.display();

}
