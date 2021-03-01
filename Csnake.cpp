#include "Csnake.h"
#include "Unit.h"
#include <conio.h>
#include "Game.h"

Csnake::Csnake(int x, int y, int length, Directions direction, int speed, char pic)
{
	m_iLength=length;
	m_iHeadX=x;
	m_iHeadY=y;
	m_iSpeed=speed;
	m_Direction=direction;
	for (int i=0; i < m_iLength; i++)
	{
		if (i == 0)
		{
			Unit myunit(m_iHeadX, m_iHeadY,'@');
			m_Body.push_back(myunit);
			m_Body[i].m_x = m_iHeadX;
			m_Body[i].m_y = m_iHeadY;
		}
		else
		{
			Unit myunit(m_iHeadX, m_iHeadY, pic);
			m_Body.push_back(myunit);
			switch (m_Direction)
			{
			case LEFT:
				m_Body[i].m_x = m_iHeadX + i;
				m_Body[i].m_y = m_iHeadY;
				break;
			case RIGHT:
				m_Body[i].m_x = m_iHeadX - i;
				m_Body[i].m_y = m_iHeadY;
				break;
			case UP:
				m_Body[i].m_x = m_iHeadX;
				m_Body[i].m_y = m_iHeadY + i;
				break;
			case DOWN:
				m_Body[i].m_x = m_iHeadX;
				m_Body[i].m_y = m_iHeadY - i;
				break;
			default:
				break;
			}
		}
	}
}

Csnake::~Csnake()
{
}
void Csnake::showSnake()
{
	for (int i = 0; i < m_iLength; i++)
	{
		m_Body[i].show();
	}

}

void Csnake::eraseSnake()
{
	for (int i = 0; i < m_iLength; i++)
	{
		m_Body[i].erase();
	}

}

void Csnake::move()
{
	
	vector<Unit> t;
	t = m_Body;
		for (int i = m_iLength - 1; i > 0; i--)//将上一结点的坐标赋给下一个结点
		{
			m_Body[i].m_x = m_Body[i - 1].m_x;
			m_Body[i].m_y = m_Body[i - 1].m_y;
		}
		switch (m_Direction)
		{
		case RIGHT:
			m_Body[0].m_x++;
			break;
		case LEFT:
			m_Body[0].m_x--;
			break;
		case UP:
			m_Body[0].m_y--;
			break;
		case DOWN:
			m_Body[0].m_y++;
			break;
		default:
			break;
		}
		for (int i = 0; i <  m_iLength; i++)
		{
			t[i].erase();
		}
		showSnake();
		Sleep(m_iSpeed);//控制移动速度
	
}

void Csnake::changeDirection()
{
	if (GetAsyncKeyState('A') && 0x8000 && m_Direction != RIGHT)
	{
		m_Direction = LEFT;
	}
	else if (GetAsyncKeyState('D') && 0x8000 && m_Direction != LEFT)
	{
		m_Direction = RIGHT;
	}
	else if (GetAsyncKeyState('W') && 0x8000 && m_Direction != DOWN)
	{
		m_Direction = UP;
	}
	else if (GetAsyncKeyState('S') && 0x8000 && m_Direction != UP)
	{
		m_Direction = DOWN;
	}
	else if (GetAsyncKeyState(VK_SPACE) && 0x8000)
	{
		showSnake();
		while (1)
		{
			if (GetAsyncKeyState(VK_ESCAPE) && 0x8000)
			{
			break;
				//Game game;
				//game.run();
			}
			if (GetAsyncKeyState('A') && 0x8000 || GetAsyncKeyState('D') && 0x8000 || GetAsyncKeyState('W') && 0x8000 || GetAsyncKeyState('S') && 0x8000)
				break;
		}
	}
	move();
	/*if (_kbhit)
	{
		char i = _getch();
		if ((i=='a'||i=='A') && m_Direction != RIGHT)
		{
			m_Direction = LEFT;
		}
		else if ((i=='d'||i=='D') != LEFT)
		{
			m_Direction = RIGHT;
		}
		else if ((i=='w'||i=='W')&& m_Direction != DOWN)
		{
			m_Direction = UP;
		}
		else if ((i=='d'||i=='D') && m_Direction != UP)
		{
			m_Direction = DOWN;
		}
		else if (GetAsyncKeyState(VK_SPACE) && 0x8000)
		{
			showSnake();
			while (1)
			{
				if (GetAsyncKeyState(VK_ESCAPE) && 0x8000)
				{
					Game game;
					game.run();
				}
				if (GetAsyncKeyState('A') && 0x8000 || GetAsyncKeyState('D') && 0x8000 || GetAsyncKeyState('W') && 0x8000 || GetAsyncKeyState('S') && 0x8000)
					break;
			}
		}*/
	//}
	
}

bool Csnake::eatFood(Food* pFood)
{	
	if (m_Body[0].m_x == pFood->m_x && m_Body[0].m_y == pFood->m_y)
	{
			pFood->erase();
			pFood->createpos();
			pFood->show();
			return true;
	}
	for (int i = 1; i < m_iLength; i++)
	{
		if (m_Body[i].m_x == pFood->m_x && m_Body[i].m_y == pFood->m_y)
		{
			pFood->erase();
			pFood->createpos();
			pFood->show();
		}
	}
	return false;
}



void Csnake::growup()
{
	m_iLength++;
	Unit myunit(0, 0, '#');
	m_Body.push_back(myunit);
}
