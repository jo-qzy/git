#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define _LENTH 10//修改游戏棋盘大
#define _WIDTH 10//只需输入内部的大小为N*N即可
#define _SNAKE_LENTH 3//蛇的初始长度

typedef struct SNAKE
{
	int x;
	int y;
	struct SNAKE *pNext;
}snake;

snake* head;//蛇头
snake* tail;//蛇尾
snake* cur = NULL;//临时指针，创建蛇身用

void Pos(int x, int y);//移动光标函数
void SnakeInit();//初始化蛇
void SnakeMove();

void Pos(int x, int y)//获取
{
	COORD pos;
	HANDLE output;
	pos.X = x;
	pos.Y = y;
	output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

void SnakeInit()
{
	int i = 0;
	cur = (snake*)malloc(sizeof(snake));
	head = cur;//保存头
	cur->x = (_LENTH + 2) / 2 * 2;
	cur->y = (_WIDTH + 2) / 2;
	for (i = 1; i < _SNAKE_LENTH; i++)
	{
		tail = (snake*)malloc(sizeof(snake));
		tail->x = head->x - i * 2;
		tail->y = head->y;
		cur->pNext = tail;
		cur = cur->pNext;
	}
	tail->pNext = NULL;
	cur = head;
	while (cur != NULL)
	{
		Pos(cur->x, cur->y);
		printf("■");
		cur = cur->pNext;
	}
}

void SnakeMove()
{
	if (GetKeyboardState(VK_UP))
	{
		Pos(tail->x, tail->y);
		printf("  ");
	}
}

//UI部分
void PrintGameWall();

void PrintGameWall()
{
	int x = 0, y = 0;
	for (x = 0; x < (_LENTH + 1) * 2; x += 2)
	{
		Pos(x, 0);
		printf("■");
		Pos(x, _WIDTH + 1);
		printf("■");
	}
	for (y = 0; y < _WIDTH + 2; y++)
	{
		Pos(0, y);
		printf("■");
		Pos((_LENTH + 1) * 2, y);
		printf("■");
	}
}