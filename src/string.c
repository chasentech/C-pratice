#include <stdio.h>
#include <math.h>

void swap(char *a, char *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int my_strlen(const char *str)
{
	int i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return i;
}

char *my_strcpy(const char *src, char *dst)
{
	int i = 0;
	
	for (i = 0; src[i] != '\0'; i++)
	{
		dst[i] = src[i];
	}
	dst[i] = '\0';
	
	return dst;
}

char *my_strncpy(char *src, char *dst, int n)
{
	int i = 0;
	while (i < n && src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	
	dst[i] = '\0';
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}

	return dst;
}

int my_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			break;
		}
		s1++;
		s2++;
	}
	
	if (*s1 > *s2)
		return 1;
	else if (*s1 < *s2)
		return -1;
	else return 0;
}

int my_strncmp(char *s1, char *s2, int n)
{
	int i = 0;
	while (*s1 != '\0' && *s2 != '\0' && i < n - 1)
	{
		if (*s1 != *s2)
		{
			break;
		}
		s1++;
		s2++;
		i++;
	}
	
	if (*s1 > *s2)
		return 1;
	else if (*s1 < *s2)
		return -1;
	else return 0;	
}

char *my_strcat(char *s1, char *s2, char *dst)
{
	char *p_dst = dst;
	int i = 0;
	
	for (i = 0; *s1 != '\0'; i++)
	{
		*dst = *s1;
		s1++;
		dst++;
	}
	
	for (i = 0; *s2 != '\0'; i++)
	{
		*dst = *s2;
		s2++;
		dst++;
	}
	*dst = '\0';
	
	return p_dst;
}

//字符颠倒（迭代）
char *reverse(char *str)
{
	int i = 0;
	int len = my_strlen(str);
	for (i = 0; i < len / 2; i++)
	{
		swap(str + i, str + len - 1 - i);
	}
	return str;
}

//字符颠倒（递归二）
void reverse3(char *start, int len)
{
	if (len <= 1)
	{
		return;
	}
	else
	{
		swap(start, start + len - 1);
		reverse3(++start, len - 2);
	}
}

//I am from Taiyuan
int len_w(char *str)
{
	int i = 0;

	while (str[i] != '\0' && str[i] != ' ')
	{
		i++;
	}
	return i;
}
//I am from Taiyuan
void reverse_r2(char *str, int len)
{
	int n = 0;

	reverse3(str, len);
	while (*str != '\0')
	{
		n = len_w(str);
		reverse3(str, n);
		str = str + n;

		if (*str == ' ')
		{
			str++;
		}
	}
}

//去除字符串空格
char *my_rm_space(char *p)
{
	char *p_out = p;
	char *p_temp = p;

	while (*p != '\0')
	{
		if (*p >= '0' && *p <= '9')
		{
			*p_temp = *p;
			p_temp++;
		}
		p++;
	}
	*p_temp = '\0';

	return p_out;
}

//字符串转整形数
int my_atoi(const char *p)
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

//字符串转浮点数
double my_atof(const char *p)
{
	double result = 0.0;
	int i_count = 0;
	int flag = 0;
	int sign = 1;
	
	while (*p != '\0')
	{
		if (*p == '-')
		{
			sign = -sign;
		}
		if (*p == '.')
		{
			flag = 1;
		}		
		if (*p >= '0' && *p <= '9')
		{
			result = result * 10 + sign * (*p - '0');
			if (flag == 1)
			{
				i_count++;		//小数位数计数
			}
		}
		p++;
	}
	
	result /= pow(10, i_count);
	
	return result;
}

//去除特定字符
char *rm_char(char *p, char x)
{
	char *p_out = p;
	char *p_temp = p;

	while (*p != '\0')
	{
		if (*p != x)
		{
			*p_temp = *p;
			p_temp++;
		}
		p++;
	}
	
	//剩余的部分全部赋值0，前面也有一个没改
	while (*p_temp != '\0')
		*p_temp++ = '\0';

	return p_out;
}

/*
//查找model第一次出现的位置
const char *my_search(const char *src, char *model)
{
	const char *temp1;
	char *temp2;
	int flag = 0;

	while (*src != '\0')
	{
		if (*src == *model)
		{	
			temp1 = src;
			temp2 = model;
		
			while (*temp1 != '\0' && *temp2 != '\0')
			{
				if (*temp1 == *temp2)
				{
					flag = 1;
					temp1++;
					temp2++;
				}
				else
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
			{
				return src;
			}
		}
		src++;
	}
	
	return "no search!";
}*/

//查找model第一次出现的位置
const char *my_search(const char *src, char *model)
{
	int i = 0;
	for (i = 0; src[i] != '\0'; i++)
	{
		int pos = i;
		int j = 0;
		
		while (src[i] != '\0' && model[j] != '\0')
		{
			if (src[i] == model[j])
			{
				i++;
				j++;
			}
			else
			{
				i = pos;	//i归位
				j = 0;
				break;
			}
		}
		
		if (model[j] == '\0')
			return src + pos;
	}
	return "no search!";
}

//统计model出现的次数
int my_index(const char *src, char *model)
{
	const char *temp1;
	char *temp2;
	int flag = 0;
	int count = 0;
	int i = 0;

	while (*src != '\0')
	{
		i = 1;
		if (*src == *model)
		{	
			temp1 = src;
			temp2 = model;
		
			while (*temp1 != '\0' && *temp2 != '\0')
			{
				if (*temp1 == *temp2)
				{
					flag = 1;
					temp1++;
					temp2++;
					i++;
				}
				else
				{
					flag = 0;
					i = 1;
					break;
				}
			}
			if (flag == 1)
			{
				count++;
			}
		}
		src = src + i;
	}
	return count;
}

//KMP算法
void my_kmp(const char *src, char *model)
{
	
}

int main()
{
	double n = 0;
	char buf[20] = {0};
	printf("Please input:");
	fgets(buf, 20, stdin);	//从终端读入数据
	
	int len = my_strlen(buf);
	buf[len - 1] = '\0';
	

	
	char s1[20] = {"34589898984545456"};
	char s2[10] = {"898"};	
	printf("%s\n", my_search(s1, s2));	
	printf("%d\n", my_index(s1, s2));	
	
	return 0;
}

