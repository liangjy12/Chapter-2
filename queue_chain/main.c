#include<stdio.h>
#include<stdbool.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
	ElementType Data;
	PtrToNode Next;
};

typedef PtrToNode Position;
typedef struct QNode *queue;
struct QNode
{
	Position front, rear;
	int Maxsize;
};

queue createq(int maxsize);
bool isempty(queue q);
ElementType deleteq(queue q);
void addq(queue q, ElementType x);

void main()
{
	queue q = createq(3);
	addq(q, 5);
	addq(q, 6);
	addq(q, 7);
	system("pause");
	return;
}

queue createq(int maxsize)
{
	queue q;
	Position head;
	q = (queue)malloc(sizeof(struct QNode));
	head = (Position)malloc(sizeof(struct Node));
	head->Next = NULL;
	q->front = q->rear = head;
	q->Maxsize = maxsize;
	return q;
}

bool isempty(queue q)
{
	return(q->front == q->rear);
}

ElementType deleteq(queue q)
{
	Position frontcell;
	ElementType frontelem;
	if (isempty(q))
	{
		printf("The Queue is empty!");
		return false;
	}
	else
	{
		frontcell = q->front;
		if (frontcell == q->rear) q->front = q->rear = NULL;
		else q->front = q->front->Next;
		frontelem = frontcell->Data;
		free(frontcell);
		return frontelem;
	}
}

void addq(queue q,ElementType x)
{
	Position temp;
	temp = (Position)malloc(sizeof(struct QNode));
	temp->Data = x;
	temp->Next = NULL;
	q->rear->Next = temp;
	q->rear = temp;
	return;
}