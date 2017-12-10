#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

char * ReverseString(char arr[]);

int main()
{
	char arr[] = "I am a stdudent.";
	printf("Ô­×Ö·û´®:%s\n", arr);
	printf("Äæ×ªºó:%s\n", ReverseString(arr));
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