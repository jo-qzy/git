#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define _LENTH 28//�޸���Ϸ���̴�
#define _WIDTH 28//ֻ�������ڲ��Ĵ�СΪN*N����
#define _SNAKE_LENTH 3//�ߵĳ�ʼ����

typedef struct SNAKE
{
	int x;
	int y;
	struct SNAKE *pNext;
}snake;

snake* head;//��ͷ
snake* tail;//��β
snake food;
short key = VK_RIGHT;
int speed = 500;
int score = 0;
int next_level = 30;

static void Pos(int x, int y);//�ƶ���꺯��
static void SnakeInit();//��ʼ����
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

static void Pos(int x, int y)//��ȡ
{
	COORD pos;
	HANDLE output;
	CONSOLE_CURSOR_INFO cci;
	pos.X = x;
	pos.Y = y;
	output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
	GetConsoleCursorInfo(output, &cci);//��ȡ��ǰ�����Ϣ
	cci.bVisible = false;//���ù�겻�ɼ�
	SetConsoleCursorInfo(output, &cci);
}

static void SnakeInit()
{
	snake* cur = NULL;
	int i = 0;
	cur = (snake*)malloc(sizeof(snake));
	head = cur;//����ͷ
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
		printf("��");
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
	printf("��");
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
			printf("��ǰ�ƶ��ٶȣ�ÿ��%d�����ƶ���ǰ�ƶ�", speed);
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
	printf("��");
	if ((head->x == food.x) && (head->y == food.y))
	{
		score += 10;
		Pos(75, 11);
		printf("�÷֣�%d", score);
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
			printf("��Ϸ������ҧ���Լ���\n");
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
		printf("��Ϸ������ײǽ��\n");
		Pos(_LENTH, _WIDTH / 2 + 1);
		system("pause");
		exit(0);
	}
}

void GameEntrance()
{
	Welcome();
	Pos(75, 11);
	printf("�÷֣�%d", score);
	Pos(75, 12);
	printf("��ǰ�ƶ��ٶȣ�ÿ��%d�����ƶ���ǰ�ƶ�", speed);
	Pos(75, 13);
	printf("ÿ���30���ٶȻ�ӿ�");
	Pos(75, 14);
	printf("����ײǽ����ײ�Լ�");
	Pos(75, 15);
	printf("���ո������ͣ����");
	PrintGameWall();
	SnakeInit();
	Pos(40, 20);
	GetFood();
	GameCycle();
}

//UI����
static void PrintGameWall()
{
	int x = 0, y = 0;
	for (x = 0; x < (_LENTH + 1) * 2; x += 2)
	{
		Pos(x, 0);
		printf("��");
		Pos(x, _WIDTH + 1);
		printf("��");
	}
	for (y = 0; y < _WIDTH + 2; y++)
	{
		Pos(0, y);
		printf("��");
		Pos((_LENTH + 1) * 2, y);
		printf("��");
	}
}

static void Welcome()
{
	Pos(28, 10);
	printf("��ӭ����̰����");
	Pos(28, 11);
	printf("��Ϸ����");
	Pos(28, 12);
	printf("1������ײǽ");
	Pos(28, 13);
	printf("2������ײ�Լ�");
	Pos(28, 14);
	printf("3���ո������ͣ���ٴΰ��¼�����Ϸ");
	Pos(28, 15);
	system("pause");
	system("cls");
}