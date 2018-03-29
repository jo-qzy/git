#pragma once

#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


#define size 100
#define row 6
#define col 6

typedef struct Pos
{
	size_t _row;
	size_t _col;
}Pos;

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



typedef struct Maze
{
	int _map[row][col];
	Pos _entry;
}Maze;

void MazeInit(Maze* m, int map[][col]);
void GetEntry(Maze* m, Pos entry);
void GetPath(Maze* m, Stack* s);
void PrintMaze(Maze* m);
int Check(Maze* m, Pos pos);

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

void GetEntry(Maze* m, Pos entry)
{
	m->_entry._row = entry._row;
	m->_entry._col = entry._col;
}

void GetPath(Maze* m, Stack* s)
{
	Pos cur, next;
	StackPush(s, m->_entry);
	while (StackEmpty(s) != 0)
	{
		cur = StackTop(s);
		
		cur._row += 1;
		if (Check(m, cur))
		{
			m->_map[cur._row][cur._col] = 2;
			StackPush(s, cur);
			continue;
		}
		cur = StackTop(s);
		cur._row -= 1;
		if (Check(m, cur))
		{
			m->_map[cur._row][cur._col] = 2;
			StackPush(s, cur);
			continue;
		}
		cur = StackTop(s);
		cur._col += 1;
		if (Check(m, cur))
		{
			m->_map[cur._row][cur._col] = 2;
			StackPush(s, cur);
			continue;
		}
		cur = StackTop(s);
		cur._col -= 1;
		if (Check(m, cur))
		{
			m->_map[cur._row][cur._col] = 2;
			StackPush(s, cur);
			continue;
		}
		
		StackPop(s);
		/*if (cur._col == 0 || cur._col == col - 1 || cur._row == 0 || cur._row == row - 1)
		{
			printf("find way!\n");
			return;
		}*/

	}
	printf("no way out\n");
}

void PrintMaze(Maze* m)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%d  ",m->_map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int Check(Maze* m, Pos pos)
{
	if (pos._col < col && pos._row < row)
	{
		if(m->_map[pos._row][pos._col] == 1)
		{ 
			return 1;
		}
	}
	return 0;
}


void test()
{
	Maze m;
	Stack *s = StackInit();
	Pos entry = { 5,1 };
	int map[row][col] = {
		{ 0,0,0,0,0,0 },
		{ 0,0,1,1,1,1 },
		{ 0,0,1,0,0,0 },
		{ 0,0,1,1,1,1 },
		{ 0,1,1,0,0,0 },
		{ 0,1,0,0,0,0 },
	};
	MazeInit(&m, map);
	PrintMaze(&m);
	GetEntry(&m, entry);
	GetPath(&m, s);
	PrintMaze(&m);
}

//Õ»²¿·Ö

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