#pragma once

#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
//#include "stack.h"

typedef enum OP_TYPE
{
	OP_NUM = 1,
	OP_ADD = 2,
	OP_SUB = 2,
	OP_MUL = 3,
	OP_DIV = 3
}OP_TYPE;

typedef struct Exp
{
	OP_TYPE _op;
	int num;
}Exp;

void GetInExp(Exp exp[]);//获取计算式
void InExpToPoExp(Exp exp[], Stack* s);//转换逆波兰表达式
int Calculate(Exp exp[], Stack* s);//计算函数

//栈函数
typedef Exp DataType;
#define SIZE 100

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

//计算器函数
void GetInExp(Exp exp[])
{
	scanf("%s");
}

void InExpToPoExp(Exp exp[], Stack* s)
{
	Exp tmp[100] = { 0 };
	Exp prev = { 0 };
	int i = 0;
	int tmp_index = 0, exp_index = 0;
	while (exp[exp_index]._op != 0)
	{
		if (exp[exp_index]._op == 1)
		{
			tmp[tmp_index] = exp[exp_index];//逆波兰表达式不需要考虑数字，直接拷贝即可
			tmp_index++;
		}
		else
		{
			if (StackEmpty(s) == 0)
			{
				StackPush(s, exp[exp_index]);//栈为空符号直接压栈
			}
			else if (exp[exp_index]._op > prev._op)//判断符号优先级问题，压栈操作
			{
				StackPush(s, exp[exp_index]);
			}
			else
			{
				prev = StackTop(s);
				while(StackEmpty(s) != 0 && exp[exp_index]._op < prev._op)
				{
					tmp[tmp_index] = prev;
					StackPop(s);
					tmp_index++;
					prev = StackTop(s);
				}
				StackPush(s, exp[exp_index]);
			}
		}
		exp_index++;
	}
	while (StackEmpty(s) != 0)
	{
		tmp[tmp_index] = StackTop(s);//将符号全部移出栈放入表达式
		StackPop(s);
		tmp_index++;
	}
	for (tmp_index = 0; tmp[tmp_index]._op != 0; tmp_index++)
	{
		exp[tmp_index] = tmp[tmp_index];
	}
}

int Calculate(Exp exp[],Stack* s)//逆波兰表达式的运算
{
	int exp_index = 0;
	int right = 0, left = 0;
	Exp result = { OP_NUM,0 };
	while (exp[exp_index]._op != 0)
	{
		if (exp[exp_index]._op == 1)
		{
			StackPush(s, exp[exp_index]);
		}
		if (exp[exp_index]._op > 1)
		{
			right = StackTop(s).num;
			StackPop(s);
			left = StackTop(s).num;
			StackPop(s);
			if (exp[exp_index]._op == OP_ADD)
			{
				result.num = left + right;
			}
			else if (exp[exp_index]._op == OP_SUB)
			{
				result.num = left - right;
			}
			else if (exp[exp_index]._op == OP_MUL)
			{
				result.num = left * right;
			}
			else if (exp[exp_index]._op == OP_DIV)
			{
				result.num = left / right;
			}
			StackPush(s, result);
		}
		exp_index++;
	}
	result = StackTop(s);
	StackPop(s);
	return result.num;
}

//栈
Stack* StackInit()
{
	Stack* newstack = (Stack*)malloc(sizeof(Stack));
	newstack->_array = (DataType*)malloc(sizeof(int) * SIZE);
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