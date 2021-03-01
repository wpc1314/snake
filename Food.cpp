#include "Food.h"
#include"stdlib.h"
#include<time.h>

Food::Food(int x, int y, char pic)
{
	m_x = x;
	m_y = y;
	m_pic =pic;
}

Food::~Food()
{
}

void Food::createpos()
{
	srand((int)time(0));//保证随机生成的食物不在同一位置
	m_x = 6 + rand() % 80;
	if (m_x == 85)
		m_x--;
	m_y = 5 + rand() % 28;
	if (m_y == 5 || m_y == 6 || m_y == 7)
		m_y = 8;
}