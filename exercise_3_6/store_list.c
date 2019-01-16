#define _CRT_SECURE_NO_WARNINGS
#include "myfunction.h"
#include<stdlib.h>

typedef struct Node *List;
struct Node
{
	int m;
	int n;
	List next;
};

List CreatList();
List FunSum(List p, List q);
List FunMult(List p, List q);
void FunPrint(List x);
void attach(int c, int e, List *rear);

void store_list()
{
	List L1, L2;
	List sum, mult;
	L1 = CreatList();
	L2 = CreatList();
	mult = FunMult(L1, L2);
	FunPrint(mult);
	printf("\n");
	sum = FunSum(L1, L2);
	FunPrint(sum);
	return;
}

List CreatList()
{
	int len,m,n;
	List p = (List)malloc(sizeof(struct Node));
	p->next = NULL;
	List t,tempcell = p;
	scanf("%d", &len);
	for (int i = 0; i < len; i++)
	{
		scanf("%d %d", &m,&n);
//		tempcell1->next = NULL;
		attach(m, n, &tempcell);
	}
	t = p;
	p = p->next;
	free(t);
	return p;
}

void attach(int c, int e, List *rear)
{
	List p;
	p = (List)malloc(sizeof(struct Node));
	p->m = c;
	p->n = e;
	p->next = NULL;
	(*rear)->next = p;
	*rear = p;
	return;
}

List FunSum(List p, List q)
{
	List t1,t2,front, rear, temp;
	int m_sum,cnt=0;
	t1 = p;
	t2 = q;
	rear = (List)malloc(sizeof(struct Node));
	front = rear;
	while (t1&&t2)
	{
		if (t1->n > t2->n)
		{
			attach(t1->m, t1->n, &rear);
			cnt++;
			t1 = t1->next;
		}
		else if (t1->n < t2->n)
		{
			attach(t2->m, t2->n, &rear);
			cnt++;
			t2 = t2->next;
		}
		else
		{
			m_sum = t1->m + t2->m;
			if (m_sum)
			{
				attach(m_sum, t1->n, &rear);
				cnt++;
			}
			t1 = t1->next;
			t2 = t2->next;
		}
	}
	if (t2) rear->next = t2;
	if (t1) rear->next = t1;
//	rear->next = NULL;
	if (!t2 && !t1 && cnt == 0) rear->next = NULL;
	temp = front;
	front = front->next;
	free(temp);
	return front;
}

List FunMult(List p, List q)
{
	List mult, rear, t1, t2, t;
	int c, e;
	if (!p || !q) return NULL;
	t1 = p;
	t2 = q;
	mult = (List)malloc(sizeof(struct Node));
	rear = mult;
	while (t2)
	{
		attach(t1->m*t2->m, t1->n + t2->n, &rear);
		t2 = t2->next;
	}
	t1 = t1->next;
	while (t1)
	{
		t2 = q;
		rear = mult;
		while (t2)
		{
			e = t1->n + t2->n;
			c = t1->m*t2->m;
			while (rear->next&&rear->next->n>e)
			{
				rear = rear->next;
			}
			if (rear->next&&rear->next->n == e)
			{
				if (rear->next->m + c) rear->next->m += c;
				else 
				{
					t = rear->next;
					rear->next = t->next;
					free(t);
				}
			}
			else
			{
				t = (List)malloc(sizeof(struct Node));
				t->m = c;
				t->n = e;
				t->next = rear->next;
				rear->next = t;
				rear = t;
			}
			t2 = t2->next;
		}
		t1 = t1->next;
	}
	t2 = mult;
	mult = mult->next;
	free(t2);
	return mult;
}

void FunPrint(List p)
{
	int flag=0;
	if (!p)
	{
		printf("0 0");
		return;
	}
	while (p)
	{
		if (!flag) flag = 1;
		else printf(" ");
		printf("%d %d", p->m, p->n);
		p = p->next;
	}
//	printf("\n");
	return;
}