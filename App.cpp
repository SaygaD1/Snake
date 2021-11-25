#include "App.h"
#include <time.h>
#include <stdlib.h>
#include <SFML/Window/Keyboard.hpp>

App::App(int X,int Y)
{
    s[0].x = X;
    s[0].y = Y;
}
void App::spawn()
{
    int n = 0;
    for (int i = 0; i < num; i++)
    {
        if (f.posx != s[i].x && f.posy != s[i].y)
        {
            n++;
        }
    }
    if (n != num)
    {
        f.posx = rand() % (N - 1) + 1;
        f.posy = rand() % (M - 1) + 1;
        spawn();
    }
}
void App::Tick()
{
    for (int i = num; i > 0; i--)
    {
        s[i].x = s[i - 1].x;
        s[i].y = s[i - 1].y;
    }
    if (abs(bufdir - dir) == 2)
    {
        dir = bufdir;
    }
    if (dir == 0) { s[0].y++; bufdir = dir; }
    if (dir == 1) { s[0].x--; bufdir = dir; }
    if (dir == 2) { s[0].y--; bufdir = dir; }
    if (dir == 3) { s[0].x++; bufdir = dir; }


    if ((s[0].x == f.posx) && (s[0].y == f.posy))
    {
        num++;
        f.posx = rand() % (N - 1) + 1;
        f.posy = rand() % (M - 1) + 1;
        spawn();
    }
    if (s[0].x > N || s[0].x < 0 || s[0].y > M || s[0].y < 0) { /*s[0].x = 0;*/ closing = true; }
    for (int i = 1; i < num; i++)
    {
        if (s[0].x == s[i].x && s[0].y == s[i].y)
        {
            num = i;
        }
    }
}
int App::getFruitX()
{
    return f.posx;
}
int App::getFruitY()
{
    return f.posy;
}
int App::getSnakeX(int i)
{
    return s[i].x;
}
int App::getSnakeY(int i)
{
    return s[i].y;
}
int& App::SetFruitX(int x)
{
    f.posx = x;
}
int& App::SetFruitY(int y)
{
    f.posy = y;
}
bool isKeyPressed(sf::Keyboard::Key key)
{
    if (key == sf::Keyboard::A || key==sf::Keyboard::Left)
    {
        dir = 0;
    }
    if (key == sf::Keyboard::S || key == sf::Keyboard::Down)
    {
        dir = 1;
    }
    if (key == sf::Keyboard::W || key == sf::Keyboard::Up)
    {
        dir = 2;
    }
    if (key == sf::Keyboard::D || key == sf::Keyboard::Right)
    {
        dir = 3;
    }
}
