#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <Windows.h>

void OutputSnakeNum(int N);

int main()
{
	int N = 0;
	scanf("%d", &N);
	OutputSnakeNum(N);
	system("pause");
	return 0;
}

void OutputSnakeNum(int N)
{
	int i = 0, j = 0;
	int row = 1, col = 1;
	int row_first = 1;//??
	int count_row = 0;//??
	int count_col = 0;
	for (i = 1; i <= N; i++)
	{
		row = row_first + count_col;//??
		row_first = row;
		count_col++;//????
		count_row = i + 1;
		for (j = 1; j <= N - i + 1; j++)
		{
			printf("%d ", row);
			row = row + count_row;
			count_row++;
		}
		printf("\n");
	}
}