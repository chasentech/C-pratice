#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node *pre;
	struct node *next;
}node;

node tail_sentinel;
node head_sentinel = {0, NULL, &tail_sentinel};
node tail_sentinel = {0, &head_sentinel, NULL};

static node *head = &head_sentinel;
static node *tail = &tail_sentinel; 

//创建节点
node *mk_node(int value)
{
	node *p = (node *)malloc(sizeof(node));
	
	if (p == NULL)
	{
		printf("malloc is failed!\n");
		exit(1);
	}
	
	p->value = value;
	p->pre = NULL;
	p->next = NULL;
}

//释放节点
void free_node(node *p)
{
	free(p);
}

//插入节点
void insert_node(node *p)
{
	p->next = head->next;
	head->next->pre = p;
	
	head->next = p;
	p->pre = head;
}

//遍历链表
void traverse()
{
	node *p = head->next;
	
	while (p != tail)
	{
		printf("%d ", p->value);
		p = p->next;
	}
	printf("\n");
}

//销毁链表
void destory()
{
	node *p = head->next;
	node *q;
	head->next = tail;
	tail->pre = head;
	
	while (p != tail)
	{
		q = p;
		p = p->next;
		free_node(q);
	}
}

//查找节点
node *search_node(int value)
{
	node *p = head->next;
	
	while (p != tail)
	{
		if (p->value == value)
		{
			printf("%d\n", p->value);
			return p;
		}
		p = p->next;
	}
	
	return NULL;
}

//移除链表
void rm_node(node *p)
{
	node *pp = head->next;
	
	while (pp != tail)
	{
		if (pp == p)
		{
			pp->pre->next = pp->next;
			pp->next->pre = pp->pre;
			
			//pp->pre = NULL;
			//pp->next = NULL;
			//free_node(pp);
		}
		
		pp = pp->next;
	}
}


//双向链表不需要逆序(从尾部遍历到头部即为逆序)
void reverse()
{
	node *p = tail->pre;
	
	while (p != head)
	{
		printf("%d ", p->value);
		p = p->pre;
	}
	printf("\n");

}

//删除value = x的节点
void dele_x_node(int x)
{
	node *p = head->next;
	
	while (p != tail)
	{
		if (p->value == x)
		{
			p->pre->next = p->next;
			p->next->pre = p->pre;
			
			free_node(p);
		}
		p = p->next;
	}
}

//插入排序
void insert_sort_node(node *p)
{
	node *pp = head->next;
	
	while (pp != tail)
	{
		if (p->value < pp->value)
		{
			break;
		}
		
		pp = pp->next;
	}

	/*
		前驱指针先建立目标指针与后面指针关系
		后驱指针反之
	*/
	
	pp->pre->next = p;
	p->pre = pp->pre;
	
	p->next = pp;
	pp->pre = p;

}

int main()
{
	node *p = NULL;
	int i = 0;
	
	for (i = 0; i < 10; i++)
	{
		if (i < 3)
		{
			p = mk_node(9);
		}
		else
		{
			p = mk_node(i + 1);
		}
		
		//insert_node(p);
		insert_sort_node(p);
	}
	traverse();

	p = search_node(5);
	rm_node(p);
	free_node(p);
	traverse();
	
	dele_x_node(9);
	traverse();
	
	
		
	destory();

	return 0;
}
