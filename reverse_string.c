//有一个字符数组的内容为:"student a am i"
//请你将数组的内容改为"i am a student". 
//要求： 
//不能使用库函数。
//只能开辟有限个空间（空间个数和字符串的长度无关）。

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

char * ReverseString(char arr[]);

int main()
{
	char arr[] = "I am a stdudent.";
	printf("原字符串:%s\n", arr);
	printf("逆转后:%s\n", ReverseString(arr));
	system("pause");
	return 0;
}

char * ReverseString(char arr[])
{
	char *head,*tail;
	char tmp = 0;
	head = arr;
	tail = arr;
	while (*tail != '\0')
	{
		tail++;
	}
	tail--;
	while (tail - head > 0)
	{
		tmp = *tail;
		*tail = *head;
		*head = tmp;
		head++;
		tail--;
	}
	return arr;
}