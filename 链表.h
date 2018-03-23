//���ݽṹ��˳�����������ϰ��ʵ����ɾ��ģ��Լ�����Ȳ���

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

ListNode *BuyListNode(DataType data);//����ռ�
void ListDestory(ListNode** ppHead);//��������
void ListPrint(ListNode* pHead);//��ӡ����

void ListPushBack(ListNode** ppHead, DataType data);//β������
void ListPopBack(ListNode* pHead);//ɾ��β��
void ListPushFront(ListNode** ppHead, DataType data);//ͷ������
ListNode* ListFind(ListNode* pHead, DataType data);// ��������
void ListInsert(ListNode** ppHead, ListNode* pos, DataType data);//ָ��λ�ò�������
void ListErase(ListNode** ppHead, ListNode* pos);//ɾ��ָ������

//������ϰ
void PrintHelp(ListNode* pHead);//1.��β��ӡ����
void PrintFromTail(ListNode* pHead);
void DeleteNodeNotTail(ListNode* pHead);//2.ɾ��һ����β�ڵ㣨���ܱ�����
void ListInsert1(ListNode* pos, DataType data);//3.��ͷ����һ���ڵ�ǰ�����������ܱ�����
ListNode* JosephCircle(ListNode* s, size_t circle_num);//4.����ʵ��Լɪ��
void ListBubbleSort(ListNode* pHead);//5.��������
ListNode* ListUnion(ListNode* pHead1, ListNode* pHead2);//6.�ϲ���������������������������

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



//������ϰ
//1.��β��ӡ����
void PrintFromTail(ListNode* pHead)
{
	PrintHelp(pHead);
	printf("\n");
}

void PrintHelp(ListNode* pHead)//��β��ӡ������������
{
	assert(pHead);
	if (pHead->_pNext != NULL)
	{
		PrintHelp(pHead->_pNext);
	}
	printf("%d ", pHead->_data);//�ݹ��ӡ
}

//2.ɾ��һ����β�ڵ㣨���ܱ�����
void DeleteNodeNotTail(ListNode* pos)
{
	assert(pos);
	ListNode* cur = pos;
	ListNode* next = pos->_pNext;
	if (cur->_pNext == NULL)
	{
		printf("The node is tail.\n");
		return;
	}
	cur->_data = next->_data;//����һ�ڵ������ǰ�ƣ�����תΪɾ����һ���ڵ�
	if (next->_pNext != NULL)
	{
		cur->_pNext = next->_pNext;
	}
	else
	{
		cur->_pNext = NULL;
	}
	free(next);
}

//3.��ͷ����һ���ڵ�ǰ�����������ܱ�����
void ListInsert1(ListNode* pos, DataType data)
{
	ListNode* cur = pos;
	ListNode* next = BuyListNode(cur->_data);
	next->_pNext = cur->_pNext;
	next->_data = cur->_data;
	cur->_pNext = next;
	cur->_data = data;
}

//4.����ʵ��Լɪ��
ListNode* JosephCircle(ListNode* pHead, size_t circle_num)
{
	assert(pHead);
	ListNode* cur = pHead;
	ListNode* next = NULL;
	while (cur->_pNext)
	{
		cur = cur->_pNext;
	}
	cur->_pNext = pHead;
	cur = cur->_pNext;
	while (cur->_pNext != cur)
	{
		size_t count = circle_num;
		while (--count)
		{
			cur = cur->_pNext;
		}
		next = cur->_pNext;
		cur->_data = next->_data;
		cur->_pNext = next->_pNext;
		free(next);
	}
	return cur;
}

//5.��������
void ReverseList(ListNode** ppHead)
{
	assert(*ppHead);
	ListNode* cur = (*ppHead);
	ListNode* new_head = NULL;
	ListNode* next;
	while (cur)
	{
		next = cur->_pNext;
		cur->_pNext = new_head;
		new_head = cur;
		cur = next;
	}
	(*ppHead) = new_head;
}

//6.�����ð������
void ListBubbleSort(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead;
	ListNode* end = NULL;
	while (end != pHead)
	{
		while (cur->_pNext != end)
		{
			if (cur->_data > cur->_pNext->_data)
			{
				cur->_data ^= cur->_pNext->_data;
				cur->_pNext->_data ^= cur->_data;
				cur->_data ^= cur->_pNext->_data;
			}
			cur = cur->_pNext;
		}
		end = cur;
		cur = pHead;
	}
}

//7.˫����ϲ����ϲ����������򣨹鲢����˼�룩
ListNode* ListUnion(ListNode* pHead1, ListNode* pHead2)
{
	ListNode* new_head = NULL, *cur = NULL;
	if (pHead1 == NULL && pHead2 == NULL)
	{
		return NULL;
	}
	if (pHead1 == NULL)
	{
		return pHead2;
	}
	if(pHead2 == NULL)
	{
		return pHead1;
	}
	if (pHead1->_data <= pHead2->_data)
	{
		new_head = pHead1;
		pHead1 = pHead1->_pNext;
	}
	else
	{
		new_head = pHead2;
		pHead2 = pHead2->_pNext;
	}
	cur = new_head;
	while (pHead1 && pHead2)
	{
		if (pHead1->_data <= pHead2->_data)
		{
			cur->_pNext = pHead1;
			pHead1 = pHead1->_pNext;
		}
		else
		{
			cur->_pNext = pHead2;
			pHead2 = pHead2->_pNext;
		}
		cur = cur->_pNext;
	}
	if (pHead1 == NULL)
	{
		cur->_pNext = pHead2;
	}
	else
	{
		cur->_pNext = pHead1;
	}
	return new_head;
}

ListNode* FindMiddleNode(ListNode* pHead)
{

}