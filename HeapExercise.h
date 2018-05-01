#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <assert.h>

//�ѵ�Ӧ��
//1.TopK����
//˼·�ǽ�һ��K��Ԫ�ص�С�ѣ���ʮ���ڸ�Ԫ�ص�ǰʮ��Ԫ�ص�����ʼ�Ѵ���
//���ֻ���ҳ�10���ڸ�Ԫ������������һ����������Ҫ��ϸ˼��Ϊʲô��С��
//��С���ҵ���󣬶���ʮ��Ԫ�رض�������Ԫ��������
void GetTopK(int* a, int size, int K);//TopK����
void AdjustDown(int* heap, int size, int parent);
void TestTopK();//��������

void GetTopK(int* a, int size, int K)//TopK����
{
	int* heap = (int*)malloc(sizeof(int) * K);
	memcpy(heap, a, sizeof(int) * K);
	//����
	for (int i = (K - 2) / 2; i >= 0; i--)
	{
		AdjustDown(heap, K, i);
	}
	//�ӵ�K+1��Ԫ�ؿ�ʼ��ȡ��������ݣ��ȶѶ�����滻�Ѷ�Ԫ��
	for (int i = K; i < size; i++)
	{
		if (*(a + i) > *heap)
		{
			*heap = *(a + i);
			AdjustDown(heap, K, 0);
		}
	}
	for (int i = 0; i < K; i++)
	{
		printf("%d ", *(heap + i));
	}
	printf("\n");
}

void AdjustDown(int* heap, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size)
		{
			if (*(heap + child) > *(heap + child + 1))
			{
				child += 1;
			}
		}
		if (*(heap + parent) > *(heap + child))
		{
			Swap(heap + parent, heap + child);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void TestTopK()
{
	int arr[] = { 53,17,78,9,45,65,87,23,31 };
	GetTopK(arr, sizeof(arr) / sizeof(arr[0]), 3);
}

//2.���ȼ����е�ʵ��
//ʵ�ַ�ʽ���ѵ���һ��Ӧ�ö��ѣ����������Ƕѣ����˸����ֶ���
#define _SIZE 5

typedef int PQueueDataType;

typedef struct PriorityQueue
{
	int* _a;
	int _size;
	int _capacity;
}PQueue;

PQueue* PQueueInit();
void PQueuePush(PQueue* q, PQueueDataType data);
void PQueueAdjustUp(PQueue* q, int child);
void PQueueAdjustDown(PQueue* q, int parent);
void PQueuePush(PQueue* q, PQueueDataType data);
void PQueuePop(PQueue* q);
PQueueDataType PQueueTop(PQueue* q);
void PQueueDestroy(PQueue* q);

void TestPQueue();//��������

PQueue* PQueueInit()
{
	PQueue* q = (PQueue*)malloc(sizeof(PQueue));
	q->_capacity = _SIZE;
	q->_size = 0;
	q->_a = (PQueueDataType*)malloc(sizeof(PQueueDataType) * q->_capacity);
	return q;
}

void PQueueCheckCapacity(PQueue* q)
{
	assert(q);
	if (q->_size == q->_capacity)
	{
		q->_capacity *= 2;
		q->_a = realloc(q->_a, sizeof(PQueueDataType) * q->_capacity);
		assert(q->_a);
	}
}

void PQueueSwap(PQueueDataType* data1, PQueueDataType* data2)
{
	assert(data1 && data2);
	*(data1) ^= *(data2);
	*(data2) ^= *(data1);
	*(data1) ^= *(data2);
}

void PQueueAdjustUp(PQueue* q, int child)
{
	assert(q);
	PQueueDataType parent = (child - 1) / 2;
	while (child)
	{
		if (*(q->_a + parent) < *(q->_a + child))
		{
			PQueueSwap(q->_a + parent, q->_a + child);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void PQueueAdjustDown(PQueue* q, int parent)
{
	assert(q);
	int child = parent * 2 + 1;
	while (child < q->_size)
	{
		if (child + 1 < q->_size)
		{
			if (*(q->_a + child) < *(q->_a + child + 1))
			{
				child += 1;
			}
		}
		if (*(q->_a + parent) < *(q->_a + child))
		{
			PQueueSwap(q->_a + parent, q->_a + child);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void PQueuePush(PQueue* q, PQueueDataType data)
{
	assert(q);
	PQueueCheckCapacity(q);
	*(q->_a + q->_size) = data;
	q->_size++;
	PQueueAdjustUp(q, q->_size - 1);
}

void PQueuePop(PQueue* q)
{
	assert(q);
	*(q->_a + 0) = *(q->_a + q->_size - 1);
	q->_size--;
	PQueueAdjustDown(q, 0);
}

PQueueDataType PQueueTop(PQueue* q)
{
	assert(q && (q->_size > 0));
	return *(q->_a + 0);
}

void PQueueDestroy(PQueue* q)
{
	assert(q);
	free(q->_a);
	free(q);
}

void TestPQueue()
{
	PQueueDataType arr[] = { 53,17,78,9,45,65,87,23,31 };
	PQueue* pq = PQueueInit();
	printf("����в��ԣ�");
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		PQueuePush(pq, arr[i]);
	}
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", *(pq->_a + i));
	}
	printf("\n");
	printf("�����в���:");
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", PQueueTop(pq));
		PQueuePop(pq);
	}
	printf("\n");
	PQueueDestroy(pq);
}