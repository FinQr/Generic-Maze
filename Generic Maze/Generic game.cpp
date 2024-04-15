#include "Generic game.h"

Generic::Generic() : m_Sten(), levelUp(false), end(0)
{
    view.reset(sf::FloatRect(0, 0, 200, 150));
    
    font.loadFromFile("font//troika.otf");
    text.setFont(font);
    text.setOutlineColor(sf::Color::Red);
    text.setCharacterSize(18);
    text.setFillColor(sf::Color::Red);

    
    m_Window.create(sf::VideoMode(800, 600),
                    "Maze generation",
                    sf::Style::Close);
}

void Generic::start(int seconds, Labirint m_Labirint)
{
    // Расчет времени
    //circle.setRadius(50.0f);
    //circle.setOutlineThickness(-1);
    //circle.setOutlineColor(sf::Color::Black);
   
    //circle.setFillColor(sf::Color(255,1,1,120));

    sf::Clock clock;
    sf::Clock GameTime;
    while (m_Window.isOpen())
    {
        // Перезапускаем таймер и записываем отмеренное время в dt
        sf::Time dt = clock.restart();
        //float time = dt.asSeconds();
        float time = dt.asSeconds();

        std::ostringstream Timer;
        Timer << (seconds - GameTime.getElapsedTime().asSeconds());
        if (seconds - GameTime.getElapsedTime().asSeconds() <= 0 ) {
            m_Window.close();
        }

        text.setString(Timer.str());
        text.setPosition(view.getCenter().x + 40, view.getCenter().y - 70);

        input(time, m_Labirint);
        update(time);
        draw(m_Labirint);
        
    }
}

void Generic::Win()
{
    sf::Clock win;
    sf::Font font;
    sf::Text text;
    font.loadFromFile("font//troika.otf");
    text.setFont(font);
    text.setOutlineColor(sf::Color(237, 147, 0));
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::Red);

    while (true) {
        std::ostringstream TextWin;
        TextWin << "YOU WIN!!!";
        text.setString(TextWin.str());
        text.setPosition(view.getCenter().x-50, view.getCenter().y - 20);
        if (4 - win.getElapsedTime().asSeconds() <= 0) {
            break;
        }
        m_Window.clear(sf::Color::Black);
        m_Window.draw(text);
        m_Window.display();
    }
    m_Window.close();
}
//Создание уровня с размерами, таймером и указанием на последний уровень
void Generic::Level(int Height_map, int Width_map, int secondGame, bool end)
{
    Labirint lab1(Height_map, Width_map, m_Sten, m_Window);
    setEnd(end);
    start(secondGame, lab1);
}

void Generic::input(float time, Labirint m_Labirint)
{
    // Обрабатываем нажатие Escape
    while (m_Window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            m_Window.close();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            m_Window.close();
        }
    }

    // Обрабатываем нажатие клавиш движения
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_Sten.moveLeft();
    }
    else
    {
        m_Sten.stopLeft();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right) )
    {
        m_Sten.moveRight();
    }
    else
    {
        m_Sten.stopRight();
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) )
    {
        m_Sten.moveTop();
    }
    else
    {
        m_Sten.stopTop();
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        m_Sten.moveDown();
    }
    else
    {
        m_Sten.stopDown();
    }
    m_Labirint.Colision(m_Sten); // Коллизия
}

void Generic::update(float h)
{
    //m_Labirint.Colision(m_Sten);
    
    setPositionCenterView(m_Sten.getPositon());
    m_Sten.update(h);
}

void Generic::draw(Labirint m_Labirint)
{
    m_Window.setView(view);

    m_Window.clear(sf::Color::White);
    // Отрисовываем карту
    
    m_Labirint.outputMap( m_Window, m_Sten);

    //Если последний уровень, то вывод экрана победы
    if (m_Labirint.setUpPortal(m_Window, m_Sten) && end) {
        Win();
    }
    //Если не последний, то промежуточный экран
    if (m_Labirint.setUpPortal(m_Window, m_Sten)) {
        levelUp = true;
        sf::Clock perechod;
        sf::Font font;
        sf::Text text;
        font.loadFromFile("font//troika.otf");
        text.setFont(font);
        text.setOutlineColor(sf::Color(237, 147, 0));
        text.setCharacterSize(28);
        text.setFillColor(sf::Color(237, 147, 0));
        while (true) {
            //m_Window.setView(view);
            std::ostringstream Timer;
            Timer << "Never give up!";
            text.setString(Timer.str());
            text.setPosition(view.getCenter().x-90, view.getCenter().y - 10);
            if (2 - perechod.getElapsedTime().asSeconds() <= 0) {
                break;
            }
            m_Window.clear(sf::Color::Black);
            m_Window.draw(text);
            m_Window.display();
        }
        m_Window.close();
    }
    else {
        m_Labirint.setUpPortal(m_Window, m_Sten);
    }

    //Вывод на экран машины и времени
    m_Window.draw(m_Sten.getSprite());
    m_Window.draw(text);

    // Отображаем все, что нарисовали
    m_Window.display();
}
