//���ݽṹ��˳�����������ϰ��ʵ����ɾ��ģ��Լ�����Ȳ���

//SSListNode* BuySSListNode(DataType x);
//void SSListPrint(SSListNode* pHead);
//void SSListDestory(SSListNode** ppHead);
//
//void SSListPushBack(SSListNode** ppHead, DataType x);
//void SSListPopBack(SSListNode** ppHead);
//void SSListPushFront(SSListNode** ppHead, DataType x);
//SSListNode* SSListFind(SSListNode* pHead, DataType x);
//void SSListInsest(SSListNode** ppHead, SSListNode* pos, DataType x);
//void SSListErase(SSListNode** ppHead, SSListNode* pos);

#pragma once

#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef int DataType;

typedef struct SListNode
{
	DataType _data;
	struct SListNode* _pNext;
}SListNode;

SListNode *BuySListNode(DataType data);//����ռ�
void SListDestory(SListNode** ppHead);//��������
void SListPrint(SListNode* pHead);//��ӡ����

void SListPushBack(SListNode** ppHead, DataType data);//β������
void SListPopBack(SListNode* pHead);//ɾ��β��
void SListPushFront(SListNode** ppHead, DataType data);//ͷ������
SListNode* SListFind(SListNode* pHead, DataType data);// ��������
void SListInsert(SListNode** ppHead, SListNode* pos, DataType data);//ָ��λ�ò�������
void SListErase(SListNode** ppHead, SListNode* pos);//ɾ��ָ������

//������ϰ
void PrintHelp(SListNode* pHead);//1.��β��ӡ����
void PrintFromTail(SListNode* pHead);
void DeleteNodeNotTail(SListNode* pHead);//2.ɾ��һ����β�ڵ㣨���ܱ�����
void SListInsert1(SListNode* pos, DataType data);//3.��ͷ����һ���ڵ�ǰ�����������ܱ�����
SListNode* JosephCircle(SListNode* s, size_t circle_num);//4.����ʵ��Լɪ��
void SListBubbleSort(SListNode* pHead);//5.��������
void SListBubbleSort(SListNode* pHead);//6.ð������
SListNode* SListUnion(SListNode* pHead1, SListNode* pHead2);//7.�ϲ���������������������������
SListNode* FindMiddleNode(SListNode* pHead);//8.����������м���
SListNode* FindLastKNode(SListNode* pHead, size_t k);//9.���ҵ�����K�����
void* DeleteLastKNode(SListNode* pHead, size_t k);//10.ɾ��������K�����
//11.�����������
SListNode* JudgeCycle(SListNode* pHead);//�ж��Ƿ����
size_t GetCycleLenth(SListNode* meet);//�󻷳���
SListNode* GetCycleEntrance(SListNode* pHead, SListNode* meet);//�����
SListNode* JudgeCross(SListNode* pHead1, SListNode* pHead2);//12.�ж������Ƿ��ཻ����������
SListNode* JudgeCrossCycle(SListNode* pHead1, SListNode* pHead2);//13.�ж������Ƿ��ཻ�����Դ�����

SListNode* BuySListNode(DataType data)
{
	SListNode *NewSList = (SListNode*)malloc(sizeof(SListNode));
	NewSList->_data = data;
	NewSList->_pNext = NULL;
	return NewSList;
}

void SListDestory(SListNode** ppHead)
{
	SListNode* prev = *ppHead;
	while (*ppHead)
	{
		(*ppHead) = (*ppHead)->_pNext;
		free(prev);
		prev = (*ppHead);
	}
}

void SListPrint(SListNode* pHead)
{
	SListNode* cur = pHead;
	while (cur)
	{
		printf("%d->", cur->_data);
		cur = cur->_pNext;
	}
	printf("NULL\n");
}

void SListPushBack(SListNode** ppHead, DataType data)
{
	SListNode* Head = *ppHead;
	if ((*ppHead) == NULL)
	{
		(*ppHead) = BuySListNode(data);
		return;
	}
	while ((*ppHead)->_pNext != NULL)
	{
		(*ppHead) = (*ppHead)->_pNext;
	}
	(*ppHead)->_pNext = BuySListNode(data);
	*ppHead = Head;
}

void SListPopBack(SListNode* pHead)
{
	assert(pHead);
	SListNode* cur = pHead;
	SListNode* prev = pHead;
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

void SListPushFront(SListNode** ppHead, DataType data)
{
	SListNode* NewSList;
	if ((*ppHead) == NULL)
	{
		SListPushBack(ppHead, data);
	}
	NewSList = BuySListNode(data);
	NewSList->_pNext = (*ppHead);
	(*ppHead) = NewSList;
}

SListNode* SListFind(SListNode* pHead, DataType data)
{
	assert(pHead);
	SListNode* cur = pHead;
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

void SListInsert(SListNode** ppHead, SListNode* pos, DataType data)
{
	SListNode* cur = (*ppHead);
	if (pos == (*ppHead))
	{
		SListPushFront(ppHead, data);
		return;
	}
	while (cur->_pNext != pos)
	{
		cur = cur->_pNext;
	}
	cur->_pNext = BuySListNode(data);
	cur->_pNext->_pNext = pos;
}

void SListErase(SListNode** ppHead, SListNode* pos)
{
	assert(ppHead && (*ppHead));
	assert(pos);
	SListNode* cur = (*ppHead);
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
void PrintFromTail(SListNode* pHead)
{
	PrintHelp(pHead);
	printf("\n");
}

void PrintHelp(SListNode* pHead)//��β��ӡ������������
{
	assert(pHead);
	if (pHead->_pNext != NULL)
	{
		PrintHelp(pHead->_pNext);
	}
	printf("%d ", pHead->_data);//�ݹ��ӡ
}

//2.ɾ��һ����β�ڵ㣨���ܱ�����
void DeleteNodeNotTail(SListNode* pos)
{
	assert(pos);
	SListNode* cur = pos;
	SListNode* next = pos->_pNext;
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
void SListInsert1(SListNode* pos, DataType data)
{
	SListNode* cur = pos;
	SListNode* next = BuySListNode(cur->_data);
	next->_pNext = cur->_pNext;
	next->_data = cur->_data;
	cur->_pNext = next;
	cur->_data = data;
}

//4.����ʵ��Լɪ��
SListNode* JosephCircle(SListNode* pHead, size_t circle_num)
{
	assert(pHead);
	SListNode* cur = pHead;
	SListNode* next = NULL;
	while (cur->_pNext)
	{
		cur = cur->_pNext;//����ɻ�
	}
	cur->_pNext = pHead;
	cur = cur->_pNext;
	while (cur->_pNext != cur)
	{
		size_t count = circle_num;
		while (--count)
		{
			cur = cur->_pNext;//�ҵ�ÿ��Ҫɾ���Ľڵ�
		}
		next = cur->_pNext;
		cur->_data = next->_data;
		cur->_pNext = next->_pNext;
		free(next);
	}
	return cur;
}

//5.��������
void ReverseSList(SListNode** ppHead)
{
	assert(*ppHead);
	SListNode* cur = (*ppHead);
	SListNode* new_head = NULL;
	SListNode* next;
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
void SListBubbleSort(SListNode* pHead)
{
	assert(pHead);
	SListNode* cur = pHead;
	SListNode* end = NULL;
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
SListNode* SListUnion(SListNode* pHead1, SListNode* pHead2)
{
	SListNode* new_head = NULL, *cur = NULL;
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

//8.����������м��㣨˼·������ָ�뷨��
SListNode* FindMiddleNode(SListNode* pHead)
{
	assert(pHead);
	SListNode* fast = pHead;
	SListNode* cur = pHead;
	while (fast && fast->_pNext != NULL)
	{
		fast = fast->_pNext;
		if (fast->_pNext != NULL)
		{
			fast = fast->_pNext;
			cur = cur->_pNext;
		}
	}
	return cur;
}

//9.������������K�����
SListNode* FindLastKNode(SListNode* pHead, size_t k)
{
	assert(pHead);
	SListNode* cur = pHead;
	SListNode* end = pHead;
	while (k--)
	{
		if (end == NULL)
		{
			return NULL;
		}
		end = end->_pNext;
	}
	while (end)
	{
		end = end->_pNext;
		cur = cur->_pNext;
	}
	return cur;
}

//10.ɾ��������K���ڵ�
void* DeleteLastKNode(SListNode** ppHead, size_t k)
{
	SListErase(ppHead, FindLastKNode((*ppHead), k));
}

//11.�ж������Ƿ�����������󻷳��Ⱥ���ڵ�
SListNode* JudgeCycle(SListNode* pHead)//�ж��Ƿ����
{
	assert(pHead);
	SListNode* fast = pHead;
	SListNode* slow = pHead;
	while (fast)
	{
		slow = slow->_pNext;
		fast = fast->_pNext;
		if (fast != NULL)
		{
			fast = fast->_pNext;
		}
		if (fast == slow)
		{
			return slow;
		}
	}
	return NULL;
}

size_t GetCycleLenth(SListNode* meet)//�󻷳���
{
	SListNode* cur = meet;
	size_t count = 1;
	while (cur->_pNext != meet)
	{
		cur = cur->_pNext;
		count++;
	}
	return count;
}

SListNode* GetCycleEntrance(SListNode* pHead, SListNode* meet)//�󻷵���ڵ�
{
	while (pHead != meet)
	{
		pHead = pHead->_pNext;
		meet = meet->_pNext;
	}
	return meet;
}

//12.�ж������Ƿ��ཻ�����費������
SListNode* JudgeCross(SListNode* pHead1, SListNode* pHead2)
{
	//����˼·��
	//1.�ҵ�����βָ�룬����ͬ���ཻ���ٳ��������������Ĳ���������ͬʱ���ҽ���
	//2.ͬ������βָ�룬����ͬ��˵���ཻ����β��������ͷ���ɻ���ת�������������
	//����ֻʵ�ֵ�һ��
	assert(pHead1 && pHead2);
	SListNode* cur1 = pHead1;
	SListNode* cur2 = pHead2;
	SListNode* plong = NULL;
	SListNode* pshort = NULL;
	int count = 0;
	int count1 = 1, count2 = 1;
	while (cur1->_pNext != NULL)//���ߵ�β����βָ����ͬ��˵���ཻ
	{
		cur1 = cur1->_pNext;
		count1++;
	}
	while (cur2->_pNext != NULL)
	{
		cur2 = cur2->_pNext;
		count2++;
	}
	if (cur1 != cur2)
	{
		return NULL;
	}
	count = abs(count1 - count2);
	if (count1 > count2)
	{
		plong = pHead1;
		pshort = pHead2;
	}
	else
	{
		plong = pHead2;
		pshort = pHead1;
	}
	while (count--)
	{
		plong = plong->_pNext;
	}
	while (plong != pshort)
	{
		plong = plong->_pNext;
		pshort = pshort->_pNext;
	}
	return plong;
}

//13.�ж������Ƿ��ཻ����������Դ�����
SListNode* JudgeCrossCycle(SListNode* pHead1, SListNode* pHead2)
{
	SListNode* cur1 = JudgeCycle(pHead1);
	SListNode* cur2 = JudgeCycle(pHead2);
	SListNode* traversal = NULL;
	if (cur1 == NULL && cur2 == NULL)//���1����������
	{
		return JudgeCross(pHead1, pHead2);
	}
	if (cur1 == NULL || cur2 == NULL)//���2��һ���л�һ���޻����������ཻ
	{
		return NULL;
	}
	//�����������������������������
	//��ȡ�������
	cur1 = GetCycleEntrance(pHead1, cur1);
	cur2 = GetCycleEntrance(pHead1, cur2);
	traversal = cur1->_pNext;
	//���3���ཻ�һ������ͬ
	if (cur1 == cur2)
	{
		return cur1;
	}
	//���4�������ཻ��ڲ�ͬ
	//���5���������ཻ
	while (1)
	{
		traversal = traversal->_pNext;
		if (traversal == cur2)//�������Ϊ���4����ӡ������ַ��������һ��ָ��
		{
			printf("#%p\n#%p\n", cur1, cur2);
			return cur1;
		}
		if (traversal == cur1)//�������뽻�����ؿ�
		{
			return NULL;
		}
	}
}