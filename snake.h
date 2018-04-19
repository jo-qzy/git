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
int speed = 500;
int score = 0;
int next_level = 30;

static void Pos(int x, int y);//移动光标函数
static void SnakeInit();//初始化蛇
static void GetFood();
static void FoodPrint();
static int SnakeFoodJudge();
static void GameCycle();
static void Pause();
static void SnakeMove();
static void DoNotBitYourself();
static void StayAwayFromWall();
void GameEntrance();

static void PrintGameWall();
static void Welcome();

static void Pos(int x, int y)//获取
{
	COORD pos;
	HANDLE output;
	CONSOLE_CURSOR_INFO cci;
	pos.X = x;
	pos.Y = y;
	output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
	GetConsoleCursorInfo(output, &cci);//获取当前光标信息
	cci.bVisible = false;//设置光标不可见
	SetConsoleCursorInfo(output, &cci);
}

static void SnakeInit()
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

static void GetFood()
{
	srand((unsigned int)time(0));
	do
	{
		food.x = (rand() % (_LENTH - 1) + 1) * 2;
		food.y = rand() % (_WIDTH - 1) + 1;
	} while (SnakeFoodJudge() == 0);
	FoodPrint();
}

static void FoodPrint()
{
	Pos(food.x, food.y);
	printf("■");
}

static int SnakeFoodJudge()
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

static void GameCycle()
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
		DoNotBitYourself();
		StayAwayFromWall();
		if ((score == next_level) && (speed >= 10))
		{
			speed -= 10;
			next_level += 30;
			Pos(75, 12);
			printf("当前移动速度：每隔%d毫秒移动向前移动", speed);
		}
		Sleep(speed);
	}
}

static void Pause()
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

static void SnakeMove()
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
		score += 10;
		Pos(75, 11);
		printf("得分：%d", score);
		GetFood();
		return;
	}
	if ((head->x != tail->x) || (head->y != tail->y))
	{
		Pos(tail->x, tail->y);
		printf("  ");
		
	}
	while (cur->pNext->pNext != NULL)
	{
		cur = cur->pNext;
	}
	free(tail);
	tail = cur;
	tail->pNext = NULL;
}

static void DoNotBitYourself()
{
	snake* cur = head->pNext;
	while (cur != NULL)
	{
		if ((head->x == cur->x) && (head->y == cur->y))
		{
			Pos(_LENTH, _WIDTH / 2);
			printf("游戏结束你咬到自己了\n");
			Pos(_LENTH, _WIDTH / 2 + 1);
			system("pause");
			exit(0);
		}
		cur = cur->pNext;
	}
}

static void StayAwayFromWall()
{
	if ((head->x == 0) || (head->x == (_LENTH + 1) * 2) || (head->y == 0) || (head->y == _WIDTH + 1))
	{
		Pos(_LENTH, _WIDTH / 2);
		printf("游戏结束你撞墙了\n");
		Pos(_LENTH, _WIDTH / 2 + 1);
		system("pause");
		exit(0);
	}
}

void GameEntrance()
{
	Welcome();
	Pos(75, 11);
	printf("得分：%d", score);
	Pos(75, 12);
	printf("当前移动速度：每隔%d毫秒移动向前移动", speed);
	Pos(75, 13);
	printf("每获得30分速度会加快");
	Pos(75, 14);
	printf("不能撞墙不能撞自己");
	Pos(75, 15);
	printf("按空格可以暂停……");
	PrintGameWall();
	SnakeInit();
	Pos(40, 20);
	GetFood();
	GameCycle();
}

//UI部分
static void PrintGameWall()
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

static void Welcome()
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