#include <stdio.h>

//递归求阶乘
int my_pow(int n)
{
	int result = 0;
	if (n == 0)
	{
		return 1;
	}
	else
	{
		result = n * my_pow(n - 1);
		return result;
	}
}

//迭代fibonacci数列
int fbnc(int n)
{
	int n_0 = 0;
	int n_1 = 1;
	int i = 0;
	int result = 0;
	
	if (n == 0 || n == 1)
	{
		return n;
	}
	
	for (i = 2; i <= n; i++)
	{
		result = n_0 + n_1;
		n_0 = n_1;
		n_1 = result;
	}
	return result;
}


//递归fibonacci数列
int fbnc2(int n)
{
	int result = 0;
	
	if (n == 0 || n == 1)
	{
		return n;
	}
	else
	{
		result = fbnc2(n - 1) + fbnc2(n - 2);
		return result;
	}
}

void hano(int n, char src, char dst, char tmp)
{
	if (n == 1)
	{
		printf("move No.%d from %c to %c\n", n, src, dst);
		return;
	}
	else
	{
		hano(n - 1, src, tmp, dst);
		printf("move No.%d from %c to %c\n", n, src, dst);
		hano(n - 1, tmp, dst, src);
	}
}

int main()
{
	int a = 0;
	int i = 0;
	a = my_pow(6);
	
	printf("6! = %d\n", a);
	
	for (i = 0; i < 10; i++)
	{
		printf("%10d%10d\n", fbnc(i), fbnc2(i));
	}
	
	hano(4, 'A', 'B', 'C');
	
	return 0;
}
