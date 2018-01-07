#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include <search.h>
#include <stdlib.h>
#include <assert.h>

int int_cmp(const void* elem1, const void* elem2);
void my_sort(void* base, size_t count, size_t size, int(*cmmp)(const void* elem1, const void* elem2));
void swap(void* data1, void* data2, size_t size);

int main()
{
	int i = 0;
	int arr[] = { 9,5,6,7,8,1,3,6,4,3 };
	int size = sizeof(arr) / sizeof(arr[0]);
	my_sort(arr, size, sizeof(int), int_cmp);
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}

void my_sort(void* base, size_t count, size_t size, int(*cmmp)(const void* elem1, const void* elem2))
{
	unsigned int i = 0;
	while (count--)
	{
		for (i = 0; i < count; i++)
		{
			if (int_cmp((char*)base + size * i, (char*)base + (size + 1) * i))
			{
				swap((char*)base + size * i, (char*)base + (size + 1) * i, size);
			}
		}
	}
}

void swap(void* data1, void* data2, size_t size)
{
	char* p1 = (char*)data1;
	char* p2 = (char*)data2;
	while (size--)
	{
		char tmp = 0;
		tmp = *(char*)data1;
		*(char*)data1 = *(char*)data2;
		*(char*)data2 = tmp;
		(char*)data1 = (char*)data1 + 1;
		(char*)data2 = (char*)data1 + 1;
	}
}

int int_cmp(const void* elem1, const void* elem2)
{
	return *(int*)elem1 > *(int*)elem2;
}