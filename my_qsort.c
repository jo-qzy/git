#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include <search.h>
#include <stdlib.h>
#include <assert.h>

int int_cmp(const void* elem1, const void* elem2);
void my_sort(void* base, size_t count, size_t size, int(*cmp)(const void* elem1, const void* elem2));
void swap(void* data1, void* data2, size_t size);

int main()
{
	int i = 0;
	int arr[] = { 9,5,6,7,8,1,3,6,4,3 };
	int size = sizeof(arr) / sizeof(arr[0]);
	//qsort(arr, size, sizeof(int), int_cmp);
	my_sort(arr, size, sizeof(int), int_cmp);//使用和qosrt一样的参数
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}

void my_sort(void* base, size_t count, size_t size, int(*cmp)(const void* elem1, const void* elem2))
{
	assert(base);//传入参数要确保base和cmp不为空
	assert(cmp);
	unsigned int i = 0;
	while ((count--) - 1)//冒泡排序，count个参数就排序count-1
	{
		for (i = 0; i < count; i++)
		{
			if (cmp((char*)base + size * i, (char*)base + (i + 1) * size))//比较函数，需要用户做自己编写
			{
				swap((char*)base + size * i, (char*)base + (i + 1) * size, size);//交换函数
			}
		}
	}
}

static void swap(void* data1, void* data2, size_t size)//修改该函数的链接属性，使他只能在该文件内部使用
{
	int  i = 0;
	while(size--)//按字节交换数据
	{
		char tmp = *(char*)data1;
		*(char*)data1 = *(char*)data2;
		*(char*)data2 = tmp;
		(char*)data1 = (char*)data1 + 1;
		(char*)data2 = (char*)data2 + 1;
	}
}

int int_cmp(const void* elem1, const void* elem2)//自行编写比较函数
{
	return *(int*)elem1 > *(int*)elem2;
}

int float_cmp(const void* elem1, const void* elem2)
{
	return *(float*)elem1 > *(float*)elem2;
}

int str_cmp(const void* elem1, const void* elem2)
{
	return strcmp((char*)elem1 ,(char*)elem2);
}