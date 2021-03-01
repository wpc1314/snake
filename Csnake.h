#pragma once
#include "Food.h"
using namespace std;
#include<vector>

enum Directions {
	UP,DOWN,LEFT,RIGHT
};
class Csnake
{
public:
	Csnake(int x = 44, int y = 18, int length = 4, Directions direction = RIGHT,int speed = 400, char pic = '#');
	virtual ~Csnake();
	void changeDirection();
	void move();
	bool eatFood(Food* pFood);
	void showSnake();
	void eraseSnake();
	void growup();
public:
	int m_iLength;
	int m_iHeadX;
	int m_iHeadY;
	int m_iSpeed;
	Directions m_Direction;
	vector<Unit> m_Body;
};

