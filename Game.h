#pragma once
#include"Csnake.h"

class Game
{
public:
	Game();
	virtual ~Game();
	void run();
	bool checkFailed();
	bool checkLevel();
	void changInfo();
	void drawGameArea();
	void drawGameInfo();
	void firstshow();
	void rules();
public:
	static const int KLEFT;
	static const int KUP;
	static const int KWIDTH;
	static const int KHEIGHT;
	static const int KSCORE_OFFSET=0;
	static const int KLEVEL_OFFSET=1;
public:
	/*Food m_pFood;
	Csnake m_pSnake;*/
	Food *m_pFood;
	Csnake *m_pSnake;
	int m_iScore= KSCORE_OFFSET;
	int m_iLevel= KLEVEL_OFFSET;
};
