#include "interface.h"
#include <iostream>
using namespace std;
#include"Unit.h"
void interf::drawGameArea()
{
	for (int i = s_y; i <=H+s_y; i++)
	{
		for (int j = s_x; j <= W+s_x; j++)
		{
			if (i == s_y || i == s_y + 2 || i == H + s_y)
			{
				Unit::gotoxy(j, i);
				cout << '-';
			}
		}
	}
	for (int i = s_x; i <= W+s_x; i++)
	{
		for (int j = s_y; j <= H+s_y; j++)
		{
			if (i == s_x || i == W + s_x)
			{
				Unit::gotoxy(i, j);
				cout << '|';
			}
		}
	}
}

void interf::drawGameInfo()
{
	for (int i = s_y; i <= H + s_y; i++)
	{
		for (int j = s_x+1; j <= W + s_x; j++)
		{
			if (i == s_y + 1)
			{
				Unit::gotoxy(j, i);
				cout << " 游戏名称：贪吃蛇";
				cout << "        编写者：伍鹏程 ";
				cout << "       当前得分:" << KSCORE_OFFSET;
				cout << "        当前关卡：" << KLIEVEL_OFFSET;
				break;
			}
		}
	}
	
}

void interf::firstshow()
{
	for (int i = s_y; i <= H + s_y; i++)
	{
		for (int j = s_x; j <= W + s_x; j++)
		{
			if (i == s_y  || i == H + s_y)
			{
				Unit::gotoxy(j, i);
				cout << '-';
			}
		}
	}
	for (int i = s_x; i <= W + s_x; i++)
	{
		for (int j = s_y; j <= H + s_y; j++)
		{
			if (i == s_x || i == W + s_x)
			{
				Unit::gotoxy(i, j);
				cout << '|';
			}
		}
	}
	Unit::gotoxy(35, 16);
	cout << "菜单：" ;
	Unit::gotoxy(35, 18);
	cout << "    1:开始游戏" ;
	Unit::gotoxy(35, 20);
	cout << "    2:游戏说明";
	Unit::gotoxy(35, 22);
	cout << "    Esc:退出游戏";
	Unit::gotoxy(86, 34);
}