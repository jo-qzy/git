#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//Aѡ��˵��B�ڶ����ҵ�����
//Bѡ��˵���ҵڶ���E���ģ�
//Cѡ��˵���ҵ�һ��D�ڶ���
//Dѡ��˵��C����ҵ�����
//Eѡ��˵���ҵ��ģ�A��һ��
int main()
{
	int A = 0, B = 0, C = 0, D = 0, E = 0;
	for (A = 1; A < 5; A++)
		for (B = 1; B < 5; B++)
			for (C = 1; C < 5; C++)
				for (D = 1; D < 5; D++)
					for (E = 1; E < 5; E++)
					{
						if ((B == 2) + (A == 3) == 1)
							if ((B == 2) + (E == 4) == 1)
								if ((C == 1) + (D == 2) == 1)
									if ((C == 5) + (D == 3) == 1)
										if ((E == 4) + (A == 1) == 1)
										{
											int flag = 0;//��flag���������Ƿ���ȷ
											flag |= 1 << (A - 1);
											flag |= 1 << (B - 1);//��ÿ��ѡ�ֵı���λ������flag��1Ϊ������
											flag |= 1 << (C - 1);//0Ϊ����������
											flag |= 1 << (D - 1);//��֪��������11011�����м�������ȱ������ǲ����ڵ�
											flag |= 1 << (E - 1);
											while (flag)
											{
												if ((flag & 1) == 0)//�����λ��1��Ϊ0,����ѭ��
													break;
												flag >>= 1;
											}
											if (flag == 0)
												printf("A:��%d B:��%d C:��%d D:��%d E:��%d\n", A, B, C, D, E);
										}
					}
	system("pause");
	return 0;
}