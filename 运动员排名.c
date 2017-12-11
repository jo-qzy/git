#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
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
											int flag = 0;//用flag来看排名是否正确
											flag |= 1 << (A - 1);
											flag |= 1 << (B - 1);//将每个选手的比特位来赋给flag，1为有排名
											flag |= 1 << (C - 1);//0为此排名无人
											flag |= 1 << (D - 1);//可知排名序列11011这种中间排名空缺的情况是不存在的
											flag |= 1 << (E - 1);
											while (flag)
											{
												if ((flag & 1) == 0)//如果该位和1与为0,跳出循环
													break;
												flag >>= 1;
											}
											if (flag == 0)
												printf("A:第%d B:第%d C:第%d D:第%d E:第%d\n", A, B, C, D, E);
										}
					}
	system("pause");
	return 0;
}