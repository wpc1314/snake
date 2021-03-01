#pragma once
#include<windows.h>
class Unit
{
public:
	int m_x;
	int m_y;
	char m_pic;
public:
	void show();//ÏÔÊ¾×Ö·û
	void erase();//²Á³ý×Ö·û
	Unit(int x = 0, int y = 0, char pic ='*');
	virtual ~Unit();
	static void gotoxy(int x, int y);//ÒÆ¶¯¹â±ê
};

