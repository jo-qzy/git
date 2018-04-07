#pragma once

#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct QueueNode
{
	DataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	QueueNode* _head;
	QueueNode* _tail;
}Queue;

void QueueInit(Queue* q);
void QueuePush(Queue* q, DataType x);
void QueuePop(Queue* q);
DataType QueueFront(Queue* q);
DataType QueueBack(Queue* q);
size_t QueueSize(Queue* q);
int QueueEmpty(Queue* q);

QueueNode* BuyNewNode()
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->_next = NULL;
	return newnode;
}

void QueueInit(Queue* q)
{
	q->_head = BuyNewNode();
	q->_tail = q->_head;
}

void QueuePush(Queue* q, DataType x)
{
	assert(q);
	q->_tail->_data = x;
	q->_tail = q->_tail->_next;
	q->_tail = BuyNewNode();
}

void QueuePop(Queue* q)
{
	assert(q);
	QueueNode* next = q->_head->_next;
	if (!QueueEmpty(q))
	{
		printf("empty\n");
	}
	free(q->_head);
	q->_head = next;
}

DataType QueueFront(Queue* q)
{
	assert(q);
	return q->_head->_data;
}

DataType QueueBack(Queue* q)
{
	assert(q);
	return q->_tail->_data;
}

size_t QueueSize(Queue* q)
{
	assert(q);
	QueueNode* cur = q->_head;
	size_t count = 0;
	while (cur != q->_tail)
	{
		cur = cur->_next;
		count++;
	}
	return count;
}

int QueueEmpty(Queue* q)
{
	if (q->_head == q->_tail)
	{
		return 0;
	}
	return 1;
}

//面试题
//两个队列实现一个栈
typedef struct QueueStack
{
	Queue* _q1;
	Queue* _q2;
}QueueStack;

QueueStack* Stack_QueueInit()
{
	QueueStack* new_qs = (QueueStack*)malloc(sizeof(QueueStack));
	QueueInit(new_qs->_q1);
	QueueInit(new_qs->_q2);
	return new_qs;
}

void StackPush_Queue(QueueStack* qs, DataType data)
{
	if (QueueEmpty(qs->_q1) == 0)
	{
		QueuePush(qs->_q2, data);
	}
	else
	{
		QueuePush(qs->_q1, data);
	}
}

void StackPop_Queue(QueueStack* qs)
{
	assert(qs);
	Queue* op = NULL;
	Queue* empty = NULL;
	if (QueueEmpty(qs->_q1) == 0)
	{
		op = qs->_q2;
		empty = qs->_q1;
	}
	else
	{
		op = qs->_q1;
		empty = qs->_q2;
	}
	while (QueueSize(op) != 1)
	{
		DataType tmp = QueueFront(op);
		QueuePop(op);
		QueuePush(empty, tmp);
	}
	QueuePop(op);
}

DataType StackTop_Queue(QueueStack* qs)
{
	if ((QueueEmpty(qs->_q1) == 0) && (QueueEmpty(qs->_q2) == 0))
	{
		assert(1);
	}
	if (QueueEmpty(qs->_q1) == 0)
	{
		return QueueBack(qs->_q2);
	}
	else
	{
		return QueueBack(qs->_q1);
	}
}