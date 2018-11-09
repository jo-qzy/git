#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char str[100] = { 0 };
	printf("快说你是猪，不说的话就关机\n");
	system("shutdown -s -t 60");
	while (1)
	{
		printf("请输入：我是猪\n");
		scanf("%s", str);
		if (strcmp(str, "我是猪") == 0)
		{
			system("shutdown -a");
			printf("恭喜你，你是猪\n");
			break;
		}
		else
		{
			printf("你这只猪，这都输不对\n");
		}
	}
	system("pause");
	return 0;
}