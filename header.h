#ifndef HEADER_H
#define HEADER_H

#include<fstream>                  
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<queue>

using namespace std;
COORD coord = { 0,0 };
void gotoxy(int x, int y)   // 초기 사용자 위치 설정
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
#endif
