#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define _LENTH 28//修改游戏棋盘大
#define _WIDTH 28//只需输入内部的大小为N*N即可
#define _SNAKE_LENTH 3//蛇的初始长度

typedef struct SNAKE
{
	int x;
	int y;
	struct SNAKE *pNext;
}snake;

snake* head;//蛇头
snake* tail;//蛇尾
snake food;
short key = VK_RIGHT;
int speed = 50;

void Pos(int x, int y);//移动光标函数
void SnakeInit();//初始化蛇
void GetFood();
void FoodPrint();
int SnakeFoodJudge();
void GameCycle();
void Pause();
void SnakeMove();
void GameEntrance();

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
	snake* cur = NULL;
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

void GetFood()
{
	srand((unsigned int)time(0));
	do
	{
		food.x = (rand() % (_LENTH - 1) + 1) * 2;
		food.y = rand() % (_WIDTH - 1) + 1;
	} while (SnakeFoodJudge() == 0);
	FoodPrint();
}

void FoodPrint()
{
	Pos(food.x, food.y);
	printf("■");
}

int SnakeFoodJudge()
{
	snake* cur = head;
	while (cur != NULL)
	{
		if((cur->x == food.x) && (cur->y == food.y))
		{
			return 0;
		}
		cur = cur->pNext;
	}
	return 1;
}

void GameCycle()
{
	while (1)
	{
		if (GetAsyncKeyState(VK_UP) && (key != VK_DOWN))
		{
			key = VK_UP;
		}
		else if (GetAsyncKeyState(VK_DOWN) && (key != VK_UP))
		{
			key = VK_DOWN;
		}
		else if (GetAsyncKeyState(VK_LEFT) && (key != VK_RIGHT))
		{
			key = VK_LEFT;
		}
		else if (GetAsyncKeyState(VK_RIGHT) && (key != VK_LEFT))
		{
			key = VK_RIGHT;
		}
		else if (GetAsyncKeyState(VK_SPACE))
		{

			Pause();
		}
		SnakeMove();
		Sleep(speed);
	}
}

void Pause()
{
	while (1)
	{
		Sleep(300);
		if (GetAsyncKeyState(VK_SPACE))
		{
			break;
		}
	}
}

void SnakeMove()
{
	snake* cur = NULL;
	cur = (snake*)malloc(sizeof(snake));
	cur->pNext = head;
	switch (key)
	{
	case VK_UP:
		cur->x = head->x;
		cur->y = head->y - 1;
		break;
	case VK_DOWN:
		cur->x = head->x;
		cur->y = head->y + 1;
		break;
	case VK_LEFT:
		cur->x = head->x - 2;
		cur->y = head->y;
		break;
	case VK_RIGHT:
		cur->x = head->x + 2;
		cur->y = head->y;
		break;
	}
	head = cur;
	Pos(head->x, head->y);
	printf("■");
	if ((head->x == food.x) && (head->y == food.y))
	{
		GetFood();
		return;
	}
	Pos(tail->x, tail->y);
	printf("  ");
	while (cur->pNext->pNext != NULL)
	{
		cur = cur->pNext;
	}
	free(tail);
	tail = cur;
	tail->pNext = NULL;
}

//UI部分
void PrintGameWall();
void Welcome();

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

void Welcome()
{
	Pos(28, 10);
	printf("欢迎来到贪吃蛇");
	Pos(28, 11);
	printf("游戏规则：");
	Pos(28, 12);
	printf("1、不能撞墙");
	Pos(28, 13);
	printf("2、不能撞自己");
	Pos(28, 14);
	printf("3、空格可以暂停，再次按下继续游戏");
	Pos(28, 15);
	system("pause");
	system("cls");
}

void GameEntrance()
{
	Welcome();
	PrintGameWall();
	SnakeInit();
	Pos(40, 20);
	GetFood();
	GameCycle();
}