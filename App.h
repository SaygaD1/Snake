#pragma once



int N = 30, M = 20;
int size = 16;
int height = M * size;
int width = N * size;

bool closing = false;

int bufdir = 0;
int dir, num = 1;


class App
{
public:
	App(int X,int Y);

	int getSnakeX(int i);
	int getSnakeY(int i);
	int getFruitX();
	int getFruitY();
	int& SetFruitX(int x);
	int& SetFruitY(int y);
	
	
	void Tick();
	void spawn();

	bool isKeyPressed(sf::Keyboard::Key key);
private:
	struct Snake
	{
		int x, y;
	} *s;
	struct Fruit
	{
		int posx, posy;
	} f;
};
