#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char str[100] = { 0 };
	printf("��˵��������˵�Ļ��͹ػ�\n");
	system("shutdown -s -t 60");
	while (1)
	{
		printf("�����룺������\n");
		scanf("%s", str);
		if (strcmp(str, "������") == 0)
		{
			system("shutdown -a");
			printf("��ϲ�㣬������\n");
			break;
		}
		else
		{
			printf("����ֻ���ⶼ�䲻��\n");
		}
	}
	system("pause");
	return 0;
}