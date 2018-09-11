#include <stdio.h>

//倒序打印每一位
void printf_array(int *a, int n)
{
	int i = 0;
	for (i = n - 1; i >= 0; i--)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//字符串转整形数
int my_atoi(char *p)
{
	int sign = 1;
	int result = 0;
	int temp = 0;

	while ( *p != '\0' )
	{
		if (*p == '-')
		{
			sign = -sign;
		}
		if (*p >= '1' && *p <= '9' && *p != ' ')
		{
			temp = sign * (*p - '0'); 
			result = result * 10 + temp;
		}
		p++;
	}
	return result;
}

int main()
{
	int a[200] = {1};//a[0] = 1
	int temp = 0;
	int count = 1;	//记位数
	int num = 0;	//进位

	int i = 0;
	int j = 0;	
	
	int n = 0;
	char buf[10] = {0};
	printf("Please input number(< 9 digit):");
	fgets(buf, 10, stdin);	//从终端读入数据
	
	int len = my_strlen(buf);
	buf[len - 1] = '\0';
	
	n = my_atoi(buf);
	printf("%d\n", n);
	
	if (n <= 0)
		return 0;
	
	//计算阶乘
	for (i = 1; i <= n; i++)
	{
		temp = 0;
		for (j = 0; j < count; j++)
		{
			temp = a[j] * i + num;	//每一位乘以i
			a[j] = temp % 10;	//每次存储最后一位
			num = temp / 10;
		}
		
		while (num != 0)	//继续存储
		{
			a[count] = num % 10;
			num /= 10;
			count++;
		}
	}
	printf_array(a, count);

	return 0;
}
