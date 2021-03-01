#include "Unit.h"
#include<iostream>
using namespace std;

Unit::Unit(int x, int y, char pic)
{
	m_x = x;
	m_y = y;
	m_pic =pic;
}

Unit::~Unit()
{
}

void Unit::gotoxy(int x, int y)
{
	COORD coor;
	coor.X = x;
	coor.Y = y;

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, coor);
}
void Unit::show()
{
	gotoxy(m_x, m_y);
	cout << m_pic;
	gotoxy(84, 34);
}
void Unit::erase()
{
	gotoxy(m_x, m_y);
	cout << ' ';
	gotoxy(84, 34);
}