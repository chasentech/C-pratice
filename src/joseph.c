/*
日期：2018.0730
名称：main.c
描述：数组解决约瑟夫环问题
*/
#include <stdio.h>
#include <stdlib.h>

int *joseph_init(int n)
{
	int i = 0;
	int *people = (int *)malloc(sizeof(int) * n);
		
	if (people == NULL)
	{
		printf("malloc failed!/n");
		exit(1);
	}

	for (i = 0; i < n; i++)
	{
		people[i] = i + 1;
	}
	
	return people;
}

void joseph_release(int *people)
{
	free(people);
}

int joseph(int n)
{
	int *p = joseph_init(n);
	int i = 0;
	int leave = n;
	int sum = 0;
	int j = 0;
	int survivor = 0;
	
	while (leave != 1)
	{
		if (p[i] > 0)
		{
			sum++;
			if (sum == 3)
			{
				sum = 0;
				leave--;
				p[i] = 0;
			}			
		}

		i++;
		if (i == n)
		{
			i = 0;
		}
	}
	
	for (j = 0; j < n; j++)
	{
		if (p[j] > 0)
		{
			survivor = p[j];
			break;
		}
	}
	
	joseph_release(p);
	return survivor;
}



int main()
{
	printf("survivor is %d\n", joseph(5));
	
	return 0;
}
