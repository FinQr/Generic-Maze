#include "Create labirint.h"

Labirint::Labirint(Sten& cp_Sten, sf::RenderWindow &window)
{
    sf::Image cl_image;
    cl_image.loadFromFile("blok.png");//загружаем файл для карты
    cl_Texture.loadFromImage(cl_image);//заряжаем текстуру картинкой
    cl_Labirint.setTexture(cl_Texture);

    sf::Image wall;
    wall.loadFromFile("wall.png");
    walltexture.loadFromImage(wall);
    Wall.setTexture(walltexture);

    getTeilMap();
    
    sf::RectangleShape rectshape;
    for (int i = 0; i < Height_map; ++i) {
        for (int j = 0; j < Width_map; ++j) {
            if (TeileMap[j][i] == 0) {
                rectshape.setSize(sf::Vector2f(32, 32));
                rectshape.setPosition(j * 32, i * 32);
                Wallab.push_back(rectshape);
            }
            else {
                rectshape.setSize(sf::Vector2f(32, 32));
                rectshape.setPosition(j * 32, i * 32);
                Tropalab.push_back(rectshape);
            }
        }
    }
    setUpHero(cp_Sten);
    //setUpPortal(window);
}

void Labirint::createMap(sf::RenderWindow &window, Sten& m_Sten)
{
    sf::Vector2f center = window.getView().getCenter();
    sf::Vector2f size = window.getView().getSize();
	for (int i = (center.y - size.y / 2) / 32; i <= (center.y + size.y / 2) / 32; ++i) {
		for (int j = (center.x - size.x / 2) / 32; j <= (center.x + size.x / 2) / 32; ++j) {
			if (TeileMap[j][i] == 0) {
				Wall.setTextureRect(sf::IntRect(0, 0, 32, 32));
                Wall.setPosition(j * 32, i * 32);
                window.draw(Wall);
			}
			if (TeileMap[j][i] == 1) {
				cl_Labirint.setTextureRect(sf::IntRect(0, 0, 32, 32));
                cl_Labirint.setPosition(j * 32, i * 32);
                window.draw(cl_Labirint);
			}
		}
	}
}

void Labirint::getTeilMap()
{
    /*int** TeileMap = new int* [Width_map];
    for (int i = 0; i < Width_map; ++i) {
        TeileMap[i] = new int[Height_map];
        for (int j = 0; j < Height_map; ++j) {
            TeileMap[j][i] = 0;
        }
    }*/
    for (int i = 0; i < Height_map; ++i) {
        for (int j = 0; j < Width_map; ++j) {
            TeileMap[j][i] = 0;
        }
    }
    
    struct Point
    {
        int arr[2] = {};
    };

    srand(time(0));
    int x = Randint(0, (Width_map - 1) / 2) * 2 + 1;
    int y = Randint(0, (Height_map - 1) / 2) * 2 - 1;
    TeileMap[x][y] = 1;
    std::vector <Point> chek;
    Point tochka;
    if (y - 2 >= 0) {
        tochka.arr[0] = x; tochka.arr[1] = y - 2;
        chek.push_back(tochka);
    }
    if (y + 2 < Height_map) {
        tochka.arr[0] = x; tochka.arr[1] = y + 2;
        chek.push_back(tochka);
    }
    if (x - 2 >= 0) {
        tochka.arr[0] = x - 2; tochka.arr[1] = y;
        chek.push_back(tochka);
    }
    if (x + 2 < Width_map) {
        tochka.arr[0] = x + 2; tochka.arr[1] = y;
        chek.push_back(tochka);
    }
    int index = 0;
    while (chek.size() > 0) {
        if (chek.size() == 1)
            index = 0;
        else
            index = Randint(0, chek.size() - 1);
        int x = chek[index].arr[0];
        int y = chek[index].arr[1];
        if (x != 0 && y != 0 && x != Width_map - 1 && y != Height_map - 1) {
            TeileMap[x][y] = 1;
        }
        auto beg = chek.cbegin();
        chek.erase(beg + index);

        std::vector <int> Dir = { 0,1,2,3 };
        int dir_index = 0;
        while (Dir.size() > 0) {
            if (Dir.size() == 1)
                dir_index = 0;
            else
                dir_index = Randint(0, Dir.size() - 1);
            switch (Dir[dir_index]) {
            case 0:
                if (y - 2 >= 0 && TeileMap[x][y - 2] == 1) {
                    TeileMap[x][y - 1] = 1;
                    //auto iter = std::find(chek.begin(), chek.end(), );
                    Dir.clear();
                }
                break;
            case 1:
                if (y + 2 < Height_map && TeileMap[x][y + 2] == 1) {
                    TeileMap[x][y + 1] = 1;
                    Dir.clear();
                }
                break;
            case 2:
                if (x - 2 >= 0 && TeileMap[x - 2][y] == 1) {
                    TeileMap[x - 1][y] = 1;
                    Dir.clear();
                }
                break;
            case 3:
                if (x + 2 < Width_map && TeileMap[x + 2][y] == 1) {
                    TeileMap[x + 1][y] = 1;
                    Dir.clear();
                }
                break;
            }
            if (Dir.size() > 0) {
                auto beg = Dir.cbegin();
                Dir.erase(beg + dir_index);
            }
            if (chek.size() > 3) {
                chek.pop_back();
            }
        }


        if (y - 2 >= 0 && (TeileMap[x][y - 2] == 0)) {
            tochka.arr[0] = x; tochka.arr[1] = y - 2;
            chek.push_back(tochka);
        }
        if (y + 2 < Height_map && (TeileMap[x][y + 2] == 0)) {
            tochka.arr[0] = x; tochka.arr[1] = y + 2;
            chek.push_back(tochka);
        }
        if (x - 2 >= 0 && (TeileMap[x - 2][y] == 0)) {
            tochka.arr[0] = x - 2; tochka.arr[1] = y;
            chek.push_back(tochka);
        }
        if (x + 2 < Width_map && (TeileMap[x + 2][y] == 0)) {
            tochka.arr[0] = x + 2; tochka.arr[1] = y;
            chek.push_back(tochka);
        }
    }

    
    //for (int m = 0; m < 4;++m) {
    //    std::vector <Point> dead_ends;
    //    for (int i = 0; i < Height_map; ++i) {
    //        for (int j = 0; j < Width_map; ++j) {
    //            /*if (TeileMap[j][i] == 1) m_Sten.setPositon(j, i);*/
    //            if (TeileMap[j][i] == 1) {
    //                int neighbors = 0;
    //                if (i - 1 >= 0 && TeileMap[j][i - 1] == 1)         neighbors++;
    //                if (i + 1 < Height_map && TeileMap[j][i + 1] == 1) neighbors++;
    //                if (j - 1 >= 0 && TeileMap[j - 1][i] == 1)         neighbors++;
    //                if (j + 1 < Width_map && TeileMap[j + 1][i] == 1)  neighbors++;
    //                if (neighbors <= 0) {
    //                    tochka.arr[0] = j; tochka.arr[1] = i;
    //                    dead_ends.push_back(tochka);
    //                }
    //            }
    //            if (TeileMap[j][i] == 0) {
    //                int neighbors = 0;
    //                if (i - 1 >= 0 && TeileMap[j][i - 1] == 1)         neighbors++;
    //                if (i + 1 < Height_map && TeileMap[j][i + 1] == 1) neighbors++;
    //                if (j - 1 >= 0 && TeileMap[j - 1][i] == 1)         neighbors++;
    //                if (j + 1 < Width_map && TeileMap[j + 1][i] == 1)  neighbors++;
    //                if (neighbors == 3) {
    //                    TeileMap[j][i] = 1;
    //                }
    //            }
    //        }
    //    }
    //    /*for (int g = 0; g < dead_ends.size(); g++) {
    //        TeileMap[dead_ends[g].arr[0]][dead_ends[g].arr[1]] = 0;
    //    }*/
    //}
}

void Labirint::setUpHero(Sten& cp_Sten)
{
    int count = Tropalab.size()/3*2;
    cp_Sten.setPositon(Tropalab[count].getPosition().x, Tropalab[count].getPosition().y);
}

bool Labirint::setUpPortal(sf::RenderWindow &window, Sten &cp_Sten)
{
    sf::Sprite portalsprite;
    sf::Texture portaltexture;
    
    sf::Image pr;

    pr.loadFromFile("portal.png");//загружаем файл для карты
    portaltexture.loadFromImage(pr);//заряжаем текстуру картинкой
    portalsprite.setTexture(portaltexture);

    portalsprite.setPosition(Tropalab[0].getPosition().x, Tropalab[0].getPosition().y);
    window.draw(portalsprite);
    if (cp_Sten.getSprite().getGlobalBounds().intersects(Tropalab[0].getGlobalBounds())) {
        return 1;
    }
    return 0;
}


int Labirint::Randint(int min, int max)
{
	int num = min + rand() % (max - min + 1);
	return num;
}

void Labirint::Colision(Sten& cp_Sten)
{
    sf::FloatRect box = cp_Sten.getSprite().getGlobalBounds();
    int x = cp_Sten.getPosx();
    int y = cp_Sten.getPosy();
    int col = Wallab.size();
    for (int i = 0; i < col; i++) {
        if (box.intersects(Wallab[i].getGlobalBounds())) {
            if (cp_Sten.getDown() && Wallab[i].getPosition().y+2 > y)//если мы шли вниз,
            {
                //cp_Sten.stopDown();
                cp_Sten.setPositon(x, y - 1);//то стопорим координату игрек персонажа. сначала получаем координату нашего квадратика на карте(стены) и затем вычитаем из высоты спрайта персонажа.
            }
            if (cp_Sten.getTop() && Wallab[i].getPosition().y+5 < y)
            {
                //cp_Sten.stopTop();
                cp_Sten.setPositon(x, y + 2);//аналогично с ходьбой вверх. dy<0, значит мы идем вверх (вспоминаем координаты паинта)
            }
            if (cp_Sten.getRight() && Wallab[i].getPosition().x+5 > x)
            {
                //cp_Sten.stopRight();
                cp_Sten.setPositon(x - 1, y);//если идем вправо, то координата Х равна стена (символ 0) минус ширина персонажа
            }
            if (cp_Sten.getLeft() && Wallab[i].getPosition().x+5 < x)
            {
                //cp_Sten.stopLeft();
                cp_Sten.setPositon(x + 2, y);//аналогично идем влево
            }
            break;
        }
    }
}

//sf::Sprite Labirint::createMap(const int Height_map, const int Width_map)
//{
//	
//	for (int i = 0; i < Height_map; ++i) {
//		for (int j = 0; j < Width_map; ++j) {
//			s_window.clear();
//			if (TileMap[i][j] == '1') {
//				s_map.setTextureRect(IntRect(0, 0, 32, 32));
//			}
//			if (TileMap[i][j] == '0') {
//				s_map.setTextureRect(IntRect(32, 0, 32, 32));
//			}
//			s_map.setPosition(j * 32, i * 32);
//			s_window.draw(s_map);
//			s_window.display();
//		}
//		
//	}
//}

