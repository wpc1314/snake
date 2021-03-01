#include "Game.h"
#include"interface.h"
#include <iostream>
using namespace std;
#include<conio.h>
#include "mmsystem.h"//導入聲音頭文件
#include "windows.h"
#pragma comment(lib,"winmm.lib")
Game::Game()
{
    m_pFood=new Food;
    m_pSnake = new Csnake;
}

Game::~Game()
{
    delete new Food;
    m_pFood = NULL;
    delete new Csnake;
    m_pSnake = NULL;
}

void Game::run()
{
        system("cls");//清屏
        firstshow();//菜单页
        char i= _getch();
        if (i=='2')
        {
            rules();//游戏说明
        }
        if (i=='1')
        {
            PlaySound("e:\\music\\Good Time.wav", NULL, SND_FILENAME | SND_ASYNC);//加载背景音乐
            system("cls");
            drawGameArea();//画边界
            drawGameInfo();//显示分值，关卡
           /* m_pFood.createpos();
            m_pFood.show();
            m_pSnake.showSnake();*/
            m_pFood->createpos();//生成食物
            m_pFood->show();
            m_pSnake->showSnake();//显示蛇
            while (1)
            {
                int t;
                t = m_pSnake->eatFood(m_pFood);//判断是否吃食物
                if (t == 1)
                {
                    m_pSnake->growup();//增长蛇身
                    m_iScore = m_iScore + 10;//增加分值
                    int l = checkLevel();//判断是否通关
                    if (l == 1)
                    {
                        m_iLevel++;
                    }
                    changInfo();
                }
                m_pSnake->changeDirection();//判断是否有改变蛇的方向，如果有作相应改变
                int c = checkFailed();//判断游戏是否失败
                if (c == 1)
                {
                    drawGameArea();
                    Unit::gotoxy(35, 16);
                    cout << "游     戏     结     束 !";
                    PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);//暂停音乐
                    Unit::gotoxy(86, 34);
                    break;
                }

                if (GetAsyncKeyState(VK_ESCAPE) && 0x8000)
                {
                    Unit::gotoxy(35, 16);
                    cout << "游     戏     结     束 !";
                    PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
                    Unit::gotoxy(86, 34);
                    break;
                }
  
            }
            
        }
        /*system("cls");
    firstshow();
    int j=_getch();
        if (GetAsyncKeyState('2') && 0x8000)
        {
            rules();
        }
        if (GetAsyncKeyState('1') && 0x8000)
        {
            system("cls");
            drawGameArea();
            drawGameInfo();
            m_pFood.createpos();
            m_pFood.show();
            m_pSnake.showSnake();
            while (1)
            {
                int t;
                t = m_pSnake.eatFood(&m_pFood);
                if (t == 1)
                {
                    m_pSnake.growup();
                    m_iScore = m_iScore + 2;
                    int l = checkLevel();
                    if (l == 1)
                    {
                        m_iLevel++;
                    }
                    changInfo();
                }
                m_pSnake.changeDirection();
                int c = checkFailed();
                if (c == 1)
                {
                    drawGameArea();
                    Unit::gotoxy(35, 16);
                    cout << "游     戏     结     束 !";
                    Unit::gotoxy(86, 34);
                    break;
                }
                if (GetAsyncKeyState(VK_ESCAPE) && 0x8000);
                if (GetAsyncKeyState(VK_ESCAPE) && 0x8000)
                {
                    Unit::gotoxy(35, 16);
                    cout << "游     戏     结     束 !";
                    Unit::gotoxy(86, 34);
                    break;
                }
            }
        }*/
}

bool Game::checkFailed()
{
    if (m_pSnake->m_Body[0].m_x==5|| m_pSnake->m_Body[0].m_x == 85|| m_pSnake->m_Body[0].m_y==7|| m_pSnake->m_Body[0].m_y==33)
    {
        return true;
    }
    for (int i = 1; i < m_pSnake->m_iLength; i++)
    {
        if (m_pSnake->m_Body[0].m_x==m_pSnake->m_Body[i].m_x&& m_pSnake->m_Body[0].m_y == m_pSnake->m_Body[i].m_y)
        {
            return true;
        }
    }
	return false;
}

bool Game::checkLevel()
{
    if (m_pSnake->m_iLength == 10)
    {
        vector<Unit> t;
        t = m_pSnake->m_Body;
        for (int i = 0; i < m_pSnake->m_iLength; i++)
        {
            t[i].erase();
        }
        m_pSnake->m_iLength = 4;
    }
    if (m_iScore % 30 == 0)//30分一关
    {
        m_pSnake->m_iSpeed -= 50;//过关改变速度
        return true;
    }
	return false;
}

void Game::changInfo()
{

    for (int i = 5; i <= 33; i++)
    {
        for (int j = 6; j <= 85; j++)
        {
            if (i == 6)
            {
                Unit::gotoxy(j, i);
                cout << " 游戏名称：贪吃蛇";
                cout << "        编写者：伍鹏程 ";
                cout << "       当前得分:" << m_iScore;
                cout << "        当前关卡：" << m_iLevel;
                break;
            }
        }
    }
}

void Game::drawGameArea()
{

    interf b;
    b.drawGameArea();
}

void Game::drawGameInfo()
{
    interf b;
    b.drawGameInfo();
}

void Game::firstshow()
{
    
    interf b;
    b.firstshow();
}

void Game::rules()
{
    system("cls");
    drawGameArea();
    Unit::gotoxy(13, 6);
    cout << "游                    戏                   说                    明";
    Unit::gotoxy(12, 8);
    cout << "1、通过W,S,A,D分别控制蛇往上下左右移动";
    Unit::gotoxy(12, 10);
    cout << "或者通过w,s,a,d分别控制蛇往上下左右移动";
    Unit::gotoxy(12, 12);
    cout << "2、空格键暂停，暂停时按任意方向键或Esc继续游戏；游戏进行时，按Esc结束游戏";
    Unit::gotoxy(12, 14);
    cout << "3、当蛇头触碰到墙壁或者自己的身体某个部位时游戏结束" ;
    Unit::gotoxy(12, 16);
    cout << "4、每增加十分，通过一关，并且速度增加";
    Unit::gotoxy(12, 18);
    cout << "按Esc键返回菜单页";
    int i=_getch();
    if (GetAsyncKeyState(VK_ESCAPE) && 0x8000)
    {
        run();
    }
    else
        rules();
}
