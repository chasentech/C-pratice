/*
时间：2018.07.24
描述：位操作相关函数实现
*/
#include <stdio.h>

//打印二进制数（正序）
void print_bit(unsigned int x)
{
	unsigned int mask = 0x80000000;
	int i = 32;
	unsigned int temp = 0;
	
	while (i--)
	{
		temp = x & mask;
/*
		if (temp == 0)
			printf("0");
		else
			printf("1");
		
		if (i % 4 == 0)
			printf(" ");
*/
		
		if (temp == 0)
		{
			printf("0");
		}
		else
		{
			printf("1");
		}
		
		if (i % 4 == 0)
		{
			printf(" ");
		}
		

		x <<= 1;
	}
	printf("\n");
}

/*
//二进制数循环右移
unsigned int cror(unsigned int x, int n)
{
	int i = 0;
	
	for (i = 0; i < n; i++)
	{
		x = (x >> 1) + ((x & 0x01) << 31); 		
	}
	
	return x;
}

//二进制数循环左移
unsigned int crol(unsigned int x, int n)
{
	int i = 0;
	
	for (i = 0; i < n; i++)
	{
		x = (x << 1) + ((x & 0x80000000) >> 31); 		
	}
	
	return x;
}
*/

unsigned int ror(unsigned int x, int n)
{
	int i = 0;
	
	//负数%
	while (n < 0)
	{
		n += 32;
	}
	n = n % 32;
	
	for (i = 0; i < n; i++)
	{
		x = (x >> 1) + (x << 31);
	}
	
	return x;
}

unsigned int ror2(unsigned int x, int n)
{
	int i = 0;
	
	//负数%
	while (n < 0)
	{
		n += 32;
	}
	n = n % 32;
	
	return (x >> n) & ~(~0u << (32 - n));
}

//统计一个字节中被置1的个数（练习1）
int count_bit_1(unsigned char x)
{
	int total = 0;
	unsigned int mask = 0x01;
	
	while (x > 0)
	{
		/*if (x & mask)
		{
			total++;
		}*/
		
		total += x & mask;
		
		x >>= 1;
	}
	return total;
}

//输出从p1到p2的二进制表示（练习2）
unsigned int fun2(unsigned int x, int p1, int p2)
{
	if (p1 > p2 || p2 > 32)
	{
		return -1;
	}

	unsigned int dst = 0;
	
	dst = (x >> p1) & ~(~0u << (p2 - p1));
	
	return dst;
}

//输出从p1到p2的二进制取反表示（练习3）
unsigned int fun3(unsigned int x, int p1, int p2)
{
	if (p1 > p2 || p2 > 32)
	{
		return -1;
	}

	unsigned int dst = 0;
	
	dst = (~x >> p1) & ~(~0u << (p2 - p1));
	
	return dst;
}

//将x的第p位置改为v（练习4）
unsigned int fun4(unsigned int x, int p, int v)
{
	unsigned int temp = 0x00000001 << p;
	
	if (v == 1)
	{
		x |= temp;
	}
	else
	{
		x &= ~temp;
	}
	
	return x;
}

//一种加密算法，中间位等于相邻两边位异或（练习5）
unsigned int fun5(unsigned int x)
{
	unsigned int dst = 0;

	dst = ror(x, 1) ^ ror(x, -1);
	
	return dst;
}


int main()
{
	print_bit(0xabcdedde);	
	print_bit(ror(0xabcdedde, 33));
	print_bit(ror2(0xabcdedde, 33));
	
	
	printf("%d\n", count_bit_1(0xf2));
	
	unsigned int x_2 = 0xf3;
	print_bit(x_2);
	x_2 = fun2(x_2, 2, 6);
	print_bit(x_2);
	printf("\n");
	
	unsigned int x_3 = 0xf3;
	print_bit(x_3);
	x_3 = fun3(x_3, 2, 6);
	print_bit(x_3);
	printf("\n");
	
	unsigned int x_4 = 0xffedabcd;
	print_bit(x_4);
	x_4 = fun4(x_4, 1, 1);
	print_bit(x_4);
	printf("\n");
	
	unsigned int x_5 = 0xffedabcd;
	print_bit(x_5);
	x_5 = fun5(x_5);
	print_bit(x_5);	
	printf("\n");

		
	return 0;
}
