#include "Game.h"
#include"interface.h"
#include <iostream>
using namespace std;
#include<conio.h>
#include "mmsystem.h"//�������^�ļ�
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
        system("cls");//����
        firstshow();//�˵�ҳ
        char i= _getch();
        if (i=='2')
        {
            rules();//��Ϸ˵��
        }
        if (i=='1')
        {
            PlaySound("e:\\music\\Good Time.wav", NULL, SND_FILENAME | SND_ASYNC);//���ر�������
            system("cls");
            drawGameArea();//���߽�
            drawGameInfo();//��ʾ��ֵ���ؿ�
           /* m_pFood.createpos();
            m_pFood.show();
            m_pSnake.showSnake();*/
            m_pFood->createpos();//����ʳ��
            m_pFood->show();
            m_pSnake->showSnake();//��ʾ��
            while (1)
            {
                int t;
                t = m_pSnake->eatFood(m_pFood);//�ж��Ƿ��ʳ��
                if (t == 1)
                {
                    m_pSnake->growup();//��������
                    m_iScore = m_iScore + 10;//���ӷ�ֵ
                    int l = checkLevel();//�ж��Ƿ�ͨ��
                    if (l == 1)
                    {
                        m_iLevel++;
                    }
                    changInfo();
                }
                m_pSnake->changeDirection();//�ж��Ƿ��иı��ߵķ������������Ӧ�ı�
                int c = checkFailed();//�ж���Ϸ�Ƿ�ʧ��
                if (c == 1)
                {
                    drawGameArea();
                    Unit::gotoxy(35, 16);
                    cout << "��     Ϸ     ��     �� !";
                    PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);//��ͣ����
                    Unit::gotoxy(86, 34);
                    break;
                }

                if (GetAsyncKeyState(VK_ESCAPE) && 0x8000)
                {
                    Unit::gotoxy(35, 16);
                    cout << "��     Ϸ     ��     �� !";
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
                    cout << "��     Ϸ     ��     �� !";
                    Unit::gotoxy(86, 34);
                    break;
                }
                if (GetAsyncKeyState(VK_ESCAPE) && 0x8000);
                if (GetAsyncKeyState(VK_ESCAPE) && 0x8000)
                {
                    Unit::gotoxy(35, 16);
                    cout << "��     Ϸ     ��     �� !";
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
    if (m_iScore % 30 == 0)//30��һ��
    {
        m_pSnake->m_iSpeed -= 50;//���ظı��ٶ�
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
                cout << " ��Ϸ���ƣ�̰����";
                cout << "        ��д�ߣ������� ";
                cout << "       ��ǰ�÷�:" << m_iScore;
                cout << "        ��ǰ�ؿ���" << m_iLevel;
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
    cout << "��                    Ϸ                   ˵                    ��";
    Unit::gotoxy(12, 8);
    cout << "1��ͨ��W,S,A,D�ֱ�����������������ƶ�";
    Unit::gotoxy(12, 10);
    cout << "����ͨ��w,s,a,d�ֱ�����������������ƶ�";
    Unit::gotoxy(12, 12);
    cout << "2���ո����ͣ����ͣʱ�����ⷽ�����Esc������Ϸ����Ϸ����ʱ����Esc������Ϸ";
    Unit::gotoxy(12, 14);
    cout << "3������ͷ������ǽ�ڻ����Լ�������ĳ����λʱ��Ϸ����" ;
    Unit::gotoxy(12, 16);
    cout << "4��ÿ����ʮ�֣�ͨ��һ�أ������ٶ�����";
    Unit::gotoxy(12, 18);
    cout << "��Esc�����ز˵�ҳ";
    int i=_getch();
    if (GetAsyncKeyState(VK_ESCAPE) && 0x8000)
    {
        run();
    }
    else
        rules();
}
