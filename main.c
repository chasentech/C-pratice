#include <stdio.h>

int add(int a, int b)
{
	return a + b;
}

int g_SUM = 0;

int main()
{
	printf("Hello\n");
	printf("sum = %d\n", add(8, 9));
	return 0;
}
