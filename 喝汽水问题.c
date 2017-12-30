#define _CRT_SECURE_NO_WARNINGS 1

//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水。编程实现

#include <stdio.h>
#include <Windows.h>

int extra = 0;

int DrinkSoda(int money);


int main()
{
	int money = 20;
	int price = 1;
	printf("%d\n", DrinkSoda(money,price));
	system("pause");
	return 0;
}

int DrinkSoda(int money,int price)
{
	int count = money / 1;//这里一元一瓶，改成多少一瓶都ok
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
	if (bottle & 1)//如果瓶子为奇数
	{
		return bottle - 1 + BottleForDrink((bottle >> 1) + 1);
	}
	else
	{
		return bottle + BottleForDrink(bottle >> 1);
	}
}