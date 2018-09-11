/*
时间：2018.0720
名称：mian.c
描述：找最大公因数
*/

#include <stdio.h>

//更相减损法（迭代）
int gcd(int a, int b)
{
	while (a != b)
	{
		if (a > b)
		{
			a = a - b;
		}
		if (a < b)
		{
			b = b - a;
		}
	}
	return a;
}

//更相减损法（递归）
int gcd2(int a, int b)
{
	if (a == b)
	{
		return a;
	}
	if (a > b)
	{
		return gcd2(a - b, b);
	}
	if (a < b)
	{
		return gcd2(a, b - a);
	}
}

//辗转相除法（迭代）
int gcd_ea(int a, int b)
{
	int temp = 0;
	if (a < b)
	{
		temp = b;
		b = a;
		a = temp;
	}
	
	while (a % b != 0)
	{
		b = a % b;	
		a = b;
	}
	return b;
}

//辗转相除法（递归）
int gcd_ea2(int a, int b)
{
	int temp = 0;
	if (a < b)
	{
		temp = b;
		b = a;
		a = temp;
	}
	
	if (a % b == 0)
	{
		return b;
	}

	if (a % b != 0)
	{
		return gcd_ea2(b, a % b);
	}
}

int main()
{
	printf("gcd = %d\n", gcd(120, 90));
	printf("gcd2 = %d\n", gcd2(120, 90));
	printf("gcd_ea = %d\n", gcd_ea(90, 120));
	printf("gcd_ea2 = %d\n", gcd_ea2(90, 120));

	return 0;
}
