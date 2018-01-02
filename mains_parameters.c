#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main(int argc,char* argv[])
{
	int i = 0;
	printf("%d\n", argc);
	for (i = 0; i < argc; i++)
	{
		printf("%s\n", *(argv + i));
	}
	return 0;
}