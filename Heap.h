#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <assert.h>

typedef int HeapDataType;

typedef struct Heap
{
	HeapDataType* _a;
	size_t _size;
	size_t _capacity;
}Heap;

void HeapInit(Heap* hp, HeapDataType* a, size_t n);//初始化堆
void HeapMake(Heap* hp);//创建初始堆
void HeapPush(Heap* hp, HeapDataType x);//插入
void HeapPop(Heap* hp);//删除堆顶元素
size_t GetHeapSize(Heap* hp);//堆大小
size_t HeapEmpty(Heap* hp);//堆是否为空
HeapDataType HeapTop(Heap* hp);//返回堆顶元素
void HeapSort(Heap* hp);//堆排序
void HeapAdjustDown(Heap* hp, int root);//堆向上调整
void HeapAdjustUp(Heap* hp, int child);//堆向下调整

void HeapInit(Heap* hp, HeapDataType* a, size_t n)
{
	hp->_a = (HeapDataType*)malloc(sizeof(HeapDataType) * n);
	hp->_size = n;
	hp->_capacity = n;
	memcpy(hp->_a, a, sizeof(HeapDataType) * n);
}

void swap(HeapDataType* x1, HeapDataType* x2)
{
	*x1 ^= *x2;
	*x2 ^= *x1;
	*x1 ^= *x2;
}

void HeapAdjust(Heap* hp, size_t parent, size_t child)
{
	int flag = 0;
	while (child < hp->_size)
	{
		flag = 0;
		if (child + 1 < hp->_size)
		{
			if (*(hp->_a + child) < *(hp->_a + child + 1))
			{
				child = child + 1;
			}
		}
		if (*(hp->_a + parent) < *(hp->_a + child))
		{
			flag = 1;
			swap(hp->_a + parent, hp->_a + child);
		}
		if (!flag)
		{
			break;
		}
		parent = child;
		child = parent * 2 + 1;
	}
}

void HeapMake(Heap* hp)
{
	assert(hp);
	int parent = (int)(hp->_size - 2) / 2;
	int child = parent * 2 + 1;
	for (parent; parent >= 0; parent--)
	{
		child = parent * 2 + 1;
		HeapAdjust(hp, parent, child);
	}
}

static void HeapCapacityCheck(Heap* hp)
{
	assert(hp);
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		hp->_a = realloc(hp->_a, sizeof(HeapDataType)*hp->_capacity);
	}
}

void HeapPush(Heap* hp, HeapDataType x)
{
	assert(hp);
	HeapCapacityCheck(hp);
	*(hp->_a + hp->_size) = x;
	hp->_size++;
	HeapAdjustUp(hp, hp->_size - 1);
}

void HeapPop(Heap* hp)
{
	assert(hp);
	if (hp->_size == 0)
	{
		return;
	}
	*(hp->_a + 0) = *(hp->_a + hp->_size - 1);
	hp->_size--;
	HeapAdjustDown(hp, 0);
}

size_t GetHeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}

size_t HeapEmpty(Heap* hp)//空为0，非空为1
{
	assert(hp);
	if (hp->_size == 0)
	{
		return 0;
	}
	return 1;
}

HeapDataType HeapTop(Heap* hp)
{
	return *(hp->_a + 0);
}

void HeapSort(Heap* hp)
{
	assert(hp);
	int tmp = hp->_size;
	while (hp->_size != 1)
	{
		swap(hp->_a + 0,hp->_a + hp->_size - 1);
		hp->_size--;
		HeapAdjustDown(hp, 0);
	}
	hp->_size = tmp;
}

void HeapAdjustDown(Heap* hp, int root)
{
	assert(hp);
	HeapAdjust(hp, root, root * 2 + 1);
}

void HeapAdjustUp(Heap* hp, int child)
{
	assert(hp && child > 0 && child < hp->_size);
	int parent = (child - 1) / 2;
	while (child != 0)
	{
		HeapAdjust(hp, parent, child);
		child = parent;
		parent = (child - 1) / 2;
	}
}

void HeapPrint(Heap* hp)
{
	assert(hp);
	size_t i = 0;
	for (i; i < (int)hp->_size; i++)
	{
		printf("%d ", *(hp->_a + i));
	}
	printf("\n");
}

void TestHeap()
{
	HeapDataType arr[] = { 53,17,78,9,45,65,87,23,31 };
	Heap hp;
	HeapInit(&hp, arr, sizeof(arr) / sizeof(HeapDataType));
	printf("HeapMake:");
	HeapMake(&hp);
	HeapPrint(&hp);
	printf("HeapPush:");
	HeapPush(&hp, 100);
	HeapPrint(&hp);
	printf("HeapPop:");
	HeapPop(&hp);
	HeapPrint(&hp);
	printf("HeapSize:%d\n", GetHeapSize(&hp));
	printf("HeapTop:%d\n", HeapTop(&hp));
	printf("HeapSort:");
	HeapSort(&hp);
	HeapPrint(&hp);
}