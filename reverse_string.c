//有一个字符数组的内容为:"student a am i"
//请你将数组的内容改为"i am a student". 
//要求： 
//不能使用库函数。
//只能开辟有限个空间（空间个数和字符串的长度无关）。

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>//为了用isspace函数，is space，是空格

char * Search(char arr[]);
void ReverseString(char *head, char *tail);

int main()
{
	char arr[] = "stdudent a am I";//原始字符串
	printf("原字符串:%s\n", arr);
	printf("逆转后:%s\n", Search(arr));
	system("pause");
	return 0;
}

char * Search(char arr[])
{
	assert(arr != '\0');
	char *head, *tail;
	head = arr;
	tail = arr;
	while (*tail != '\0')
	{
		if (isspace(*tail))//先逆转每个单词
		{
			ReverseString(head, tail - 1);
			head = tail + 1;//头指针要指向单词首位
		}
		tail++;
	}
	ReverseString(arr, tail - 1);//逆转整个句子
	return arr;
}

void ReverseString(char *head, char *tail)
{
	char tmp = 0;
	while (tail - head > 0)//真正的交换操作
	{
		tmp = *tail;
		*tail = *head;
		*head = tmp;
		head++;
		tail--;
	}
}