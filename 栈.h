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


//面试题
//1.两个栈实现一个队列
void QuequePush_Stack(Stack* s1, DataType data);
DataType QuequePop_Stack(Stack* s1, Stack* s2);
void test_2StoQ();

void QuequePush_Stack(Stack* s1, DataType data)
{
	StackPush(s1, data);
}

DataType QuequePop_Stack(Stack* s1, Stack* s2)
{
	DataType ret;
	if (StackEmpty(s1) == 0 && StackEmpty(s2) == 0)
	{
		return;
	}
	if (StackEmpty(s2) != 0)
	{
		ret = StackTop(s2);
		StackPop(s2);
		return ret;
	}
	while (StackEmpty(s1) != 1)
	{
		StackPush(s2, StackTop(s1));
		StackPop(s1);
	}
	ret = StackTop(s1);//要取的元素为s1的栈底元素
	StackPop(s1);
	return ret;
}

void test_2StoQ()//测试用例
{
	Stack* s1 = StackInit();
	Stack* s2 = StackInit();
	int i = 0;
	for (i; i<5; i++)
	{
		QuequePush_Stack(s1, i);
	}
	printf("%d\n", QuequePop_Stack(s1, s2));
	printf("%d\n", QuequePop_Stack(s1, s2));
}

//2.实现栈的出栈入栈，可以出其中的最小值