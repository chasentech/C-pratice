/*******************************************************
时间：2018.07.12
描述：打印某一年日历
*******************************************************/
#include <stdio.h>

//是否闰年
int is_leap_year(int year)
{
	if (year % 100 == 0 && year % 400 == 0)
	{
		return 1;
	}
	else if (year % 4 == 0)
	{
		return 1;
	}
	else return 0;
}

//计算星期几
int week_day(int year, int month, int day)
{
	int week = 0;
	if (month == 1 || month == 2)
	{
		year -= 1;
		month += 12;
	}
	
	//week    0->周一    6->周日
	week = (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year/100 + year/400) % 7;
	
	//调整序号
	if (week == 6)
		week = 0;
	else
		week += 1;
	
	return week;
}

//打印每个月日历
void print_month(int month, int week)
{
	int i = 0;
	int j = 0;	
	
	//打印空格
	for (i = 0; i < week; i++)
		printf("    ");
	
	for (j = 0; j < month; j++)
	{	
		printf("%-4d", j + 1);	
		
		week++;
		
		if (week == 7)
		{
			week = 0;
			printf("\n");
		}
	}
}

//打印年历
void print_year(int year)
{
	int i = 0;
	int week = 0;
	int month_total[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	
	if (is_leap_year(year) == 1)
	{
		month_total[1] = 29;
	}
	
	for (i = 0; i < 12; i++)
	{
		printf("--------%d年%d月--------\n", year, i + 1);
		printf("日  一  二  三  四  五  六\n");
		//printf("1   2   3   4   5   6   7\n");
		
		week = week_day(year, i + 1, 1);	//计算每个月一号
		print_month(month_total[i], week);
		
		printf("\n");
		printf("\n");
	}
}

int main()
{
	int year = 2000;
	
	printf("请输入年份：");
	scanf("%d", &year);
	
	print_year(year);
	return 0;
}
