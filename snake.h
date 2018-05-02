#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define _LENTH 28//�޸���Ϸ���̴�
#define _WIDTH 28//ֻ�������ڲ��Ĵ�СΪN*N����
#define _SNAKE_LENTH 3//�ߵĳ�ʼ����
#define _SNAKE_SPEED 300//�߳�ʼ�ٶ�

typedef struct SNAKE
{
	int x;
	int y;
	struct SNAKE *pNext;
}snake;

static void Pos(int x, int y);//�ƶ���꺯��
static void SnakeInit(snake** head,snake**tail);//��ʼ����
static void GetFood(snake* head,snake** food);
static void FoodPrint(snake* food);
static int SnakeFoodJudge(snake* head,snake* food);
static void GameCycle();
static void Pause();
static void SnakeMove(snake** head, snake** tail, snake** food,short key,int* score);
static void DoNotBitYourself(snake* head);
static void StayAwayFromWall(snake* head);
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

static void SnakeInit(snake** head,snake** tail)
{
	snake* cur = NULL;
	int i = 0;
	cur = (snake*)malloc(sizeof(snake));
	*head = cur;//����ͷ
	cur->x = (_LENTH + 2) / 2 * 2;
	cur->y = (_WIDTH + 2) / 2;
	for (i = 1; i < _SNAKE_LENTH; i++)
	{
		*tail = (snake*)malloc(sizeof(snake));
		(*tail)->x = (*head)->x - i * 2;
		(*tail)->y = (*head)->y;
		cur->pNext = *tail;
		cur = cur->pNext;
	}
	(*tail)->pNext = NULL;
	cur = *head;
	while (cur != NULL)
	{
		Pos(cur->x, cur->y);
		printf("��");
		cur = cur->pNext;
	}
}

static void GetFood(snake* head,snake** food)
{
	srand((unsigned int)time(0));
	do
	{
		(*food)->x = (rand() % (_LENTH - 1) + 1) * 2;
		(*food)->y = rand() % (_WIDTH - 1) + 1;
	} while (SnakeFoodJudge(head,*food) == 0);
	FoodPrint(*food);
}

static void FoodPrint(snake* food)
{
	Pos(food->x, food->y);
	printf("��");
}

static int SnakeFoodJudge(snake* head,snake* food)
{
	snake* cur = head;
	while (cur != NULL)
	{
		if((cur->x == food->x) && (cur->y == food->y))
		{
			return 0;
		}
		cur = cur->pNext;
	}
	return 1;
}

static void GameCycle()
{
	snake* food = (snake*)malloc(sizeof(snake));
	snake* head = NULL;
	snake* tail = NULL;
	short key = VK_RIGHT;
	int score = 0;
	int speed = _SNAKE_SPEED;
	int next_level = 30;
	SnakeInit(&head, &tail);
	GetFood(head,&food);
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
		SnakeMove(&head,&tail,&food,key,&score);
		DoNotBitYourself(head);
		StayAwayFromWall(head);
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

static void SnakeMove(snake** head, snake** tail,snake** food,short key,int* score)
{
	snake* cur = NULL;
	cur = (snake*)malloc(sizeof(snake));
	cur->pNext = *head;
	switch (key)
	{
	case VK_UP:
		cur->x = (*head)->x;
		cur->y = (*head)->y - 1;
		break;
	case VK_DOWN:
		cur->x = (*head)->x;
		cur->y = (*head)->y + 1;
		break;
	case VK_LEFT:
		cur->x = (*head)->x - 2;
		cur->y = (*head)->y;
		break;
	case VK_RIGHT:
		cur->x = (*head)->x + 2;
		cur->y = (*head)->y;
		break;
	}
	(*head) = cur;
	Pos((*head)->x, (*head)->y);
	printf("��");
	if (((*head)->x == (*food)->x) && ((*head)->y == (*food)->y))
	{
		*score += 10;
		Pos(75, 11);
		printf("�÷֣�%d", *score);
		GetFood(*head,food);
		return;
	}
	if (((*head)->x != (*tail)->x) || ((*head)->y != (*tail)->y))
	{
		Pos((*tail)->x, (*tail)->y);
		printf("  ");
	}
	while (cur->pNext->pNext != NULL)
	{
		cur = cur->pNext;
	}
	free(*tail);
	*tail = cur;
	(*tail)->pNext = NULL;
}

static void DoNotBitYourself(snake* head)
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

static void StayAwayFromWall(snake* head)
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
	printf("�÷֣�0");
	Pos(75, 12);
	printf("��ǰ�ƶ��ٶȣ�ÿ��300�����ƶ���ǰ�ƶ�");
	Pos(75, 13);
	printf("ÿ���30���ٶȻ�ӿ�");
	Pos(75, 14);
	printf("����ײǽ����ײ�Լ�");
	Pos(75, 15);
	printf("���ո������ͣ����");
	PrintGameWall();
	Pos(40, 20);
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