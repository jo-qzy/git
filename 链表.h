//数据结构：顺序表中链表练习，实现增删查改，以及排序等操作

//SListNode* BuySListNode(DataType x);
//void SListPrint(SListNode* pHead);
//void SListDestory(SListNode** ppHead);
//
//void SListPushBack(SListNode** ppHead, DataType x);
//void SListPopBack(SListNode** ppHead);
//void SListPushFront(SListNode** ppHead, DataType x);
//SListNode* SListFind(SListNode* pHead, DataType x);
//void SListInsest(SListNode** ppHead, SListNode* pos, DataType x);
//void SListErase(SListNode** ppHead, SListNode* pos);

#pragma once

#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <time.h>

typedef int DataType;

typedef struct ListNode
{
	DataType _data;
	struct ListNode* _pNext;
}ListNode;

ListNode *BuyListNode(DataType data);
void ListDestory(ListNode** ppHead);
void ListPrint(ListNode* pHead);

void ListPushBack(ListNode** ppHead, DataType data);
void ListPopBack(ListNode* pHead);
void ListPushFront(ListNode** ppHead, DataType data);
ListNode* ListFind(ListNode* pHead, DataType data);
void ListInsert(ListNode** ppHead, ListNode* pos, DataType data);
void ListErase(ListNode** ppHead, ListNode* pos);

ListNode* BuyListNode(DataType data)
{
	ListNode *NewList = (ListNode*)malloc(sizeof(ListNode));
	NewList->_data = data;
	NewList->_pNext = NULL;
	return NewList;
}

void ListDestory(ListNode** ppHead)
{
	ListNode* prev = *ppHead;
	while (*ppHead)
	{
		(*ppHead) = (*ppHead)->_pNext;
		free(prev);
		prev = (*ppHead);
	}
}

void ListPrint(ListNode* pHead)
{
	ListNode* cur = pHead;
	while (cur)
	{
		printf("%d->", cur->_data);
		cur = cur->_pNext;
	}
	printf("NULL\n");
}

void ListPushBack(ListNode** ppHead, DataType data)
{
	ListNode* Head = *ppHead;
	if ((*ppHead) == NULL)
	{
		(*ppHead) = BuyListNode(data);
		return;
	}
	while ((*ppHead)->_pNext != NULL)
	{
		(*ppHead) = (*ppHead)->_pNext;
	}
	(*ppHead)->_pNext = BuyListNode(data);
	*ppHead = Head;
}

void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead;
	ListNode* prev = pHead;
	if (cur->_pNext == NULL)
	{
		free(cur);
		return;
	}
	while (cur->_pNext != NULL)
	{
		prev = cur;
		cur = cur->_pNext;
	}
	prev->_pNext = NULL;
	free(cur);
}

void ListPushFront(ListNode** ppHead, DataType data)
{
	ListNode* NewList;
	if ((*ppHead) == NULL)
	{
		ListPushBack(ppHead, data);
	}
	NewList = BuyListNode(data);
	NewList->_pNext = (*ppHead);
	(*ppHead) = NewList;
}

ListNode* ListFind(ListNode* pHead, DataType data)
{
	assert(pHead);
	ListNode* cur = pHead;
	while (cur)
	{
		if (cur->_data == data)
		{
			return cur;
		}
		else
		{
			cur = cur->_pNext;
		}
	}
	return NULL;
}

void ListInsert(ListNode** ppHead, ListNode* pos, DataType data)
{
	ListNode* cur = (*ppHead);
	if (pos == (*ppHead))
	{
		ListPushFront(ppHead, data);
		return;
	}
	while (cur->_pNext != pos)
	{
		cur = cur->_pNext;
	}
	cur->_pNext = BuyListNode(data);
	cur->_pNext->_pNext = pos;
}

void ListErase(ListNode** ppHead, ListNode* pos)
{
	assert(ppHead && (*ppHead));
	assert(pos);
	ListNode* cur = (*ppHead);
	if (cur == pos)
	{
		(*ppHead) = (*ppHead)->_pNext;
		free(cur);
		return;
	}
	while (cur->_pNext != pos)
	{
		cur = cur->_pNext;
	}
	cur->_pNext = pos->_pNext;
	free(pos);
}