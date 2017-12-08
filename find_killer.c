#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
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