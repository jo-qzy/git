#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
int main()
{
	char killer = 0;
	for (killer = 'a'; killer <= 'd'; killer++)
		if (3 == (killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd'))
			break;
	printf("killer is %c\n", killer);
	system("pause");
	return 0;
}