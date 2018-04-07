#pragma once

#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
#define size 10

typedef struct Stack
{
	DataType* _array;
	size_t	_top;
	size_t	_capacity;
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
	newstack->_capacity = size;
	newstack->_array = (DataType*)malloc(sizeof(DataType) * newstack->_capacity);
	newstack->_top = 0;
	return newstack;
}

void StackPush(Stack* s, DataType x)
{
	if (s->_top == s->_capacity - 1)
	{
		s->_capacity *= 2;
		s->_array = (DataType*)realloc(s->_array, sizeof(DataType) * s->_capacity);
	}
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
	return s->_top;
}

int StackEmpty(Stack* s)
{
	if (s->_top == 0)
	{
		return 0;
	}
	return 1;
}


//面试题
//1.两个栈实现一个队列
void QuequePush_Stack(Stack* s1, DataType data);
DataType QuequePop_Stack(Stack* s1, Stack* s2);
void TestTwoStackToQueque();

void QuequePush_Stack(Stack* s1, DataType data)
{
	StackPush(s1, data);
}

DataType QuequePop_Stack(Stack* s1, Stack* s2)
{
	DataType ret;
	if (StackEmpty(s1) == 0 && StackEmpty(s2) == 0)
	{
		assert(1);
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

void TestTwoStackToQueque()//测试用例
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

//2.实现栈的出栈入栈，且可以给出其中的最小值
typedef struct MinStack
{
	Stack* _st;
	Stack* _min;
}MinStack;

MinStack* MinStackInit();
void MinStackPush(MinStack* ms, DataType data);
void MinStackPop(MinStack* ms);
DataType MinStackTop(MinStack* ms);
DataType MinStackMin(MinStack* ms);

//缺点：当重复入最小值的时候，入100个最小值，最小值得栈也会入100个最小值

MinStack* MinStackInit()
{
	MinStack* ms;
	ms = (MinStack*)malloc(sizeof(MinStack));
	ms->_st = StackInit();
	ms->_min = StackInit();
	return ms;
}

void MinStackPush(MinStack* ms, DataType data)
{
	assert(ms);
	StackPush(ms->_st, data);
	if (StackEmpty(ms->_min) == 0)
	{
		StackPush(ms->_min, data);
	}
	else if ((data == StackTop(ms->_min)) || (data < StackTop(ms->_min)))
	{
		StackPush(ms->_min, data);
	}
}

void MinStackPop(MinStack* ms)
{
	assert(ms);
	if (StackEmpty(ms->_st) == 0)
	{
		assert(1);
	}
	if (StackTop(ms->_st) == StackTop(ms->_min))
	{
		StackPop(ms->_min);
	}
	StackPop(ms->_st);
}

DataType MinStackTop(MinStack* ms)
{
	assert(ms);
	return StackTop(ms->_st);
}

DataType MinStackMin(MinStack* ms)
{
	assert(ms);
	return StackTop(ms->_min);
}

void TestMinStack()//测试用例
{
	MinStack* ms = MinStackInit();
	MinStackPush(ms, 4);
	printf("%d\n", MinStackMin(ms));
	MinStackPush(ms, 3);
	printf("%d\n", MinStackMin(ms));
	MinStackPush(ms, 5);
	MinStackPush(ms, 6);
	MinStackPush(ms, 2);
	MinStackPush(ms, 8);
	printf("%d\n", MinStackMin(ms));
	MinStackPop(ms);
	MinStackPop(ms);
	MinStackPop(ms);
	printf("%d\n", MinStackMin(ms));
}