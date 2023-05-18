#include <SFML/Graphics.hpp>
#include"GameMenu.h"
#include "Generic game.h"
#include<SFML/Audio.hpp>

using namespace sf;

struct TextFormat
{
    int size_font = 10;
    Color menu_text_color = Color::White;
    float bord = 0.0f;
    Color border_color = Color::Black;
};

// функция настройки текста
void InitText(Text& mtext, float xpos, float ypos, const String& str, TextFormat Ftext);

// Игровой процесс
void GamеStart();

// Настройки игры

// Описание игры
void About_Game();



int main()
{
    // Создаём окно windows
    RenderWindow window(VideoMode::getDesktopMode(), L"Моя игра", Style::Default);


    //window.setMouseCursorVisible(false); //отключаем видимость курсора

    // Размер экрана
    auto width = static_cast<float>(VideoMode::getDesktopMode().width);
    auto height = static_cast<float>(VideoMode::getDesktopMode().height);

    //Заставка загрузки
    Texture texthome;
    texthome.loadFromFile("Image/z1.png");
    RectangleShape homecls(Vector2f(640, 280));
    homecls.setTexture(&texthome);
    homecls.setPosition(Vector2f(width / 2 - homecls.getLocalBounds().width / 2, height / 2 - homecls.getLocalBounds().height / 2));
    window.draw(homecls);
    window.display();

    // Звуковые эффекты
    SoundBuffer buffer;
    SoundBuffer buf_return;

    if (!buffer.loadFromFile("audio/audiomenu2.wav")) return 22;
    if (!buf_return.loadFromFile("audio/audiomenu5.wav")) return 22;
    Sound sound;
    Sound sound_return;
    sound.setBuffer(buffer);
    sound_return.setBuffer(buf_return);


    // Название пунктов меню
    std::vector<String> name_menu{ L"Старт",L"Об игре", L"Выход" };
    // Объект меню
    game::GameMenu mymenu(window, width / 2, 270, 85, 100, name_menu);
    // Установка цвета отображения меню
    mymenu.setColorTextMenu(Color(237, 147, 0), Color::Blue, Color::Black);
    mymenu.AlignMenu(2);

    // Плавное появление из черного
    Texture texture_back;
    if (!texture_back.loadFromFile("image/t.jpg")) return 51;
    Sprite backgroundBlack;
    backgroundBlack.setColor(sf::Color(255, 255, 255, 255));
    backgroundBlack.setTexture(texture_back);
    backgroundBlack.setTextureRect(IntRect(0, 0, static_cast<int>(width), static_cast<int>(height)));
    float alpha = 255;


    // Устанавливаем фон экрана меню
    RectangleShape background(Vector2f(width, height));

    Texture texture_window;
    if (!texture_window.loadFromFile("image/fmenu.jpg")) return 4;
    background.setTexture(&texture_window);

    // Шрифт для названия экрана
    Font font;
    //if (!font.loadFromFile("font/stil.otf")) return 5;
    font.loadFromFile("font/troika.otf");
    // Текст с названием экрана
    Text Titul;
    Titul.setFont(font);
    TextFormat Ftext;
    Ftext.size_font = 100;
    Ftext.menu_text_color = Color(237, 147, 0);
    Ftext.bord = 3;
    InitText(Titul, 455, 50, L"Лабиринт", Ftext);

    Clock clock;
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {

            if (event.type == Event::KeyReleased)
            {
                // События выбра пунктов меню
                if (event.key.code == Keyboard::Up) { sound.play(); mymenu.MoveUp(); }       // вверх
                if (event.key.code == Keyboard::Down) { sound.play(); mymenu.MoveDown(); }  // вниз
                if (event.key.code == Keyboard::Return)                                     // ввод
                {
                    sound_return.play();
                    // Переходим на выбранный пункт меню
                    switch (mymenu.getSelectedMenuNumber())
                    {
                    case 0:GamеStart();  break;
                    case 1:About_Game();  break;
                    case 2:window.close(); break;
                    default:break;
                    }
                }
            }
            if (event.type == sf::Event::Closed)
                window.close();
        }


        // Плавное осветление экрана меню
        if (alpha > 0)
        {
            alpha -= 0.5f;
            backgroundBlack.setColor(Color(255, 255, 255, static_cast<unsigned char>(alpha)));
        }

        // Область отрисовки объектов      
        window.clear();
        window.draw(background);
        window.draw(Titul);
        mymenu.draw();
        window.draw(backgroundBlack);
        window.display();
    }
    return 0;
}

// функция настройки текста
void InitText(Text& mtext, float xpos, float ypos, const String& str, TextFormat Ftext)
{
    mtext.setCharacterSize(Ftext.size_font);
    mtext.setPosition(xpos, ypos);
    mtext.setString(str);
    mtext.setFillColor(Ftext.menu_text_color);
    mtext.setOutlineThickness(Ftext.bord);
    mtext.setOutlineColor(Ftext.border_color);

}

// Игровой процесс
void GamеStart()
{
    Generic game;
    game.start();
}

// Описание игры
void About_Game()
{
    RenderWindow About(VideoMode::getDesktopMode(), L"О игре", Style::Default);

    RectangleShape background_ab(Vector2f(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height));
    Texture texture_ab;
    if (!texture_ab.loadFromFile("image/menu2.jpg")) exit(3);
    background_ab.setTexture(&texture_ab);

    // Шрифт для названия экрана
    Font font;
    if (!font.loadFromFile("font/troika.otf")) exit(6);
    // Текст с названием экрана
    Text Titul;
    Titul.setFont(font);
    TextFormat Ftext;
    Ftext.size_font = 30;
    Ftext.menu_text_color = Color(237, 147, 0);
    Ftext.bord = 3;
    InitText(Titul, 60, 30, L"Персонаж может появляться в центре лабиринта.\nВыход из лабиринта в виде портала (их может быть несколько)\nИспользуются мортиры обстреливающие героя, которые\nподталкивают его к более быстрому прохождению уровня.", Ftext);

    while (About.isOpen())
    {
        Event event_play;
        while (About.pollEvent(event_play))
        {
            if (event_play.type == Event::Closed) About.close();
            if (event_play.key.code == Keyboard::Escape) About.close();
        }
        About.clear();
        About.draw(background_ab);
        About.draw(Titul);
        About.display();
    }
}