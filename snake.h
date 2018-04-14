#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define _LENTH 10//�޸���Ϸ���̴�
#define _WIDTH 10//ֻ�������ڲ��Ĵ�СΪN*N����
#define _SNAKE_LENTH 3//�ߵĳ�ʼ����

typedef struct SNAKE
{
	int x;
	int y;
	struct SNAKE *pNext;
}snake;

snake* head;//��ͷ
snake* tail;//��β
snake* cur = NULL;//��ʱָ�룬����������

void Pos(int x, int y);//�ƶ���꺯��
void SnakeInit();//��ʼ����
void SnakeMove();

void Pos(int x, int y)//��ȡ
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

void SnakeMove()
{
	if (GetKeyboardState(VK_UP))
	{
		Pos(tail->x, tail->y);
		printf("  ");
	}
}

//UI����
void PrintGameWall();

void PrintGameWall()
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