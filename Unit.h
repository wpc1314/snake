#pragma once
#include<windows.h>
class Unit
{
public:
	int m_x;
	int m_y;
	char m_pic;
public:
	void show();//��ʾ�ַ�
	void erase();//�����ַ�
	Unit(int x = 0, int y = 0, char pic ='*');
	virtual ~Unit();
	static void gotoxy(int x, int y);//�ƶ����
};

