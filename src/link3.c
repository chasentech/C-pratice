/*
日期：2018.0729
名称：link1.c
描述：环形链表(解决约瑟夫环问题)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
	int value;
	struct node *next;
}node;

node *head = NULL;
node *tail = NULL;

//创建节点
node *mk_node(int value)
{
	node *p = (node *)malloc(sizeof(node));
	if (p == NULL)
	{
		printf("malloc failed!\n");
		exit(1);
	}
	
	p->value = value;
	p->next = NULL;
	
	return p;
}

//释放节点
void free_node(node *p)
{
	free(p);
}

//插入节点
void insert_node(node *p)
{
	tail->next = p;
	tail = p;
}

//遍历节点
void traverse()
{
	node *p = head;
	
	while (1)
	{
		printf("%d ", p->value);
		p = p->next;
		
		if (p == head)
		{
			break;
		}		
	}
	printf("\n");
}

void joseph_init(int n)
{
	int i = 0;
	int *people = (int *)malloc(sizeof(int) * n);
		
	if (people == NULL)
	{
		printf("malloc failed!/n");
		exit(1);
	}

	node *p = mk_node(1);
	head = p;
	tail = p;
	
	
	for (i = 2; i <= n; i++)
	{
		p = mk_node(i);
		insert_node(p);
	}
	
	tail->next = head;
	traverse();
}

void joseph_release(int *people)
{
	free(people);
}

int joseph(int n)
{
	joseph_init(n);
	int survivor = 0;
	int sum = 0;
	
	node *pre = tail;
	node *p = head;
	
	while (p->next != p)
	{
		sum++;
		if(sum == 3)
		{
			sum = 0;
			pre->next = p->next;
			p->next = NULL;
			free_node(p);
			
			p = pre->next;
			
			continue;
		}
		
		p = p->next;
		pre = pre->next;
	}
	
	survivor = p->value;
	free_node(p);

	return survivor;
}

int main()
{
	printf("%d\n", joseph(5));
	
	
	
	
	return 0;
}
