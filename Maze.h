#pragma once

#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


#define size 100
#define row 6
#define col 6

int stack_flag = 0;
int shortest = 0;

typedef struct Pos
{
	size_t _row;
	size_t _col;
}Pos;

/////////////////////////////////////////////////
////ջ����///////////
///////////////////////////////////
typedef Pos DataType;

typedef struct Stack
{
	DataType* _array;
	size_t	_top;
	size_t	_end;
}Stack;

Stack* StackInit();
void StackPush(Stack* s, DataType x);
void StackPop(Stack* s);
DataType StackTop(Stack* s);
size_t StackSize(Stack* s);
int StackEmpty(Stack* s);
/////////////////////////////
////////////////////////////////

////////////�Թ�����
typedef struct Maze
{
	int _map[row][col];
	//Pos _entry;
}Maze;

void MazeInit(Maze* m, int map[][col]);//��ʼ��
void GetPath(Maze* m, Pos entry, int flag);//�ڵ�ͼ�ϱ�����п���·��
void GetShortPath(Maze* m, Pos entry, Stack* s);//��ȡ���·�������������ȣ���ȡ����һ��
void PrintMaze(Maze* m);//��ӡ��ͼ
void PrintPath(Stack* s);//��ӡ·��
int CheckIsAccess(Maze* m, Pos pos, int flag);//�ж�·���Ƿ��ͨ

void test();//��������

void MazeInit(Maze* m, int map[][col])
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			m->_map[i][j] = map[i][j];
		}
	}
}

//void GetEntry(Maze* m, Pos entry)
//{
//	m->_entry._row = entry._row;
//	m->_entry._col = entry._col;
//}

void GetPath(Maze* m, Pos entry, int flag)
{
	Pos next = entry;
	m->_map[entry._row][entry._col] = flag + 1;//��ڱ��Ϊ2����һ����Ϊǰһ�� + 1
	if (flag != 1)//�г��ڲ��֣�flag���÷�ֱֹ������ڴ��˳�
	{
		if ((entry._col == 0) || (entry._col == col - 1) || (entry._row == 0) || (entry._row == row - 1))
		{
			if (shortest == 0)//��ȡ����
			{
				shortest = flag;
			}
			else if (shortest > flag)
			{
				shortest = flag;
			}
			return;
		}
	}
	//��
	next = entry;
	next._row = next._row - 1;
	if (CheckIsAccess(m, next, flag + 1))
	{
		GetPath(m, next, flag + 1);//�ݹ�ʵ��
	}
	//��
	next = entry;
	next._row = next._row + 1;
	if (CheckIsAccess(m, next, flag + 1))
	{
		GetPath(m, next, flag + 1);
	}
	//��
	next = entry;
	next._col = next._col - 1;
	if (CheckIsAccess(m, next, flag + 1))
	{
		GetPath(m, next, flag + 1);
	}
	//��
	next = entry;
	next._col = next._col + 1;
	if (CheckIsAccess(m, next, flag + 1))
	{
		GetPath(m, next, flag + 1);
	}
}

void GetShortPath(Maze* m, Pos entry, Stack* s)
{
	Pos next = entry;
	if (m->_map[entry._row][entry._col] != 2)
	{
		if ((entry._col == 0) || (entry._col == col - 1) || (entry._row == 0) || (entry._row == row - 1))
			//��������
		{
			if (m->_map[entry._row][entry._col] - 1 == shortest)
			{
				stack_flag = 1;//��ջ��ʼ��־
				StackPush(s, entry);
			}
			return;
		}
	}
	//��
	next = entry;
	next._row = next._row - 1;
	if (m->_map[next._row][next._col] == m->_map[entry._row][entry._col] + 1)
	{
		GetShortPath(m, next, s);
		if (stack_flag == 1)
		{
			StackPush(s, entry);
			return;//����Ҫ���зֲ���ߣ��õ��ڵ���������
		}
	}
	//��
	next = entry;
	next._row = next._row + 1;
	if (m->_map[next._row][next._col] == m->_map[entry._row][entry._col] + 1)
	{
		GetShortPath(m, next, s);
		if (stack_flag == 1)
		{
			StackPush(s, entry);
			return;
		}
	}
	//��
	next = entry;
	next._col = next._col - 1;
	if (m->_map[next._row][next._col] == m->_map[entry._row][entry._col] + 1)
	{
		GetShortPath(m, next, s);
		if (stack_flag == 1)
		{
			StackPush(s, entry);
			return;
		}
	}
	//��
	next = entry;
	next._col = next._col + 1;
	if (m->_map[next._row][next._col] == m->_map[entry._row][entry._col] + 1)
	{
		GetShortPath(m, next, s);
		if (stack_flag == 1)
		{
			StackPush(s, entry);
			return;
		}
	}
}

void PrintMaze(Maze* m)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%d  ", m->_map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void PrintPath(Stack* s)
{
	while (StackEmpty(s) != 0)
	{
		printf("(%d,%d)->", StackTop(s)._row, StackTop(s)._col);
		StackPop(s);
	}
	printf("Exit\n");
}

int CheckIsAccess(Maze* m, Pos pos, int flag)
{
	if (pos._col < col && pos._row < row)//�жϱ߽�
	{
		if ((m->_map[pos._row][pos._col] == 1) || (m->_map[pos._row][pos._col] >= flag))//�ж�·���Ƿ��ͨ
		//
		{
			return 1;
		}
	}
	return 0;
}

//��������
void test()
{
	Maze m;
	Stack *s = StackInit();
	Pos entry = { 5,1 };
	int map[row][col] = {
		{ 0,0,0,0,0,0 },
		{ 0,0,1,1,1,0 },
		{ 0,0,1,0,1,0 },
		{ 0,0,1,1,1,1 },
		{ 0,1,1,0,0,0 },
		{ 0,1,0,0,0,0 },
	};
	MazeInit(&m, map);
	PrintMaze(&m);
	GetPath(&m, entry, 1);
	PrintMaze(&m);
	GetShortPath(&m, entry, s);
	PrintPath(s);
}

//ջ����

Stack* StackInit()
{
	Stack* newstack = (Stack*)malloc(sizeof(Stack));
	newstack->_array = (DataType*)malloc(sizeof(DataType) * size);
	newstack->_end = 0;
	newstack->_top = 0;
	return newstack;
}

void StackPush(Stack* s, DataType x)
{
	*(s->_array + s->_top) = x;
	s->_top++;
}

void StackPop(Stack* s)
{
	if (!StackEmpty(s))
	{
		return;
	}
	s->_top--;
}

DataType StackTop(Stack* s)
{
	return *(s->_array + s->_top - 1);
}

size_t StackSize(Stack* s)
{
	return s->_top - s->_end;
}

int StackEmpty(Stack* s)
{
	if (s->_top == s->_end)
	{
		return 0;
	}
	return 1;
}