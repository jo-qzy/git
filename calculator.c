#define _CRT_SECURE_NO_WARNINGS 1

//ʹ��main�����Ĳ�����ʵ��һ��������������������Խ���������������һ�������� - a��ѡ��ִ�мӷ�
//�� - s��ѡ��ִ�м������� - m��ѡ��ִ�г˷����� - d��ѡ��ִ�г�����������������Ϊ��������
//���磺�����в������룺test.exe - a 1 2
//ִ��1 + 2���3

#include <stdio.h>
#include <windows.h>

int main(int argc, char* argv[])
{
	//int num1 = atoi(argv[2]);//linux�¿���ֱ��д������ʱ���������в���
	//int num2 = atoi(argv[3]);//vs����ôд�ᱨ���ڴ��޷����ʣ�ԭ��ȱʧ�����в���
	if (argc != 4)
	{
		printf("�����������");
		return 0;
	}
	if ((**(argv + 1)) == '-')
	{
		switch (*(*(argv + 1) + 1))//��Ч��*(argv[1] + 1)
		{
		case 'a':
			printf("%d\n", atoi(argv[2]) + atoi(argv[3]));
			break;
		case 's':
			printf("%d\n", atoi(argv[2]) - atoi(argv[3]));
			break;
		case 'm':
			printf("%d\n", atoi(argv[2]) * atoi(argv[3]));
			break;
		case 'd':
			printf("%d\n", atoi(argv[2]) / atoi(argv[3]));
			break;
		default:
			printf("�޴��������������\n");
			break;
		}
	}
	return 0;
}