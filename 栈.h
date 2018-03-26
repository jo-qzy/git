#pragma once

#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
#define size 100

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

Stack* StackInit()
{
	Stack* newstack = (Stack*)malloc(sizeof(Stack));
	newstack->_array = (DataType*)malloc(sizeof(int) * size);
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