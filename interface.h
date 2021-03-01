#pragma once
#include<windows.h>
class interf
{
public:
	void drawGameArea();
	void drawGameInfo();
	void firstshow();
public:
	int s_x=5;
	int s_y=5;
	int H =28;
	int W = 80;

	static const int KLEFT;
	static const int KUP;
	static const int KWIDTH;
	static const int KHEIGHT;
	static const int KSCORE_OFFSET=0;
	static const int KLIEVEL_OFFSET=1;
};