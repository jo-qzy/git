#define _CRT_SECURE_NO_WARNINGS 1

//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ�����ʵ��

#include <stdio.h>
#include <Windows.h>

int extra = 0;

int DrinkSoda1(int money, int price);
int DrinkSoda2(int money, int price);

int main()
{
	int money = 20;
	int price = 1;
	printf("%d\n", DrinkSoda1(money, price));
	printf("%d\n", DrinkSoda2(money,price));
	system("pause");
	return 0;
}

//����1���ǵݹ��㷨
int DrinkSoda1(int money, int price)
{
	int bottle = money / price;
	int sum = bottle;
	while (bottle != 1)
	{
		sum = sum + bottle / 2;
		if (bottle % 2 == 1)
		{
			bottle = bottle / 2 + 1;
		}
		else
		{
			bottle = bottle / 2;
		}
	}
	return sum;
}

//����2���ݹ��㷨
int DrinkSoda2(int money,int price)
{
	int count = money / 1;//����һԪһƿ���ĳɶ���һƿ��ok
	if (0 == money)
	{
		return 0;
	}
	else
	{
		return BottleForDrink(count);
	}
}

int BottleForDrink(int bottle)
{
	if (0 == bottle)
	{
		return 0;
	}
	if (1 == bottle)
		return 1;
	if (bottle & 1)//���ƿ��Ϊ����
	{
		return bottle - 1 + BottleForDrink((bottle >> 1) + 1);
	}
	else
	{
		return bottle + BottleForDrink(bottle >> 1);
	}
}