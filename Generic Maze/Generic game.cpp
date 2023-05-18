//#include <stack>
#include "Generic game.h"
//#include <vector>
//#include "cstdlib"
//#include "ctime"

Generic::Generic() : m_Sten(), m_Labirint(m_Sten, m_Window)
{
    view.reset(sf::FloatRect(0, 0, 200, 150));

    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    //m_Labirint.getTeilMap();
    
    font.loadFromFile("font//troika.otf");
    text.setFont(font);
    text.setOutlineColor(Color::Red);
    text.setCharacterSize(18);
    text.setFillColor(Color::Red);

    
    m_Window.create(VideoMode(800, 600),
                    "Maze generation",
                    Style::Default);
    //Image m_image;
    //m_image.loadFromFile("blok.png");//загружаем файл для карты
    //m_BackgroundTexture.loadFromImage(m_image);//заряжаем текстуру картинкой
    //m_BackgroundSprite.setTexture(m_BackgroundTexture);
    //m_Window.setFramerateLimit(256);

    //m_BackgroundTexture.loadFromFile("background.jpg");

    // Связываем спрайт и текстуру
    //m_BackgroundSprite.setTexture(m_BackgroundTexture);

}

void Generic::start()
{
    // Расчет времени
    
    int seconds = 20;
    Clock clock;
    Clock GameTime;
    while (m_Window.isOpen())
    {
        // Перезапускаем таймер и записываем отмеренное время в dt
        Time dt = clock.restart();
        //float time = dt.asSeconds();
        float time = dt.asSeconds();
        //хранит текущий кадр
        // Обрабатываем нажатие Escape
        std::ostringstream Timer;
        Timer << (seconds - GameTime.getElapsedTime().asSeconds());
        if (seconds - GameTime.getElapsedTime().asSeconds() <= 0 ) {
            m_Window.close();
        }
        text.setString(Timer.str());
        text.setPosition(view.getCenter().x + 40, view.getCenter().y - 70);
        input(time);
        update(time);
        draw();
    }
}

//void Generic::createMap(const int Height_map, const int Width_map)
//{
//    
//    for (int i = 0; i < Height_map; ++i) {
//        for (int j = 0; j < Width_map; ++j) {
//            if (TeileMap[j][i] == 0 || TeileMap[j][i] > 1) {
//                m_BackgroundSprite.setTextureRect(IntRect(64, 0, 32, 32));
//            }
//            if (TeileMap[j][i] == 1) {
//                m_BackgroundSprite.setTextureRect(IntRect(0, 0, 32, 32));
//            }
//            m_BackgroundSprite.setPosition(j * 32, i * 32);
//            m_Window.draw(m_BackgroundSprite);
//        }
//    }
//}
//
//int Randint(int min, int max) {
//    int num = min + rand() % (max - min + 1);
//    return num;
//}
//void Generic::getTeilMap(const int Height_map, const int Width_map)
//{
//    for (int i = 0; i < Height_map; ++i) {
//        for (int j = 0; j < Width_map; ++j) {
//            TeileMap[j][i] = 0;
//        }
//    }
//    struct Point
//    {
//        int arr[2] = {};
//    };
//    srand(time(0));
//    int x = Randint(0, Width_map / 2) * 2  + 1;
//    int y = Randint(0, Height_map / 2) * 2 + 1;
//    TeileMap[x][y] = 1;
//    //m_Sten.setPositon(x, y);
//    std::vector <Point> chek;
//    Point tochka;
//    if (y - 2 >= 0) {
//        tochka.arr[0] = x; tochka.arr[1] = y - 2;
//        chek.push_back(tochka);
//    }
//    if (y + 2 < Height_map) {
//        tochka.arr[0] = x; tochka.arr[1] = y + 2;
//        chek.push_back(tochka);
//    }
//    if (x - 2 >= 0) {
//        tochka.arr[0] = x-2; tochka.arr[1] = y;
//        chek.push_back(tochka);
//    }
//    if (x+2 < Width_map) {
//        tochka.arr[0] = x+2; tochka.arr[1] = y;
//        chek.push_back(tochka);
//    }
//    int index = 0;
//    while (chek.size() > 0) {
//        if (chek.size() == 1) 
//            index = 0;
//        else 
//            index = Randint(0, chek.size()-1);
//        int x = chek[index].arr[0];
//        int y = chek[index].arr[1];
//        TeileMap[x][y] = 1;
//        auto beg = chek.cbegin();
//        chek.erase(beg + index);
//
//        std::vector <int> Dir = {0,1,2,3};
//        int dir_index = 0;
//        while (Dir.size() > 0) {
//            if (Dir.size() == 1)
//                dir_index = 0;
//            else
//                dir_index = Randint(0, Dir.size()-1);
//            switch (Dir[dir_index]) {
//            case 0:
//                if (y - 2 >= 0 && TeileMap[x][y - 2] == 1) {
//                    TeileMap[x][y-1] = 1;
//                    //auto iter = std::find(chek.begin(), chek.end(), );
//                    Dir.clear();
//                }
//                break;
//            case 1:
//                if (y + 2 < Height_map && TeileMap[x][y + 2] == 1) {
//                    TeileMap[x][y+1] = 1;
//                    Dir.clear();
//                }
//                break;
//            case 2:
//                if (x - 2 >= 0 && TeileMap[x-2][y] == 1) {
//                    TeileMap[x-1][y] = 1;
//                    Dir.clear();
//                }
//                break;
//            case 3:
//                if (x+2 < Width_map && TeileMap[x+2][y] == 1) {
//                    TeileMap[x+1][y] = 1;
//                    Dir.clear();
//                }
//                break;
//            }
//            if (Dir.size() > 0) {
//                auto beg = Dir.cbegin();
//                Dir.erase(beg + dir_index);
//            }
//            if (chek.size() > 3) {
//                chek.pop_back();
//            }
//        }
//        
//        
//        if (y - 2 >= 0 && (TeileMap[x][y - 2] == 0)) {
//            tochka.arr[0] = x; tochka.arr[1] = y - 2;
//            chek.push_back(tochka);
//        }
//        if (y + 2 < Height_map && (TeileMap[x][y + 2] == 0)) {
//            tochka.arr[0] = x; tochka.arr[1] = y + 2;
//            chek.push_back(tochka);
//        }
//        if (x - 2 >= 0 && (TeileMap[x-2][y] == 0)) {
//            tochka.arr[0] = x - 2; tochka.arr[1] = y;
//            chek.push_back(tochka);
//        }
//        if (x + 2 < Width_map && (TeileMap[x+2][y] == 0)) {
//            tochka.arr[0] = x + 2; tochka.arr[1] = y;
//            chek.push_back(tochka);
//        }
//    }
//
//    for (int m = 0; m < 4;++m) {
//        std::vector <Point> dead_ends;
//        for (int i = 0; i < Height_map; ++i) {
//            for (int j = 0; j < Width_map; ++j) {
//                if (TeileMap[j][i] == 1) m_Sten.setPositon(j, i);;
//                if (TeileMap[j][i] == 1) {
//                    int neighbors = 0;
//                    if (i - 1 >= 0 && TeileMap[j][i-1] == 1)         neighbors++;
//                    if (i + 1 < Height_map && TeileMap[j][i+1] == 1) neighbors++;
//                    if (j - 1 >= 0 && TeileMap[j-1][i] == 1)         neighbors++;
//                    if (j + 1 < Width_map && TeileMap[j+1][i] == 1)  neighbors++;
//                    if (neighbors <= 0) {
//                        tochka.arr[0] = j; tochka.arr[1] = i;
//                        dead_ends.push_back(tochka);
//                    }
//                }
//                /*if (TeileMap[j][i] == 0) {
//                    int neighbors = 0;
//                    if (i - 1 >= 0 && TeileMap[j][i - 1] == 1)         neighbors++;
//                    if (i + 1 < Height_map && TeileMap[j][i + 1] == 1) neighbors++;
//                    if (j - 1 >= 0 && TeileMap[j - 1][i] == 1)         neighbors++;
//                    if (j + 1 < Width_map && TeileMap[j + 1][i] == 1)  neighbors++;
//                    if (neighbors == 4) {
//                        TeileMap[j][i] = 1;
//                    }
//                }*/
//            }
//        }
//        /*for (int g = 0; g < dead_ends.size(); g++) {
//            TeileMap[dead_ends[g].arr[0]][dead_ends[g].arr[1]] = 0;
//        }*/
//    }
//}

void Generic::input(float time)
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

    if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right) )
    {
        m_Sten.moveRight();
    }
    else
    {
        m_Sten.stopRight();
    }
    
    if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up) )
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
    m_Labirint.Colision(m_Sten);
}

void Generic::update(float h)
{
    //m_Labirint.Colision(m_Sten);
    
    getPositionHero(m_Sten.getPositon());
    m_Sten.update(h);
}

void Generic::draw()
{
    m_Window.setView(view);

    m_Window.clear(Color::White);
    // Отрисовываем карту
    
    m_Labirint.createMap(m_Window, m_Sten);
    if (m_Labirint.setUpPortal(m_Window, m_Sten)) {
        m_Window.close();
    }
    else {
        m_Labirint.setUpPortal(m_Window, m_Sten);
    }
    //m_Window.draw(m_Labirint.GetSprite());
    // И Stena

    m_Window.draw(m_Sten.getSprite());
    m_Window.draw(text);

    // Отображаем все, что нарисовали
    m_Window.display();
}

//void Generic::Colision()
//{
//    int h = Height;
//    int w = Width;
//    int x = m_Sten.getPosx();
//    int y = m_Sten.getPosy();
//    for (auto i = y / 32; i < (y + h) / 32; i++)//проходимся по тайликам, контактирующим с игроком, то есть по всем квадратикам размера 32*32, которые мы окрашивали в 9 уроке. про условия читайте ниже.
//        for (auto j = x / 32; j < (x + w) / 32; j++)//икс делим на 32, тем самым получаем левый квадратик, с которым персонаж соприкасается. (он ведь больше размера 32*32, поэтому может одновременно стоять на нескольких квадратах). А j<(x + w) / 32 - условие ограничения координат по иксу. то есть координата самого правого квадрата, который соприкасается с персонажем. таким образом идем в цикле слева направо по иксу, проходя по от левого квадрата (соприкасающегося с героем), до правого квадрата (соприкасающегося с героем)
//        {
//            if (TeileMap[i][j] == 0)//если наш квадратик соответствует символу 0 (стена), то проверяем "направление скорости" персонажа:
//            {
//                if (y > 0)//если мы шли вниз,
//                {
//                    ;//то стопорим координату игрек персонажа. сначала получаем координату нашего квадратика на карте(стены) и затем вычитаем из высоты спрайта персонажа.
//                }
//                if (y < 0)
//                {
//                    return 1;//аналогично с ходьбой вверх. dy<0, значит мы идем вверх (вспоминаем координаты паинта)
//                }
//                if (x > 0)
//                {
//                    return 1;//если идем вправо, то координата Х равна стена (символ 0) минус ширина персонажа
//                }
//                if (x < 0)
//                {
//                    return 1;//аналогично идем влево
//                }
//            }
//            //else m_Sten.update(h);
//        }
//    /*m_Sten.getSprite().setPosition(m_Sten.getPositon());*/
//}
